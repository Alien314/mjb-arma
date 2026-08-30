class CfgWeapons {
  class Default;
  class ItemInfo : Default {scope = 1;};
  /*/Zoomy fuck
  class Default {opticsZoomInit = 0.66; opticsZoomMax = 1.5; opticsZoomMin = 0.33;};
  class PistolCore;
  class Pistol : PistolCore {opticsZoomInit = 0.66; opticsZoomMax = 1.5; opticsZoomMin = 0.33;};
  class RifleCore;
  class Rifle : RifleCore {opticsZoomInit = 0.66; opticsZoomMax = 1.5; opticsZoomMin = 0.33;};
  class GrenadeLauncher : Default {opticsZoomInit = 0.66; opticsZoomMax = 1.5; opticsZoomMin = 0.33;};
  class Put : Default {opticsZoomInit = 0.66; opticsZoomMax = 1.5; opticsZoomMin = 0.33;};*/

	// Muzzle flashes
	class Zasleh2;
	class Zasleh1 : Zasleh2 {
		model = "A3\weapons_f\data\zasleh1_proxy.p3d";
	};
	class ZaslehPilot : Zasleh2 {
		model = "A3\weapons_f\data\zasleh1_pilot_proxy.p3d";
	};
	class Zasleh2Pilot : Zasleh2 {
		model = "A3\weapons_f\data\zasleh2_pilot_proxy.p3d";
	};

  class GrenadeLauncher;

    
  class MGunCore;
  class MGun : MGunCore {
    class manual;
    class close : manual {
      aiBurstTerminable = 0;
    };
    class short : close {
      aiBurstTerminable = 0;
    };
    class medium : close {
      aiBurstTerminable = 0;
    };
    class far : close {
      aiBurstTerminable = 0;
    };
  };
  class M134_minigun : MGunCore {
    aiDispersionCoefX = 20.0;
    aiDispersionCoefY = 15.0;
  };
  class LMG_RCWS : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class LMG_M200 : LMG_RCWS { };
  // HMG_M2 Explicitly overrides aiDispersionCoef in vanilla configs
  // so we can't take advantage of inheritance. Must explicitly override here.
  class HMG_01;
  class HMG_M2 : HMG_01 {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CannonCore;
  class gatling_30mm_base : CannonCore { };
  class gatling_30mm : gatling_30mm_base { };
  class autocannon_Base_F : CannonCore {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
  };
  class autocannon_30mm_CTWS : autocannon_Base_F { };
// Xian autocannon
  
  // CUP
  // FAL Sounds?
  class CUP_Vhmg_DSHKM_veh : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vhmg_KORD_veh : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vhmg_KPVT_veh : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vhmg_GAU19_veh : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vhmg_PKT_veh : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vhmg_PKT_MGNest : CUP_Vhmg_PKT_veh { };
  class CUP_Vhmg_PKT_veh2 : CUP_Vhmg_PKT_MGNest {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vhmg_PKT_veh3 : CUP_Vhmg_PKT_MGNest {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vlmg_M134_veh : MGun {
    aiDispersionCoefX = 20.0;
    aiDispersionCoefY = 15.0;
  };
  class CUP_Vlmg_M240_veh : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vlmg_M240_nest : CUP_Vlmg_M240_veh {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vlmg_MG3_veh : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class CUP_Vlmg_UK59_veh : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  
  class CUP_Vacannon_2A42_veh : CannonCore {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
  };
  class CUP_Vacannon_AK630_veh : CannonCore {
    aiDispersionCoefX = 20;
    aiDispersionCoefY = 15;
  };
  class CUP_Vacannon_M197_veh : CannonCore {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
  };
  class CUP_Vacannon_M230_veh : CannonCore {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
	magazines[] += {"mjb_300Rnd_TE1_Red_Tracer_30x113mm_M789_HEDP_M","mjb_300Rnd_TE1_Green_Tracer_30x113mm_M789_HEDP_M","mjb_300Rnd_TE1_Yellow_Tracer_30x113mm_M789_HEDP_M","mjb_300Rnd_TE1_White_Tracer_30x113mm_M789_HEDP_M"};
  };
  class CUP_Vacannon_M242_veh : CannonCore {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
  };
  class CUP_Vacannon_M621_AW159_veh : CannonCore {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
  };
  
  class PKT : MGun { // ???
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };

#if __has_include("\rhsafrf\addons\rhs_c_weapons\script_component.hpp")
  // RHS
  class RHS_M2 : HMG_M2 { };
  class RHS_M2_offroad : RHS_M2 {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class rhs_weap_DSHKM : LMG_RCWS {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class rhs_weap_kpvt : MGun {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class rhs_weap_nsvt : rhs_weap_DSHKM {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class rhs_weap_pkt : PKT {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class rhs_weap_gau21_1 : RHS_M2 {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  class rhs_weap_m240veh : LMG_M200 {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  
  class rhs_weap_azp23 : CannonCore {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
  };
  class rhs_weap_2a42_base : autocannon_30mm_CTWS {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
  };/* Helo nose guns
  class rhs_weap_M197 : gatling_30mm {
    aiDispersionCoefX = 12;
    aiDispersionCoefY = 9;
  };
  class rhs_weap_gi2_base : rhs_weap_M197 {
    aiDispersionCoefX = 12;
    aiDispersionCoefY = 9;
  };*/
  class RHS_weap_M242BC : autocannon_30mm_CTWS {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
  };
#else
#endif

	class CUP_Vacannon_SPG9_veh : CannonCore {
        ace_overpressure_priority = 1;
        ace_overpressure_angle = 60;
        ace_overpressure_range = 10;
        ace_overpressure_damage = 0.7;
        ace_overpressure_backblast = 1;
		ace_overpressure_offset = 1.25;
	};
  class Rifle;
  class Rifle_Base_F : Rifle { class WeaponSlotsInfo; };
  class Rifle_Short_Base_F : Rifle_Base_F { class WeaponSlotsInfo; };
  class Rifle_Long_Base_F : Rifle_Base_F { class WeaponSlotsInfo; };

  // CTAR/QBZ+GL rifle modes fix
  class arifle_CTAR_base_F : Rifle_Base_F {
	class FullAuto;
	class Single;
  };
  class arifle_CTAR_GL_base_F : arifle_CTAR_base_F {
	class FullAuto : FullAuto {};
	class Single : Single {};
  };

  // 3CB
  /* class UK3CB_PKT : rhs_weap_pkt {
    aiDispersionCoefX = 40.0;
    aiDispersionCoefY = 30.0;
  };
  
  // Bizon mag name fix
  class CUP_smg_bizon : Rifle_Base_F
  {
      magazineWell[] = {"CBA_9x18_PP19"};
  };
  */
  // Meme MOA
  class CUP_smg_SA61 : Rifle_Base_F {
	class FullAuto : Mode_FullAuto {
		dispersion = 0.002;
	};
	class Single : Mode_SemiAuto {
		dispersion = 0.002;
	};
	class WeaponSlotsInfo;
  };
  class CUP_smg_SA61_RIS : CUP_smg_SA61 {
	class WeaponSlotsInfo : WeaponSlotsInfo {
		mass = 32;
	};
  };
  class CUP_smg_BallisticShield_Sa61 : CUP_smg_SA61_RIS {
	class FullAuto : FullAuto {
		dispersion = 0.02007;
	};
	class Single : Single {
		dispersion = 0.02007;
	};
  };

  // Fix Galil recoil
  class CUP_arifle_GALIL_BASE : Rifle_Base_F {
    recoil = "CUP_L86_recoil";
	class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_556 {
		};
	};
  };
  class CUP_arifle_Galil_black : CUP_arifle_GALIL_BASE {
	descriptionShort = "Assault rifle<br/>Caliber: 7.62x51mm NATO";
    recoil = "recoil_ebr";
	class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_762 {
		};
	};
  };
  class CUP_arifle_Galil_SAR_black : CUP_arifle_GALIL_BASE {
    recoil = "CUP_M4A1_recoil";
  };

  // muzzle slots
  class CUP_smg_MP7 : Rifle_Short_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_46 {
			delete compatibleItems;
		};
	};
  };
  class CUP_smg_P90_BASE : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : MuzzleSlot_57 {
			delete compatibleItems;
		};
	};
  };
  class CUP_arifle_ACR_BASE_68 : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : CUP_ACR_MuzzleSlot {
			class compatibleItems : compatibleItems {
				ACE_muzzle_mzls_B = 1;
			};
		};
	};
  };
  class CUP_Famas_Base : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_556 {
			delete compatibleItems;
		};
	};
  };
  class CUP_arifle_SR3M_Vikhr : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_762R {
			delete compatibleItems;
		};
	};
  };
  /* // inherits from L7A2 no muzzle device I guess
  class CUP_lmg_FNMAG : Rifle_Long_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_762 {
			delete compatibleItems;
		};
	};
  };*/
  class CUP_lmg_M240 : Rifle_Long_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_762 {
			delete compatibleItems;
		};
	};
  };
  class CUP_lmg_M240_B : CUP_lmg_M240 {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_762 {
			delete compatibleItems;
		};
	};
  };
  class CUP_srifle_M14 : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : MuzzleSlot_762 {
			delete compatibleItems;
		};
	};
  };
  class CUP_srifle_M14_DMR : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_762 {
			delete compatibleItems;
		};
	};
  };
  // shotgun
  class CUP_sgun_M1014_base : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_12G {
			delete compatibleItems;
		};
	};
  };

  /* // just randomly places muzzle flash
  class CUP_M60E4_Base : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : MuzzleSlot_762 {
			delete compatibleItems;
		};
	};
  };
  class CUP_lmg_MG3 : Rifle_Long_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : MuzzleSlot_762R {
			delete compatibleItems;
		};
	};
  };
  class CUP_lmg_UK59 : Rifle_Long_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : MuzzleSlot_762R {
			delete compatibleItems;
		};
	};
  };
  class CUP_sgun_AA12 : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_12G {
			delete compatibleItems;
		};
	};
  };
  class CUP_sgun_Saiga12K : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_12G {
			delete compatibleItems;
		};
	};
  };
  class CUP_sgun_SPAS12 : Rifle_Base_F {
    class WeaponSlotsInfo : WeaponSlotsInfo {
		class MuzzleSlot : asdg_MuzzleSlot_12G {
			delete compatibleItems;
		};
	};
  };
  */

  class CUP_saw_base : Rifle_Long_Base_F {
	class WeaponSlotsInfo : WeaponSlotsInfo {
		class CowsSlot : CUP_PicatinnyTopShortMount {
			delete compatibleItems;
		};
	};
  };


  class CUP_lmg_MG3 : Rifle_Long_Base_F {
	magazines[] += {"mjb_CUP_120Rnd_TE4_LRT4_IR_Tracer_762x51_Belt_M"};
  };

  class mjb_CUP_lmg_M240_338: CUP_lmg_M240_B {
	displayName = "M240B .338";
	descriptionShort = "Medium machine gun <br/>Caliber: .338";
	magazines[] = {};
	magazineWell[] = {"CBA_338NM_LINKS"};
  };

  class CUP_lmg_Pecheneg_top_rail_B50_vfg;
  class mjb_CUP_lmg_Pecheneg_top_rail_B50_vfg_93 : CUP_lmg_Pecheneg_top_rail_B50_vfg {
	displayName = "PKP 9.3x64mm (RIS/B-50/Grip)";
	descriptionShort = "Medium machine gun <br/>Caliber: 9.3x64mm";
	magazines[] = {};
	magazineWell[] = {"CBA_93x64_LINKS"};
  };

  // .45 50m Zeroing
  class SMG_01_Base : Rifle_Short_Base_F {
	discreteDistance[] = {50,100,200};
	discreteDistanceInitIndex = 1;
  };

  class CUP_smg_M3A1 : Rifle_Base_F {
	discreteDistance[] = {50,100,200};
	discreteDistanceInitIndex = 1;
  };

  class CUP_Mac10_Base : Rifle_Base_F {
	discreteDistance[] = {50,100};
	discreteDistanceInitIndex = 1;
  };

  class Pistol_Base_F;
  class CUP_hgun_M17_Coyote : Pistol_Base_F {
	magazineWell[] = {"CBA_9x19_P320"};
  };
  class CUP_hgun_CZ75 : Pistol_Base_F {
	magazineWell[] = {"CBA_9x19_CZ75_Full"};
  };

  class CUP_hgun_SA61 : Pistol_Base_F {
	class FullAuto : Mode_FullAuto {
		dispersion = 0.004916;
	};
	class Single : Mode_SemiAuto {
		dispersion = 0.004916;
	};
  };

  // switch
  class CUP_hgun_Glock17 : Pistol_Base_F {};
  class CUP_hgun_Glock18 : CUP_hgun_Glock17 {
	descriptionShort = "Selective fire pistol<br/>Caliber: 9x19mm";
	displayName = "G18";
	modes[] = {"Single","Auto"};
	class Auto : Mode_FullAuto {
		ACE_barrelLength = 114.046;
		ACE_barrelTwist = 248.92;
		dispersion = 0.00435;
		initSpeed = -0.9595;
		jsrs_soundeffect = "JSRS2_Distance_Effects_Glock";
		maxRange = 50;
		maxRangeProbab = 0.1;
		midRange = 25;
		midRangeProbab = 0.6;
		minRange = 5;
		minRangeProbab = 0.3;
		reloadtime = 0.05;
		sounds[] = {"StandardSound","SilencedSound"};
		class BaseSoundModeType {
			closure1[] = {"A3\sounds_f\weapons\closure\closure_handgun_3",1.03514,1,10};
			closure2[] = {"A3\sounds_f\weapons\closure\closure_handgun_3",1.03514,1.1,10};
			soundClosure[] = {"closure1",0.5,"closure2",0.5};
			weaponSoundEffect = "DefaultRifle";
		};
		class SilencedSound : BaseSoundModeType {
			begin1[] = {"A3\sounds_f\weapons\silenced\silent-07",0.562341,1,200};
			begin2[] = {"A3\sounds_f\weapons\silenced\silent-08",0.562341,1,200};
			soundBegin[] = {"begin1",0.5,"begin2",0.5};
			soundSetShot[] = {"jsrs_2025_glock_shot_silenced_soundset","jsrs_2025_tailsystem_9mm_pistol_silenced_sonic_soundset"};
		}
		class StandardSound : BaseSoundModeType {
			begin1[] = {"CUP\Weapons\CUP_Weapons_Glock17\data\sfx\Glock17_s1.wss",1,1,800};
			begin2[] = {"CUP\Weapons\CUP_Weapons_Glock17\data\sfx\Glock17_s2.wss",1,1,800};
			begin3[] = {"CUP\Weapons\CUP_Weapons_Glock17\data\sfx\Glock17_s3.wss",1,1,800};
			begin4[] = {"CUP\Weapons\CUP_Weapons_Glock17\data\sfx\Glock17_s4.wss",1,1,800};
			soundBegin[] = {"begin1",0.25,"begin2",0.25,"begin3",0.25,"begin4",0.25};
			soundSetShot[] = {"jsrs_2025_glock_shot_soundset","jsrs_2025_tailsystem_9mm_pistol_sonic_soundset"};
		}
	};
  };
  class CUP_hgun_Glock18_blk : CUP_hgun_Glock18 {
	displayName = "G18 (Black)";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\CUP\Weapons\CUP_Weapons_glock17\data\glock17_blk_co.paa"};
  };
  class CUP_hgun_Glock18_tan : CUP_hgun_Glock18 {
	displayName = "G18 (Tan)";
	hiddenSelections[] = {"Camo"};
	hiddenSelectionsTextures[] = {"\CUP\Weapons\CUP_Weapons_glock17\data\glock17_tan_co.paa"};
  };

  class greenmag_ammo_127x54_basic_60Rnd;
  class greenmag_ammo_93x64_basic_60Rnd : greenmag_ammo_127x54_basic_60Rnd {
    displayName = "9.3x64mm - 60 Rnd";
    greenmag_ammotype = "greenmag_ammo_93x64_basic_1Rnd";
  };
  class greenmag_ammo_12G_basic_24Rnd : greenmag_ammo_127x54_basic_60Rnd {
    displayName = "12G - 24 Shell";
    greenmag_ammotype = "greenmag_ammo_12G_basic_1Rnd";
	greenmag_bullets = 24;
  };
  class greenmag_ammo_127x54_basic_30Rnd;
  class greenmag_ammo_93x64_basic_30Rnd : greenmag_ammo_127x54_basic_30Rnd {
    displayName = "9.3x64mm - 30 Rnd";
    greenmag_ammotype = "greenmag_ammo_93x64_basic_1Rnd";
  };
  class greenmag_ammo_12G_basic_12Rnd : greenmag_ammo_127x54_basic_30Rnd {
    displayName = "12G - 12 Shell";
    greenmag_ammotype = "greenmag_ammo_12G_basic_1Rnd";
	greenmag_bullets = 12;
  };
  class greenmag_ammo_127x108_basic_1Rnd;
  class greenmag_ammo_12G_basic_1Rnd : greenmag_ammo_127x108_basic_1Rnd {
    displayName = "12G - 1 Shell";
    greenmag_ammotype = "greenmag_ammo_12G_basic_1Rnd";
  };

  // Rhs scope adapter attachment visibility in arsenal
