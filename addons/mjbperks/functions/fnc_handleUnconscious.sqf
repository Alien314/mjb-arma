#include "\z\ace\addons\dragging\script_component.hpp"
/*
 * Author: commy2
 * Handles consciousness change of a unit while dragging / carrying.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call ace_dragging_fnc_handleUnconscious;
 *
 * Public: No
*/

params ["_unit"];

private _player = ACE_player;

if (_player getVariable [QGVAR(isDragging), false]) exitWith {
    private _draggedObject = _player getVariable [QGVAR(draggedObject), objNull];

    // Handle falling unconscious
    if (_unit isEqualTo _player) then {
        [_unit, _draggedObject] call FUNC(dropObject);
    };

    // Handle waking up dragged unit
    if ((mjb_wakeDropDragged || {!alive _unit}) && {_unit isEqualTo _draggedObject}) then {
        [_player, _draggedObject] call FUNC(dropObject);
    };
};

if (_player getVariable [QGVAR(isCarrying), false]) exitWith {
    private _carriedObject = _player getVariable [QGVAR(carriedObject), objNull];

    // Handle falling unconscious
    if (_unit isEqualTo _player) then {
        [_unit, _carriedObject] call FUNC(dropObject_carry);
    };

    // Handle waking up dragged unit
    if ( (mjb_wakeDropCarried || {!alive _unit}) && {_unit isEqualTo _carriedObject}) then {
        [_player, _carriedObject] call FUNC(dropObject_carry);
    };
};

if !(!_active && {alive _unit && {local _unit}}) exitWith {};
private _owner = _unit getVariable [QEGVAR(common,owner),objNull];
if ( !isNull _owner ) then {
	if (!mjb_wakeDropDragged && {_owner getVariable [QGVAR(isDragging), false]}) exitWith {
		[_unit, "AinjPpneMrunSnonWnonDb_still", 0] call EFUNC(common,doAnimation);
	};
	if (mjb_wakeDropCarried) exitWith {};
	[_unit, "AinjPfalMstpSnonWnonDf_carried_dead", 2] call EFUNC(common,doAnimation);
};