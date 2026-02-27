params ["_unit", ["_duration", tsp_cba_animate_carry]];

_targets = (_unit nearEntities [["CAManBase"], 3]) select {animationState _x == "ainjpfalmstpsnonwrfldnon_carried_up"};
[[[_unit, _targets#0],_duration],{params ['_units','_duration']; private _unit = (_units select (local (_units # 1))); mjb_tsp_defaultAnimSpeed = getAnimSpeedCoef _unit; _unit setAnimSpeedCoef 10/_duration}] remoteExec ["call",[_unit, _targets#0]];
_unit setVariable ["ace_dragging_isCarrying", true, true];
_unit setVariable ["ace_dragging_carriedObject", _targets#0, true];
[ace_dragging_fnc_startCarryPFH, 0.2, [_unit, _targets#0, cba_missionTime + _duration]] call CBA_fnc_addPerFrameHandler;
sleep _duration;
[[[_unit, _targets#0]],{params ['_units','_duration']; private _unit = (_units select (local (_units # 1))); _unit setAnimSpeedCoef mjb_tsp_defaultAnimSpeed; mjb_tsp_defaultAnimSpeed = nil;}] remoteExec ["call",[_unit, _targets#0]];
[_unit, "blockThrow", "ace_dragging", true] call ace_common_fnc_statusEffect_set;