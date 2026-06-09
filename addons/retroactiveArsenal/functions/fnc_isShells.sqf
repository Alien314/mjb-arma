params ['_class'];

private _noTac = getNumber (configFile >> "CfgMagazines" >> _class >> 'mjb_disableTacReload');
if (_noTac isEqualTo 0) exitWith {false};

private _ammo = getText (configFile >> "CfgMagazines" >> _class >> "ammo");
if ("12Ga" in _ammo) exitWith {_ammo};

false