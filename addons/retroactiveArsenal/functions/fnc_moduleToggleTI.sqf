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

if ((equipmentDisabled _unit) select 1) exitWith {
	_unit disableTIEquipment false;
	_unit setVariable ["A3TI_Disable",false,true];
	systemChat "Thermals re-enabled.";
};

_unit disableTIEquipment true;
_unit setVariable ["A3TI_Disable",true,true];
systemChat "Thermals disabled.";
