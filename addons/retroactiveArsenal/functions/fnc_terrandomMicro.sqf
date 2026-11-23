params ["_values", "_logic"];
_values params ["_area","_struct","_rFac","_undo"];//,"_zOff"

private _pos = getPosASL _logic;
getTerrainInfo params ["","","_terrainGW","_terrainGS","_SL"];

_logic addEventHandler ["Deleted", {
	params ["_entity"];
	private _defaults = (_entity getVariable ["defaults",[]]);
	if (_defaults isEqualTo []) exitWith {};
	setTerrainHeight [_defaults,true];
}];

//systemChat str getTerrainInfo;

private _center = _pos;
private _start = [(_pos # 0) - _area, (_pos # 1) - _area];
private _maxRaise = _terrainGW;
private _maxAdjDiff = _terrainGW;
private _startX = (_start select 0);
private _startY = (_start select 1);
private _posHeights = [];
private _defaults = [];
private _heightGrid = [];

private _missionObjs = ( (((8 allObjects 0) + (8 allObjects 1)) select { !(_x isKindOf "Logic")  && { _x distance2D _center < (_area + _struct)} }) + (nearestTerrainObjects [_center, ["BUILDING","HOUSE","CHURCH","CHAPEL","FUELSTATION","HOSPITAL","RUIN","BUNKER","WALL","FENCE","FORTRESS","FOUNTAIN","VIEW-TOWER","LIGHTHOUSE","QUAY","BUSSTOP","ROAD","TRANSMITTER","STACK","TOURISM","WATERTOWER","TRACK","MAIN ROAD","POWER LINES","RAILWAY","POWERSOLAR","POWERWAVE","POWERWIND","SHIPWRECK","TRAIL"], (_area + _struct), false, true]) );

for "_posX" from _startX to (_startX + (2 * _area)) step _terrainGW do
{
	_heightGrid pushBack [];
	private _cheX = (_posX - _startX + _terrainGW);
	for "_posY" from _startY to (_startY + (2 * _area)) step _terrainGW  do
	{
		_start set [0,_posX];
		_start set [1,_posY];
		private _dist = _center distance2D _start;
		if (_dist > (_area + 1)) then {
			(_heightGrid select ( (_cheX / _terrainGW) - 1) ) pushBack (getTerrainHeight _start);
			continue
		};
		private _oldHeight = getTerrainHeight _start;
		private _newHeight = _oldHeight;
		private _objs = if (_struct isEqualTo 0) then {true} else {( count (_missionObjs select { _x distance2D _start < (_struct ) } ) ) isEqualTo 0};
		private _cheY = (_posY - _startY + _terrainGW);
		if (_cheX > _terrainGW && {_objs}) then {
			private _xMid = ( (_heightGrid select ( (_cheX / _terrainGW) - 2) ) select ( (_cheY / _terrainGW) - 1) );
			if (_cheY > _terrainGW) then {
				private _yMid = ( (_heightGrid select ( (_cheX / _terrainGW) - 1) ) select ( (_cheY / _terrainGW) - 2) );
				_xMid = (random [_yMid min _xMid, selectRandom [_yMid,_xMid,(_yMid + _xMid) / 2], _yMid max _xMid]) + ((random (_terrainGW / 5)) - (_terrainGW / 10));
			};
			_newHeight = random [(_xMid - _terrainGW/((random _rFac) + 1)), _xMid, (_xMid + _terrainGW/((random _rFac) + 1))];//( (random (_terrainGW * 2) ) - _terrainGW)
			//_newHeight = _xMid + ( (random _terrainGW ) ) - _terrainGW / 2);//( (random (_terrainGW * 2) ) - _terrainGW)
		} else {
			if (_cheY > _terrainGW && {_objs}) then {
				private _yMid = ( (_heightGrid select ( (_cheX / _terrainGW) - 1) ) select ( (_cheY / _terrainGW) - 2) );
				_newHeight = random [(_yMid - _terrainGW/((random _rFac) + 1)), _yMid, (_yMid + _terrainGW/((random _rFac) + 1))]; //( (random (_terrainGW * 2) ) - _terrainGW)
			} else {  if (!_objs) exitWith {}; _newHeight = random [(_oldHeight - _terrainGW/((random _rFac) + 1)), _oldHeight, (_oldHeight + _terrainGW / ((random _rFac) + 1))];//_oldHeight + ( (random (_maxRaise * 2) ) - _maxRaise) };
			};
		};
		_newHeight = (_oldHeight - _maxRaise) max _newHeight min (_oldHeight + _maxRaise);
		if (_dist > (_area - (_area / 10))) then {
			_newHeight = if (_newHeight > _oldHeight) then {
				_oldHeight + ( (_newHeight mod _oldHeight) * (1 - ((_dist - (_area - (_area / 10 + 1))) / (_area / 10 + 1))) )
			} else {
				_oldHeight - ( (_oldHeight mod _newHeight) * (1 - ((_dist - (_area - (_area / 10 + 1))) / (_area / 10 + 1))) )
			};
		};
		_defaults pushBack (_start + [_oldHeight]);
		_posHeights pushBack (_start + [_newHeight]);
		(_heightGrid select ( (_cheX / _terrainGW) - 1) ) pushBack _newHeight;
		//systemChat str (_start + [_newHeight]);
		//sleep .05;
	};
};

_logic setVariable ["defaults", _defaults];
if (isRemoteExecuted || (!isDedicated)) then {
	"Micro-terrain generated" remoteExec ["systemChat", remoteExecutedOwner];
};

//newTerrain = _posHeights;
setTerrainHeight [_posHeights,true];
