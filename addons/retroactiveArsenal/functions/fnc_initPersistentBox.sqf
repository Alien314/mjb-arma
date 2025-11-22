/*
  How to use:

    If you want persistence between multiple missions, put 'missionGroup = "missionGroupName";' in description.ext for each of the missions.

    Give an object a name in editor or use 'this' from the object's init box.

    Put '[objectName, "varName"] call mjb_arsenal_fnc_initPersistentBox;' in the init.sqf or the container's init box, should work for vehicle inventories as well.

	Be sure you use different varNames for different objects, or the contents of both will be the last one closed.
*/

params [["_crate",objNull,[objNull]], ["_varName",nil,[""]], ["_override",false,[true]]];

if (!canSuspend) exitWith {_this spawn mjb_arsenal_fnc_initPersistentBox};
sleep (random 1);

mjb_profCrateOverride = _override;

if (_crate isEqualTo objNull) exitWith {false};

private _prevPersist = _crate getVariable ["mjb_persistName", nil];
if (!isNil "_prevPersist") then {
  private _prevSave = _crate getVariable ["mjb_persistSaveHandler", nil];
  _crate removeEventHandler ["ContainerClosed", _prevSave];
} else {
	private _action =
	[
		"crate_ammo_arsenal","RATS Ammo Arsenal","\A3\ui_f\data\igui\cfg\weaponicons\MG_ca.paa",
		{
			[] call mjb_arsenal_fnc_arsenalAmmo;
		},
		{},
		{},
		[],
		[0,0,0],
		5
	] call ace_interact_menu_fnc_createAction;
	
    [_crate, 0, ["ACE_MainActions"], _action] call ace_interact_menu_fnc_addActionToObject;
};

_crate setVariable ["mjb_persistName", _varName];

_crate setVariable ["mjb_persistSaveHandler", (_crate addEventHandler ["ContainerClosed", {
    params ["_container", ""];
    [_container, (_container getVariable ["mjb_persistName",nil]) ] remoteExec ["mjb_arsenal_fnc_getPersistentBox", 2];
  }]
)];

if !(isServer) exitWith {};

private _boxesName = ('mjb_persistentBoxes' + _varName);
private _boxes = (missionNamespace getVariable [_boxesName,[]]);
missionNamespace setVariable [_boxesName, (_boxes + [_crate])];

_crate addEventHandler ["Deleted", {
	params ["_crate"];
    private _varName = _crate getVariable ["mjb_persistName", nil];
    if (isNil '_varName') exitWith {};
	private _boxesName = ('mjb_persistentBoxes' + _varName);
	private _boxes = (missionNamespace getVariable [_boxesName,[]]);
	missionNamespace setVariable [_boxesName, (_boxes - [_crate] - [objNull])];
}];

if (isNil ("mjb_persistEnd" + _varName)) then {
    missionNamespace setVariable [("mjb_persistEnd" + _varName),true];
	[{!(isNil "tmf_common_ending")}, { params ["_varName"];
        private _boxesName = ('mjb_persistentBoxes' + _varName);
        private _boxes = (missionNamespace getVariable [_boxesName,[]]);
        if (_boxes isEqualTo []) exitWith {};
		[(_boxes select 0), _varName] remoteExec ["mjb_arsenal_fnc_getPersistentBox", 2];
	}, [_varName]] call cba_fnc_waitUntilAndExecute;
};

if (isNil ("mjb_persistTimer" + _varName)) then {
  missionNamespace setVariable [("mjb_persistTimer" + _varName), (
    [_varName] spawn {
		params ["_varName"];
		sleep 300;
        private _boxesName = ('mjb_persistentBoxes' + _varName);
        private _boxes = (missionNamespace getVariable [_boxesName,[]]);
		while {_boxes isNotEqualTo []} do {
			[(_boxes select 0), _varName] remoteExec ["mjb_arsenal_fnc_getPersistentBox", 2];
			sleep 300;
            _boxes = (missionNamespace getVariable [_boxesName,[]]);
		};
	}
  )];
};

// _crate allowDamage false;

[_crate,_varName] call mjb_arsenal_fnc_loadPersistentBox;