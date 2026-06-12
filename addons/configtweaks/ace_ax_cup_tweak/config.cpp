class CfgPatches {
  class mjb_ace_ax_cup_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "ACE AX Cup tweak";
		requiredAddons[]=
		{
			"aceax_compat_cup","aceax_acebi_compat"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgSettings {
	class CBA {
		class Versioning {
			delete aceax;
		};
	};
};

class XtdGearInfos {
	class CfgWeapons {
		class CUP_U_B_GER_Crye {
			camo = "TRPTRN";
		};
		class CUP_U_B_GER_Crye2 {
			camo = "TRPTRN";
		};
		// remove cringe
		delete CUP_H_OpsCore_Covered_MCAM_US;
		delete CUP_H_OpsCore_Spray_US;
	};
};

class XtdGearModels {
	class CfgVehicles {
		class acebi_carryall {
			class camo {
				values[] += {"CBR"};
			};
		};
	};
	class CfgWeapons {
		class cup_crye {
			class camo {
				values[] += {"TRPTRN"};
			};
		};
		class cup_opscore_fast {
			class camo {
				values[] = {"AAF","BLK","FLCK","TRPTRN","GRN","GRY","MTP","MC","MM14","SPRAY","TAN","TSW","UCP"};
				delete MC_US;
				delete SPRAY_US;
			};
		};
	};
};