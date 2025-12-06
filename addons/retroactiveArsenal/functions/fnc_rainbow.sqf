if ( ( (player weaponState (primaryWeapon player) ) select 3) isEqualTo "mjb_150Rnd_93x64_Mag_trc_rbw_full" ) then {
	if !(isNil "mjb_rainbowHandle") exitWith {};
	mjb_rainbowHandle = (player addEventHandler ["Fired", {
		params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_gunner"];
		if (_magazine isEqualTo "mjb_150Rnd_93x64_Mag_trc_rbw_full") then {mjb_rainbow = _weapon;};
		if (isNil 'mjb_rainbow' || {!(_magazine in ["mjb_150Rnd_93x64_Mag_trc_rbw_full","mjb_150Rnd_93x64_Mag_trc_grn_full","mjb_150Rnd_93x64_Mag_trc_ylw_full","mjb_150Rnd_93x64_Mag_trc_red_full"])}) exitWith {
			if !(isNil 'mjb_rainbow') then {
				player addWeaponItem [mjb_rainbow,"mjb_150Rnd_93x64_Mag_trc_rbw_full",true];
			};
			mjb_rainbow = nil;
		};
		private _nextMag = switch (_magazine) do {
			case "mjb_150Rnd_93x64_Mag_trc_rbw_full" : {"mjb_150Rnd_93x64_Mag_trc_grn_full"};
			case "mjb_150Rnd_93x64_Mag_trc_grn_full" : {"mjb_150Rnd_93x64_Mag_trc_ylw_full"};
			case "mjb_150Rnd_93x64_Mag_trc_ylw_full" : {"mjb_150Rnd_93x64_Mag_trc_red_full"};
			default {"mjb_150Rnd_93x64_Mag_trc_rbw_full"};
		};
		player addWeaponItem [_weapon,_nextMag,true];
		player setWeaponReloadingTime [player,_muzzle,1];
	}]);
} else {
	if !(isNil "mjb_rainbowHandle") then {
		player removeEventHandler ['Fired', mjb_rainbowHandle];
		mjb_rainbowHandle = nil;
	};
};