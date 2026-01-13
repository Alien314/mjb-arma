#include "settings.sqf"

if !(hasInterface) exitWith {};

['ace_unconscious',{ params ['_unit','_active'];
  if !(_active && {mjb_med_tweaks_unstableWakeChance > 0 && { local _unit && {isPlayer _unit}}}) exitWith {};
  [_unit] spawn mjb_med_tweaks_fnc_unstableWake;
}] call cba_fnc_addEventHandler;