#if __has_include("\rhsafrf\addons\rhs_c_weapons\script_component.hpp")
  class rhs_acc_ekp1;
  class rhs_acc_npz : rhs_acc_ekp1 {
    scopeArsenal = 2;
  };
#else
#endif

// Fix backpack disposable inconsistent mass
  class Launcher;
  class Launcher_Base_F : Launcher {
		class WeaponSlotsInfo;
		class Single : Mode_SemiAuto
		{
			dispersion = 0.05;
		};
	};

	#define DGT_PROB_RPG 1.2
	#define DGT_PROB_MRAW 1.1

	class Launch_RPG7_F: Launcher_Base_F
	{
		class Single : Mode_SemiAuto
		{
			//dispersion = 0.05; // 0.0002
			aiDispersionCoefX = 1.4; // 1.4
			aiDispersionCoefY = 1.7; // 1.7
			aiRateOfFire = 5; // 7
			//aiRateOfFireDispersion = 1; // 1
			//aiRateOfFireDistance = 600; //600
			maxRange = 500; // 600
			maxRangeProbab = DGT_PROB_RPG; // 0.1;
			midRange = 300; // 400
			midRangeProbab = DGT_PROB_RPG; // 0.8
			minRange = 15; // 10
			minRangeProbab = DGT_PROB_RPG; // 0.3
		};
	};
	
	class launch_MRAWS_base_F: Launcher_Base_F
	{
		class Single : Mode_SemiAuto
		{
			dispersion = 0.05; // 0.07;
			aiDispersionCoefX = 1.4; // 1.4
			aiDispersionCoefY = 1.7; // 1.7
			aiRateOfFire = 5; // 7
			//aiRateOfFireDispersion = 1; // 1
			//aiRateOfFireDistance = 600; //600
			maxRange = 700; // 700
			maxRangeProbab = DGT_PROB_MRAW; // 0.1;
			midRange = 400; // 400
			midRangeProbab = DGT_PROB_MRAW; // 0.8
			minRange = 15; // 50
			minRangeProbab = DGT_PROB_MRAW; // 0.3
		};
	};
	
	class launch_Vorona_base_F: Launcher_Base_F
	{
		class Single : Mode_SemiAuto
		{
			aiRateOfFireDistance = 1000;
			maxRange = 1000;
			maxRangeProbab = DGT_PROB_MRAW; // 0.1;
			midRange = 800;
			midRangeProbab = DGT_PROB_MRAW; // 0.8
			minRange = 10;
			minRangeProbab = DGT_PROB_MRAW; // 0.3
		};
	};
	
	
	class launch_RPG32_F: Launcher_Base_F
	{
		class Single : Mode_SemiAuto
		{
			//dispersion = 0.05; // 0.0002;
			aiDispersionCoefX = 1.4; // 1.4
			aiDispersionCoefY = 1.7; // 1.7
			//aiRateOfFireDistance = 500; //500
			maxRange = 600; // 600
			maxRangeProbab = DGT_PROB_MRAW; // 0.85;
			midRange = 40; // 400
			midRangeProbab = DGT_PROB_MRAW; // 0.85
			minRange = 15; // 50
			minRangeProbab = DGT_PROB_MRAW; // 0.3
		};
	};
	
	
	class CUP_launch_RPG7V: Launcher_Base_F
	{
		class Single : Mode_SemiAuto
		{
			//dispersion = 0.05; // 0.0002
			aiDispersionCoefX = 1.4; // 1.4
			aiDispersionCoefY = 1.7; // 1.7
			aiRateOfFire = 5; // 7
			//aiRateOfFireDispersion = 1; // 1
			//aiRateOfFireDistance = 600; //600
			maxRange = 500; // 600
			maxRangeProbab = DGT_PROB_RPG; // 0.1;
			midRange = 300; // 400
			midRangeProbab = DGT_PROB_RPG; // 0.8
			minRange = 15; // 10
			minRangeProbab = DGT_PROB_RPG; // 0.3
		};
	};
	
	/*class CUP_launch_PzF_Base;
	
	class CUP_launch_BF3_Loaded: CUP_launch_PzF_Base
	{
		class Single : Mode_SemiAuto
		{
			//dispersion = 0.05; // 0.0002
			maxRange = 500; // 500
			//maxRangeProbab = DGT_PROB_RPG; // 0.1;
			midRange = 350; // 350
			//midRangeProbab = DGT_PROB_RPG; // 0.8
			minRange = 10; // 10
			//minRangeProbab = DGT_PROB_RPG; // 0.3
		};	
	};
	
	class CUP_launch_HCPF3_Loaded: CUP_launch_PzF_Base
	{
		class Single : Mode_SemiAuto
		{
			//dispersion = 0.05; // 0.0002
			maxRange = 500; // 500
			//maxRangeProbab = DGT_PROB_RPG; // 0.1;
			midRange = 350; // 350
			//midRangeProbab = DGT_PROB_RPG; // 0.8
			minRange = 10; // 10
			//minRangeProbab = DGT_PROB_RPG; // 0.3
		};	
	};
	
	class CUP_launch_PzF3_Loaded: CUP_launch_PzF_Base
	{
		class Single : Mode_SemiAuto
		{
			//dispersion = 0.05; // 0.0002
			maxRange = 500; // 500
			//maxRangeProbab = DGT_PROB_RPG; // 0.1;
			midRange = 350; // 350
			//midRangeProbab = DGT_PROB_RPG; // 0.8
			minRange = 10; // 10
			//minRangeProbab = DGT_PROB_RPG; // 0.3
		};	
	};*/
	
	class CUP_launch_MAAWS: Launcher_Base_F
	{
		class Single : Mode_SemiAuto
		{
			//dispersion = 0.05; // 0.0002
			maxRange = 700; // 700
			maxRangeProbab = DGT_PROB_MRAW; // 0.1;
			midRange = 400; // 400
			midRangeProbab = DGT_PROB_MRAW; // 0.8
			minRange = 50; // 50
			minRangeProbab = DGT_PROB_MRAW; // 0.3
		};
	};
	
	class CUP_launch_MAAWS_Scope: CUP_launch_MAAWS{};
	
	class CUP_launch_Mk153Mod0: Launcher_Base_F
	{
		class Single : Mode_SemiAuto
		{
			//dispersion = 0.05; // 0.0002
			maxRange = 600; // 700
			maxRangeProbab = DGT_PROB_RPG; // 0.1;
			midRange = 400; // 400
			midRangeProbab = DGT_PROB_RPG; // 0.8
			minRange = 50; // 50
			minRangeProbab = DGT_PROB_RPG; // 0.3
		};
	};
	
	class CUP_launch_Mk153Mod0_blk: CUP_launch_Mk153Mod0{};
	class CUP_launch_Mk153Mod0_blk_SMAWOptics: CUP_launch_Mk153Mod0_blk{};
	class CUP_launch_Mk153Mod0_SMAWOptics: CUP_launch_Mk153Mod0{};

  // squeak two at4 into kitbag
  class CUP_launch_M136_Loaded : Launcher_Base_F {
	class WeaponSlotsInfo : WeaponSlotsInfo {
		mass = 137.4;
	};
  };
  class CUP_launch_M136 : CUP_launch_M136_Loaded {
	class WeaponSlotsInfo : WeaponSlotsInfo {
		mass = 137.4;
	};
  };
  class CUP_launch_M72A6_Loaded : Launcher_Base_F {
	displayName = "M72A5";
	class WeaponSlotsInfo : WeaponSlotsInfo {
		//class CowsSlot : CUP_PicatinnyTopShortMount {}; // puts your eye in the tube
		mass = 57.3;
	};
  };
  class CUP_launch_M72A6_Used : CUP_launch_M72A6_Loaded {
    displayName = "M72A5 (Used)";
  };
  class CUP_launch_M72A6_Special_Loaded : CUP_launch_M72A6_Loaded {
    displayName = "M72A5 (Special)";
  };
  class CUP_launch_M72A6_Special : CUP_launch_M72A6_Special_Loaded {
    displayName = "M72A5 (Special)";
  };
  class CUP_launch_M72A6_Special_Used : CUP_launch_M72A6_Special_Loaded {
    displayName = "M72A5 (Special)(Used)";
  };
  class CUP_launch_RPG18_Loaded : Launcher_Base_F {
	class WeaponSlotsInfo : WeaponSlotsInfo {
		mass = 57.3;
	};
  };
  class CUP_launch_RPG26_Loaded : Launcher_Base_F {
	class WeaponSlotsInfo : WeaponSlotsInfo {
		mass = 64;
	};
  };
  class CUP_launch_RShG2_Loaded : Launcher_Base_F {
	displayName = "RShG-2 (Thermobaric)";
	class WeaponSlotsInfo : WeaponSlotsInfo {
		mass = 88.2;
	};
  };

  // M72A8
  class mjb_launch_M72A10_Loaded : CUP_launch_M72A6_Loaded {
	displayName = "M72A8 (HEDP)";
	magazines[] = {"mjb_M72A10_M"};
	baseWeapon = "mjb_launch_M72A10";
    hiddenSelectionsTextures[] = {"\z\mjb\addons\flags\data\m72a8_co.paa"};
	ace_overpressure_angle = 30;
	ace_overpressure_damage = 0.6;
	ace_overpressure_range = 2;
  };
  class mjb_launch_M72A10 : mjb_launch_M72A10_Loaded {
	baseWeapon = "mjb_launch_M72A10";
	displayName = "M72A8 (HEDP)";
	magazines[] = {"CBA_FakeLauncherMagazine"};
	scope = 2;
	scopeArsenal = 2;
  };
  class mjb_launch_M72A10_Used : mjb_launch_M72A10_Loaded {
	displayName = "M72A8 (Used)";
	baseWeapon = "mjb_launch_M72A10_used";
	magazines[] = {"CBA_FakeLauncherMagazine"};
	mass = 17.3;
	model = "\CUP\Weapons\CUP_Weapons_M72A6\CUP_m72a6_used.p3d";
  };

  // M72A10
  class mjb_launch_M72A10_HE_Loaded : CUP_launch_M72A6_Loaded {
	displayName = "M72A10 (HE)";
	magazines[] = {"mjb_M72A10_HE_M"};
	baseWeapon = "mjb_launch_M72A10_HE";
    hiddenSelectionsTextures[] = {"\z\mjb\addons\flags\data\m72a10_co.paa"};
	ace_overpressure_angle = 30;
	ace_overpressure_damage = 0.6;
	ace_overpressure_range = 2;
  };
  class mjb_launch_M72A10_HE : mjb_launch_M72A10_HE_Loaded {
	baseWeapon = "mjb_launch_M72A10_HE";
	displayName = "M72A10 (HE)";
	magazines[] = {"CBA_FakeLauncherMagazine"};
	scope = 2;
	scopeArsenal = 2;
  };
  class mjb_launch_M72A10_HE_Used : mjb_launch_M72A10_HE_Loaded {
	displayName = "M72A10 (Used)";
	baseWeapon = "mjb_launch_M72A10_HE_Used";
	magazines[] = {"CBA_FakeLauncherMagazine"};
	mass = 17.3;
	model = "\CUP\Weapons\CUP_Weapons_M72A6\CUP_m72a6_used.p3d";
  };

  // yeet bino sway
  class Binocular : Default {
    swayCoef = 0.02; // default 0.34
  };


  // Add 556 to Grot
  class arifle_MSBS65_base_F : Rifle_Base_F {
    magazineWell[] += {"STANAG_556x45","CBA_556x45_STANAG","CBA_556x45_STANAG_L"};
  };

  class Throw : GrenadeLauncher {
	class ThrowMuzzle: GrenadeLauncher
	{
		// This is the entry to edit
		// need to adjust dispersion here?
		//aiDispersionCoefX = DGT_ACC; // 6
		//aiDispersionCoefY = DGT_ACC; // 6
		// VALUES FROM PREVIOUS RELEASE
		aiRateOfFire = 3; // 0.1  Setting this high (20) makes AI look at the sky
		aiRateOfFireDispersion = 2; // 0
		aiRateOfFireDistance = 60; // 60
		//maxRange = 60; // 60
		maxRangeProbab = 1.015; // 0.03
		//midRange = 45; // 45
		midRangeProbab = 1.015; // 0.9
		//minRange = 10; // 10
		minRange = 15; // 10
		minRangeProbab = 1.015; // 0.2
		//minRangeProbab = 0.2; // 0.2
	};

    muzzles[] += {"mjb_SmokeShellLightBlueMuzzle","mjb_SmokeShellPinkMuzzle","mjb_SmokeShellBurstMuzzle","mjb_SmokeShellBurstBlueMuzzle","mjb_SmokeShellBurstGreenMuzzle","mjb_SmokeShellBurstRedMuzzle","mjb_SmokeShellBurstOrangeMuzzle","mjb_SmokeShellBurstPurpleMuzzle","mjb_SmokeShellBurstYellowMuzzle","mjb_SmokeShellBurstLightBlueMuzzle","mjb_SmokeShellBurstPinkMuzzle"};
	class mjb_SmokeShellLightBlueMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellLightBlue"};
	};
	class mjb_SmokeShellPinkMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellPink"};
	};
	class mjb_SmokeShellBurstMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellBurst"};
	};
	class mjb_SmokeShellBurstBlueMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellBurstBlue"};
	};
	class mjb_SmokeShellBurstGreenMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellBurstGreen"};
	};
	class mjb_SmokeShellBurstRedMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellBurstRed"};
	};
	class mjb_SmokeShellBurstOrangeMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellBurstOrange"};
	};
	class mjb_SmokeShellBurstPurpleMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellBurstPurple"};
	};
	class mjb_SmokeShellBurstYellowMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellBurstYellow"};
	};
	class mjb_SmokeShellBurstLightBlueMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellBurstLightBlue"};
	};
	class mjb_SmokeShellBurstPinkMuzzle : ThrowMuzzle {
		displayName = "Smoke Grenade";
		magazines[] = {"mjb_SmokeShellBurstPink"};
	};
  };
