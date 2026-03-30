params ["_unit", ["_sling", false], ["_holster", false], ["_drawPistol", false], ["_drawLauncher", false], ["_unsling", false], ["_slingClass", "auto"], ["_unslingClass", "auto"], ["_time", 0]];

_knife = if (!isNil "tsp_fnc_melee_weapon") then {!([_unit, handGunWeapon _unit] call tsp_fnc_melee_weapon in ["", "pistol"])} else {false};
if ("sling" in gestureState _unit) exitWith {}; //-- No slinging while doing slinging action
if (_sling) then {
	[[_unit] call tsp_fnc_animate_sling_get, _unit getVariable [primaryWeapon _unit+"pref", ""]] params ["_slings", "_preference"];

	if (_slingClass isEqualTo "auto") then {_slingClass = if (_preference != "" && {_preference in _slings}) then {_preference} else {_slings#0}};  //-- If weapon has preference


	_unit setVariable [primaryWeapon _unit+"pref", _slingClass];  //-- Set preference
	if (_drawPistol && {!_knife && {tsp_cba_animate_sling_style isEqualTo "adhd"} }) then {  //-- Chamber check
		[_unit, "tsp_animate_sling_check"] remoteExec ["playActionNow"];
		playSound3D ["A3\Sounds_F\weapons\Other\dry5-rifle.wss", _unit, false, getPosASL _unit, 5, 1, 10];
		_time = _time + 0.1;
	};
	tsp_future pushBack [time + _time, [_unit], {params ["_unit"]; [_unit, "tsp_animate_sling_sling"] remoteExec ["playActionNow"]}];  //-- Play animation
	tsp_future pushBack [time + _time + 0.2, [_unit, _slingClass, !_drawPistol && {!_drawLauncher && {!_unsling} }], {
		params ["_unit", "_slingClass", "_unarmed"]; _rifle = (getUnitLoadout _unit)#0; //-- Get rifle before we throw it

		private _holder = ([_unit, primaryWeapon _unit, true, true, "tsp_holder", !_unarmed, isNil "tsp_server_animate" || vehicle _unit != _unit] call tsp_fnc_throw);

		_unit setVariable [(_slingClass + "holder"), _holder];

		_holder setDamage 1;
		_holder attachTo [_unit, call compile (missionNameSpace getVariable ("tsp_cba_animate_"+_slingClass))#0, "Spine3", true]; 

		[_holder, call compile (missionNameSpace getVariable ("tsp_cba_animate_" + _slingClass))#1] call BIS_fnc_setObjectRotation;

		[_holder, false] remoteExec ["hideObjectGlobal",2];

		_unit setVariable [(_slingClass + "weapon"), [_holder, _rifle]];

		private _slingHandle = _unit getVariable [("tsp_slingKilledHandler"),nil];
		if (isNil '_slingHandle') then {
			_unit setVariable [("tsp_slingKilledHandler"),
				([_unit, "Killed", { params ["_unit"];
					private _slung = _unit getVariable [(_thisArgs + "weapon"),nil];
					if (!isNil "_slung") then {
						[_unit,_slung,_thisArgs] spawn { params ["_unit","_slung","_slingClass"]; sleep 1;
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
							_unit setVariable [(_slingClass + "weapon"),nil];
						};
					};
					_unit setVariable [("tsp_slingKilledHandler"),nil];
					_unit removeEventHandler [_thisEvent,_thisEventHandler];
				},_slingClass] call CBA_fnc_addBISEventHandler )
			];

			// Hide sling in vics so they don't float into people's faces
			[_unit,"GetInMan", {
				params ["_unit"];
				if (vehicle _unit isEqualTo _unit) exitWith {};
				private _slung = _unit getVariable [(_thisArgs + "weapon"),nil];
				_slung params [['_slingContainer',nil]];
				if (isNil '_slingContainer') exitWith {};
				[_slingContainer,true] remoteExec ["hideObjectGlobal", 2];
			},_slingClass] call CBA_fnc_addBISEventHandler;
			[_unit,"GetOutMan", {
				params ["_unit"];
				if (vehicle _unit isNotEqualTo _unit) exitWith {};
				private _slung = _unit getVariable [(_thisArgs + "weapon"),nil];
				_slung params [['_slingContainer',nil]];
				if (isNil '_slingContainer') exitWith {};
				[_slingContainer,false] remoteExec ["hideObjectGlobal", 2];
			},_slingClass] call CBA_fnc_addBISEventHandler;
		};
		if (_unarmed && {vehicle _unit isEqualTo _unit}) then {_unit switchMove (animationState _unit regexReplace ["wrfl", "wnon"] regexReplace ["sras", "snon"] regexReplace ["slow", "snon"])};
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
		if (vehicle _unit isEqualTo _unit) then {[_unit, animationState _unit regexReplace ["wrfl", "wpst"]] remoteExec ["switchMove"]};  //-- Using blendfactor breaks leaning, thanks BI!
		if (_knife) exitWith {[_unit, "ready"] spawn tsp_fnc_melee_action};
		[_unit, "tsp_animate_sling_draw" + (if (tsp_cba_animate_sling_style isEqualTo "israeli") then {"_israeli"} else {""})] remoteExec ["playActionNow"];
		if (tsp_cba_animate_sling_style isEqualTo "israeli") then {playSound3D ["A3\Sounds_F\weapons\Other\reload_bolt_1.wss", _unit, false, getPosASL _unit, 5, 1, 10]};
	}];
};
if (_drawLauncher) then {
	tsp_future pushBack [time + _time, [_unit], {
		params ["_unit"];
		if (vehicle _unit isEqualTo _unit) then {[_unit, [animationState _unit regexReplace ["wrfl", "wlnr"], 0, 0, false]] remoteExec ["switchMove"]};
		[_unit, secondaryWeapon _unit] remoteExec ["selectWeapon"];
		[_unit, "tsp_animate_sling_unlaunch"] remoteExec ["playActionNow"];
	}];
};
if (_unsling) then {
	private _curWep = currentWeapon _unit;
	if (_curWep isNotEqualTo "") then {
		if (_curWep isEqualTo secondaryWeapon _unit) exitWith {[_unit, "tsp_animate_sling_launch"] remoteExec ["playActionNow"]; _time = 1};
		if (_curWep isEqualTo binocular _unit) then {[_unit, "tsp_animate_sling_unbino"] remoteExec ["playActionNow"]; _time = 0.7};
	};
	
	tsp_future pushBack [time + _time, [_unit, _sling, _holster, if (_unslingClass == "auto") then {([_unit, false] call tsp_fnc_animate_sling_get)#0} else {_unslingClass}], {
		params ["_unit", "_sling", "_holster", "_unslingClass"];
		(_unit getVariable [(_unslingClass + "weapon"), []]) params ["_holder", "_rifle"]; _rifle params ["_class", "_suppressor", "_pointer", "_optic", "_magazine1", "_magazine2", "_bipod"];
		_unit addWeapon _class; {_unit addPrimaryWeaponItem _x} forEach [_suppressor, _pointer, _optic, _bipod];          //-- Add weapon and attachments
		_weaponItems = (weaponsItems _unit select {_x#0 isEqualTo _class})#0; deleteVehicle _holder;                            //-- Get weapon items (including any magazines that were auto-loaded)
		{if (count _x > 0) then {_unit addWeaponItem [_class, [_x#0, _x#1], true]}} forEach [_magazine1, _magazine2];   //-- Load correct magazine into weapon
		//{if (count _x isEqualTo 0) then {_unit removePrimaryWeaponItem ((getUnitLoadout _unit#0#(4+_forEachIndex)))#0}} forEach [_magazine1, _magazine2]; //-- If mag is empty, remove auto loaded magazine
		{if (count _x > 0) then {_unit addMagazine [_x#0, _x#1]}} forEach [_weaponItems#4, _weaponItems#5];           //-- Return auto-loaded magazine to inventory
		if (vehicle _unit isEqualTo _unit) then {
			if (stance _unit isEqualTo "CROUCH") exitWith { [_unit, "amovpknlmstpslowwrfldnon_amovpknlmstpsraswrfldnon"] remoteExec ["switchMove"]};
			[_unit, "amovpercmstpslowwrfldnon_amovpercmstpsraswrfldnon"] remoteExec ["switchMove"]
		};
		if (vehicle _unit isEqualTo _unit && {!_holster}) then {_unit switchMove (if (stance _unit isEqualTo "CROUCH") then {"amovpknlmstpslowwrfldnon_amovpknlmstpsraswrfldnon"} else {"amovpercmstpslowwrfldnon_amovpercmstpsraswrfldnon"})};

		_unit setVariable [_unslingClass+"weapon", []]; [_unit, primaryWeapon _unit] remoteExec ["selectWeapon"];
	}]
};

tsp_future pushBack [time + _time + 0.2, [_unit], {  //-- Walking speed changes with amount of slung weapons
	params ["_unit"]; _weapons = ([_unit, false] call tsp_fnc_animate_sling_get);
	if (primaryWeapon _unit isNotEqualTo "") then {_weapons pushBack [primaryWeapon _unit]};
	if (count _weapons <= 2) exitWith {_unit allowSprint true; _unit forceWalk false};
	if (count _weapons > 2) exitWith {_unit allowSprint false; _unit forceWalk true};


}]