 params ["_unit", ["_sling", false], ["_holster", false], ["_drawPistol", false], ["_drawLauncher", false], ["_unsling", false], ["_time", 0], ["_slung", (_this#0) getVariable ["tsp_slung", []]]];

_knife = if (!isNil "tsp_fnc_melee_weapon") then {!([_unit, handGunWeapon _unit] call tsp_fnc_melee_weapon in ["", "pistol"])} else {false};
if ("sling" in gestureState _unit) exitWith {};
if (_sling) then {
	if (_drawPistol && !_knife && tsp_cba_animate_sling_style == "adhd") then {  //-- Chamber check
		[_unit, "tsp_animate_sling_check"] remoteExec ["playActionNow"];
		playSound3D ["A3\Sounds_F\weapons\Other\dry5-rifle.wss", _unit, false, getPosASL _unit, 5, 1, 10];
		_time = _time + 0.1;
	};
	tsp_future pushBack [time + _time, [_unit], {params ["_unit"]; [_unit, "tsp_animate_sling_sling"] remoteExec ["playActionNow"]}];  //-- Play animation
	tsp_future pushBack [time + _time + 0.2, [_unit], {params ["_unit"]; _holder = [_unit, primaryWeapon _unit, true, false, "tsp_holder2"] call tsp_fnc_throw; _unit setVariable ["tsp_holder", _holder]}];  //-- Throw weapon, hide it
	tsp_future pushBack [time + _time + 0.2, [_unit], {  //-- Attach it, orient it
		params ["_unit"]; 
		(_unit getVariable "tsp_holder") setDamage 1;
		(_unit getVariable "tsp_holder") attachTo [_unit, tsp_cba_animate_sling_pos#0, "Spine3", true]; 
		[_unit getVariable "tsp_holder", tsp_cba_animate_sling_pos#1] call BIS_fnc_setObjectRotation;
	}];
	tsp_future pushBack [time + _time + 0.2, [_unit, !_drawPistol && !_drawLauncher && !_unsling], {  //-- Remove weapon and unhide chest weapon
		params ["_unit", "_unarmed"];
		_rifle = (getUnitLoadout _unit)#0; _unit removeWeapon (primaryWeapon _unit);
		[_unit getVariable "tsp_holder", false] remoteExec ["hideObjectGlobal"];
		if (_unarmed) then {_unit action ["SWITCHWEAPON", _unit, _unit, -1]};
		if (_unarmed && vehicle _unit == _unit) then {[_unit, [animationState _unit regexReplace ["wrfl", "wnon"] regexReplace ["sras", "snon"] regexReplace ["slow", "snon"], 0, 0, false]] remoteExec ["switchMove"]};
		if (_unarmed) then {[_unit, "tsp_common_stop"] remoteExec ["playActionNow"]};
		_unit setVariable ["tsp_slung", [_unit getVariable "tsp_holder", _rifle]];
		_unit setVariable [("tsp_slingKilledHandler"),
			(_unit addEventHandler ["Killed", { params ["_unit"];
				private _slung = _unit getVariable ["tsp_slung",nil];
				if (!isNil "_slung") then {
					[_unit,_slung] spawn { params ["_unit","_slung"]; sleep 1;
						_slung params [['_slingContainer',objNull],['_slung',nil]];
						if !(isNil '_slung') then {
							deleteVehicle _slingContainer;
							sleep 0.1;
							private _deathBox = (_unit nearObjects ["WeaponHolderSimulated",2]);
							if (count _deathBox isEqualTo 0) then {
								_deathBox = createVehicle ["WeaponHolderSimulated",_unit,[],2,"CAN_COLLIDE"];
							} else {_deathBox = (_deathBox select 0)};
							_deathBox addWeaponWithAttachmentsCargoGlobal [_slung, 1];
						};
						_unit setVariable ["tsp_slung",nil];
					};
				};
				_unit setVariable [("tsp_slingKilledHandler"),nil];
				_unit removeEventHandler [_thisEvent,_thisEventHandler];
			}] )
		];
	}];
	_time = _time + 0.2;
};
if (_holster) then {
	[_unit, handgunWeapon _unit] remoteExec ["selectWeapon"];
	[_unit, "tsp_animate_sling_" + (if (_knife) then {"sheath"} else {"holster"})] remoteExec ["playActionNow"];
	_unit spawn {sleep 0.2; playSound3D ["A3\Sounds_F\weapons\Closure\firemode_changer_1.wss", _this, false, getPosASL _this, 5, 1, 5]};
	_time = 0.7;
};
if (_drawPistol) then {
	tsp_future pushBack [time + _time, [_unit], {
		params ["_unit"];
		//if (vehicle _unit == _unit) then {[_unit, [animationState _unit regexReplace ["wrfl", "wpst"], 0, 0, false]] remoteExec ["switchMove"]};
		if (vehicle _unit == _unit) then {[_unit, [animationState _unit regexReplace ["wrfl", "wpst"]]] remoteExec ["switchMove"]};
		if (_knife) exitWith {[_unit, "ready"] spawn tsp_fnc_melee_action};
		[_unit, "tsp_animate_sling_draw" + (if (tsp_cba_animate_sling_style == "israeli") then {"_israeli"} else {""})] remoteExec ["playActionNow"];
		if (tsp_cba_animate_sling_style == "israeli") then {playSound3D ["A3\Sounds_F\weapons\Other\reload_bolt_1.wss", _unit, false, getPosASL _unit, 5, 1, 10]};
	}];
	//tsp_future pushBack [time + _time + 0.01, [_unit], {params ["_unit"]; if (vehicle _unit == _unit) then {[_unit, animationState _unit] remoteExec ["switchMove"]}}];
};
if (_drawLauncher) then {
	tsp_future pushBack [time + _time, [_unit], {
		params ["_unit"];
		if (vehicle _unit == _unit) then {[_unit, [animationState _unit regexReplace ["wrfl", "wlnr"], 0, 0, false]] remoteExec ["switchMove"]};
		[_unit, secondaryWeapon _unit] remoteExec ["selectWeapon"];
		[_unit, "tsp_animate_sling_unlaunch"] remoteExec ["playActionNow"];
	}];
};
if (_unsling) then {
	if (currentWeapon _unit == secondaryWeapon _unit && secondaryWeapon _unit != "") then {[_unit, "tsp_animate_sling_launch"] remoteExec ["playActionNow"]; _time = 1};
	if (currentWeapon _unit == binocular _unit && binocular _unit != "") then {[_unit, "tsp_animate_sling_unbino"] remoteExec ["playActionNow"]; _time = 0.7};
	tsp_future pushBack [time + _time, [_unit, _sling, _slung], {
		params ["_unit", "_sling", "_slung"]; _slung params ["_holder", "_rifle"]; _rifle params ["_class", "_suppressor", "_pointer", "_optic", "_magazine1", "_magazine2", "_bipod"];
		_unit addWeapon _class; {_unit addPrimaryWeaponItem _x} forEach [_suppressor, _pointer, _optic, _bipod];          //-- Add weapon and attachments
		_weaponItems = (weaponsItems _unit select {_x#0 == _class})#0; deleteVehicle _holder;                            //-- Get weapon items (including any magazines that were auto-loaded)
		{if (count _x > 0) then {_unit addWeaponItem [_class, [_x#0, _x#1], true]}} forEach [_magazine1, _magazine2];   //-- Load correct magazine into weapon
		{if (count _x == 0) then {_unit removePrimaryWeaponItem ((getUnitLoadout _unit#0#(4+_forEachIndex)))#0}} forEach [_magazine1, _magazine2]; //-- If mag is empty, remove auto loaded magazine
		{if (count _x > 0) then {_unit addMagazine [_x#0, _x#1]}} forEach [_weaponItems#4, _weaponItems#5];           //-- Return auto-loaded magazine to inventory
		if (vehicle _unit == _unit && stance _unit == "CROUCH") then {[_unit, "amovpknlmstpslowwrfldnon_amovpknlmstpsraswrfldnon"] remoteExec ["switchMove"]};
		if (vehicle _unit == _unit && stance _unit != "CROUCH") then {[_unit, "amovpercmstpslowwrfldnon_amovpercmstpsraswrfldnon"] remoteExec ["switchMove"]};
		[_unit, primaryWeapon _unit] remoteExec ["selectWeapon"];
		if (_sling) then {[_unit, "tsp_animate_sling_swap"] remoteExec ["playActionNow"]} else {_unit setVariable ["tsp_slung", []]};  //-- Dont overwrite if we slung a rifle beforehand
	}]
};