#define DGT_PROB_UGL 1.05
  class UGL_F : GrenadeLauncher {
	aiDispersionCoefX = 3;
	aiDispersionCoefY = 8;
	aiRateOfFire = 30;
	aiRateOfFireDispersion = 90;
	aiRateOfFireDistance = 400;
	class Single : Mode_SemiAuto {
		aiDispersionCoefX = 3;
		aiDispersionCoefY = 8;
		aiRateOfFire = 30;
		aiRateOfFireDispersion = 90;
		aiRateOfFireDistance = 400;
		maxRange = 400;
		maxRangeProbab = DGT_PROB_UGL; // 0.05
		midRange = 200;
		midRangeProbab = DGT_PROB_UGL; // 0.7
		minRange = 20;
		minRangeProbab = DGT_PROB_UGL; // 0.1
	};
  };

  class arifle_MX_Base_F : Rifle_Base_F {
	class GL_3GL_F : UGL_F {
		class Single : Single {
			aiRateOfFire = 15;
			aiRateOfFireDispersion = 5;
			aiRateOfFireDistance = 400;
		};
	};
  };

  class CUP_glaunch_Base : Rifle_Base_F {
	aiDispersionCoefX = 6;
	aiDispersionCoefY = 6;
	aiRateOfFire = 15;
	aiRateOfFireDispersion = 5;
	aiRateOfFireDistance = 400;
	class Single : Mode_SemiAuto {
		aiDispersionCoefX = 6;
		aiDispersionCoefY = 6;
		aiRateOfFire = 15;
		aiRateOfFireDispersion = 5;
		aiRateOfFireDistance = 400;
		maxRange = 400;
		maxRangeProbab = DGT_PROB_UGL; // 0.05
		midRange = 200;
		midRangeProbab = DGT_PROB_UGL; // 0.7
		minRange = 20;
		minRangeProbab = DGT_PROB_UGL; // 0.1
	};
  };
  /*class CUP_glaunch_6G30 : CUP_glaunch_Base {
	aiDispersionCoefX = 6;
	aiDispersionCoefY = 6;
	aiRateOfFire = 15;
	aiRateOfFireDispersion = 5;
	aiRateOfFireDistance = 400;
  };
  class CUP_glaunch_M32 : CUP_glaunch_Base {
	aiDispersionCoefX = 6;
	aiDispersionCoefY = 6;
	aiRateOfFire = 15;
	aiRateOfFireDispersion = 5;
	aiRateOfFireDistance = 400;
  };*/
  class CUP_glaunch_M79 : CUP_glaunch_Base {
	aiDispersionCoefX = 6;
	aiDispersionCoefY = 6;
	aiRateOfFire = 30;
	aiRateOfFireDispersion = 90;
	aiRateOfFireDistance = 400;
	class Single : Single {
		aiDispersionCoefX = 6;
		aiDispersionCoefY = 6;
		aiRateOfFire = 30;
		aiRateOfFireDispersion = 90;
		aiRateOfFireDistance = 400;
		maxRange = 400;
		maxRangeProbab = DGT_PROB_UGL; // 0.05
		midRange = 200;
		midRangeProbab = DGT_PROB_UGL; // 0.7
		minRange = 20;
		minRangeProbab = DGT_PROB_UGL; // 0.1
	};
  };
  class CUP_glaunch_Mk13 : CUP_glaunch_Base {
	aiDispersionCoefX = 3;
	aiDispersionCoefY = 8;
	aiRateOfFire = 30;
	aiRateOfFireDispersion = 90;
	aiRateOfFireDistance = 400;
	class Single : Single {
		aiDispersionCoefX = 3;
		aiDispersionCoefY = 8;
		aiRateOfFire = 30;
		aiRateOfFireDispersion = 90;
		aiRateOfFireDistance = 400;
		maxRange = 400;
		maxRangeProbab = DGT_PROB_UGL; // 0.05
		midRange = 200;
		midRangeProbab = DGT_PROB_UGL; // 0.7
		minRange = 20;
		minRangeProbab = DGT_PROB_UGL; // 0.1
	};
  };
  class CUP_arifle_AK_Base : Rifle_Base_F {
	class GP25Muzzle : UGL_F {
		class Single : Single {};
    };
  };
