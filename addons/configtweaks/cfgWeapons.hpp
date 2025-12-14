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
    aiDispersionCoefX = 4.0;
    aiDispersionCoefY = 3.0;
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
    aiDispersionCoefX = 4.0;
    aiDispersionCoefY = 3.0;
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
    aiDispersionCoefX = 12;
    aiDispersionCoefY = 9;
  };
  class CUP_Vacannon_M197_veh : CannonCore {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
  };
  class CUP_Vacannon_M230_veh : CannonCore {
    aiDispersionCoefX = 40;
    aiDispersionCoefY = 30;
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
  
  class Rifle_Base_F;
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
		dispersion = 0.02007;
	};
	class Single : Mode_SemiAuto {
		dispersion = 0.02007;
	};
  };

  class Pistol_Base_F;
  class CUP_hgun_M17_Coyote : Pistol_Base_F {
	magazineWell[] = {"CBA_9x19_P320"};
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

// squeak two at4 into kitbag
  class Launcher_Base_F;
  class CUP_launch_M136_Loaded : Launcher_Base_F {class WeaponSlotsInfo;};
  class CUP_launch_M136 : CUP_launch_M136_Loaded {
	class WeaponSlotsInfo : WeaponSlotsInfo { mass = 137.4; };
  };
  class CUP_M136 : CUP_launch_M136 {
	class WeaponSlotsInfo : WeaponSlotsInfo { mass = 137.4; };
  };

  // yeet bino sway
  class Binocular : Default {
    swayCoef = 0.04; // default 0.34
  };

  
  class ItemCore;

#include "CfgWeapons_flashlights.hpp" // needs ItemCore
  

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


/*/plates are med to rats?
class CBA_MiscItem;
class diw_armor_plates_main_plate : CBA_MiscItem { ACE_isMedicalItem = 1; };//*/

#include "CfgWeapons_vests.hpp" // needs ItemCore


#define NVG_WHITE_PRESET ace_nightvision_colorPreset[] = {0.0, {0.0, 0.0, 0.0, 0.0}, {1.1, 0.8, 1.9, 0.9}, {1, 1, 6, 0.0}}
#define NVG_WHITE_PRESETOLD colorPreset[] = {0.0, {0.0, 0.0, 0.0, 0.0}, {1.1, 0.8, 1.9, 0.9}, {1, 1, 6, 0.0}}
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
};