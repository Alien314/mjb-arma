// Flashlights, special thanks G4rrus
  #define LIGHTCONF(NAME,PARENT) \
  class ##NAME## : ##PARENT## \
  { \
      class ItemInfo : InventoryFlashLightItem_Base_F \
      { \
          class FlashLight \
          { \
              ambient[] = {0.9,0.81,0.7}; \
              color[] = {180,160,130}; \
              coneFadeCoef = 10; \
              direction = "flash"; \
              flareMaxDistance = 300; \
              flareSize = 4; \
              innerAngle = 10; \
              intensity = 4000; \
              outerAngle = 80; \
              position = "flash dir"; \
              scale[] = {0}; \
              class Attenuation \
              { \
                    constant = 32; \
                    hardLimitEnd = 105; \
                    hardLimitStart = 15; \
                    linear = 1; \
                    quadratic = 0.05; \
                    start = 0; \
              }; \
          }; \
      }; \
  };
  #define LIGHTCONFT1(NAME,PARENT) \
  class ##NAME## : ##PARENT## \
  { \
      class ItemInfo : InventoryFlashLightItem_Base_F \
      { \
          class FlashLight \
          { \
              ambient[] = {0.9,0.81,0.7}; \
              color[] = {180,160,130}; \
              coneFadeCoef = 10; \
              direction = "flash_dir"; \
              flareMaxDistance = 300; \
              flareSize = 4; \
              innerAngle = 10; \
              intensity = 4000; \
              outerAngle = 80; \
              position = "flash_pos"; \
              scale[] = {0}; \
              class Attenuation \
              { \
                    constant = 32; \
                    hardLimitEnd = 105; \
                    hardLimitStart = 15; \
                    linear = 1; \
                    quadratic = 0.05; \
                    start = 0; \
              }; \
          }; \
      }; \
  };
  #define LASREQ(NAME,PARENT) \
  class ##NAME## : ##PARENT## \
  { \
      class ItemInfo : InventoryFlashLightItem_Base_F {}; \
  };
  
  class InventoryFlashLightItem_Base_F;

  
  LIGHTCONF(acc_flashlight,ItemCore);
  LIGHTCONF(acc_flashlight_pistol,ItemCore);
  LIGHTCONF(acc_esd_01_flashlight,ItemCore);
  LIGHTCONF(CUP_acc_Flashlight,ItemCore);
  LIGHTCONF(cup_acc_llm01_f,ItemCore);
  LIGHTCONF(cup_acc_llm_flashlight,ItemCore);
  LIGHTCONF(CUP_acc_Glock17_Flashlight,ItemCore);
  LIGHTCONF(cup_acc_cz_m3x,CUP_acc_Flashlight);
  LIGHTCONF(CUP_acc_Zenit_2DS,ItemCore);
  class CUP_acc_ANPEQ_15_Flashlight_Tan_L : ItemCore
  {
      class ItemInfo : InventoryFlashLightItem_Base_F {};
  };
  LASREQ(CUP_acc_ANPEQ_15_Flashlight_Black_L,CUP_acc_ANPEQ_15_Flashlight_Tan_L);
  LASREQ(CUP_acc_ANPEQ_15_Flashlight_OD_L,CUP_acc_ANPEQ_15_Flashlight_Tan_L);
  LIGHTCONF(CUP_acc_ANPEQ_15_Flashlight_Tan_F,CUP_acc_ANPEQ_15_Flashlight_Tan_L);
  LIGHTCONF(CUP_acc_ANPEQ_15_Flashlight_Black_F,CUP_acc_ANPEQ_15_Flashlight_Black_L);
  LIGHTCONF(CUP_acc_ANPEQ_15_Flashlight_OD_F,CUP_acc_ANPEQ_15_Flashlight_OD_L);
  LASREQ(CUP_acc_ANPEQ_15_Top_Flashlight_Black_L,CUP_acc_ANPEQ_15_Flashlight_Tan_L);
  LASREQ(CUP_acc_ANPEQ_15_Top_Flashlight_OD_L,CUP_acc_ANPEQ_15_Flashlight_Tan_L);
  LASREQ(CUP_acc_ANPEQ_15_Top_Flashlight_Tan_L,CUP_acc_ANPEQ_15_Flashlight_Tan_L);
  LIGHTCONF(CUP_acc_ANPEQ_15_Top_Flashlight_Black_F,CUP_acc_ANPEQ_15_Top_Flashlight_Black_L);
  LIGHTCONF(CUP_acc_ANPEQ_15_Top_Flashlight_OD_F,CUP_acc_ANPEQ_15_Top_Flashlight_OD_L);
  LIGHTCONF(CUP_acc_ANPEQ_15_Top_Flashlight_Tan_F,CUP_acc_ANPEQ_15_Top_Flashlight_Tan_L);
  class CUP_acc_ANPEQ_2_Flashlight_Black_L : ItemCore
  {
      class ItemInfo : InventoryFlashLightItem_Base_F {};
  };
  LASREQ(CUP_acc_ANPEQ_2_Flashlight_Coyote_L,CUP_acc_ANPEQ_2_Flashlight_Black_L);
  LASREQ(CUP_acc_ANPEQ_2_Flashlight_OD_L,CUP_acc_ANPEQ_2_Flashlight_Black_L);
  LIGHTCONF(CUP_acc_ANPEQ_2_Flashlight_Black_F,CUP_acc_ANPEQ_2_Flashlight_Black_L);
  LIGHTCONF(CUP_acc_ANPEQ_2_Flashlight_Coyote_F,CUP_acc_ANPEQ_2_Flashlight_Coyote_L);
  LIGHTCONF(CUP_acc_ANPEQ_2_Flashlight_OD_F,CUP_acc_ANPEQ_2_Flashlight_OD_L);
  