/*
  class CUP_arifle_AKM;
  class CUP_arifle_AKM_GL : CUP_arifle_AKM {
	class GP25Muzzle : UGL_F {
		class Single : Single {};
    };
  };*/
  class CUP_arifle_xm29_ke_base;
  class CUP_arifle_xm29_he_base : CUP_arifle_xm29_ke_base {
	class XMHEMuzzle : Rifle_Base_F {
		aiDispersionCoefX = 6;
		aiDispersionCoefY = 6;
		aiRateOfFire = 15;
		aiRateOfFireDispersion = 5;
		aiRateOfFireDistance = 600;
		class Airburst : Mode_SemiAuto {
			aiDispersionCoefX = 6;
			aiDispersionCoefY = 6;
			aiRateOfFire = 15;
			aiRateOfFireDispersion = 5;
			aiRateOfFireDistance = 600;
			maxRange = 600;
			maxRangeProbab = DGT_PROB_UGL; // 0.05
			midRange = 300;
			midRangeProbab = DGT_PROB_UGL; // 0.7
			minRange = 20;
			minRangeProbab = DGT_PROB_UGL; // 0.1
		};
    };
  };

  
  class ItemCore;

  class InventoryOpticsItem_Base_F;
  /*/ hamr is sad :'(
  class optic_Hamr : ItemCore {
    class ItemInfo : InventoryOpticsItem_Base_F {
		class OpticsModes {
			class Hamr2Scope {
				//useModelOptics = 1;
				//opticsFlare = 0;
				//opticsPPEffects[] = {}; //"OpticsRadialBlur1","OpticsBlur1"
			};
		};
	};
  };*/

  // FH speed fix
  class InventoryMuzzleItem_Base_F;
  class CUP_acc_sffh : ItemCore {
		class ItemInfo : InventoryMuzzleItem_Base_F {
			class MagazineCoef {
				initSpeed = 1.0;
			};
		};
  };

