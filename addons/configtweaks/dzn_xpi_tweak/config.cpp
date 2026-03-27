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

#define Q(var) #var

// --- XPI Types
#define XPI_T_VISIBLE VisibleModes
#define XPI_T_IR IRModes


// --- XPI Modes
#define XPI_M_IR_LASER IRLaser
#define XPI_M_IR_ILLUM IRIlluminator
#define XPI_M_IR_ILLUM_W IRIlluminator_Wide
#define XPI_M_IR_LASER_x_IR_ILLUM IRLaser_x_IRIlluminator
#define XPI_M_IR_LASER_x_IR_ILLUM_W IRLaser_x_IRIlluminator_Wide
#define XPI_M_IR_LIGHT IRFlashlight
#define XPI_M_IR_LIGHT_WIDE IRFlashlight_Wide
#define XPI_M_VISIBLE_LASER VisibleLaser
#define XPI_M_LIGHT Flashlight
#define XPI_M_LIGHT_W Flashlight_Wide
#define XPI_M_VISIBLE_LASER_x_LIGTH VisibleLaser_x_Flashlight
#define XPI_M_VISIBLE_LASER_x_LIGTH_WIDE VisibleLaser_x_Flashlight_Wide
#define XPI_M_IR_ILLUM_POINTER IRIlluminatorPointer

class CfgDznXPI {
// disable vis laser in extended pointer modes menu
	/*/class VisibleModes {
		delete VisibleLaser;
		delete VisibleLaser_x_Flashlight;
		delete VisibleLaser_x_Flashlight_Wide;
		class Flashlight_Wide {
			order = 0;
		};
		class Flashlight {
			order = 1;
		};
	};/*/
	class Bundles {
/*/ disable vis laser in extended pointer modes menu
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
//*/

		// MCC MRT_switchItemHintText = "IR Combo-Far";
		#define MCC_LASER(var) class var { \
			var##IRC = 1; \
			var##IRCF = 1; \
			var##IRL = 1; \
			var##IRT = 1; \
			var##VISL = 1; \
		}

		// Laser
		MCC_LASER(MCC_AK_LA30_);
		MCC_LASER(MCC_AR_LA30_);
		MCC_LASER(MCC_AR18_LA30_);
		MCC_LASER(MCC_L3Squad_AK_Top_);
		MCC_LASER(MCC_L3Squad_AR_Top_);
		MCC_LASER(MCC_L3Squad_AR18_Top_);
		MCC_LASER(MCC_L3Squad_);
		MCC_LASER(MCC_LA30_);
		MCC_LASER(MCC_NGAL_AK_Top_);
		MCC_LASER(MCC_NGAL_AR_Top_);
		MCC_LASER(MCC_NGAL_AR18_Top_);
		MCC_LASER(MCC_NGAL_);
		MCC_LASER(MCC_OGL_AK_Top_BLK_);
		MCC_LASER(MCC_OGL_AK_Top_FDE_);
		MCC_LASER(MCC_OGL_AR_Top_BLK_);
		MCC_LASER(MCC_OGL_AR_Top_FDE_);
		MCC_LASER(MCC_OGL_AR18_Top_BLK_);
		MCC_LASER(MCC_OGL_AR18_Top_FDE_);
		MCC_LASER(MCC_OGL_BLK_);
		MCC_LASER(MCC_OGL_FDE_);
		MCC_LASER(MCC_PEQ15_AK_Top_BLK_);
		MCC_LASER(MCC_PEQ15_AK_Top_FDE_);
		MCC_LASER(MCC_PEQ15_AR_Top_BLK_);
		MCC_LASER(MCC_PEQ15_AR_Top_FDE_);
		MCC_LASER(MCC_PEQ15_AR18_Top_BLK_);
		MCC_LASER(MCC_PEQ15_AR18_Top_FDE_);
		MCC_LASER(MCC_PEQ15_BLK_);
		MCC_LASER(MCC_PEQ15_FDE_);

