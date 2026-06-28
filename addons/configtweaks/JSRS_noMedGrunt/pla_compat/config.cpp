class CfgPatches {
  class mjb_jsrs_noMedGrunt_PLA {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "JSRS No Med Grunt - PLA compat";
	requiredAddons[]=
        {
            "Flex_CUP_PLA_Weapons_JSRSPatch",
			"Flex_CUP_PLA_Weapons_Launchers_PF98",
			"Flex_CUP_PLA_Weapons_Rifles_QBZ95",
			"Flex_CUP_PLA_Weapons_Rifles_QBZ95_JSRSPatch",
			"Flex_CUP_PLA_Weapons_Pistols_QSZ92"
	};
    skipWhenMissingDependencies = 1;
  };
};

class Mode_Burst;
class Mode_FullAuto;
class Mode_SemiAuto;

class CfgWeapons {
class arifle_AK12_F;
class Flex_CUP_PLA_ARifle_QBZ95_blk: arifle_AK12_F
	{
		descriptionShort = "Assault Rifle<br />Caliber: 5.8x42 mm";
		class Single: Mode_SemiAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[]=
				{
					"jsrs_2025_car95_shot_soundset",
					"jsrs_2025_tailsystem_65mm_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundsetshot[]=
				{
					"jsrs_2025_car95_shot_silenced_soundset",
					"jsrs_2025_tailsystem_65mm_rifle_silenced_soundset"
				};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[]=
				{
					"jsrs_2025_car95_shot_soundset",
					"jsrs_2025_tailsystem_65mm_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundsetshot[]=
				{
					"jsrs_2025_car95_shot_silenced_soundset",
					"jsrs_2025_tailsystem_65mm_rifle_silenced_soundset"
				};
			};
		};
		class Burst: Mode_Burst
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[]=
				{
					"jsrs_2025_car95_shot_soundset",
					"jsrs_2025_tailsystem_65mm_rifle_soundset"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundsetshot[]=
				{
					"jsrs_2025_car95_shot_silenced_soundset",
					"jsrs_2025_tailsystem_65mm_rifle_silenced_soundset"
				};
			};
		};
	};
	class Launcher_Base_F;
	class Flex_CUP_PLA_Launch_PF98_base: Launcher_Base_F
	{
		soundfly[]=
		{
			"z\jsrs2025\addons\sounds_weapons\sounds\launchers\rocket_fly.wss",
			1,
			1,
			2500
		};
		drysound[]=
		{
			"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\launcher_dry.wss",
			1,
			1,
			10
		};
		changefiremodesound[]=
		{
			"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\launcher_firemode.wss",
			1,
			1,
			10
		};
		reloadmagazinesound[]=
		{
			"z\jsrs2025\addons\sounds_weapons\sounds\mechanics\reloads\launcher_mraws_reload.wss",
			2,
			1,
			35
		};
		class Mode_SemiAuto_Player: Mode_SemiAuto
		{
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundsetshot[]=
				{
					"jsrs_2025_debris_dust_soundset",
					"jsrs_2025_mraws_shot_soundset",
					"jsrs_2025_tailsystem_Launcher_soundset"
				};
			};
		};
	};
};