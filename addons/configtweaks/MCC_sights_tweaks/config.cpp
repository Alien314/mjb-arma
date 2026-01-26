class CfgPatches {
  class mjb_mcc_sights_tweaks {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Momo";
    name = "MCC sights tweaks";
	requiredAddons[]=
        {
            "MCC_RD",//weapons[] = {"MCC_MicroT2","MCC_MicroT2_Down","MCC_MicroT2_Up","MCC_EXPS3_BLK","MCC_EXPS3_BLK_Down","MCC_EXPS3_BLK_Up","MCC_EXPS3_FDE","MCC_EXPS3_FDE_Down","MCC_EXPS3_FDE_Up","MCC_Romeo9t_blk","MCC_Romeo9t_fde","MCC_Romeo9t_BLK_Down","MCC_Romeo9T_BLK_Up","MCC_Romeo9T_FDE_Down","MCC_Romeo9T_FDE_Up"};
            "MCC_LPVO",//weapons[] = {"MCC_Vortex_Elanor_Acro_BLK","MCC_Vortex_Elanor_Acro_FDE","MCC_Vortex_Elanor_Acro_TAN","MCC_Mark5_10_BLK","MCC_Mark5_10_FDE","MCC_Trijicon_VCOG_18","MCC_ZCO_10_BLK_DMR"};
            "MCC_ERD"//weapons[] = {"MCC_GBRS_T2_FDE","MCC_GBRS_T2_Mag_Down_FDE","MCC_GBRS_T2_Mag_Up_FDE","MCC_GBRS_T2_Mag_Up_BLK","MCC_GBRS_EXPS3_FDE","MCC_GBRS_EXPS3_Mag_Down_FDE","MCC_GBRS_EXPS3_Mag_Up_FDE","MCC_GBRS_EXPS3_Mag_Up_BLK","MCC_MicroT2_UnityX_BLK","MCC_MicroT2_UnityX_FDE","MCC_MicroT2_UnityX_BLK_Down","MCC_MicroT2_UnityX_BLK_Up","MCC_MicroT2_UnityX_FDE_Down","MCC_MicroT2_UnityX_FDE_Up","MCC_EXPS3_UnityX_BLK","MCC_EXPS3_UnityX_BLK_Down","MCC_EXPS3_UnityX_BLK_Up","MCC_EXPS3_UnityX_FDE","MCC_EXPS3_UnityX_FDE_Down","MCC_EXPS3_UnityX_FDE_Up"};
        };
    skipWhenMissingDependencies = 1;
  };
};