		// Flashlight
		class MCC_M600V_BLK {
			MCC_M600V_BLK = 1;
			MCC_M600V_IR_BLK = 1;
		};
		class MCC_M600V_FDE {
			MCC_M600V_FDE = 1;
			MCC_M600V_IR_FDE = 1;
		};
		class MCC_M300C_BLK {
			MCC_M300C_BLK = 1;
			MCC_M300C_IR_BLK = 1;
		};
		class MCC_M300C_FDE {
			MCC_M300C_FDE = 1;
			MCC_M300C_IR_FDE = 1;
		};
		class MCC_WMLX_BLK {
			MCC_WMLX_BLK = 1;
			MCC_WMLX_IR_BLK = 1;
		};
		class MCC_WMLX_FDE {
			MCC_WMLX_FDE = 1;
			MCC_WMLX_IR_FDE = 1;
		};

		#define MCC_COMBO(var) class var { \
			var##IRC = 1; \
			var##IRCF = 1; \
			var##IRL = 1; \
			var##IRT = 1; \
			var##VISC = 1; \
			var##VISL = 1; \
			var##WL = 1; \
		}
		MCC_COMBO(MCC_AK_NGAL_M600V_BLK_);
		MCC_COMBO(MCC_AK_NGAL_M600V_FDE_);
		MCC_COMBO(MCC_AK_OGL_WMLX_BLK_);
		MCC_COMBO(MCC_AK_OGL_WMLX_FDE_);
		MCC_COMBO(MCC_AK_PEQ15_M300C_BLK_);
		MCC_COMBO(MCC_AK_PEQ15_M300C_FDE_);
		MCC_COMBO(MCC_AR_LA30_M600V_BLK_);
		MCC_COMBO(MCC_AR_LA30_M600V_FDE_);
		MCC_COMBO(MCC_AR_LA30_M600V_Tail_BLK_);
		MCC_COMBO(MCC_AR_LA30_M600V_Tail_FDE_);
		MCC_COMBO(MCC_AR_NGAL_M600V_BLK_);
		MCC_COMBO(MCC_AR_NGAL_M600V_FDE_);
		MCC_COMBO(MCC_AR_NGAL_M600V_Tail_BLK_);
		MCC_COMBO(MCC_AR_NGAL_M600V_Tail_FDE_);
		MCC_COMBO(MCC_AR_OGL_WMLX_BLK_);
		MCC_COMBO(MCC_AR_OGL_WMLX_FDE_);
		MCC_COMBO(MCC_AR_PEQ15_M300C_BLK_);
		MCC_COMBO(MCC_AR_PEQ15_M300C_FDE_);
		MCC_COMBO(MCC_AR_PEQ15_M300C_Tail_BLK_);
		MCC_COMBO(MCC_AR_PEQ15_M300C_Tail_FDE_);
		MCC_COMBO(MCC_AR18_LA30_M600V_BLK_);
		MCC_COMBO(MCC_AR18_LA30_M600V_FDE_);
		MCC_COMBO(MCC_AR18_LA30_M600V_Tail_BLK_);
		MCC_COMBO(MCC_AR18_LA30_M600V_Tail_FDE_);
		MCC_COMBO(MCC_AR18_NGAL_M600V_BLK_);
		MCC_COMBO(MCC_AR18_NGAL_M600V_FDE_);
		MCC_COMBO(MCC_AR18_NGAL_M600V_Tail_BLK_);
		MCC_COMBO(MCC_AR18_NGAL_M600V_Tail_FDE_);
		MCC_COMBO(MCC_AR18_OGL_WMLX_BLK_);
		MCC_COMBO(MCC_AR18_OGL_WMLX_FDE_);
		MCC_COMBO(MCC_AR18_PEQ15_M300C_BLK_);
		MCC_COMBO(MCC_AR18_PEQ15_M300C_FDE_);
		MCC_COMBO(MCC_AR18_PEQ15_M300C_Tail_BLK_);
		MCC_COMBO(MCC_AR18_PEQ15_M300C_Tail_FDE_);
		MCC_COMBO(MCC_PEQ16_AK_TOP_);
		MCC_COMBO(MCC_PEQ16_AR_TOP_);
		MCC_COMBO(MCC_PEQ16_AR18_TOP_);
		MCC_COMBO(MCC_PEQ16_);
		MCC_COMBO(MCC_VarioRay_AK_TOP_);
		MCC_COMBO(MCC_VarioRay_AR_TOP_);
		MCC_COMBO(MCC_VarioRay_AR18_TOP_);
		MCC_COMBO(MCC_VarioRay_);
	};
};

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
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_Tan_F_VxLW,CUP_acc_ANPEQ_15_Top_Flashlight_Tan_L);
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_Tan_F_VxL,CUP_acc_ANPEQ_15_Top_Flashlight_Tan_L);
	class CUP_acc_ANPEQ_15_Top_Flashlight_OD_L;
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_OD_V,CUP_acc_ANPEQ_15_Top_Flashlight_OD_L);
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_OD_F_VxLW,CUP_acc_ANPEQ_15_Top_Flashlight_OD_L);
	LASER_RED(CUP_acc_ANPEQ_15_Top_Flashlight_OD_F_VxL,CUP_acc_ANPEQ_15_Top_Flashlight_OD_L);
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

	// MCC
