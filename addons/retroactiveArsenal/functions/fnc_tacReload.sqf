params ["_unit", "_weapon", "_muzzle", "_newMagazine", "_oldMagazine"];
// skip unload when weapon empty?

if (!mjb_tacReload) exitWith {};
private _class = if (isNil '_oldMagazine') then {(_newMagazine select 0)} else {(_oldMagazine select 0)};
if (mjb_tacForbiddenMags isEqualType '') then { mjb_tacForbiddenMags = (mjb_tacForbiddenMags splitString ',')};
if (mjb_tacForbiddenMuzzles isEqualType '') then {mjb_tacForbiddenMuzzles = (mjb_tacForbiddenMuzzles splitString ',')};
if ((_unit isNotEqualTo (call CBA_fnc_currentUnit)) || {
	_muzzle in (mjb_tacForbiddenMuzzles) || { 
	_class in (mjb_tacForbiddenMags) || {
	(mjb_tacLoadHash getOrDefaultCall [(_class + '_notMagazine'), {
		_class call mjb_arsenal_fnc_notMagazine
	}, true]) } } } 
) exitWith { };
private _curTime = cba_missionTime;
_unit setVariable ['mjb_tacReloadTime',_curTime];
_unit setVariable [('mjb_tacReloadTime' + _class),_curTime];
// delay 0.15 and leave action until a tenth of reload time
private _aID = (_unit addAction ['Quick Reload', {
	params ['_unit','','_aID','_args'];
	_args params ['_oldMagazine','_muzzle'];
	if (currentMuzzle _unit isNotEqualTo _muzzle) exitWith { };
	// wait until gesture is at 0.15 progress then drop magazine
	[{
		((_this select 0) getUnitMovesInfo 5) > 0.15
	},
	{
		params ['_unit','_oldMagazine','_muzzle'];
		if (currentMuzzle _unit isNotEqualTo _muzzle) exitWith { };
		if (!isNil '_oldMagazine') then {
			_oldMagazine params ['_class','_ammo'];
			if (!mjb_tacDropEmptyMagazines && {_ammo isEqualTo 0}) exitWith { };
			private _deathBox = objNull;
			if (mjb_tacSimGlobal) then {
				_deathBox = createVehicle ["WeaponHolderSimulated_scripted",[0,0,0],[],2,"CAN_COLLIDE"];
			} else {
				_deathBox = createVehicleLocal ["WeaponHolderSimulated_scripted",[0,0,0],[],2,"CAN_COLLIDE"];
			};
			private _pos = _unit selectionPosition "lefthand";
			_pos set [2,((_pos select 2) - 0.2)];
			_pos = (_unit modelToWorldVisualWorld (_pos));
			private _posT = ((ASLToATL _pos) select 2);
			if (_posT < 0) then {_pos set [2,((_pos select 2) - (_posT - 0.05))]};
			_deathBox setPosASL _pos;
			[_deathBox,_class,_ammo] spawn { params ['_deathBox','_class','_ammo'];
				sleep 0.2;
				while { velocity _deathBox params ['_i','_y','_z']; (_i min _y min _z) < -0.1 || {(_i max _y max _z) > 0.1} } do {
					sleep 0.2;
				};
				private _pos = getPosASL _deathBox;
				private _holder = ((((_deathBox nearObjects ["WeaponHolderSimulated",1.5]) + (_deathBox nearObjects ["GroundWeaponHolder",1.5])) select {alive _x}) - [_deathBox]);
				deleteVehicle _deathbox;
				if (count _holder isEqualTo 0) then {
					_holder = createVehicle ["GroundWeaponHolder",(ASLToAGL _pos),[],0,"CAN_COLLIDE"];
					_holder setVectorUp surfaceNormal _pos;
				} else {_holder = (_holder select 0)};
				[_holder, _class, 1, true, _ammo] call CBA_fnc_addMagazineCargo;
			};
			[_deathBox, _class, 1, true, _ammo] call CBA_fnc_addMagazineCargo;
			_deathBox addEventHandler ["ContainerOpened", { params ["", "_unit"];
				[{
					!isNull (findDisplay 602)
				},
				{
					(findDisplay 602) closeDisplay 0;
					[{
						_this action ["Gear", objNull];
					}, _unit] call CBA_fnc_execNextFrame;
				}, _unit] call CBA_fnc_waitUntilAndExecute;
			}];
		};
		_unit switchGesture [gestureState _unit, 0.45];
		private _evID = (_unit addEventHandler ["Reloaded", {
			params ["_unit", "_weapon", "_muzzle", "_newMagazine", "_oldMagazine"];
			if (!isNil '_oldMagazine') then {
				_oldMagazine params ['_class','_ammo'];
				private _then = (_unit getVariable ['mjb_tacReloadTime',cba_missionTime]);
				private _thenMag = (_unit getVariable [('mjb_tacReloadTime' + _class),0]);
				if (_then isNotEqualTo _thenMag) exitWith {_unit setVariable [('mjb_tacReloadTime' + _class),nil]; _unit removeEventHandler [_thisEvent,_thisEventHandler]; };
				[_unit,_class,_ammo] call CBA_fnc_removeMagazine;
				
				_unit setVariable [('mjb_tacReloadTime' + _class),nil];
			} else {_unit setVariable [('mjb_tacReloadTime' + (_newMagazine select 0)),nil];};
			_unit setVariable ['mjb_tacReloadTime',nil];
			_unit removeEventHandler [_thisEvent,_thisEventHandler];
		}]);
		[{
			params ['_unit','_evID'];
			_unit removeEventHandler ['Reloaded', _evID];
		},[_unit,_evID],((_unit getUnitMovesInfo 7) * (1.01 - (0.45 - (_unit getUnitMovesInfo 5))))] call CBA_fnc_waitAndExecute;
	}, [_unit,_oldMagazine,_muzzle],((_unit getUnitMovesInfo 7) * (1.01 - (_unit getUnitMovesInfo 5))),{ }] call CBA_fnc_waitUntilAndExecute;
	_unit removeAction _aID;
},[_oldMagazine,_muzzle],-1,false,true,'reloadMagazine']);
// remove action after a part of gesture time elapsed
[{params ['_unit','_aID']; _unit removeAction _aID;},[_unit,_aID],(((_unit getUnitMovesInfo 7) * 0.15) max 0.6)] call CBA_fnc_waitAndExecute;