params ["_logic"];

if !(local _logic) exitWith {};

private _unit = attachedTo _logic;
deleteVehicle _logic;

private _isObj = _unit isEqualType objNull;
private _isPerson = (_isObj && {(_unit isKindOf "CAManBase")});
if (isNull _unit || { !_isObj }) exitWith {
    //[objNull, "No unit or vehicle selected."] call BIS_fnc_showCuratorFeedbackMessage;
};

if !(_isPerson) exitWith {};
if (isNil "zen_dialog") exitWith {};

private _factions = [[''],['Current']];
if (isNil "mjb_arsenal_factionCache") then {
	private _configList = ("true" configClasses (configFile >> "CfgLoadouts")) apply {[configName _x, getText (_x >> 'displayName')]};
	{
		private _list = (_x select 0);
		(_factions select 0) pushBack (toLower _list); (_factions select 1) pushBack ((_x select 1) + ' (' + _list + ')');
	} forEach _configList;
	mjb_arsenal_factionCache = +_factions;
} else {_factions = mjb_arsenal_factionCache};

private _def = (_unit getVariable ['tmf_assignGear_faction', (toLower faction _unit)]);
private _defName = ((_factions select 1) select ((_factions select 0) find _def));
(_factions select 1) set [0,'Current/Default (' + _defName + ')'];
//[["","blu_f","blu_g_f","opf_f","opf_g_f","ind_f","ind_g_f","civ_f","rats","example_enemy"],["Current","NATO","FIA (West)","CSAT","FIA (East)","AAF","FIA (Resistance)","Altis Civilians","RATS","xExample Enemy Loadout"]]
["Set Unit Faction/role", 
	[
		["LIST", "Faction:", [(_factions select 0), (_factions select 1)]]
	], {  params ["_values", "_args"];
		_values params ["_faction"];
		_args params ["_unit",'_defact'];

		private _loadSet = ([_faction,_defact] select (_faction isEqualTo ''));
		private _cache = ("mjb_arsenal_roleCache" + str (_loadSet));
		private _roles = [[''],['Current']];
		if (isNil _cache) then {
			private _configList = ("true" configClasses (configFile >> "CfgLoadouts" >> _loadSet)) apply {[configName _x, getText (_x >> 'displayName')]};
			{
				private _list = (_x select 0);
				(_roles select 0) pushBack (toLower _list); (_roles select 1) pushBack ((_x select 1) + ' (' + _list + ')');
			} forEach _configList;
			missionNamespace setVariable [_cache, +_roles];
		} else {_roles = (missionNamespace getVariable [_cache, [[nil],['Current']]]);};

		private _def = (_unit getVariable ['tmf_assignGear_role', "r"]);
		private _defDex = ((_roles select 0) find _def);
		private _defName = ([((_roles select 1) select _defDex), _def] select (_defDex < 0));
		(_roles select 1) set [0,'Current/Default (' + _defName + ')'];
		["Set Unit Role", 
			[
				["LIST", "New Role:", [(_roles select 0), (_roles select 1)]],
				["CHECKBOX", "Use Retroactive Arsenal?", false, true],
				["CHECKBOX", "Move their arsenal here?", false, true]
			], {  params ["_values", "_args"];
				_values params ["_role",'_retro','_move'];
				_args params ["_unit",'_faction'];
				if (_move) then { _unit setVariable ["startpos", getPosASL _unit, true]; };
				[[_unit,_role,_faction],{ params ['_unit','_role','_faction'];
					if (_faction isEqualTo '') then {_faction = nil};
					private _tmfRole = _role;
					if (_tmfRole isEqualTo '') then {_tmfRole = nil};
					[_unit,_faction,_tmfRole] call TMF_assignGear_fnc_assignGear;
					if (hasInterface && {isPlayer _unit}) then {
						if (!_retro && {fileExists "loadouts\arsenal.sqf"}) then {
							execVM "loadouts\arsenal.sqf";
						} else { [false, _role] call mjb_arsenal_fnc_arsenal };
						0 spawn {sleep 0.1; [0,true] spawn mjb_arsenal_fnc_toughLoop;};
					};
				}] remoteExec ["call",_unit];
		},{},[_unit,_faction]] call zen_dialog_fnc_create;
},{},[_unit,_def]] call zen_dialog_fnc_create;