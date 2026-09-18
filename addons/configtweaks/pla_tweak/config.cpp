class CfgPatches {
  class mjb_pla_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "PLA tweak";
		requiredAddons[]=
		{
			"Flex_CUP_PLA_Weapons_Pistols_QSZ92",
			"dynamicLoadout_LK", //weapons[] = {"missiles_TY90_AA_LK","missiles_AKD9_AG_LK","missiles_TL2_AG_LK","missiles_AKD10_AG_LK","Rocket_57mm_HE_LK","Rocket_90mm_HE_LK","Rocket_130mm_HE_LK","LK_weapon_PL10Launcher","LK_weapon_PL15Launcher","LK_weapon_YJ91Launcher","LK_weapon_YJ9ELauncher","LK_weapon_LS6_100KG","LK_weapon_LS6_250KG","LK_weapon_LS6_500KG","fakeweapon_fueltank_lk"};
			"CSK181_c",
			"CSVP4_c",
			"HQ6A_c",
			"LK_Jets_C",
			"PGZ09_LK",
			"PLL09_LK",
			"PLZ05_LK",
			"Z10_LK",
			"Z11WA_LK",
			"Z19_LK",
			"Z20_LK",
			"Z20T_LK",
			"Z8L_LK",
			"ZBD04_LK",
			"ZTD05_LK",
			"ZBL09_LK",
			"ZTL11_LK",
			"ZTQ15_LK",
			"ZTZ96_c_LK",
			"ZTZ99_LK",
			"ZTZ99A_LK"

		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgAmmo {
	class ammo_Penetrator_Base;
	class ammo_Penetrator_100mm_missile_LK : ammo_Penetrator_Base {
		caliber = 40;
	};
	class ammo_Penetrator_105mm_missile_LK : ammo_Penetrator_Base {
		caliber = 50;
	};
	class ammo_Penetrator_125mm_missile_LK : ammo_Penetrator_Base {
		caliber = 56.6667;
	};
	class ammo_Penetrator_AKD10 : ammo_Penetrator_Base { // scalpel
		caliber = 56.6667;
	};
	class ammo_Penetrator_AKD9 : ammo_Penetrator_Base {
		caliber = 50;
	};
	class ammo_Penetrator_CM102 : ammo_Penetrator_Base {
		caliber = 66.6667;
	};
	class ammo_Penetrator_HJ9_LK : ammo_Penetrator_Base { // vorona
		caliber = 60;
	};
	class ammo_Penetrator_TL2 : ammo_Penetrator_Base { // scalpel
		caliber = 56.6667;
	};
	class ammo_Penetrator_YJ91 : ammo_Penetrator_Base { // AGM
		caliber = 66.6667;
	};
};

class CfgWeapons {
	class hgun_Rook40_F;
	class Flex_CUP_PLA_HGun_QSZ92 : hgun_Rook40_F {
		descriptionShort = "Handgun<br />Caliber: 5.8x21 mm";
		magazines[] = {"mjb_20rnd_58x21_mag"};
		magazineWell[] = {"CBA_58x21_qsz92"};
	};
};

class CfgMagazines {
	class 16Rnd_9x21_Mag;
	class mjb_20rnd_58x21_mag : 16Rnd_9x21_Mag
	{
		displayName = "5.8x21mm 20Rnd mag (5.7 greenmag)";
		descriptionShort = "Caliber: 5.8x21 mm<br />Rounds: 20<br />Used in: QSZ-92";
		count = 20;
		ammo = "B_570x28_Ball";
		greenmag_basicammo = "greenmag_ammo_570x28_basic_1Rnd";
		greenmag_ammo = "greenmag_ammo_570x28_basic_1Rnd";
		initSpeed = 479;
	};

	class LK_TL2X4_AG;
	class LK_TL2X1_AG : LK_TL2X4_AG {

	};
};
class CfgMagazineWells {
	class CBA_58x21_qsz92 {
		mjb_mags[] = {"mjb_20rnd_58x21_mag"};
	};
};