params ["_logic"];

if !(local _logic) exitWith {};

private _unit = attachedTo _logic;
deleteVehicle _logic;

private _isObj = _unit isEqualType objNull;
private _isPerson = (_isObj && {(_unit isKindOf "CAManBase")});
if (isNull _unit || { !_isObj }) exitWith {
    //[objNull, "No unit or vehicle selected."] call BIS_fnc_showCuratorFeedbackMessage;
};

if !(_isPerson) exitWith {};

if (isNil "mjb_jtacArray") then {mjb_jtacArray = []};
mjb_jtacArray pushBackUnique _unit;
publicVariable mjb_jtacArray;