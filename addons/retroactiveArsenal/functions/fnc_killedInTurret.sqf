params ["_unit"];
if (!local _unit || {isPlayer _unit || {vehicle _unit isEqualTo _unit}}) exitWith {};

private _veh = vehicle _unit;
private _tur = _veh unitTurret _unit;

_veh selectWeaponTurret [_veh currentWeaponTurret _tur,_tur];
