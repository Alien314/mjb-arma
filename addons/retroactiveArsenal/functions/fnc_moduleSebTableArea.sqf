params ["_logic"];

if !(local _logic) exitWith {};

if (isNil "zen_dialog") exitWith {};
if (isNil "sebs_briefing_table_main") exitWith {systemChat "Seb's Briefing Table Mod not loaded."};
if (isNil "mjb_activeSebTable") exitWith {systemChat "No table marked."};

["Seb Table", 
	[
		["SLIDER", "Resolution:", [1,20,10]],
		["SLIDER:RADIUS", "Area:", [100,2000,300,0,_logic]],
		["SLIDER", "Map Scale:", [1,10,1]],
		["SLIDER", "Above Table:", [0,1,0]]
	], {  params ["_values", "_args"];
		_values params ["_res","_area","_scale"];
		_args params ["_logic"];

		deleteMarker "mjb_sebTableMarker";
		private _marker = createMarkerLocal ["mjb_sebTableMarker",(getPos _logic),-1,player];
		_marker setMarkerShapeLocal "RECTANGLE";
		_marker setMarkerSizeLocal [_area, _area];
		_marker setMarkerBrushLocal "SolidBorder";
		_marker setMarkerColor "#FF00FF";
		[mjb_activeSebTable, _marker, _res, _scale, true, true, 0] remoteExecCall ["sebs_briefing_table_fnc_createTable", 0, mjb_activeSebTable];
		
		deleteVehicle _logic;
},{},[_logic]] call zen_dialog_fnc_create;