//#if __has_include
	#define VARTWO(var,var2) var##var2
	#define MCC_LASER(var,var2) class var##var2##IRL : ItemCore { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_IR); \
			mode = Q(XPI_M_IR_LASER); \
		}; \
	}; \
	class var##var2##IRC : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_IR); \
			mode = Q(XPI_M_IR_LASER_x_IR_ILLUM_W); \
		}; \
	}; \
	class var##var2##IRCF : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_IR); \
			mode = Q(XPI_M_IR_LASER_x_IR_ILLUM); \
		}; \
	}; \
	class var##var2##IRT : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_IR); \
			mode = Q(XPI_M_IR_ILLUM); \
		}; \
	}; \
	class var##var2##VISC : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_VISIBLE); \
			mode = Q(XPI_M_VISIBLE_LASER_x_LIGTH); \
		}; \
	}; \
	class var##var2##VISL : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_VISIBLE); \
			mode = Q(XPI_M_VISIBLE_LASER); \
		}; \
	};

	// Laser
		MCC_LASER(MCC_AK_LA30,_);
		MCC_LASER(MCC_AR_LA30,_);
		MCC_LASER(MCC_AR18_LA30,_);
		MCC_LASER(MCC_L3Squad_AK_Top,_);
		MCC_LASER(MCC_L3Squad_AR_Top,_);
		MCC_LASER(MCC_L3Squad_AR18_Top,_);
		MCC_LASER(MCC_L3Squad,_);
		MCC_LASER(MCC_LA30,_);
		MCC_LASER(MCC_NGAL_AK_Top,_);
		MCC_LASER(MCC_NGAL_AR_Top,_);
		MCC_LASER(MCC_NGAL_AR18_Top,_);
		MCC_LASER(MCC_NGAL,_);
		MCC_LASER(MCC_OGL_AK_Top,_BLK_);
		MCC_LASER(MCC_OGL_AK_Top,_FDE_);
		MCC_LASER(MCC_OGL_AR_Top,_BLK_);
		MCC_LASER(MCC_OGL_AR_Top,_FDE_);
		MCC_LASER(MCC_OGL_AR18_Top,_BLK_);
		MCC_LASER(MCC_OGL_AR18_Top,_FDE_);
		MCC_LASER(MCC_OGL,_BLK_);
		MCC_LASER(MCC_OGL,_FDE_);
		MCC_LASER(MCC_PEQ15_AK_Top,_BLK_);
		MCC_LASER(MCC_PEQ15_AK_Top,_FDE_);
		MCC_LASER(MCC_PEQ15_AR_Top,_BLK_);
		MCC_LASER(MCC_PEQ15_AR_Top,_FDE_);
		MCC_LASER(MCC_PEQ15_AR18_Top,_BLK_);
		MCC_LASER(MCC_PEQ15_AR18_Top,_FDE_);
		MCC_LASER(MCC_PEQ15,_BLK_);
		MCC_LASER(MCC_PEQ15,_FDE_);

	// flashlights
	class MCC_M600V_BLK : ItemCore {
		class dzn_XPI {
			bundle = "MCC_M600V_BLK";
			type=Q(XPI_T_VISIBLE);
			mode = Q(XPI_M_LIGHT);
		};
	};
	class MCC_M600V_IR_BLK : MCC_M600V_BLK {
		class dzn_XPI {
			bundle = "MCC_M600V_BLK";
			type=Q(XPI_T_IR);
			mode = Q(XPI_M_IR_LIGHT);
		};
	};
	class MCC_M600V_FDE : ItemCore {
		class dzn_XPI {
			bundle = "MCC_M600V_FDE";
			type=Q(XPI_T_VISIBLE);
			mode = Q(XPI_M_LIGHT);
		};
	};
	class MCC_M600V_IR_FDE : MCC_M600V_FDE {
		class dzn_XPI {
			bundle = "MCC_M600V_FDE";
			type=Q(XPI_T_IR);
			mode = Q(XPI_M_IR_LIGHT);
		};
	};

	class MCC_M300C_BLK : ItemCore {
		class dzn_XPI {
			bundle = "MCC_M300C_BLK";
			type=Q(XPI_T_VISIBLE);
			mode = Q(XPI_M_LIGHT);
		};
	};
	class MCC_M300C_IR_BLK : MCC_M300C_BLK {
		class dzn_XPI {
			bundle = "MCC_M300C_BLK";
			type=Q(XPI_T_IR);
			mode = Q(XPI_M_IR_LIGHT);
		};
	};
	class MCC_M300C_FDE : ItemCore {
		class dzn_XPI {
			bundle = "MCC_M300C_FDE";
			type=Q(XPI_T_VISIBLE);
			mode = Q(XPI_M_LIGHT);
		};
	};
	class MCC_M300C_IR_FDE : MCC_M300C_FDE {
		class dzn_XPI {
			bundle = "MCC_M300C_FDE";
			type=Q(XPI_T_IR);
			mode = Q(XPI_M_IR_LIGHT);
		};
	};

	class MCC_WMLX_BLK : ItemCore {
		class dzn_XPI {
			bundle = "MCC_WMLX_BLK";
			type=Q(XPI_T_VISIBLE);
			mode = Q(XPI_M_LIGHT);
		};
	};
	class MCC_WMLX_IR_BLK : MCC_WMLX_BLK {
		class dzn_XPI {
			bundle = "MCC_WMLX_BLK";
			type=Q(XPI_T_IR);
			mode = Q(XPI_M_IR_LIGHT);
		};
	};
	class MCC_WMLX_FDE : ItemCore {
		class dzn_XPI {
			bundle = "MCC_WMLX_FDE";
			type=Q(XPI_T_VISIBLE);
			mode = Q(XPI_M_LIGHT);
		};
	};
	class MCC_WMLX_IR_FDE : MCC_WMLX_FDE {
		class dzn_XPI {
			bundle = "MCC_WMLX_FDE";
			type=Q(XPI_T_IR);
			mode = Q(XPI_M_IR_LIGHT);
		};
	};

