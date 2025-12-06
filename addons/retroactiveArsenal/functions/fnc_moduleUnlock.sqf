params ["_logic"];

if !(local _logic) exitWith {};

private _unit = attachedTo _logic;
deleteVehicle _logic;

private _isObj = _unit isEqualType objNull;
private _isPerson = (_isObj && {(_unit isKindOf "CAManBase")});
if (isNull _unit || { !_isObj }) exitWith {
    //[objNull, "No unit or vehicle selected."] call BIS_fnc_showCuratorFeedbackMessage;
};

if (_isPerson) exitWith {};
if (isNil "zen_dialog") exitWith {};

["Lock/Unlock", 
	[
		["CHECKBOX", "Empty to Unlock, Check to Lock:", false, true],
		["CHECKBOX", "Lock for Players Only:", false, true],
		["CHECKBOX", "Lock Vehicle Inventory:", false, true]
	], {  params ["_values", "_args"];
		_values params ["_lock","_players","_cargo"];
		_args params ["_vehicle"];
        if (_players && {_lock}) then {_lock = false};
		{
			_x params ["_unit","_type","_cargo","_turret"];
			switch (_type) do {
				case "driver": {
					[_vehicle, _lock] remoteExec ["lockDriver",_vehicle];
					[_vehicle, ([([1,2] select _lock),3] select _players)] remoteExec ["lock",_vehicle];
				};

				case "cargo": {
					[_vehicle, [_cargo, _lock]] remoteExec ["lockCargo",[_vehicle,_unit]];
				};

				default {
					[_vehicle, [_turret, _lock]] remoteExec ["lockTurret",[_vehicle,_unit]];
				};
			};
		} forEach (fullCrew [_vehicle,"",true]);
        if (!_cargo) exitWith {
			[[_vehicle],{ params ['_vehicle'];
				private _id = _vehicle getVariable ['mjb_cargoLock',nil];
				if (isNil '_id') exitWith {};
                _vehicle removeEventHandler ["ContainerOpened",_id];
				_vehicle setVariable ['mjb_cargoLock',nil];
			}] remoteExec ['call'];
			remoteExec ["", ('mjb_lock' + (str _vehicle))];
		};
		[[_vehicle],{ params ['_vehicle'];
            if (!hasInterface) exitWith {};
            if (isNull _vehicle) exitWith {};
            _vehicle setVariable ['mjb_cargoLock',(
				[_vehicle, "ContainerOpened", {
					// ace_vehiclelock_fnc_onOpenInventory
					 playSound "ACE_Sound_Click";

					[{
						!isNull (findDisplay 602)
					},
					{
						(findDisplay 602) closeDisplay 0;
						[{
							ACE_player action ["Gear", objNull];
						}, []] call CBA_fnc_execNextFrame;
					}, []] call CBA_fnc_waitUntilAndExecute;
				}] call CBA_fnc_addBISEventHandler
			)];
        }] remoteExec ['call',0,('mjb_lock' + (str _vehicle))];
},{},[_unit]] call zen_dialog_fnc_create;