class CfgWeapons {
	// Base classes
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	
	// Macro: Sights Red Dots
	#define MCC_DOT(var) class var : ItemCore { \
		class ItemInfo : InventoryOpticsItem_Base_F { \
	    	class OpticsModes { \
				class Aco { \
	        		discreteDistance[] = {100}; \
	        		discreteDistanceInitIndex = 0; \
				}; \
			}; \
		}; \
	};
	
	// Macro: Sights optics Down. (base,var reversed)
	#define MCC_DWN(base,var) class var : base { \
			class ItemInfo : InventoryOpticsItem_Base_F { \
	      		class OpticsModes { \
					class Aco { \
						discreteDistance[] = {100}; \
						discreteDistanceInitIndex = 0; \
					}; \
	    		}; \
	  		}; \
		}
	
	// Macro: Sights optics Up.
	#define MCC_UP(var,base) class var : base { \
			class ItemInfo : InventoryOpticsItem_Base_F { \
	      		class OpticsModes { \
	        		class Magnified { \
	          			discreteDistance[] = {300}; \
	          			discreteDistanceInitIndex = 0; \
	      			}; \
	    		}; \
	  		}; \
		}
	
	// 1x / red dots
	MCC_DOT(MCC_EXPS3_BLK);
	MCC_DOT(MCC_EXPS3_FDE);
	MCC_DOT(MCC_GBRS_EXPS3_FDE);
	MCC_DOT(MCC_Romeo9t_blk);
	MCC_DOT(MCC_Romeo9t_fde);
	MCC_DOT(MCC_MicroT2);
	MCC_DOT(MCC_MicroT2_UnityX_BLK);
	MCC_DOT(MCC_GBRS_T2_FDE);
	//MCC_DWN(MCC_GBRS_T2_FDE,MCC_GBRS_T2_BLK);
	//MCC_DWN(MCC_MicroT2_UnityX_BLK,MCC_MicroT2_UnityX_FDE);
	//MCC_DWN(MCC_GBRS_EXPS3_FDE,MCC_GBRS_EXPS3_BLK);

	// 1x / optics down
	MCC_DWN(MCC_EXPS3_BLK,MCC_EXPS3_BLK_Down);
	MCC_DWN(MCC_EXPS3_FDE,MCC_EXPS3_FDE_Down);
	MCC_DWN(MCC_GBRS_EXPS3_FDE,MCC_GBRS_EXPS3_Mag_Down_FDE);
	//MCC_DWN(MCC_GBRS_EXPS3_Mag_Down_FDE,MCC_GBRS_EXPS3_Mag_Down_BLK);
	//MCC_DWN(MCC_EXPS3_BLK_Down,MCC_EXPS3_UnityX_BLK_Down);
	//MCC_DWN(MCC_EXPS3_FDE_Down,MCC_EXPS3_UnityX_FDE_Down);
	MCC_DWN(MCC_Romeo9t_blk,MCC_Romeo9t_BLK_Down);
	MCC_DWN(MCC_Romeo9t_fde,MCC_Romeo9T_FDE_Down);
	MCC_DWN(MCC_MicroT2,MCC_MicroT2_Down);
	MCC_DWN(MCC_MicroT2,MCC_MicroT2_UnityX_BLK_Down);
	MCC_DWN(MCC_MicroT2,MCC_MicroT2_UnityX_FDE_Down);
	MCC_DWN(MCC_GBRS_EXPS3_FDE,MCC_GBRS_T2_Mag_Down_FDE);
	//MCC_DWN(MCC_GBRS_T2_Mag_Down_FDE,MCC_GBRS_T2_Mag_Down_BLK);
	class MCC_GBRS_EXPS3_Mag_Down_BLK;
	class MCC_EXPS3_UnityX_BLK_Down;
	class MCC_EXPS3_UnityX_FDE_Down;
	class MCC_GBRS_T2_Mag_Down_BLK;
	
	// 3x / optics up
	MCC_UP(MCC_EXPS3_BLK_Up,MCC_EXPS3_BLK_Down);
	MCC_UP(MCC_EXPS3_FDE_Up,MCC_EXPS3_FDE_Down);
	MCC_UP(MCC_GBRS_EXPS3_Mag_Up_BLK,MCC_GBRS_EXPS3_Mag_Down_BLK);
	MCC_UP(MCC_GBRS_EXPS3_Mag_Up_FDE,MCC_GBRS_EXPS3_Mag_Down_FDE);
	MCC_UP(MCC_EXPS3_UnityX_BLK_Up,MCC_EXPS3_UnityX_BLK_Down);
	MCC_UP(MCC_EXPS3_UnityX_FDE_Up,MCC_EXPS3_UnityX_FDE_Down);
	MCC_UP(MCC_Romeo9t_BLK_Up,MCC_Romeo9t_BLK_Down);
	MCC_UP(MCC_Romeo9T_FDE_Up,MCC_Romeo9T_FDE_Down);
	MCC_UP(MCC_MicroT2_Up,MCC_MicroT2_Down);
	MCC_UP(MCC_MicroT2_UnityX_BLK_Up,MCC_MicroT2_UnityX_BLK_Down);
	MCC_UP(MCC_MicroT2_UnityX_FDE_Up,MCC_MicroT2_UnityX_FDE_Down);
	MCC_UP(MCC_GBRS_T2_Mag_Up_BLK,MCC_GBRS_T2_Mag_Down_BLK);
	MCC_UP(MCC_GBRS_T2_Mag_Up_FDE,MCC_GBRS_T2_Mag_Down_FDE);
};
