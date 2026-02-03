params ["_logic"];

if !(local _logic) exitWith {};

private _unit = attachedTo _logic;
deleteVehicle _logic;

private _isObj = _unit isEqualType objNull;
private _isTable = (_isObj && {('table' in (toLower (typeOf _unit)))});

if (isNil "sebs_briefing_table_main") exitWith {systemChat "Seb's Briefing Table Mod not loaded."};
if (isNil "mjb_activeSebTable") exitWith {systemChat "No table marked."};

[mjb_activeSebTable] remoteExecCall ["sebs_briefing_table_fnc_clearTable", 0, mjb_activeSebTable]; 