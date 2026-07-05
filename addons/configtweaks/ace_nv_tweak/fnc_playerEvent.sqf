#include "\z\ace\addons\nightvision\script_component.hpp"

if ((hmd ace_player) isEqualTo "") then {
	if (headgear ace_player isNotEqualTo "") then {
		private _subItems = getArray (configFile >> "CfgWeapons" >> (headgear ace_player) >> "subItems");
		if (_subItems isEqualTo []) exitWith {};
		private _nvg = _subItems findIf { "nvg" in (toLower _x) };
		if (_nvg isEqualTo -1) exitWith {};
		[{
			GVAR(playerHMD) = (_this select 0);
			[] call FUNC(refreshGoggleType);
		},[(_subItems select _nvg)]] call CBA_fnc_execNextFrame;
	};
};