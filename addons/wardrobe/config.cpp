
class CfgPatches {
  class mjb_wardrobe {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "MJB Wardrobe";
    requiredAddons[] = {"ace_wardrobe"};
    skipWhenMissingDependencies = 1;
  };
};

/*class Extended_PostInit_EventHandlers
{
	class mjb_wardrobe
	{
		init="call compileScript ['z\mjb\addons\wardrobe\XEH_postInit.sqf']";
	};
};

class Extended_PreInit_EventHandlers
{
	class mjb_wardrobe
	{
		init="call compileScript ['z\mjb\addons\wardrobe\XEH_preInit.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class mjb_wardrobe
	{
		init="call compileScript ['z\mjb\addons\wardrobe\XEH_preStart.sqf']";
	};
};*/

#include "\x\cba\addons\main\script_macros_common.hpp"
#include "\z\ace\addons\wardrobe\script_macros_wardrobe.hpp"
class ace_wardrobe {
    // Remove unused imported base classes once done
    class ace_wardrobe_base;
    class ace_wardrobe_base_H_visor_up;
    class ace_wardrobe_base_H_visor_down;
    class ace_wardrobe_base_H_goggles_on;
    class ace_wardrobe_base_H_goggles_off;
    class ace_wardrobe_base_H_mask_on;
    class ace_wardrobe_base_H_mask_off;
    class ace_wardrobe_base_U_sleeves_up;
    class ace_wardrobe_base_U_sleeves_down;
    class ace_wardrobe_base_U_gloves_on;
    class ace_wardrobe_base_U_gloves_off;
    class ace_wardrobe_base_U_jacket_open;
    class ace_wardrobe_base_U_jacket_closed;
    class ace_wardrobe_base_U_hood_raised;
    class ace_wardrobe_base_U_hood_lowered;    

    // Begin to define your configs ...

    // Vanilla
    UNIFORM_JACKET(U_B_CombatUniform_mcam_tshirt,U_B_CombatUniform_mcam);
    UNIFORM_JACKET(U_B_T_Soldier_AR_F,U_B_T_Soldier_F);
    // Women
    UNIFORM_JACKET(U_B_CombatUniform_mcam_tshirt_W,U_B_CombatUniform_mcam_W);
    UNIFORM_JACKET(WU_B_T_Soldier_F,WU_B_T_Soldier_AR_F);

    // CUP
    UNIFORM_HOOD(CUP_U_I_GUE_Anorak_01,CUP_U_I_GUE_Anorak_03);
};