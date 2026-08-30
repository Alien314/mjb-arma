#include "\z\ace\addons\dragging\script_component.hpp"
#undef DRAG_ANIMATIONS
#define DRAG_ANIMATIONS ["amovppnemsprslowwpstdnon_turnl", "amovppnemsprslowwpstdnon_turnr", "amovppnemsprslowwpstdnon", "amovppnemsprslowwpstdfr", "amovppnemsprslowwpstdfl", "amovppnemsprslowwpstdbr", "amovppnemsprslowwpstdbl", "amovppnemsprslowwpstdr", "amovppnemsprslowwpstdl", "amovppnemsprslowwpstdf", "amovppnemrunslowwpstdb", "amovppnemrunslowwpstdf", "amovppnemsprslowwpstdb", "amovppnemrunsraswpstdf", "amovppnemstpsraswpstdnon", "amovppnemstpsraswpstdnon_turnr", "amovppnemstpsraswpstdnon_turnl", "amovppnemrunslowwpstdbr", "amovppnemrunslowwpstdbl", "amovppnemrunslowwpstdr", "amovppnemrunslowwpstdl", "amovppnemrunslowwpstdfl", "amovppnemrunslowwpstdfr", "amovppnemsprslowwrfldnon_turnl", "amovppnemsprslowwrfldnon_turnr", "amovppnemsprslowwrfldnon", "amovppnemsprslowwrfldfr", "amovppnemsprslowwrfldfl", "amovppnemsprslowwrfldbr", "amovppnemsprslowwrfldbl", "amovppnemsprslowwrfldr", "amovppnemsprslowwrfldl", "amovppnemsprslowwrfldf", "amovppnemrunsnonwnondl", "amovppnemrunsnonwnondnon_turnl", "amovppnemrunsnonwnondnon_turnr", "amovppnemrunsnonwnondr", "amovppnemrunsnonwnondfl", "amovppnemrunsnonwnondfr", "amovppnemrunsnonwnondbl", "amovppnemrunslowwrfldb", "amovppnemrunsnonwnondbr", "amovppnemrunsnonwnondb", "amovppnemrunslowwrfldf", "amovppnemsprslowwrfldb", "amovppnemrunsraswrfldf", "amovppnemstpsraswrfldnon", "amovppnemstpsraswrfldnon_turnr", "amovppnemstpsraswrfldnon_turnl", "amovppnemrunslowwrfldbr", "amovppnemrunslowwrfldbl", "amovppnemrunslowwrfldr", "amovppnemrunslowwrfldl", "amovppnemrunslowwrfldfl", "amovppnemrunslowwrfldfr",  "amovppnemstpsnonwnondnon", "amovppnemstpsraswpstdnon", "amovppnemrunsraswpstdnon", "amovppnemrunsnonwnondf", "amovpercmstpslowwrfldnon_acinpknlmwlkslowwrfldb_2", "amovpercmstpsraswpstdnon_acinpknlmwlksnonwpstdb_2", "amovpercmstpsnonwnondnon_acinpknlmwlksnonwnondb_2", "acinpknlmstpsraswrfldnon", "acinpknlmstpsnonwpstdnon", "acinpknlmstpsnonwnondnon", "acinpknlmwlksraswrfldb", "acinpknlmwlksnonwnondb", "ace_dragging_rifle_limpb", "ace_dragging", "ace_dragging_limpb", "ace_dragging_static", "ace_dragging_drop"]
/*
 * Author: commy2
 * Handle the animation for a unit for the dragging module.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Animation <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, "amovpercmstpsnonwnondnon"] call ace_dragging_fnc_handleAnimChanged;
 *
 * Public: No
*/

params ["_unit", "_anim"];
//IGNORE_PRIVATE_WARNING ["_thisArgs", "_thisID"];
_thisArgs params ["_realUnit"];
TRACE_4("params",_unit,_anim,_realUnit,_thisID);

if (_unit != _realUnit) exitWith {
    TRACE_2("respawn (unit changed) - remove EH",_unit,_realUnit);
    _unit removeEventHandler ["AnimChanged", _thisID];
};


if (_unit getVariable [QGVAR(isDragging), false]) then {
    // Drop dragged object when not in valid animation
    /*if (stance _unit isEqualTo "PRONE" && {_anim isEqualTo "amovppnemstpsraswrfldnon_amovpknlmstpsraswrfldnon"}) exitWith {
        [_target, "AinjPpneMrunSnonWnonDb_grab", 2] call EFUNC(common,doAnimation);
        [{
            private _unitWeapon = _this getVariable [QGVAR(currentWeapon), ""];

            if (_unitWeapon isKindOf ["Pistol", configFile >> "CfgWeapons"]) then {
                [_this, "ACE_dragWithPistol"] call EFUNC(common,doGesture);
            } else {
                [_this, "ACE_dragWithRifle"] call EFUNC(common,doGesture);
            };
        }, _unit] call CBA_fnc_execNextFrame;
        [{[_this, "AinjPpneMrunSnonWnonDb_still", 0] call EFUNC(common,doAnimation);},_target,0.2] call CBA_fnc_waitAndExecute;
        if (GVAR(dragAndFire)) then {
            [_unit, "DefaultAction", _unit getVariable [QGVAR(blockFire), -1]] call EFUNC(common,removeActionEventHandler); 
        };
	};*/
    if (!(_anim in DRAG_ANIMATIONS) && {!(_unit call EFUNC(common,isSwimming))}) then {
        private _draggedObject = _unit getVariable [QGVAR(draggedObject), objNull];
        if (!isNull _draggedObject) then {
            TRACE_2("stop drag",_unit,_draggedObject);
            [_unit, _draggedObject] call FUNC(dropObject);
			if (_anim in ["amovpknlmstpsraswrfldnon","amovppnemstpsraswrfldnon_amovpknlmstpsraswrfldnon","amovppnemstpsraswpstdnon_amovpknlmstpsraswpstdnon"]) then {
				[{!(animationState (_this select 0) in ["amovppnemstpsraswrfldnon_amovpknlmstpsraswrfldnon","amovppnemstpsraswpstdnon_amovpknlmstpsraswpstdnon"])},{
					_this call FUNC(startDrag);
				},[_unit,_draggedObject],6] call CBA_fnc_waitUntilAndExecute;
			};
        };
    };
} else {
    if (_unit getVariable [QGVAR(isCarrying), false]) then {
        // Drop carried object when not standing; also some exceptions when picking up crate
        if (stance _unit != "STAND" && {_anim != "amovpercmstpsnonwnondnon"}) then {
            private _carriedObject = _unit getVariable [QGVAR(carriedObject), objNull];

            if (!isNull _carriedObject) then {
                TRACE_2("stop carry",_unit,_carriedObject);
                [_unit, _carriedObject] call FUNC(dropObject_carry);
            };
        };
    } else {
        TRACE_1("not drag/carry - remove EH",_unit);
        _unit removeEventHandler ["AnimChanged", _thisID];
    };
};
