#include "XEH_PREP.hpp"
#include "settings.sqf"

if (isClass (configFile >> "CfgPatches" >> "greenmag_main")) then {
  private _greenmagArray = "getText (_x >> 'author') isEqualTo '[W] Miller' && {getText (_x >> 'displayName') isNotEqualTo 'Speedloader'}" configClasses (configFile >> "CfgWeapons") apply {configName _x};
  if (isNil "mjb_greenmagButtonId") then {mjb_greenmagButtonId = -1;};
  mjb_greenmagButtonId = [_greenmagArray, "Greenmag","\A3\ui_f\data\igui\cfg\weaponicons\MG_ca.paa", mjb_greenmagButtonId] call ace_arsenal_fnc_addRightPanelButton;
};