#include "CfgWeapons_flashlights.hpp" // needs ItemCore


// Uniforms
  class Uniform_Base;
  class UniformItem;
  class U_IG_Guerilla1_1 : Uniform_Base {
	class ItemInfo : UniformItem {
		containerClass = "Supply40";
	};
  };
  class U_IG_Guerilla2_1 : Uniform_Base {
	class ItemInfo : UniformItem {
		containerClass = "Supply40";
	};
  };
  class U_IG_Guerilla2_2 : Uniform_Base {
	class ItemInfo : UniformItem {
		containerClass = "Supply40";
	};
  };
  class U_IG_Guerilla2_3 : Uniform_Base {
	class ItemInfo : UniformItem {
		containerClass = "Supply40";
	};
  };
  class U_IG_Guerilla3_1 : Uniform_Base {
	class ItemInfo : UniformItem {
		containerClass = "Supply40";
	};
  };
  class U_IG_Guerilla3_2 : Uniform_Base {
	class ItemInfo : UniformItem {
		containerClass = "Supply40";
	};
  };
  class U_IG_Guerrilla_6_1 : Uniform_Base {
	class ItemInfo : UniformItem {
		containerClass = "Supply40";
	};
  };//*/
  class CUP_U_C_Tracksuit_01 : ItemCore {
	class ItemInfo : UniformItem {
		containerClass = "Supply40";
	};
  };
  class WU_B_GEN_Commander_F : Uniform_Base {
	class ItemInfo : UniformItem {
		containerClass = "Supply40";
	};
  };

  class HeadgearItem;
  #define HATARMOR(NAME,PARENT) \
  class ##NAME## : ##PARENT## \
  { \
    class ItemInfo : HeadgearItem \
    { \
	  class HitpointsProtectionInfo \
  	  { \
		class Head \
		{ \
			hitPointName = "HitHead"; \
			armor = 6; \
			passThrough = 0.5; \
		}; \
	  }; \
    }; \
  };

  HATARMOR(HelmetBase,ItemCore);

  HATARMOR(CUP_H_RUS_Bandana_GSSh_Headphones,ItemCore);
  HATARMOR(CUP_H_RUS_Bandana_HS,ItemCore);
  HATARMOR(CUP_H_FR_BandanaWdl,ItemCore);
  HATARMOR(CUP_H_FR_BoonieWDL,ItemCore);
  HATARMOR(CUP_H_FR_Cap_Headset_Green,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_Burberry,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_Back_Burberry,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_Back_EP_Burberry,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_EP_Burberry,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_PRR_Burberry,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_Back_Grey,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_Back_EP_Grey,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_EP_Grey,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_PRR_Grey,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_Back_tan,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_Back_EP_tan,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_EP_tan,ItemCore);
  HATARMOR(CUP_H_PMC_Cap_PRR_tan,ItemCore);
  HATARMOR(CUP_H_C_Ushanka_01,ItemCore);
  HATARMOR(CUP_H_PMC_PRR_Headset,ItemCore);
  HATARMOR(CUP_H_PMC_Beanie_Headphones_Black,ItemCore);
  HATARMOR(CUP_H_PMC_Beanie_Khaki,ItemCore);
  HATARMOR(CUP_H_PMC_Beanie_Headphones_Khaki,ItemCore);
  HATARMOR(CUP_H_PMC_Beanie_Winter,ItemCore);
  HATARMOR(CUP_H_PMC_Beanie_Headphones_Winter,ItemCore);
  HATARMOR(CUP_H_ChDKZ_Beret,ItemCore);

  class H_Beret_blk : HelmetBase {};
  HATARMOR(CUP_H_SLA_BeretRed,H_Beret_blk);
  HATARMOR(CUP_H_PMC_Beanie_Black,CUP_H_PMC_Beanie_Khaki);
  HATARMOR(CUP_H_C_Beanie_01,ItemCore);

