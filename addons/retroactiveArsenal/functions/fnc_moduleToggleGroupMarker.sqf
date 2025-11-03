params ["_logic"];

private _unit = attachedTo _logic;

deleteVehicle _logic;

private _isObj = _unit isEqualType objNull;
private _isPerson = (_isObj && {(_unit isKindOf "CAManBase")});
if (isNull _unit || { !_isObj }) exitWith {
    //[objNull, "No unit or vehicle selected."] call BIS_fnc_showCuratorFeedbackMessage;
};

if (!_isPerson) then {_unit = (((fullCrew [_unit,""]) select 0) select 0);};

private _group = group _unit;

private _hidden = _group getVariable ['ACE_map_hideBlueForceMarker',false];

if (_hidden) exitWith {
	_group setVariable ['ACE_map_hideBlueForceMarker',nil,true];
};
_group setVariable ['ACE_map_hideBlueForceMarker',true,true];