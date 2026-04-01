#include "\z\ace\addons\rangecard\script_component.hpp"
//#include "..\script_component.hpp"
/*
 * Authors: Ruthberg
 * Updates the ammo and weapon class names.
 *
 * Arguments:
 * 0: Target <OBJECT>
 * 1: Unit <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, player] call ace_rangecard_fnc_updateClassNames
 *
 * Public: No
 */

params ["_target", "_unit"];

private _weaponClass = primaryWeapon _target;

if (_weaponClass isEqualTo "") exitWith {};

private _ammoClass = "";
private _magazineClass = "";
private _muzzleClass = "";
private _cfgMagazines = configFile >> "CfgMagazines";

{
    _ammoClass = getText (_cfgMagazines >> _x >> "ammo");

    if (_ammoClass isKindOf "BulletBase") exitWith {
        _magazineClass = _x;
        _muzzleClass = ((primaryWeaponItems _unit) select 0);
    };
} forEach (primaryWeaponMagazine _target);

if (_magazineClass isEqualTo "") exitWith {};

private _return = [
    _target call EFUNC(scopes,getCurrentZeroRange),
    [_target, 0] call EFUNC(scopes,getBoreHeight),
    _ammoClass,
    _magazineClass,
    _weaponClass,
	_muzzleClass
];

if (_target == _unit) then {
    GVAR(rangeCardInfo) = _return;
} else {
    GVAR(rangeCardCopyInfo) = _return;
};