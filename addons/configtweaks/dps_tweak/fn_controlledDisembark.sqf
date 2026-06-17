// ====================================================================================
// DPS_fnc_controlledDisembark - Trigger controlled disembark
// ====================================================================================
// Dismounts only cargo units (not crew) in a controlled manner with staggered exits
// and post-dismount formation setup
//
// Uses doGetOut for dismount
//
// Params:
//   _vehicle - Vehicle to dismount cargo from
// ====================================================================================

params ["_vehicle"];

if (!alive _vehicle) exitWith {};
if (_vehicle getVariable ["DPS_DisembarkInProgress", false]) exitWith {};
if ((getPosATL _vehicle) select 2 > 10) exitWith {};  // Sling-loaded or airborne

// Only execute where vehicle is local (server, HC, or client who owns it)
if (!local _vehicle) exitWith {};

_vehicle setVariable ["DPS_DisembarkInProgress", true, true];
_vehicle setVariable ["DPS_LastDismountTime", time, true];

// Uses fullCrew to correctly identify cargo vs turret crew (loader, rear gunner, etc.)
private _cargoUnits = [_vehicle] call DPS_fnc_getCargoUnits;

if (count _cargoUnits == 0) exitWith {
    _vehicle setVariable ["DPS_DisembarkInProgress", false, true];
};

private _group = group (_cargoUnits select 0);
private _driver = driver _vehicle;
private _isPlayerLed = [_group] call DPS_fnc_isPlayerLedGroup;

// Check if turretless (transport/soft-skin) — driver dismounts too
private _isTurretless = count ((_vehicle call BIS_fnc_vehicleCrewTurrets) - [-1]) == 0;

// Set driver as group leader so vehicle continues to waypoint (AI groups only)
if (!_isPlayerLed && !isNull _driver && alive _driver && {group _driver == _group}) then {
    _group selectLeader _driver;
    [format ["Set driver %1 as group leader", name _driver]] call DPS_fnc_log;
};

// setFormation works where group leader is local (AI groups only)
if (!_isPlayerLed && local leader _group) then {
    _group setFormation "WEDGE";
};

// Flag turretless driver dismount BEFORE the spawn so GetOut EH knows to allow it
if (_isTurretless && !isNull _driver && alive _driver && !isPlayer _driver) then {
    _vehicle setVariable ["DPS_DriverDismounted", true, true];
};

[format ["Controlled disembark: %1 units from %2%3", count _cargoUnits, typeOf _vehicle,
    if (_isTurretless) then { " (turretless - driver dismounts too)" } else { "" }]] call DPS_fnc_log;

// Spawn dismount sequence
[_vehicle, _cargoUnits, _group] spawn {
    params ["_vehicle", "_cargoUnits", "_group"];

    // Stop vehicle for safe dismount
    if (local _vehicle) then { _vehicle forceSpeed 0 };
    sleep 2;

    // Staggered dismount — sleep between each doGetOut to prevent exit animation conflicts
    // AUTOCOMBAT is NOT re-enabled here — the GetOut EH handles blocking,
    // and AUTOCOMBAT will be re-enabled naturally when the unit engages on foot
    {
        unassignVehicle _x;
        if (local _x) then {
            [_x] orderGetIn false;
            doGetOut _x;
        } else {
            [_x] remoteExec ["DPS_fnc_remoteEnableAndDebus", _x];
        };
        sleep 0.5;
    } forEach _cargoUnits;

    // Turretless: dismount the driver too
    private _isTurretless = _vehicle getVariable ["DPS_DriverDismounted", false];
    private _driverUnit = driver _vehicle;
    if (_isTurretless && !isNull _driverUnit && alive _driverUnit && !isPlayer _driverUnit) then {
        unassignVehicle _driverUnit;
        if (local _driverUnit) then {
            [_driverUnit] orderGetIn false;
            doGetOut _driverUnit;
        } else {
            [_driverUnit] remoteExec ["DPS_fnc_remoteEnableAndDebus", _driverUnit];
        };
        _cargoUnits pushBack _driverUnit;  // Add to verification list
        sleep 0.5;
        [format ["Driver %1 ordered to dismount (turretless vehicle)", name _driverUnit]] call DPS_fnc_log;
    };

    // Wait for all units to actually exit (timeout scales with unit count)
    private _timeout = 5 + (count _cargoUnits) * 3;
    private _exitStart = time;
    waitUntil {
        sleep 1;
        (_cargoUnits findIf {alive _x && vehicle _x == _vehicle}) == -1 || (time - _exitStart > _timeout)
    };

    // Fallback: force-eject any unit still inside
    // moveOut does not trigger GetOut EH, so replicate its effects manually
    private _stuck = _cargoUnits select {alive _x && vehicle _x == _vehicle};
    private _crewData = fullCrew _vehicle;
    {
        private _unit = _x;
        private _seatRole = "cargo";
        private _seatTurret = [];
        private _crewIdx = _crewData findIf {(_x select 0) isEqualTo _unit};
        if (_crewIdx != -1) then {
            _seatRole = (_crewData select _crewIdx) select 1;
            _seatTurret = (_crewData select _crewIdx) select 3;
        };

        if (local _unit) then {
            moveOut _unit;
            [_unit] orderGetIn false;
            [_unit] allowGetIn false;
        } else {
            _unit remoteExec ["moveOut", _unit];
            [[_unit], false] remoteExec ["orderGetIn", _unit];
            [[_unit], false] remoteExec ["allowGetIn", _unit];
        };

        unassignVehicle _unit;
        _unit setVariable ["DPS_OriginalVehicle", _vehicle, true];
        _unit setVariable ["DPS_DismountTime", time, true];
        _unit setVariable ["DPS_OriginalRole", _seatRole, true];
        if (_seatRole == "turret") then {
            _unit setVariable ["DPS_OriginalTurretPath", _seatTurret, true];
        };
        _unit setVariable ["DPS_Blocked", true, true];

        if (!isNil "DPS_BlockedUnits") then {
            DPS_BlockedUnits pushBackUnique _unit;
        };

        [format ["FALLBACK: moveOut %1 (role: %2, doGetOut failed)", name _unit, _seatRole]] call DPS_fnc_log;
    } forEach _stuck;

    if (count _stuck > 0) then {
        _vehicle setVariable ["DPS_InfantryDismounted", true, true];
    };

    _vehicle setVariable ["DPS_DisembarkInProgress", false, true];

    // Restore vehicle movement and force path recalculation
    [_vehicle] call DPS_fnc_resumeVehicle;

    // Re-confirm driver as leader after dismount sequence (AI groups only)
    private _drv = driver _vehicle;
    private _isPlayerLedGrp = [_group] call DPS_fnc_isPlayerLedGroup;

    if (!_isPlayerLedGrp && !isNull _drv && alive _drv && {group _drv == _group}) then {
        _group selectLeader _drv;

        // Re-suppress LAMBS on driver to ensure vehicle follows waypoints
        _drv setVariable ["lambs_danger_disableAI", true];
    };

    // Set tactical formation for dismounted infantry (AI groups only)
    if (!_isPlayerLedGrp && !isNull _group && {count (units _group) > 0}) then {
        if (local leader _group) then {
            _group setFormation "WEDGE";
        };

        // Make dismounted infantry follow the group (driver/vehicle)
        // Don't issue doMove to anyone - let waypoint drive the group
        {
            if (alive _x && vehicle _x == _x && local _x) then {
                _x doFollow (leader _group);
            };
        } forEach (units _group);
    };
};
