class CfgPatches {
  class mjb_dzn_xpi_tweaks {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "Dzn XPI Tweaks";
	requiredAddons[]=
        {
            "dzn_xpi",
			"dzn_XPI_A3",
			"dzn_XPI_CUP",
			"ace_laserpointer",
			"ace_irlight"
        };
    skipWhenMissingDependencies = 1;
  };
};

/*/ disable vis laser in extended pointer modes menu
class CfgDznXPI {
	//class VisibleModes {
		delete VisibleLaser;
		delete VisibleLaser_x_Flashlight;
		delete VisibleLaser_x_Flashlight_Wide;
		class Flashlight_Wide {
			order = 0;
		};
		class Flashlight {
			order = 1;
		};
	};//
	class Bundles {
		class dzn_XPI_DBAL_Pointer {
			dzn_XPI_acc_DBAL_A3_V = 0;
		};
		
		#define DISABLE_VIS(var,var2) class CUP_##var { \
			CUP_acc_##var2##_V = 0; \
			CUP_acc_##var2##_VxL = 0; \
			CUP_acc_##var2##_VxLW = 0; \
		}
		class CUP_ANPEQ15_Black {
			CUP_acc_ANPEQ_15_Black_V = 0;
		};
		DISABLE_VIS(ANPEQ15_Black_Top,ANPEQ_15_Black_Top);
		DISABLE_VIS(ANPEQ15_OD,ANPEQ_15_OD);
		DISABLE_VIS(ANPEQ15_OD_Top,ANPEQ_15_OD_Top);
		DISABLE_VIS(ANPEQ15_Tan,ANPEQ_15);
		DISABLE_VIS(ANPEQ15_Tan_Top,ANPEQ_15_Tan_Top);
		DISABLE_VIS(ANPEQ15_TOPxFlashlight_Black,ANPEQ_15_TOP_Flashlight_Black);
		DISABLE_VIS(ANPEQ15_TOPxFlashlight_OD,ANPEQ_15_TOP_Flashlight_OD);
		DISABLE_VIS(ANPEQ15_TOPxFlashlight_Tan,ANPEQ_15_TOP_Flashlight_Tan);
		DISABLE_VIS(ANPEQ15xFlashlight_Black,ANPEQ_15_Flashlight_Black);
		DISABLE_VIS(ANPEQ15xFlashlight_OD,ANPEQ_15_Flashlight_OD);
		DISABLE_VIS(ANPEQ15xFlashlight_Tan,ANPEQ_15_Flashlight_Tan);
		//DISABLE_VIS(CUP_ANPEQ2_Black_Top);
		//DISABLE_VIS(CUP_ANPEQ2_Camo);
		//DISABLE_VIS(CUP_ANPEQ2_Coyote_Top);
		//DISABLE_VIS(CUP_ANPEQ2_desert);
		//DISABLE_VIS(CUP_ANPEQ2_grey);
		//DISABLE_VIS(CUP_ANPEQ2_OD_Top);
		DISABLE_VIS(ANPEQ2xFlashlight_Black,ANPEQ_2_Flashlight_Black);
		DISABLE_VIS(ANPEQ2xFlashlight_Coyote,ANPEQ_2_Flashlight_Coyote);
		DISABLE_VIS(ANPEQ2xFlashlight_OD,ANPEQ_2_Flashlight_OD);
		DISABLE_VIS(CZ_M3X,CZ_M3X);
		DISABLE_VIS(GlockTacticalLight,Glock17);
		DISABLE_VIS(LLM01,LLM01);
		DISABLE_VIS(LLM01_coyote,LLM01_coyote);
		DISABLE_VIS(LLM01_desert,LLM01_desert);
		DISABLE_VIS(LLM01_hex,LLM01_hex);
		DISABLE_VIS(LLM01_od,LLM01_od);
		DISABLE_VIS(LLM3,LLM);
		DISABLE_VIS(LLM3_black,LLM_black);
		DISABLE_VIS(LLM3_OD,LLM_OD);
		DISABLE_VIS(MLPLS,MLPLS_Laser);
	};
};
//*/

#define RIFLE_LASER_VISIBLE_GREEN	\
	class Pointer                   \
	{                               \
		beamMaxLength=20;           \
		beamThickness=0.035;        \
		beamColor[]={0,1,0};        \
		dotColor[]={0,383,0};       \
		IRdotSize=0.05;             \
	}

#define RIFLE_LASER_VISIBLE_RED		\
	class Pointer                   \
	{                               \
		beamMaxLength=20;           \
		beamThickness=0.035;        \
		beamColor[]={1,0,0};        \
		dotColor[]={383,0,0};       \
		IRdotSize=0.05;             \
	}

/*#define RIFLE_LASER_IR(POS,DIR)   \
	class Pointer                   \
	{                               \
		irDistance=5;               \
		irLaserEnd=Q(DIR);          \
		irLaserPos=Q(POS);          \
	}*/

class CfgWeapons {
	class ItemCore;
	class InventoryFlashLightItem_Base_F;
	class CUP_acc_ANPEQ_2;

