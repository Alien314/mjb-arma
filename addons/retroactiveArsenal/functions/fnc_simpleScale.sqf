params [['_obj',objNull],['_scale',1,[1]],['_attach',objNull],['_offset',[0,0,0]],['_notSimple',false]];

if !(local _obj) exitWith {};

private _box = boundingBoxReal [_obj,"ViewGeometry"];
private _pos = getPosASL _obj;

private _terrainOff = ((getPosATL _obj) # 2);
if (_terrainOff <  0.1 && {_terrainOff > -0.1}) then {
	_pos set [2,((_pos # 2) + (abs (_box # 0 # 2) * _scale))];
};

private _simpleObj = [(createSimpleObject [(getText (configFile >> "CfgVehicles" >> (typeOf _obj) >> "model")), _pos]), _obj] select _notSimple;


if !(isNull _attach) then {
	_simpleObj attachTo [_attach,_offset];
};

if (isNull _attach && {_offset isNotEqualTo [0,0,0]}) then {
	_pos = getPosASL _simpleObj;
	_pos = _pos vectorAdd _offset;
	_simpleObj setPosASL _pos;
};

private _dir = vectorDir _obj;
private _up = vectorUp _obj;
_simpleObj setVectorDirAndUp [_dir,_up];

deleteVehicle _obj;

_simpleObj setObjectScale _scale;

_simpleObj