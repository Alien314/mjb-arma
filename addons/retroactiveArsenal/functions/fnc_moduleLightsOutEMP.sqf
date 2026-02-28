params ["_logic"];

if (!local _logic || {!isNil 'mjb_moduleLightsActive'}) exitWith {};
mjb_moduleLightsActive = true;
if (isNil "zen_dialog") exitWith {deleteVehicle _logic;};

["Lights Out/EMP", 
	[
		["SLIDER:RADIUS", "Area:", [10,4000,1000,0,_logic]],
		["CHECKBOX", "Turn off Terrain object Lights", true, true],
		["CHECKBOX", "Turn off Entity Lights", true, true]
	], {  params ["_values", "_logic"];
		_values params ["_area","_terrain","_entity"];
		mjb_moduleLightsActive = nil;

		[[_logic,_area,_terrain,_entity], { params ['_logic','_radius','_tera','_ent'];

			private _objects = [];
			if (_ent) then {
				_objects append (8 allObjects 1 select {_x distance2d _logic < _radius});
			};

			if (!_tera) exitWith {{_x switchLight "OFF";} forEach _objects;};
			for "_i" from 0 to 1 do
			{
				private _found = nearestTerrainObjects [_logic,              [           ["BUILDING","HOUSE","CHURCH","CHAPEL","FUELSTATION","HOSPITAL","RUIN","BUNKER"],              ["CROSS","FORTRESS","FOUNTAIN","VIEW-TOWER","LIGHTHOUSE","QUAY","HIDE","BUSSTOP","ROAD","FOREST","TRANSMITTER","STACK","TOURISM","WATERTOWER","TRACK","MAIN ROAD","POWER LINES","RAILWAY","POWERSOLAR","POWERWAVE","POWERWIND"]] select _i,_radius,false,true]; _objects append _found;
			};
			_objects append (8 allObjects 0 select {_x distance2d _logic < _radius});

			{_x switchLight "OFF";} forEach _objects;

		}] remoteExec ["call", 0, _logic];

		if (isMultiplayer) then {
		_logic setVariable ["mjb_lightsOutArgs",[_area,_terrain,_entity],2];
		[_logic, ["Deleted", {
				params ["_logic"];
				(_logic getVariable ["mjb_lightsOutArgs",[0,false,false]]) params ["_radius","_tera","_ent"];
				private _pos = getPos _logic;
				[[_pos,_radius,_tera,_ent], { params ['_logic','_radius','_tera','_ent'];

					private _objects = [];
					if (_ent) then {
						_objects append (8 allObjects 1 select {_x distance2d _logic < _radius});
					};

					if (!_tera) exitWith {{_x switchLight "ON";} forEach _objects;};
					for "_i" from 0 to 1 do
					{
						private _found = nearestTerrainObjects [_logic,              [           ["BUILDING","HOUSE","CHURCH","CHAPEL","FUELSTATION","HOSPITAL","RUIN","BUNKER"],              ["CROSS","FORTRESS","FOUNTAIN","VIEW-TOWER","LIGHTHOUSE","QUAY","HIDE","BUSSTOP","ROAD","FOREST","TRANSMITTER","STACK","TOURISM","WATERTOWER","TRACK","MAIN ROAD","POWER LINES","RAILWAY","POWERSOLAR","POWERWAVE","POWERWIND"]] select _i,_radius,false,true]; _objects append _found;
					};
					_objects append (8 allObjects 0 select {_x distance2d _logic < _radius});

					{_x switchLight "ON";} forEach _objects;

				}] remoteExec ["call", 0];
			}]
		] remoteExec ["addEventHandler",2];
		} else {
		missionNamespace setVariable ["mjb_lightsOutArgs",[_area,_terrain,_entity,getPos _logic]];
			_logic spawn { while {alive _this} do {sleep 5;};params ["_logic"];
				(missionNamespace getVariable ["mjb_lightsOutArgs",[0,false,false]]) params ["_radius","_tera","_ent","_pos"];
				[[_pos,_radius,_tera,_ent], { params ['_logic','_radius','_tera','_ent'];

					private _objects = [];
					if (_ent) then {
						_objects append (8 allObjects 1 select {_x distance2d _logic < _radius});
					};

					if (!_tera) exitWith {{_x switchLight "ON";} forEach _objects;};
					for "_i" from 0 to 1 do
					{
						private _found = nearestTerrainObjects [_logic,              [           ["BUILDING","HOUSE","CHURCH","CHAPEL","FUELSTATION","HOSPITAL","RUIN","BUNKER"],              ["CROSS","FORTRESS","FOUNTAIN","VIEW-TOWER","LIGHTHOUSE","QUAY","HIDE","BUSSTOP","ROAD","FOREST","TRANSMITTER","STACK","TOURISM","WATERTOWER","TRACK","MAIN ROAD","POWER LINES","RAILWAY","POWERSOLAR","POWERWAVE","POWERWIND"]] select _i,_radius,false,true]; _objects append _found;
					};
					_objects append (8 allObjects 0 select {_x distance2d _logic < _radius});

					{_x switchLight "ON";} forEach _objects;

				}] remoteExec ["call", 0];
			};
		};
},{params ['','_logic']; mjb_moduleLightsActive = nil; deleteVehicle _logic;},_logic] call zen_dialog_fnc_create;