#if __has_include("\rhsafrf\addons\rhs_c_weapons\script_component.hpp")
  class H_HelmetB;
  HATARMOR(rhs_beanie,H_HelmetB);
  HATARMOR(rhs_fieldcap_m88,rhs_beanie);
  HATARMOR(rhs_ushanka,rhs_fieldcap_m88);
  HATARMOR(rhsgref_Booniehat_alpen,ItemCore);
  HATARMOR(rhsusf_Bowman,ItemCore);
#else
#endif

class H_PilotHelmetFighter_B;
class H_PilotHelmetFighter_I;
class H_PilotHelmetFighter_O;
class mjb_H_PilotHelmetFighter_B_WP : H_PilotHelmetFighter_B {
	displayName = "Pilot Helmet [NATO, WP]";
	subItems[] = {"mjb_Integrated_NVG_WP"};
};
class mjb_H_PilotHelmetFighter_I_WP : H_PilotHelmetFighter_I {
	displayName = "Pilot Helmet [AAF, WP]";
	subItems[] = {"mjb_Integrated_NVG_WP"};
};
class mjb_H_PilotHelmetFighter_O_WP : H_PilotHelmetFighter_O {
	displayName = "Pilot Helmet [CSAT, WP]";
	subItems[] = {"mjb_Integrated_NVG_WP"};
};

