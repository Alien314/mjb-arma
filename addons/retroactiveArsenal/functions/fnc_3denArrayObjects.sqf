params [['_objects',[objNull]],['_xCount',1],['_yCount',1],['_zStep',0],['_stepX',false],['_xAdd',0],['yAdd',0]];

private _object = (_objects select 0); //((get3denSelected "" select 0) select 0)

if (_object isEqualTo objNull) exitWith {systemChat "No object selected"};

//private _yCount = -2;	// -south/+north
//private _xCount = -5;	// -east/+west
//private _zStep = 0;		// -down/+up
//private _stepX = false;	// step on X axis, false for Y
//private _xAdd = 0; // additional offsetX
//private _yAdd = -0.1; // additional offsetY

if (_xCount isEqualTo 0 || {_yCount isEqualTo 0}) exitWith { systemChat "Cannot array by 0."};


private _posBase = getPos _object;
private _posX = (_pos # 0);
private _posZ = (_pos # 2);

private _box = boundingBoxReal [_object,"ViewGeometry"];
//[[-10.064,-6.0456,-12.6854],[10.0705,6.0667,12.2874],17.1446]

private _classPoses = +_objects;
_classPoses apply { [typeOf _x, getPos _x] };

delete3DENEntities _objects;

private _offsetX = (abs (_box # 0 # 0) min abs (_box # 1 # 0)) * 2 + _xAdd;
private _offsetY = (abs (_box # 0 # 1) min abs (_box # 1 # 1)) * 2 + _yAdd;

if (_xCount < 0) then {_offsetX = -_offsetX; _xCount = abs _xCount;};
if (_yCount < 0) then {_offsetY = -_offsetY; _yCount = abs _yCount;};

private _newEntities = [];
_yCount = _yCount - 1;
_xCount = _xCount - 1;
{ _x params ['_type','_pos'];
	for '_y' from 0 to _yCount do {
		if (!_stepX) then {_pos set [2, ((_pos # 2) + (_zStep * _yCount))];};
		_pos set [1, ((_pos # 1) + _offsetY)];
		_pos set [0,_posX];
		if (_stepX) then {_pos set [2, _posZ];};
		for '_x' from 0 to _xCount do {
				_pos set [0, ((_pos # 0) + (_offsetX * _xCount))];
				if (_stepX) then {_pos set [2, ((_pos # 2) + (_zStep * _xCount))];};
				create3DENEntity ["Object", _type, _pos, true];
		};
	};
} forEach _classPoses;
