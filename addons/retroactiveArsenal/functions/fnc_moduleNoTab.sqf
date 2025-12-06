params ["_logic"];

if (isServer) then {
	if !(isNil 'mjb_noTabJIP' ) then { remoteExec ['','mjb_noTabJIP']; };
	[[], {
		if !(hasInterface) exitWith {};

		waitUntil {!isNull player};

		private _ctabItems = ( ("getText (_x >> 'author') isEqualTo 'cTab Authors'" configClasses (configFile >> "CfgWeapons") apply {configName _x}) - ["ItemcTabHCam"] + ["ItemGPS","ACE_microDAGR","ACE_DAGR"] );

		{ 
			private _did = true;
			while {_did} do {
				_did = ([player, _x] call CBA_fnc_removeItem);
				sleep 0.01;
			}; 
			player unlinkItem _x;
		} forEach _ctabItems;

		waitUntil {!isNil 'arsenal'}; sleep 1;

		if !(isNil 'arsenal') then {
			[arsenal, _ctabItems] call ace_arsenal_fnc_removeVirtualItems;
		};
		if !(isNil 'missionArsenal') then {
			[missionArsenal, _ctabItems] call ace_arsenal_fnc_removeVirtualItems;
		};
		[true,true] call ace_arsenal_fnc_refresh;
	}] remoteExec ['spawn',0,'mjb_noTabJIP'];
};

if !(local _logic) exitWith {};

deleteVehicle _logic;