params ['_obj','_pos'];
_obj addAction ["Open Garage", { params ["_target", "_caller", "_actionId", "_args"];
  _args params ['_pos'];
  private _vic = missionNamespace getVariable ['mjb_vic',objNull];
  private _near = (_pos nearEntities 12);
  if (_near findIf {private _block = _x; isPlayer _block || {(crew _block) findIf {isPlayer _x && {alive _x}} > -1}} > -1) exitWith {systemChat "Player on spawn location."};
  if (!isNull _vic && { !((crew _vic) findIf {isPlayer _x && {alive _x}} > -1) }) then {_near pushBackUnique _vic};
  {deleteVehicleCrew _x; deleteVehicle _x} forEach _near;
  private _vehicle = createVehicle ["Land_HelipadEmpty_F", _pos, [], 0, "CAN_COLLIDE"];
  _target setVariable ['mjb_inUse',true,true];
  mjb_vicArsenal = _target;
  mjb_garagePos = _pos;
	[missionNamespace, "garageClosed", {
		[{mjb_vicArsenal setVariable ['mjb_inUse',nil,true];
        mjb_vicArsenal = nil;},nil,7] call CBA_fnc_waitAndExecute;
        [mjb_garage_PFH] call CBA_fnc_removePerFrameHandler;
        mjb_garage_PFH = nil;
        private _vic = mjb_vic;
		if (isNull _vic) then {_vic = (((nearestObjects [mjb_garagePos,['LandVehicle','Air','Ship'],30,true]) + [objNull]) select 0);};
		if (isNull _vic) exitWith {systemChat "Vehicle was not found, likely invisible to other players."};
		private _pos = getPosATL _vic;
        private _dir = getDir _vic;
		private _params = [_vic,[missionNamespace,'mjb_garageSave'],[],false] call BIS_fnc_saveVehicle;
        deleteVehicle _vic;
		_params params ['_class','_animSources','_textures','_crew'];
        mjb_vic = createVehicle [_class, _pos, [], 0, "NONE"];
		_vic = mjb_vic;
		//[_vic, _textures, _animSources] call BIS_fnc_initVehicle;
		for '_i' from 0 to (count _textures - 1) do {_vic setObjectTextureGlobal [_i,(_textures # _i)];};
		for '_i' from 0 to (count _animSources - 1) do {_vic animateSource ((_animSources # _i) + [true]);};
        _vic setDir _dir;
        if (getText (configFile >> 'CfgVehicles' >> (typeOf _vic) >> 'vehicleClass') isEqualTo 'Autonomous' || {count _crew > 0} ) then {
			//blufor createVehicleCrew mjb_vic;
			private _vehCfg = configFile >> "CfgVehicles" >> typeOf _vic;
			private _crewCount = {round getNumber (_x >> "dontCreateAI") < 1 && 
								  ((_x == _vehCfg && {round getNumber (_x >> "hasDriver") > 0}) ||
								   (_x != _vehCfg && {round getNumber (_x >> "hasGunner") > 0}))} count ([_vic, configNull] call BIS_fnc_getTurrets);
			private _grp = createGroup [(side player),true];
            for '_i' from 1 to _crewCount do {
				private _unit = _grp createUnit ['B_UAV_AI',[0,0,0],[],0,"CAN_COLLIDE"];
				_unit moveInAny _vic;
			};
			//for '_i' from 0 to (count _crew - 1) do {systemChat "x"};
            {deleteWaypoint [_grp,0];} forEach (waypoints _grp);
        };
		[missionNamespace, "garageClosed", _thisScriptedEventHandler] call BIS_fnc_removeScriptedEventHandler;
	}] call BIS_fnc_addScriptedEventHandler;
  ["Open", [true, _vehicle]] call BIS_fnc_garage;
  diw_armor_plates_main_transferTarg = objNull;
  mjb_garage_PFH = [{ params ['_pos'];
	private _vic = (((nearestObjects [_pos,['LandVehicle','Air','Ship'],30,true]) + [objNull]) select 0);
	_vic setDir 290;
	if !(isPlayer _vic) then {mjb_vic = _vic;};
  }, 0, _pos] call CBA_fnc_addPerFrameHandler;
},[_pos],1.5,true,true,"",
  "!(_target getVariable ['mjb_inUse',false])",
  5
];