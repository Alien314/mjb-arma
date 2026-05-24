
if (isNil 'arsenalSupp') then {
	arsenalSupp = "building" createVehicleLocal [0,0,0];
};

// All muzzle devices, except the L85 blank firing adapter, and some bipods for some reason
private _itemSuppressor = (("getNumber (_x >> 'scope') isEqualTo 2 && {getNumber (_x >> 'ItemInfo' >> 'type') isEqualTo 101}" configClasses (configFile >> "CfgWeapons") apply {configName _x}) - ["CUP_acc_bfa"]);

[arsenalSupp,(_itemSuppressor)] call ace_arsenal_fnc_initBox;

[arsenalSupp, player] call ace_arsenal_fnc_openBox;