// combos don't have a wide/spotlight for IR light only
	#define MCC_COMBO(var,var2) class var##var2##IRL : ItemCore { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_IR); \
			mode = Q(XPI_M_IR_LASER); \
		}; \
	}; \
	class var##var2##IRC : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_IR); \
			mode = Q(XPI_M_IR_LASER_x_IR_ILLUM_W); \
		}; \
	}; \
	class var##var2##IRCF : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_IR); \
			mode = Q(XPI_M_IR_LASER_x_IR_ILLUM); \
		}; \
	}; \
	class var##var2##IRT : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_IR); \
			mode = Q(XPI_M_IR_ILLUM); \
		}; \
	}; \
	class var##var2##VISC : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_VISIBLE); \
			mode = Q(XPI_M_VISIBLE_LASER_x_LIGTH); \
		}; \
	}; \
	class var##var2##VISL : var##var2##IRL { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_VISIBLE); \
			mode = Q(XPI_M_VISIBLE_LASER); \
		}; \
	}; \
	class var##var2##WL : ItemCore { \
		class dzn_XPI { \
			bundle = Q(VARTWO(var,var2)); \
			type=Q(XPI_T_VISIBLE); \
			mode = Q(XPI_M_LIGHT); \
		}; \
	};

	MCC_COMBO(MCC_AK_NGAL_M600V,_BLK_);
	MCC_COMBO(MCC_AK_NGAL_M600V,_FDE_);
	MCC_COMBO(MCC_AK_OGL_WMLX,_BLK_);
	MCC_COMBO(MCC_AK_OGL_WMLX,_FDE_);
	MCC_COMBO(MCC_AK_PEQ15_M300C,_BLK_);
	MCC_COMBO(MCC_AK_PEQ15_M300C,_FDE_);
	MCC_COMBO(MCC_AR_LA30_M600V,_BLK_);
	MCC_COMBO(MCC_AR_LA30_M600V,_FDE_);
	MCC_COMBO(MCC_AR_LA30_M600V_Tail,_BLK_);
	MCC_COMBO(MCC_AR_LA30_M600V_Tail,_FDE_);
	MCC_COMBO(MCC_AR_NGAL_M600V,_BLK_);
	MCC_COMBO(MCC_AR_NGAL_M600V,_FDE_);
	MCC_COMBO(MCC_AR_NGAL_M600V_Tail,_BLK_);
	MCC_COMBO(MCC_AR_NGAL_M600V_Tail,_FDE_);
	MCC_COMBO(MCC_AR_OGL_WMLX,_BLK_);
	MCC_COMBO(MCC_AR_OGL_WMLX,_FDE_);
	MCC_COMBO(MCC_AR_PEQ15_M300C,_BLK_);
	MCC_COMBO(MCC_AR_PEQ15_M300C,_FDE_);
	MCC_COMBO(MCC_AR_PEQ15_M300C_Tail,_BLK_);
	MCC_COMBO(MCC_AR_PEQ15_M300C_Tail,_FDE_);
	MCC_COMBO(MCC_AR18_LA30_M600V,_BLK_);
	MCC_COMBO(MCC_AR18_LA30_M600V,_FDE_);
	MCC_COMBO(MCC_AR18_LA30_M600V_Tail,_BLK_);
	MCC_COMBO(MCC_AR18_LA30_M600V_Tail,_FDE_);
	MCC_COMBO(MCC_AR18_NGAL_M600V,_BLK_);
	MCC_COMBO(MCC_AR18_NGAL_M600V,_FDE_);
	MCC_COMBO(MCC_AR18_NGAL_M600V_Tail,_BLK_);
	MCC_COMBO(MCC_AR18_NGAL_M600V_Tail,_FDE_);
	MCC_COMBO(MCC_AR18_OGL_WMLX,_BLK_);
	MCC_COMBO(MCC_AR18_OGL_WMLX,_FDE_);
	MCC_COMBO(MCC_AR18_PEQ15_M300C,_BLK_);
	MCC_COMBO(MCC_AR18_PEQ15_M300C,_FDE_);
	MCC_COMBO(MCC_AR18_PEQ15_M300C_Tail,_BLK_);
	MCC_COMBO(MCC_AR18_PEQ15_M300C_Tail,_FDE_);

	MCC_COMBO(MCC_PEQ16_AK_TOP,_);
	MCC_COMBO(MCC_PEQ16_AR_TOP,_);
	MCC_COMBO(MCC_PEQ16_AR18_TOP,_);
	MCC_COMBO(MCC_PEQ16,_);
	MCC_COMBO(MCC_VarioRay_AK_TOP,_);
	MCC_COMBO(MCC_VarioRay_AR_TOP,_);
	MCC_COMBO(MCC_VarioRay_AR18_TOP,_);
	MCC_COMBO(MCC_VarioRay,_);
};