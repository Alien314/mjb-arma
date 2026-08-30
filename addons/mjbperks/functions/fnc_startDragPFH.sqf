#include "\z\ace\addons\dragging\script_component.hpp"
#undef DRAG_ANIMATIONS
#define DRAG_ANIMATIONS ["amovppnemsprslowwpstdnon_turnl", "amovppnemsprslowwpstdnon_turnr", "amovppnemsprslowwpstdnon", "amovppnemsprslowwpstdfr", "amovppnemsprslowwpstdfl", "amovppnemsprslowwpstdbr", "amovppnemsprslowwpstdbl", "amovppnemsprslowwpstdr", "amovppnemsprslowwpstdl", "amovppnemsprslowwpstdf", "amovppnemrunslowwpstdb", "amovppnemrunslowwpstdf", "amovppnemsprslowwpstdb", "amovppnemrunsraswpstdf", "amovppnemstpsraswpstdnon", "amovppnemstpsraswpstdnon_turnr", "amovppnemstpsraswpstdnon_turnl", "amovppnemrunslowwpstdbr", "amovppnemrunslowwpstdbl", "amovppnemrunslowwpstdr", "amovppnemrunslowwpstdl", "amovppnemrunslowwpstdfl", "amovppnemrunslowwpstdfr", "amovppnemsprslowwrfldnon_turnl", "amovppnemsprslowwrfldnon_turnr", "amovppnemsprslowwrfldnon", "amovppnemsprslowwrfldfr", "amovppnemsprslowwrfldfl", "amovppnemsprslowwrfldbr", "amovppnemsprslowwrfldbl", "amovppnemsprslowwrfldr", "amovppnemsprslowwrfldl", "amovppnemsprslowwrfldf", "amovppnemrunsnonwnondl", "amovppnemrunsnonwnondnon_turnl", "amovppnemrunsnonwnondnon_turnr", "amovppnemrunsnonwnondr", "amovppnemrunsnonwnondfl", "amovppnemrunsnonwnondfr", "amovppnemrunsnonwnondbl", "amovppnemrunslowwrfldb", "amovppnemrunsnonwnondbr", "amovppnemrunsnonwnondb", "amovppnemrunslowwrfldf", "amovppnemsprslowwrfldb", "amovppnemrunsraswrfldf", "amovppnemstpsraswrfldnon", "amovppnemstpsraswrfldnon_turnr", "amovppnemstpsraswrfldnon_turnl", "amovppnemrunslowwrfldbr", "amovppnemrunslowwrfldbl", "amovppnemrunslowwrfldr", "amovppnemrunslowwrfldl", "amovppnemrunslowwrfldfl", "amovppnemrunslowwrfldfr",  "amovppnemstpsnonwnondnon", "amovppnemstpsraswpstdnon", "amovppnemrunsraswpstdnon", "amovppnemrunsnonwnondf", "amovpercmstpslowwrfldnon_acinpknlmwlkslowwrfldb_2", "amovpercmstpsraswpstdnon_acinpknlmwlksnonwpstdb_2", "amovpercmstpsnonwnondnon_acinpknlmwlksnonwnondb_2", "acinpknlmstpsraswrfldnon", "acinpknlmstpsnonwpstdnon", "acinpknlmstpsnonwnondnon", "acinpknlmwlksraswrfldb", "acinpknlmwlksnonwnondb", "ace_dragging_rifle_limpb", "ace_dragging", "ace_dragging_limpb", "ace_dragging_static", "ace_dragging_drop"]
/*
 * Author: commy2
 * Checks for dragging conditions. If these are met, the unit will start dragging. Called from ace_dragging_fnc_startDrag.
 *
 * Arguments:
 * 0: Arguments <ARRAY>
 * - 0: Unit <OBJECT>
 * - 1: Target <OBJECT>
 * - 2: Timeout <NUMBER>
 * 1: PFEH Id <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [[player, cursorTarget, 10], _idPFH] call ace_dragging_fnc_startDragPFH;
 *
 * Public: No
 */

#ifdef DEBUG_ENABLED_DRAGGING
    systemChat format ["%1 startDragPFH running", CBA_missionTime];
#endif

params ["_args", "_idPFH"];
_args params ["_unit", "_target", "_timeOut"];

// Handle aborting drag
if !(_unit getVariable [QGVAR(isDragging), false]) exitWith {
    TRACE_4("drag false",_unit,_target,_timeOut,CBA_missionTime);
    _idPFH call CBA_fnc_removePerFrameHandler;
};

// Drop if the target is destroyed or if the target moved away from carrier (e.g. weapon disassembled)
if (!alive _target || {_unit distance _target > 10}) exitWith {
    TRACE_4("dead/distance",_unit,_target,_timeOut,CBA_missionTime);
    [_unit, _target] call FUNC(dropObject);

    _idPFH call CBA_fnc_removePerFrameHandler;
};

// Timeout: Drop target. CBA_missionTime, because anim length is linked to ingame time
if (CBA_missionTime > _timeOut) exitWith {
    TRACE_4("timeout",_unit,_target,_timeOut,CBA_missionTime);
    [_unit, _target] call FUNC(dropObject);

    _idPFH call CBA_fnc_removePerFrameHandler;
};

// Unit is ready to start dragging
if (animationState _unit in DRAG_ANIMATIONS || {_unit call EFUNC(common,isSwimming)}) exitWith {
    TRACE_4("Start Dragging",_unit,_target,_timeOut,CBA_missionTime);
    [_unit, _target] call FUNC(dragObject);

    _idPFH call CBA_fnc_removePerFrameHandler;
};
