class CfgPatches {
  class ConfigTweaks {
    ammo[] = {"mjb_338_NM_trc_gr","mjb_338_NM_trc_ylw","mjb_93x64_trc_gr","mjb_93x64_trc_ylw","mjb_65x25_CBJ"};
    magazines[] = {"mjb_150Rnd_93x64_Mag_tracer","mjb_150Rnd_93x64_Mag_trc_red","mjb_150Rnd_93x64_Mag_trc_ylw", "mjb_130Rnd_338_Mag_tracer","mjb_130Rnd_338_Mag_trc_gr","mjb_130Rnd_338_Mag_trc_ylw","mjb_13Rnd_65x25_Browning_HP","mjb_15Rnd_65x25_M9","mjb_16Rnd_65x25_cz75","mjb_17Rnd_65x25_M17","mjb_17Rnd_65x25_glock17","mjb_30Rnd_65x25_Vityaz","mjb_30Rnd_65x25_MP5","mjb_150Rnd_93x64_Mag_trc_rbw_full"/*, "CUP_64Rnd_9x18_Bizon_M","CUP_64Rnd_Green_Tracer_9x18_Bizon_M","CUP_64Rnd_Red_Tracer_9x18_Bizon_M","CUP_64Rnd_White_Tracer_9x18_Bizon_M","CUP_64Rnd_Yellow_Tracer_9x18_Bizon_M"*/};
    units[] = {"Box_Rats_Ammo","mjb_O_customSoldier","mjb_O_customSoldier_mg"}; //
    weapons[] = {"CUP_NVG_GPNVG_tan_WP","CUP_NVG_GPNVG_black_WP","CUP_NVG_GPNVG_winter_WP"};
    requiredVersion = 0.1;
    author = "SuperJam, Camelith, Alien314";
    name = "Config Tweaks";
	requiredAddons[]=
        {
            "ace_ballistics",
            "CUP_Creatures_People_LoadOrder",
            "CUP_Weapons_Ammunition",
            "CUP_AirVehicles_LoadOrder",
            "CUP_TrackedVehicles_LoadOrder",
            "CUP_WaterVehicles_LoadOrder",
            "CUP_WheeledVehicles_LoadOrder",
			"PMC_Vest",
			"ace_recoil",
			"ace_laserpointer"
        };
    };
};

// AI Turrets Dispersion Config Tweaks (Built on nkenny's @LAMBS_Turrets)

class CfgBrains {
  class DefaultSoldierBrain {
    class Components {
      class AIBrainAimingErrorComponent {
        maxAngularErrorTurrets =
            0.1308;  // half of the error cone in radians, used for turrets
      };
    };
  };
};

// No greenmag spaghetti tweak
class CfgInventoryGlobalVariable { maxSoldierLoad = 9001; };

class CfgRecoils {
  class recoil_default;
  class recoil_mk200 : recoil_default {
	muzzleOuter[] = {"0.4*0.2","0.6*1", "0.4*1" ,"0.2*1"};
  };
  class recoil_zafir : recoil_default {
	muzzleOuter[] = {"0.5*0.2","1*1", "0.5*1" ,"0.3*1"};
  };
};

class Mode_SemiAuto;
class Mode_FullAuto;



/*class CfgSounds {
  class 3den_notificationWarning {
    sound[] = {"\a3\3DEN\Data\Sound\CfgSound\notificationWarning",0.85,1};
  };
};*/

#include "CfgAmmo.hpp" // MMG Tracer ammo, (commented Ammo config)
#include "CfgMagazines.hpp" // GreenMag simple compatibility, MMG Tracer boxes
#include "CfgVehicles.hpp"  // BRH for all units/uniforms
#include "CfgWeapons.hpp" // AIDispersion, Weapon, Greenmag items, Accessory, Helmet, and Vest tweaks