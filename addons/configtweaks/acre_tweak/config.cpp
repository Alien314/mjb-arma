class CfgPatches {
  class mjb_acre_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "MJB Acre tweak";
		requiredAddons[]=
		{
			"acre_sys_attenuate",
			"acre_sys_intercom"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgVehicles {
	class LandVehicle;
	class Car;
	class Car_F;

#define MRAP_INTERCOM class AcreIntercoms { \
			class Intercom_1 { \
				displayName = "$STR_ACRE_sys_intercom_crewIntercom"; \
				shortName = "$STR_ACRE_sys_intercom_shortCrewIntercom"; \
				icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa"; \
				allowedPositions[] = {"crew"}; \
				masterPositions[] = {"gunner"}; \
				connectedByDefault = 1; \
			}; \
		} \
 \
		acre_hasInfantryPhone = 0; \
		acre_infantryPhoneIntercom[] = {"all"}; \
		acre_infantryPhoneControlActions[] = {"intercom_1"}; \
		acre_eventInfantryPhone = "acre_sys_intercom_fnc_noApiFunction"

	class MRAP_01_Base_F : Car_F {MRAP_INTERCOM;};
	class MRAP_02_Base_F : Car_F {MRAP_INTERCOM;};
	class MRAP_03_Base_F : Car_F {MRAP_INTERCOM;};

	// ACRE intercompartment attenuation
	#define ATT_INT 0.6  // attenutation to other compartments
	#define ATT_OUT 0.3  // attenutation to own compartment while turned out
	#define ATT_ONT 0.75 // attenutation to other compartments while turned out
	#define COMPART(var)	class Compartment##var { \
		Compartment1 = ATT_INT; \
		Compartment2 = ATT_INT; \
		Compartment3 = ATT_INT; \
		Compartment4 = ATT_INT; \
	}
	#define COMPARTOUT1	class Compartment1 { \
		Compartment1 = ATT_OUT; \
		Compartment2 = ATT_ONT; \
		Compartment3 = ATT_ONT; \
		Compartment4 = ATT_ONT; \
	}
	#define COMPARTOUT2	class Compartment2 { \
		Compartment1 = ATT_ONT; \
		Compartment2 = ATT_OUT; \
		Compartment3 = ATT_ONT; \
		Compartment4 = ATT_ONT; \
	}
	#define COMPARTOUT3	class Compartment3 { \
		Compartment1 = ATT_ONT; \
		Compartment2 = ATT_ONT; \
		Compartment3 = ATT_OUT; \
		Compartment4 = ATT_ONT; \
	}
	#define COMPARTOUT4	class Compartment4 { \
		Compartment1 = ATT_ONT; \
		Compartment2 = ATT_ONT; \
		Compartment3 = ATT_ONT; \
		Compartment4 = ATT_OUT; \
	}

	class Wheeled_APC_F: Car_F {
		class ACRE {
			class attenuation {
				COMPART(1);
				COMPART(2);
				COMPART(3);
				COMPART(4);
			};

			class attenuationTurnedOut {
				COMPARTOUT1;
				COMPARTOUT2;
				COMPARTOUT3;
				COMPARTOUT4;
			};
		};
	};

	class Tank : LandVehicle {
		class ACRE {
			class attenuation {
				COMPART(1);
				COMPART(2);
				COMPART(3);
				COMPART(4);
			};

			class attenuationTurnedOut {
				COMPARTOUT1;
				COMPARTOUT2;
				COMPARTOUT3;
				COMPARTOUT4;
			};
		};
	};

	// CUP

	class CUP_ECVHMMWV_Base : Car_F {MRAP_INTERCOM;};

	class CUP_HMMWV_Base : Car_F {MRAP_INTERCOM;};

	class CUP_M1240_Base : Car_F {MRAP_INTERCOM;};

	class CUP_nHMMWV_Base : Car_F {MRAP_INTERCOM;};

	class CUP_RG31_BASE : Car_F {MRAP_INTERCOM;};

	class CUP_SUV_Base;
	class CUP_SUV_Armored_Base : CUP_SUV_Base {MRAP_INTERCOM;};

	class CUP_T810_Base;
	class CUP_T810_Armed_Base : CUP_T810_Base {MRAP_INTERCOM;};

	class CUP_Tigr_Base : Car_F {MRAP_INTERCOM;};

	class CUP_UpHMMWV_Base : Car_F {MRAP_INTERCOM;};

	class CUP_BTR60_Base : Wheeled_APC_F {
		class ACRE : ACRE {
			class attenuationTurnedOut : attenuationTurnedOut {
				class Compartment1 : Compartment1 {
					Compartment2 = 0.1; // less attenuation to ride on tops while turned out
				};
			};
		};
	};
	class CUP_BTR80_Common_Base : Wheeled_APC_F {
		class ACRE : ACRE {
			class attenuationTurnedOut : attenuationTurnedOut {
				class Compartment1 : Compartment1 {
					Compartment2 = 0.1;
				};
			};
		};
	};
};
