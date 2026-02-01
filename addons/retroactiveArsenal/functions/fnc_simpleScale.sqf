params [['_obj',objNull],['_scale',1,[1]],['_attach',objNull],['_offset',[0,0,0]]];

if !(local _obj) exitWith {};

private _box = boundingBoxReal [_obj,"ViewGeometry"];
private _pos = getPosASL _obj;

private _terrainOff = ((getPosATL _obj) # 2);
if (_terrainOff <  0.1 && {_terrainOff > -0.1}) then {
	_pos set [2,((_pos # 2) + (abs (_box # 0 # 2) * _scale))];
};
private _simpleObj = createSimpleObject [(getText (configFile >> "CfgVehicles" >> (typeOf _obj) >> "model")), _pos];

if (_attach isNotEqualTo objNull) then {
	_simpleObj attachTo [_attach,_offset];
};

private _dir = vectorDir _obj;
private _up = vectorUp _obj;
_simpleObj setVectorDirAndUp [_dir,_up];

deleteVehicle _obj;

_simpleObj setObjectScale _scale;