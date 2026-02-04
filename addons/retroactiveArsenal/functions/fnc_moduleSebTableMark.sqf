params ["_logic"];

if !(local _logic) exitWith {};

private _unit = attachedTo _logic;
private _loc = getPosASLVisual _logic;
deleteVehicle _logic;

if (isNil "sebs_briefing_table_main") exitWith {systemChat "Seb's Briefing Table Mod not loaded."};

private _isObj = _unit isEqualType objNull;
private _isTable = (_isObj && { _unit isKindOf "Static" || { _unit isKindOf "Thing" } });

if (!isNull _unit && !_isTable ) exitWith {
    systemChat "Object not static or thing.";
};

if (isNull _unit) then {
	KK_fnc_setPosAGLS = {
		params ["_obj", "_pos", ["_offset",0]];
		_offset = _pos select 2;
		_pos set [2, worldSize];
		_obj setPosASL _pos;
		_pos set [2, vectorMagnitude (_pos vectorDiff getPosVisual _obj) + _offset];
		_obj setPosASL _pos;
	};
	_loc = (ASLToAGL _loc);
	_unit = createVehicle ['Land_CampingTable_small_F',_loc,[], 0, "CAN_COLLIDE"];
	[_unit,_loc] call KK_fnc_setPosAGLS;
	_unit enableSimulationGlobal false;
	
	_loc = getPosASLVisual _unit;
	_unit enableSimulationGlobal false;
	private _box = boundingBoxReal [_unit,"ViewGeometry"];
	private _offsetX = (abs (_box # 0 # 0) min abs (_box # 1 # 0)) * 2;
	private _offsetY = (abs (_box # 0 # 1) min abs (_box # 1 # 1)) * 2;
	
	private _posZ = (_loc select 2);
	private _poses = [];
	for "_i" from -1 to 1 do {
		private _posY = ((_loc select 1) - ((_offsetY + 0.05) * _i));
		for "_j" from -1 to 1 do {
			private _posX = ((_loc select 0) - ((_offsetY - 0.05) * _j));
			_poses pushBack [_posX, _posY, _posZ];
		};
	};
	_poses deleteAt 4;
	{
		private _obj = createVehicle ['Land_CampingTable_small_F',_x,[], 0, "CAN_COLLIDE"];
		_obj enableSimulationGlobal false;
		_obj setPosASL _x;
	} forEach _poses;

	_unit setVariable ["mjb_sebTable",true,true];
};

missionNamespace setVariable ["mjb_activeSebTable",_unit,true];

_unit addEventHandler ["Deleted", {
	params ["_entity"];
	[_entity] remoteExecCall ["sebs_briefing_table_fnc_clearTable", 0, _entity];
}];