#if __has_include("\rhsafrf\addons\rhs_c_weapons\script_component.hpp")
  class rhs_acc_2dpZenit : acc_flashlight
  {
      class ItemInfo : InventoryFlashLightItem_Base_F
      {
          class FlashLight : FlashLight
          {
              coneFadeCoef = 10;
              flareMaxDistance = 300;
              flareSize = 4;
              innerAngle = 10;
              intensity = 4000;
              outerAngle = 80;
              scale[] = {0};
              class Attenuation
              {
                    constant = 32;
                    hardLimitEnd = 105;
                    hardLimitStart = 15;
                    linear = 1;
                    quadratic = 0.05;
                    start = 0;                
              };
          };
      };
  };
  class rhs_acc_perst3;
  LASREQ(rhs_acc_perst3_2dp,rhs_acc_perst3);
  class rhs_acc_perst3_2dp_light : rhs_acc_perst3_2dp
  {
      class ItemInfo : InventoryFlashLightItem_Base_F
      {
          class FlashLight : FlashLight
          {
              coneFadeCoef = 10;
              flareMaxDistance = 300;
              flareSize = 4;
              innerAngle = 10;
              intensity = 4000;
              outerAngle = 80;
              scale[] = {0};
              class Attenuation
              {
                    constant = 32;
                    hardLimitEnd = 105;
                    hardLimitStart = 15;
                    linear = 1;
                    quadratic = 0.05;
                    start = 0;                
              };
          };
      };
  };
#else
#endif

  class acc_pointer_IR;/* : ItemCore {
	MRT_SwitchItemNextClass = "acc_pointer_IR";
	MRT_SwitchItemPrevClass = "acc_pointer_IR";
  };

  class ACE_acc_pointer_green_IR : acc_pointer_IR {
	MRT_SwitchItemNextClass = "ACE_acc_pointer_green_IR";
	MRT_SwitchItemPrevClass = "ACE_acc_pointer_green_IR";
  };*/

  /*/ oopsy added visble laser again lol
  class ACE_DBAL_A3_Red : acc_pointer_IR {
	MRT_SwitchItemPrevClass = "ACE_DBAL_A3_Red_II";
  };
  class ACE_DBAL_A3_Red_II : ACE_DBAL_A3_Red {
	MRT_SwitchItemNextClass = "ACE_DBAL_A3_Red";
  };
  class ACE_DBAL_A3_Green : ACE_DBAL_A3_Red {
	MRT_SwitchItemPrevClass = "ACE_DBAL_A3_Green_II";
  };
  class ACE_DBAL_A3_Green_II : ACE_DBAL_A3_Red_II {
	MRT_SwitchItemNextClass = "ACE_DBAL_A3_Green";
  };//*/

