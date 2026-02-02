if (isNil "ace_interact_menu") exitWith {};
if (!isNil "mjb_perksInit") exitWith {};
mjb_perksInit = true;
if (isDedicated) exitWith {};
if (mjb_perks) then {
    call mjb_perks_fnc_perkSelect;
	if (mjb_flashDoorEnabled) exitWith {};
	['CAManBase'] call mjb_perks_fnc_flash;
} else {
	['CAManBase'] call mjb_perks_fnc_flash;
};


if (mjb_enableFlags) then {
    private _condition = {
        true
    };
    private _flag = "\A3\ui_f\data\igui\cfg\actions\takeflag_ca.paa";
    private _statement = { };
    private _action = ["ratsFlags","Flags",_flag,_statement,_condition, { }, [_flag], [0,0,0], 3, [false, true, false, false, true]] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 1, ["ACE_SelfActions","ACE_Equipment"], _action, true] call ace_interact_menu_fnc_addActionToClass;

    private _condition = {
        true
    };
    private _flag = "z\mjb\addons\flags\data\canadaflag_ca.paa";
    private _statement = { params ["_target", "_player", "_actionParams"]; _actionParams params ["_flag"];
        if (getForcedFlagTexture (vehicle _target) isEqualTo _flag) exitWith {[(vehicle _target),""] remoteExec ["forceFlagTexture",0];};
        [(vehicle _target),_flag] remoteExec ["forceFlagTexture",0];
    };
    private _disableMod = {
        params ["_target", "_player", "_params", "_actionData"]; _params params ["_flag"];
        if ((getForcedFlagTexture (vehicle _target)) isEqualTo _flag) then {
            _actionData set [1, "Remove Canadian Flag"];
        };
    };
    private _action = ["ratsFlag","Attach Canadian Flag",_flag,_statement,_condition, { }, [_flag], [0,0,0], 3, [false, true, false, false, true], _disableMod] call ace_interact_menu_fnc_createAction;
    [(typeOf player), 1, ["ACE_SelfActions","ACE_Equipment","ratsFlags"], _action, true] call ace_interact_menu_fnc_addActionToClass;

    private _condition = {
        true
    };
    private _flag = "z\mjb\addons\flags\data\ratsflag_ca.paa";
    private _statement = { params ["_target", "_player", "_actionParams"]; _actionParams params ["_flag"];
        if (getForcedFlagTexture (vehicle _target) isEqualTo _flag) exitWith {[(vehicle _target),""] remoteExec ["forceFlagTexture",0];};
        [(vehicle _target),_flag] remoteExec ["forceFlagTexture",0];
    };
    private _disableMod = {
        params ["_target", "_player", "_params", "_actionData"]; _params params ["_flag"];
        if ((getForcedFlagTexture (vehicle _target)) isEqualTo _flag) then {
            _actionData set [1, "Remove RATS Flag"];
        };
    };
    private _action = ["ratsFlag","Attach RATS Flag",_flag,_statement,_condition, { }, [_flag], [0,0,0], 3, [false, true, false, false, true], _disableMod] call ace_interact_menu_fnc_createAction;
    ["CAManBase", 1, ["ACE_SelfActions","ACE_Equipment","ratsFlags"], _action, true] call ace_interact_menu_fnc_addActionToClass;
};

private _condition = {
    params ["", "_player"];
    private _curState = lifeState _player;
    (_curState isNotEqualTo "INCAPACITATED" || {_curState isEqualTo "INCAPACITATED" && {incapacitatedState _player isNotEqualTo "UNCONSCIOUS"}})
};
private _statement = {
params ["_target", "_player", "_params", "_actionData"];
	if (_target getVariable ["mjb_afkToggle", false]) exitWith {
		_target setVariable ["mjb_afkToggle", nil, true];

// if ace ever allows interact while attached somehow
		private _attached = attachedTo player;
		if (isNull _attached) exitWith {};

		if (_attached getVariable ['ace_dragging_isDragging',false]) exitWith {
			[_attached, player] remoteExec ['ace_dragging_fnc_dropObject',_attached];
		};

		[_attached, player] remoteExec ['ace_dragging_fnc_dropObject_carry',_attached];
	};
    _target setVariable ["mjb_afkToggle", true, true];
};
private _disableMod = {
    params ["_target", "_player", "_params", "_actionData"];
    if (_target getVariable ["mjb_afkToggle", false]) then {
        _actionData set [1, "Disable AFK, disallow ace carry"];
    };
};
private _action = ["ratsAFK","AFK, allow ace carry","",_statement,_condition, { }, [], [0,0,0], 3, [false, true, false, false, true], _disableMod] call ace_interact_menu_fnc_createAction;
["CAManBase", 1, ["ACE_SelfActions","ACE_Equipment"], _action, true] call ace_interact_menu_fnc_addActionToClass;