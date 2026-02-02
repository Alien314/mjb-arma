params ['_veh'];

private _turret = _veh unitTurret player;

_veh enableDirectionStabilization [true, _turret];

private _parents = [configFile >> "CfgVehicles" >> (typeOf _veh), true] call BIS_fnc_returnParents;
private _base = _parents select (_parents findIf {'base' in (toLower _x)});
mjb_weaponOffset = [mjb_stabilizeOffsets, _base] call CBA_fnc_hashGet;
//mjb_otherTarget = false;
mjb_stabTogglePFH = [{ params ['_args','_handle']; _args params ['_veh','_turret'];
	if !(_veh directionStabilizationEnabled _turret) exitWith {
		_veh lockCameraTo [objNull,_turret,true];
		//mjb_otherTarget = nil;
		//mjb_stabTarget = nil;
		//mjb_stabMouseTime = nil;
		mjb_lastTarget = nil;
		mjb_lastPosition = nil;
		mjb_weaponOffset = nil;
		"mjb_stabToggle" cutFadeOut 0;
		[_handle] call CBA_fnc_removePerFrameHandler;
	};
	private _mouseMoving = (inputAction "AimUp" + inputAction "AimDown" + inputAction "AimLeft" + inputAction "AimRight") > 0;
	//if (!isNil 'mjb_stabTarget' && {cursorObject isNotEqualTo mjb_stabTarget}) then {mjb_stabTarget = nil};
	/*/private _lockTarget = (_veh lockedCameraTo _turret);
	if (!isNil '_lockTarget') exitWith {
		//private _other = false;
		//if (isNil "mjb_stabTarget") then { mjb_otherTarget = true; mjb_stabTarget = _lockTarget; };
		private _unlock = false;
		if (_mouseMoving) exitWith {
			if (isNil 'mjb_stabMouseTime') then {
				mjb_stabMouseTime = cba_missionTime;
			};
			if ((cba_missionTime - mjb_stabMouseTime) > 0.25) then {
				_unlock = true;
			};
		}; //else { mjb_stabMouseTime = nil; };
		//if (_unlock) exitWith {_veh lockCameraTo [objNull,_turret,true];};
		_veh lockCameraTo [AGLToASL (unitAimPositionVisual _lockTarget),_turret,true];
	};
	//*/
	private _class = typeOf cursorObject;
	if (_class isKindOf ['AllVehicles',configFile >> "CfgVehicles"] && { !(_class isKindOf ['CAManBase',configFile >> "CfgVehicles"]) }) then {
		"mjb_stabToggle" cutText ["<t size='1.63' shadow='0' font='EtelkaMonospacePro'><br/><br/><br/><br/><br/><br/><br/>POINT</t>", "PLAIN", 0.001, false, true, true];
		"mjb_stabToggle" cutFadeOut 15;
		if (_mouseMoving) exitWith {mjb_lastPosition = nil; mjb_lastTarget = nil; _veh lockCameraTo [objNull,_turret,true];};
		//mjb_stabTarget = cursorObject;
		//mjb_otherTarget = false;
//_veh weaponDirection (_veh currentWeaponTurret _turret)
//(positionCameraToWorld [0,0,0]) vectorFromTo (AGLToASL (unitAimPositionVisual cursorObject))
		mjb_lastTarget = cursorObject;
		mjb_lastPosition = (mjb_lastTarget modelToWorldVisualWorld ((mjb_lastTarget worldToModelVisual (unitAimPositionVisual mjb_lastTarget)) vectorAdd mjb_weaponOffset));
		_veh lockCameraTo [mjb_lastPosition,_turret,false]; // mjb_stabTarget
	} else {
		if (!isNil 'mjb_lastTarget' && {(!_mouseMoving || { cursorTarget isNotEqualTo objNull && {	cursorTarget isEqualTo mjb_lastTarget } }) } ) exitWith {
			//if (isNil 'mjb_reacquire') then {mjb_reacquire = true; mjb_adjust = true; 0 spawn {sleep 0.3; mjb_ajust = nil; sleep 1; mjb_reacquire = nil;};};
			if (mjb_canReacquire && {(count (lineIntersectsObjs [positionCameraToWorld [0,0,0],(getPosASLVisual mjb_lastTarget),_veh,mjb_lastTarget,false,20])) isEqualTo 0}) exitWith {
				mjb_lastPosition = (mjb_lastTarget modelToWorldVisualWorld ((mjb_lastTarget worldToModelVisual (unitAimPositionVisual mjb_lastTarget)) vectorAdd mjb_weaponOffset));
				_veh lockCameraTo [mjb_lastPosition,_turret,false];
				//if (isNil 'mjb_adjust' && {cursorObject isNotEqualTo mjb_lastTarget}) then {mjb_weaponOffset = mjb_weaponOffset + 0.05; mjb_adjust = true; 0 spawn {sleep 0.1; mjb_ajust = nil;};};
			};
			_veh lockCameraTo [mjb_lastPosition,_turret,true];
		};
		mjb_lastTarget = nil;
		mjb_lastPosition = nil;
		"mjb_stabToggle" cutText ["<t size='1.63' shadow='0' font='EtelkaMonospacePro'><br/><br/><br/><br/><br/><br/><br/>AREA</t>", "PLAIN", 0.001, false, true, true];
		"mjb_stabToggle" cutFadeOut 1;
	};
}, 0, [_veh,_turret]] call CBA_fnc_addPerFrameHandler;