class H_HelmetO_ViperSP_hex_F;
class H_HelmetO_ViperSP_ghex_F;
class mjb_H_HelmetO_ViperSP_hex_WP : H_HelmetO_ViperSP_hex_F {
	displayName = "Special Purpose Helmet (Hex, WP)";
	subItems[] = {"mjb_Integrated_NVG_TI_1_WP"};
};
class mjb_H_HelmetO_ViperSP_ghex_WP : H_HelmetO_ViperSP_ghex_F {
	displayName = "Special Purpose Helmet (Green Hex, WP)";
	subItems[] = {"mjb_Integrated_NVG_TI_1_WP"};
};

/*/plates are med to rats?
class CBA_MiscItem;
class diw_armor_plates_main_plate : CBA_MiscItem { ACE_isMedicalItem = 1; };//*/

#include "CfgWeapons_vests.hpp" // needs ItemCore


#define NVG_WHITE_PRESET ace_nightvision_colorPreset[] = {0.0, {0.0, 0.0, 0.0, 0.0}, {1.1, 0.8, 1.9, 0.9}, {1, 1, 6, 0.0}}
#define NVG_WHITE_PRESETOLD colorPreset[] = {0.0, {0.0, 0.0, 0.0, 0.0}, {1.1, 0.8, 1.9, 0.9}, {1, 1, 6, 0.0}}

