
["z\mjb\addons\configtweaks\ace_nv_tweak\fnc_onSlotItemChanged.sqf", "ace_nightvision_fnc_onSlotItemChanged"] call CBA_fnc_compileFunction;
["z\mjb\addons\configtweaks\ace_nv_tweak\fnc_pfeh.sqf", "ace_nightvision_fnc_pfeh"] call CBA_fnc_compileFunction;

call compile preprocessFileLineNumbers "z\ace\addons\nightvision\XEH_preInit.sqf";

//#include "settings.sqf"
["z\mjb\addons\configtweaks\ace_nv_tweak\fnc_playerEvent.sqf", "mjb_nightvision_fnc_playerEvent"] call CBA_fnc_compileFunction;