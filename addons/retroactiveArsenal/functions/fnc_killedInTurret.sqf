params ["_unit"];
if (!local _unit || {isPlayer _unit || {vehicle _unit isEqualTo _unit}}) exitWith {};

private _veh = vehicle _unit;
private _tur = _veh unitTurret _unit;
//if (count (_veh weaponsTurret _tur) isEqualTo 0) exitWith {};
//private _wep = weaponState [_veh,_tur];
//_wep params ["_weapon", "_muzzle", "_firemode"];
_veh selectWeaponTurret [_veh currentWeaponTurret _tur,_tur];

//"getNumber (_x >> 'showToPlayer') isEqualTo 1" configClasses (configFile >> "CfgWeapons" >> (get3denSelected "" #0#0)  currentWeaponTurret [0]) apply {configName _x}

/*

 params ["_unit"];
 if (vehicle _unit isEqualTo _unit) exitWith {};

 private _veh = vehicle _unit;
 private _tur = _veh unitTurret _unit;
 private _wep = weaponState [_veh,_tur];
 systemChat str _wep;
 _wep params ["_weapon", "_muzzle", "_firemode", "_mag", "_ammo", "_roundReloadPhase", "_magazineReloadPhase"];
 if (getNumber (configFile >> "CfgWeapons" >> _weapon >> _firemode >> "showToPlayer") isEqualTo 0) then {
  private _newMode = (("getNumber (_x >> 'showToPlayer') isEqualTo 1" configClasses (configFile >> "CfgWeapons" >> _weapon) ) select 0);
  _veh selectWeaponTurret [_weapon,_tur,_muzzle,_newMode];
 };
*/