#if __has_include("\rhsafrf\addons\rhs_c_weapons\script_component.hpp")
  LASREQ(rhsusf_acc_anpeq15,acc_pointer_IR);
  LIGHTCONF(rhsusf_acc_anpeq15_light,rhsusf_acc_anpeq15);
  LIGHTCONF(rhsusf_acc_anpeq15_wmx_light,rhsusf_acc_anpeq15_light);
  LIGHTCONF(rhsusf_acc_anpeq16a_light,rhsusf_acc_anpeq15_light);
  LIGHTCONF(rhsusf_acc_M952V,rhsusf_acc_anpeq15_light);
  LIGHTCONF(rhsusf_acc_wmx,rhsusf_acc_M952V);
#else
#endif
  
  
  /*/ T1
  LIGHTCONFT1(Tier1_10_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_10_LA5_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_10_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_10_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_10_NGAL_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_10_NGAL_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_10_NGAL_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_10_NGAL_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_145_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_145_LA5_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_145_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_145_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_145_NGAL_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_145_NGAL_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_145_NGAL_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_145_NGAL_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_416_LA5_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_416_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_416_LA5_M600V_alt_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_416_LA5_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_416_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_416_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_416_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_M249_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M249_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M249_LA5_M603V_FL,acc_pointer_IR);  
  
  LIGHTCONFT1(Tier1_M300C,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M300C_Black,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_M4BII_LA5_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M4BII_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M4BII_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M4BII_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M4BII_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_M4BII_NGAL_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M4BII_NGAL_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M4BII_NGAL_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M4BII_NGAL_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M4BII_NGAL_M603V_FL,acc_pointer_IR);  
  
  LIGHTCONFT1(Tier1_M600V,acc_pointer_IR);
  LIGHTCONFT1(Tier1_M600V_Black,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_MCX_LA5_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MCX_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MCX_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MCX_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MCX_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_MCX_NGAL_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MCX_NGAL_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MCX_NGAL_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MCX_NGAL_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MCX_NGAL_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_Mk18_LA5_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk18_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk18_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk18_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk18_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_Mk18_NGAL_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk18_NGAL_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk18_NGAL_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk18_NGAL_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk18_NGAL_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_Mk46Mod0_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk46Mod0_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk46Mod0_LA5_M603V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk46Mod1_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk46Mod1_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk46Mod1_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_Mk48Mod0_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk48Mod0_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk48Mod0_LA5_M603V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk48Mod1_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk48Mod1_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_Mk48Mod1_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_MP7_LA5_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MP7_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MP7_NGAL_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MP7_NGAL_M300C_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_MW_LA5_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_LA5_M600V_alt_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_LA5_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_MW_NGAL_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_NGAL_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_NGAL_M600V_alt_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_NGAL_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_NGAL_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_NGAL_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_MW_NGAL_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_RAHG_LA5_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_LA5_M600V_alt_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_LA5_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_RAHG_NGAL_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_NGAL_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_NGAL_M600V_alt_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_NGAL_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_NGAL_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_NGAL_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_RAHG_NGAL_M603V_FL,acc_pointer_IR);  
  
  LIGHTCONFT1(Tier1_SCAR_LA5_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_SCAR_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_SCAR_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_SCAR_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_SCAR_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_SCAR_NGAL_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_SCAR_NGAL_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_SCAR_NGAL_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_SCAR_NGAL_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_SCAR_NGAL_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_URX4_LA5_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_LA5_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_LA5_M600V_alt_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_LA5_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_LA5_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_LA5_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_LA5_M603V_FL,acc_pointer_IR);
  
  LIGHTCONFT1(Tier1_URX4_NGAL_M300C_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_NGAL_M300C_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_NGAL_M600V_alt_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_NGAL_M600V_alt_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_NGAL_M600V_Black_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_NGAL_M600V_FL,acc_pointer_IR);
  LIGHTCONFT1(Tier1_URX4_NGAL_M603V_FL,acc_pointer_IR);  
  
  LIGHTCONFT1(tier1_dbalpl_fl,ItemCore);
  LIGHTCONFT1(tier1_tlr1,ItemCore);
  LIGHTCONFT1(Tier1_X300U,ItemCore);*/