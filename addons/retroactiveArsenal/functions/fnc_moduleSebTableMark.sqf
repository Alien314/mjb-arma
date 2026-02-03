params ["_logic"];

if !(local _logic) exitWith {};

private _unit = attachedTo _logic;
deleteVehicle _logic;

if (isNil "sebs_briefing_table_main") exitWith {systemChat "Seb's Briefing Table Mod not loaded."};

private _isObj = _unit isEqualType objNull;
private _isTable = (_isObj && {('table' in (toLower (typeOf _unit)))});

if ( !_isTable ) exitWith {
    systemChat "Object is not a Table.";
};

missionNamespace setVariable ["mjb_activeSebTable",_unit,true];