class Integrated_NVG_F;
class mjb_Integrated_NVG_WP : Integrated_NVG_F {
	displayName = "NV Goggles (Gen3, Integrated WP)";
	NVG_WHITE_PRESET;
	NVG_WHITE_PRESETOLD;
};
class Integrated_NVG_TI_0_F;
class mjb_Integrated_NVG_TI_0_WP : Integrated_NVG_TI_0_F {
	NVG_WHITE_PRESET;
	NVG_WHITE_PRESETOLD;
};
class Integrated_NVG_TI_1_F;
class mjb_Integrated_NVG_TI_1_WP : Integrated_NVG_TI_1_F {
	NVG_WHITE_PRESET;
	NVG_WHITE_PRESETOLD;
};

/*/ ACE added now
	class CUP_NVG_GPNVG_black;
	class CUP_NVG_GPNVG_winter;
	class CUP_NVG_GPNVG_tan;
	class CUP_NVG_GPNVG_black_WP: CUP_NVG_GPNVG_black {
		displayName = "GPNVG (Black, WP)";
		descriptionShort = "Night Vision Goggles";
		NVG_WHITE_PRESET;
		NVG_WHITE_PRESETOLD;
	};
	class CUP_NVG_GPNVG_winter_WP: CUP_NVG_GPNVG_winter {
		displayName = "GPNVG (Winter, WP)";
		descriptionShort = "Night Vision Goggles";
		NVG_WHITE_PRESET;
		NVG_WHITE_PRESETOLD;
	};
	class CUP_NVG_GPNVG_tan_WP: CUP_NVG_GPNVG_tan {
		displayName = "GPNVG (Tan, WP)";
		descriptionShort = "Night Vision Goggles";
		NVG_WHITE_PRESET;
		NVG_WHITE_PRESETOLD;
	};
*/

	class NVGogglesB_blk_F;
	class NVGogglesB_grn_F;
	class NVGogglesB_gry_F;

	class mjb_NVGogglesB_blk : NVGogglesB_blk_F {
		displayName = "ENVG-II (Black, No TI)";
		visionMode[] = {"Normal","NVG"};
	};

	class mjb_NVGogglesB_grn : NVGogglesB_grn_F {
		displayName = "ENVG-II (Green, No TI)";
		visionMode[] = {"Normal","NVG"};
	};

	class mjb_NVGogglesB_gry : NVGogglesB_gry_F {
		displayName = "ENVG-II (Grey, No TI)";
		visionMode[] = {"Normal","NVG"};
	};

	class mjb_NVGogglesB_blk_WP : NVGogglesB_blk_F {
		ace_nightvision_colorPreset[] = {0,{0,0,0,0},{1.1,0.8,1.9,0.9},{1,1,6,0}};
		displayName = "ENVG-II (Black, No TI, WP)";
		visionMode[] = {"Normal","NVG"};
	};

	class mjb_NVGogglesB_grn_WP : NVGogglesB_grn_F {
		ace_nightvision_colorPreset[] = {0,{0,0,0,0},{1.1,0.8,1.9,0.9},{1,1,6,0}};
		displayName = "ENVG-II (Green, No TI, WP)";
		visionMode[] = {"Normal","NVG"};
	};

	class mjb_NVGogglesB_gry_WP : NVGogglesB_gry_F {
		ace_nightvision_colorPreset[] = {0,{0,0,0,0},{1.1,0.8,1.9,0.9},{1,1,6,0}};
		displayName = "ENVG-II (Grey, No TI, WP)";
		visionMode[] = {"Normal","NVG"};
	};
};

class CBA_DisposableLaunchers {
	mjb_launch_M72A10_Loaded[] = {"mjb_launch_M72A10","mjb_launch_M72A10_Used"};
	mjb_launch_M72A10_HE_Loaded[] = {"mjb_launch_M72A10_HE","mjb_launch_M72A10_HE_Used"};
};