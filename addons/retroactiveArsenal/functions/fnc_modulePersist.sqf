if !(local _logic) exitWith {};

deleteVehicle _logic;

private _persist = (missionNamespace getVariable ["mjb_persistenceActive",false]);
private _persistName = mjb_pLoadName;
if (isNil "_persistName") then {_persistName = "none"};

["Persistence Key", [
	["EDIT", "Key", _persistName, true]
], {  params ["_values", "_args"];
	_values params ["_name"];

	mjb_pLoadName = _name;
	publicVariable "mjb_pLoadName";

	["mjb_modulePersist",[_name],"mjb_modulePersistence"] call CBA_fnc_globalEventJIP;
},{},[]] call zen_dialog_fnc_create;