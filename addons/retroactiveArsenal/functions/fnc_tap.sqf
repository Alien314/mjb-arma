params ["_unit", ["_target", objNull], ["_side", -1], ["_mode", if ((getCameraViewDirection (_this#0))#2 < -0.35) then {"leg"} else {"shoulder"}]];

    _targets = [_unit, eyePos _unit, [0,15,30,45,60,-15,-30,-45,-60], 3, getCameraViewDirection _unit] call tsp_fnc_obstruction select {alive (_x#0) && _x#0 isKindOf "CAManBase"};
    if (_target isEqualTo objNull && count _targets > 0) then {_target = _targets#0#0};
    if (_target isEqualTo objNull || "leg" in gestureState _unit || "shoulder" in gestureState _unit) exitWith {};
	if (_mode isEqualTo "head" || {((getCameraViewDirection (_this#0))#2 > -0.05 || {( (floor ((getPosWorld ACE_player) # 2)) - (floor ((getPosWorld cursorObject) # 2))) > 0.9}) && {((positionCameraToWorld [0,0,0]) distance (_target modelToWorld selectionPosition [_target, "head", 12, true, "FirstPoint"])) < 3}}) exitWith {[ACE_player, _target] spawn hfgb_fnc_patHead;};
    if (_side == -1) then {_side = [0,1] select([ACE_player, _target] call BIS_fnc_relativeDirTo < 180)};
    [_unit, "", "tsp_animate_"+_mode+"_wnon_laut", "", "tsp" in gestureState _unit, true, true] spawn tsp_fnc_gesture_play;
    [[name _unit, "Squeezed your " + (["right", "left"] select _side) + " " + _mode], tsp_fnc_hint] remoteExec ["call", _target];
    [_unit, 5, "", 0] call tsp_fnc_animate_effect; sleep 0.3; 
    [_target, 5, "A3\Sounds_F\characters\footsteps\int_carpet\carpet_int_sprint_HPF_"+str(round random 8 max 1)+".wss", 1] call tsp_fnc_animate_effect;