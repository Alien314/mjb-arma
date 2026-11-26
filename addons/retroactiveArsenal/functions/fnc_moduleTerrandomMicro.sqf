params ["_logic"];

if !(local _logic) exitWith {};		
//deleteVehicle _logic;

if (isNil "zen_dialog") exitWith {};
private _pos = getPosATL _logic;
getTerrainInfo params ["","","_terrainGW","",""];
_logic setPosATL [(round (_pos # 0)) - ((round (_pos # 0)) mod _terrainGW), (round (_pos # 1)) - ((round (_pos # 1)) mod _terrainGW), 0];

["Generate Micro Terrain", 
	[
		["SLIDER:RADIUS", "Area:", [50,500,(_terrainGW * 100 / 4),0,getPosASL _logic]],
		["SLIDER", "Avoid Building/Roads Radius:", [0,30,15]],
		["SLIDER", "Incline divisor (1 is spiky):", [1,5,3]],
		["SLIDER", "Smoothing factor (0 is spiky):", [0,50,25]],
		["SLIDER", "Max Raise/lower (meters):", [1,10,(_terrainGW min 4)]],
		["CHECKBOX", "!Module can be deleted to undo!", true],
		["CHECKBOX", format ["!Map Cell Size: %1!",_terrainGW], true]
		//["SLIDER", "Height Offset:", [0,1,0]]
	], {
		_this remoteExec ["mjb_arsenal_fnc_terrandomMicro",2];
},{},_logic] call zen_dialog_fnc_create;