	#define LASER_GREEN(VAR,BASE) class VAR : BASE { \
		class ItemInfo : InventoryFlashLightItem_Base_F { \
			RIFLE_LASER_VISIBLE_GREEN; \
		}; \
	}

	#define LASER_RED(VAR,BASE) class VAR : BASE { \
		class ItemInfo : InventoryFlashLightItem_Base_F { \
			RIFLE_LASER_VISIBLE_RED; \
		}; \
	}
	class dzn_XPI_acc_DBAL_A3_base;
	LASER_GREEN(dzn_XPI_acc_DBAL_A3_V,dzn_XPI_acc_DBAL_A3_base);


    class acc_pointer_IR : ItemCore {
        class ItemInfo;
    };

    class ACE_acc_pointer_red : acc_pointer_IR {
        class ItemInfo : ItemInfo {
            RIFLE_LASER_VISIBLE_RED;
        };
    };
    class ACE_acc_pointer_green : ACE_acc_pointer_red {
        class ItemInfo : ItemInfo {
            RIFLE_LASER_VISIBLE_GREEN;
        };
    };
	class ACE_DBAL_A3_Red;
    class ACE_DBAL_A3_Red_VP : ACE_DBAL_A3_Red {
        class ItemInfo: InventoryFlashLightItem_Base_F {
            RIFLE_LASER_VISIBLE_RED;
        };
    };
    class ACE_DBAL_A3_Green_VP : ACE_DBAL_A3_Red_VP {
        class ItemInfo : ItemInfo {
            RIFLE_LASER_VISIBLE_GREEN;
        };
    };

	class CUP_acc_ANPEQ_15;
	LASER_RED(CUP_acc_ANPEQ_15_V,CUP_acc_ANPEQ_15);
	class CUP_acc_ANPEQ_15_Black;
	LASER_RED(CUP_acc_ANPEQ_15_Black_V,CUP_acc_ANPEQ_15_Black);
	class CUP_acc_ANPEQ_15_OD;
	LASER_RED(CUP_acc_ANPEQ_15_OD_V,CUP_acc_ANPEQ_15_OD);
	class CUP_acc_ANPEQ_15_Tan_Top;
	LASER_RED(CUP_acc_ANPEQ_15_Tan_Top_V,CUP_acc_ANPEQ_15_Tan_Top);
	class CUP_acc_ANPEQ_15_Black_Top;
	LASER_RED(CUP_acc_ANPEQ_15_Black_Top_V,CUP_acc_ANPEQ_15_Black_Top);
	class CUP_acc_ANPEQ_15_OD_Top;
	LASER_RED(CUP_acc_ANPEQ_15_OD_Top_V,CUP_acc_ANPEQ_15_OD_Top);

	class CUP_acc_ANPEQ_2_Flashlight_Black_L;
	LASER_RED(CUP_acc_ANPEQ_2_Flashlight_Black_V,CUP_acc_ANPEQ_2_Flashlight_Black_L);
	LASER_RED(CUP_acc_ANPEQ_2_Flashlight_Black_VxLW,CUP_acc_ANPEQ_2_Flashlight_Black_L);
	LASER_RED(CUP_acc_ANPEQ_2_Flashlight_Black_VxL,CUP_acc_ANPEQ_2_Flashlight_Black_L);
	class CUP_acc_ANPEQ_2_Flashlight_Coyote_L;
	LASER_RED(CUP_acc_ANPEQ_2_Flashlight_Coyote_V,CUP_acc_ANPEQ_2_Flashlight_Coyote_L);
	LASER_RED(CUP_acc_ANPEQ_2_Flashlight_Coyote_VxLW,CUP_acc_ANPEQ_2_Flashlight_Coyote_L);
	LASER_RED(CUP_acc_ANPEQ_2_Flashlight_Coyote_VxL,CUP_acc_ANPEQ_2_Flashlight_Coyote_L);
	class CUP_acc_ANPEQ_2_Flashlight_OD_L;
	LASER_RED(CUP_acc_ANPEQ_2_Flashlight_OD_V,CUP_acc_ANPEQ_2_Flashlight_OD_L);
	LASER_RED(CUP_acc_ANPEQ_2_Flashlight_OD_VxLW,CUP_acc_ANPEQ_2_Flashlight_OD_L);
	LASER_RED(CUP_acc_ANPEQ_2_Flashlight_OD_VxL,CUP_acc_ANPEQ_2_Flashlight_OD_L);

	class CUP_acc_ANPEQ_15_Flashlight_Tan_L;
	LASER_RED(CUP_acc_ANPEQ_15_Flashlight_Tan_V,CUP_acc_ANPEQ_15_Flashlight_Tan_L);
	LASER_RED(CUP_acc_ANPEQ_15_Flashlight_Tan_VxLW,CUP_acc_ANPEQ_15_Flashlight_Tan_L);
	LASER_RED(CUP_acc_ANPEQ_15_Flashlight_Tan_VxL,CUP_acc_ANPEQ_15_Flashlight_Tan_L);
	class CUP_acc_ANPEQ_15_Flashlight_OD_L;
	LASER_RED(CUP_acc_ANPEQ_15_Flashlight_OD_V,CUP_acc_ANPEQ_15_Flashlight_OD_L);
	LASER_RED(CUP_acc_ANPEQ_15_Flashlight_OD_VxLW,CUP_acc_ANPEQ_15_Flashlight_OD_L);
	LASER_RED(CUP_acc_ANPEQ_15_Flashlight_OD_VxL,CUP_acc_ANPEQ_15_Flashlight_OD_L);
	class CUP_acc_ANPEQ_15_Flashlight_Black_L;
	LASER_RED(CUP_acc_ANPEQ_15_Flashlight_Black_V,CUP_acc_ANPEQ_15_Flashlight_Black_L);
	LASER_RED(CUP_acc_ANPEQ_15_Flashlight_Black_VxLW,CUP_acc_ANPEQ_15_Flashlight_Black_L);
	LASER_RED(CUP_acc_ANPEQ_15_Flashlight_Black_VxL,CUP_acc_ANPEQ_15_Flashlight_Black_L);

	class CUP_acc_ANPEQ_15_Top_Flashlight_Tan_L;
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_Tan_V,CUP_acc_ANPEQ_15_Top_Flashlight_Tan_L);
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_Tan_VxLW,CUP_acc_ANPEQ_15_Top_Flashlight_Tan_L);
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_Tan_VxL,CUP_acc_ANPEQ_15_Top_Flashlight_Tan_L);
	class CUP_acc_ANPEQ_15_Top_Flashlight_OD_L;
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_OD_V,CUP_acc_ANPEQ_15_Top_Flashlight_OD_L);
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_OD_VxLW,CUP_acc_ANPEQ_15_Top_Flashlight_OD_L);
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_OD_VxL,CUP_acc_ANPEQ_15_Top_Flashlight_OD_L);
	class CUP_acc_ANPEQ_15_Top_Flashlight_Black_L;
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_Black_V,CUP_acc_ANPEQ_15_Top_Flashlight_Black_L);
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_Black_VxLW,CUP_acc_ANPEQ_15_Top_Flashlight_Black_L);
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_Black_VxL,CUP_acc_ANPEQ_15_Top_Flashlight_Black_L);

	class CUP_acc_CZ_M3X;
	LASER_RED(CUP_acc_CZ_M3X_V,CUP_acc_CZ_M3X);
	LASER_RED(CUP_acc_CZ_M3X_VxL,CUP_acc_CZ_M3X);

	class CUP_acc_MLPLS_Laser;
	LASER_GREEN(CUP_acc_MLPLS_Laser_V,CUP_acc_MLPLS_Laser);

	class CUP_acc_Glock17_Flashlight;
	LASER_GREEN(CUP_acc_Glock17_V,CUP_acc_Glock17_Flashlight);
	LASER_GREEN(CUP_acc_Glock17_VxL,CUP_acc_Glock17_Flashlight);

	class CUP_acc_LLM01_L;
	LASER_GREEN(CUP_acc_LLM01_V,CUP_acc_LLM01_L);
	LASER_GREEN(CUP_acc_LLM01_VxLW,CUP_acc_LLM01_L);
	LASER_GREEN(CUP_acc_LLM01_desert_V,CUP_acc_LLM01_V);
	class CUP_acc_LLM01_desert_L;
	LASER_GREEN(CUP_acc_LLM01_desert_VxLW,CUP_acc_LLM01_desert_L);
	LASER_GREEN(CUP_acc_LLM01_hex_V,CUP_acc_LLM01_V);
	class CUP_acc_LLM01_hex_L;
	LASER_GREEN(CUP_acc_LLM01_hex_VxLW,CUP_acc_LLM01_hex_L);
	LASER_GREEN(CUP_acc_LLM01_od_V,CUP_acc_LLM01_V);
	class CUP_acc_LLM01_od_L;
	LASER_GREEN(CUP_acc_LLM01_od_VxLW,CUP_acc_LLM01_od_L);
	LASER_GREEN(CUP_acc_LLM01_coyote_V,CUP_acc_LLM01_V);
	class CUP_acc_LLM01_coyote_L;
	LASER_GREEN(CUP_acc_LLM01_coyote_VxLW,CUP_acc_LLM01_coyote_L);

	class CUP_acc_LLM;
	LASER_GREEN(CUP_acc_LLM_V,CUP_acc_LLM);
	LASER_GREEN(CUP_acc_LLM_VxLW,CUP_acc_LLM);
	LASER_GREEN(CUP_acc_LLM_VxL,CUP_acc_LLM);
	class CUP_acc_LLM_black;
	LASER_GREEN(CUP_acc_LLM_black_V,CUP_acc_LLM_V);
	LASER_GREEN(CUP_acc_LLM_black_VxLW,CUP_acc_LLM_black);
	LASER_GREEN(CUP_acc_LLM_black_VxL,CUP_acc_LLM_black);
	class CUP_acc_LLM_od;
	LASER_GREEN(CUP_acc_LLM_od_V,CUP_acc_LLM_V);
	LASER_GREEN(CUP_acc_LLM_od_VxLW,CUP_acc_LLM_od);
	LASER_GREEN(CUP_acc_LLM_od_VxL,CUP_acc_LLM_od);
};