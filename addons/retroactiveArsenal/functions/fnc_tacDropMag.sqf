params ['_unit','_magazine'];

_magazine params ['_class','_ammo'];
if (!mjb_tacDropEmptyMagazines && {_ammo isEqualTo 0}) exitWith { };
private _deathBox = objNull;
if (mjb_tacSimGlobal) then {
	_deathBox = createVehicle ["WeaponHolderSimulated_scripted",[0,0,0],[],2,"CAN_COLLIDE"];
} else {
	_deathBox = createVehicleLocal ["WeaponHolderSimulated_scripted",[0,0,0],[],2,"CAN_COLLIDE"];
};
private _closeObj = cursorObject;
private _closeObjClass = typeOf cursorObject;
if (_obj in (nearestTerrainObjects [_unit,['TREE','SMALL TREE','BUSH','WALL'],10]) || {
	( (getNumber (configFile >> 'CfgVehicles' >> _closeObjClass >> 'armor')) * (getNumber (configFile >> 'CfgVehicles' >> _closeObjClass >> 'mapSize')) ) < 2000 } ) then {
	_closeObj  disableCollisionWith _deathBox;
};
private _pos = _unit selectionPosition "lefthand";
_pos set [0,((_pos select 0) - 0.2)];
_pos set [1,((_pos select 1) + 0.2)];
_pos set [2,((_pos select 2) - 0.0)];
_pos = (_unit modelToWorldVisualWorld (_pos));
private _posT = ((ASLToATL _pos) select 2);
if (_posT < 0) then {_pos set [2,((_pos select 2) - (_posT - 0.05))]};
_deathBox setPosASL _pos;
private _wepDir = (_unit weaponDirection currentWeapon _unit);
_deathBox setVectorDir _wepDir;
_deathBox setVelocityModelSpace [(-1 * ((_wepDir # 2) + 0.5 max 0)), (2 + (_wepDir # 2)), (1 + (_wepDir # 2))];
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