params ["_logic"];

if !(local _logic) exitWith {};
private _pos = getPosASL _logic;		
deleteVehicle _logic;

if (isNil "zen_dialog") exitWith {};
if (isNil "sebs_briefing_table_main") exitWith {systemChat "Seb's Briefing Table Mod not loaded."};
if (isNil "mjb_activeSebTable") exitWith {systemChat "No table marked."};

["Seb Table", 
	[
		["SLIDER", "Resolution:", [1,20,10]],
		["SLIDER:RADIUS", "Area:", [20,1000,300,0,_pos]],
		["SLIDER", "Map Scale(Table Relative):", [0.1,3,1]],
		["SLIDER", "Above Table:", [0,1,0]]
	], {  params ["_values", "_pos"];
		_values params ["_res","_area","_scale","_zOff"];

		deleteMarker "mjb_sebTableMarker";
		private _marker = createMarkerLocal ["mjb_sebTableMarker",_pos,-1,player];
		_marker setMarkerShapeLocal "RECTANGLE";
		_marker setMarkerSizeLocal [_area, _area];
		_marker setMarkerBrushLocal "Border";
		_marker setMarkerColor "#(1,0,1)";
		if (mjb_activeSebTable getVariable ["mjb_sebTable",false]) then {_scale = 3};
		[mjb_activeSebTable, _marker, _res, _scale, true, true, _zOff] remoteExecCall ["sebs_briefing_table_fnc_createTable", 0, mjb_activeSebTable];
},{},_pos] call zen_dialog_fnc_create;
