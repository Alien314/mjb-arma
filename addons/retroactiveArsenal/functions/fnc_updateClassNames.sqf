#include "\z\ace\addons\rangecard\script_component.hpp"
/*
 * Authors: Ruthberg
 * Updates the ammo and weapon class names
 *
 * Arguments:
 * unit <OBJECT>
 *
 * Return Value:
 * Update successful? <BOOL>
 *
 * Example:
 * unit call ace_rangecard_fnc_updateClassNames
 *
 * Public: No
 */

private _unit = _this;

private _ammoClass = "";
private _magazineClass = "";
private _muzzleClass = "";
private _weaponClass = primaryWeapon _unit;

if (_weaponClass == "") exitWith { (GVAR(ammoClass) != "" && GVAR(magazineClass) != "" && GVAR(muzzleClass) != "" && GVAR(weaponClass) != "") };

{
    private _ammo = getText (configFile >> "CfgMagazines" >> _x >> "ammo");
    private _ammoConfig = (configFile >> "CfgAmmo" >> _ammo);
    private _parentClasses = [_ammoConfig, true] call BIS_fnc_returnParents;
    if ("BulletBase" in _parentClasses) exitWith {
        _ammoClass = _ammo;
        _magazineClass = _x;
        _muzzleClass = ((primaryWeaponItems _unit) select 0);
    };
} forEach (primaryWeaponMagazine _unit);

if (_ammoClass == "") exitWith { (GVAR(ammoClass) != "" && GVAR(magazineClass) != "" && GVAR(muzzleClass) != "" && GVAR(weaponClass) != "") };

if (_unit == ACE_player) then {
    GVAR(zeroRange)     = [_unit] call EFUNC(scopes,getCurrentZeroRange);
    GVAR(boreHeight)    = [_unit, 0] call EFUNC(scopes,getBoreHeight);
    GVAR(ammoClass)     = _ammoClass;
    GVAR(magazineClass) = _magazineClass;
    GVAR(muzzleClass) = _muzzleClass;
    GVAR(weaponClass)   = _weaponClass;
} else {
    GVAR(zeroRangeCopy)     = [_unit] call EFUNC(scopes,getCurrentZeroRange);
    GVAR(boreHeightCopy)    = [_unit, 0] call EFUNC(scopes,getBoreHeight);
    GVAR(ammoClassCopy)     = _ammoClass;
    GVAR(magazineClassCopy) = _magazineClass;
    GVAR(muzzleClassCopy) = _muzzleClass;
    GVAR(weaponClassCopy)   = _weaponClass;
};

true
