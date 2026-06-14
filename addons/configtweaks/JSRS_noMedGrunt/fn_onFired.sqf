//#include "script_component.hpp"
/*
 * Author: joko // Jonas
 * Handles Every Gun Shot and calls different required FiredEH callbacks
 *
 * Arguments:
 * FiredEH Args
 *
 * Return Value:
 * None
 */

params [
    "_shooter",
    "_weapon",
    "_muzzle",
    "_mode",
    "_ammo",
    "_magazine",
    "_projectile",
    "_gunner"
];

if (mjb_disableJSRSEcho) exitWith {};

[_shooter, _weapon, _muzzle, _ammo, _magazine] call jsrs_fnc_onFiredEcho;