params ["_unit", "_weapon", ["_orient", true], ["_remove", true], ["_class", "WeaponHolderSimulated"], ["_select", true], ["_local", isNil "tsp_server_animate"]];
_weapon params ['_weaponClass'];
if (_weaponClass isEqualTo "") exitWith {};

_dir = vectorNormalized ((_unit weaponDirection _weaponClass) vectorCrossProduct [0, 0, 1]);
_up = _dir vectorCrossProduct (_unit weaponDirection _weaponClass);
_pos = _unit modelToWorldWorld (_unit selectionPosition "RightHand") vectorAdd (_dir vectorMultiply 0.7);
_holder = if (_local) then {createVehicleLocal [_class, [0, 0, 0], [], 0, "CAN_COLLIDE"]} else {createVehicle [_class, [0, 0, 0], [], 0, "CAN_COLLIDE"]};
if (_weapon isEqualType '') then {
	_holder addWeaponWithAttachmentsCargoGlobal [weaponsItems _unit select {_x select 0 isEqualTo _weaponClass} select 0, 1];
} else {
	_holder addWeaponWithAttachmentsCargoGlobal	[_weapon,1];
};
if (_select && {!isPlayer _unit}) then {_unit spawn {sleep 0.5; _this selectWeapon handgunWeapon _this}};
if (_orient) then {_holder setPosWorld _pos; _holder setVectorDirAndUp [_up, _dir]};
if (_remove) then {_unit removeWeapon [_weaponClass, _select]};
_holder