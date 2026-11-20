class CfgPatches {
  class mjb_flex_acre_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "MJB Flex Acre tweak";
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

	class CSK181_base_F : Car_F {
		class AcreIntercoms {
			class Intercom_1 {
				displayName = "$STR_ACRE_sys_intercom_crewIntercom";
				shortName = "$STR_ACRE_sys_intercom_shortCrewIntercom";
				icon = "\a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa";
				allowedPositions[] = {"crew"};
				masterPositions[] = {"gunner"};
				connectedByDefault = 1;
			};
		};

		acre_hasInfantryPhone = 0;
		acre_infantryPhoneIntercom[] = {"all"};
		acre_infantryPhoneControlActions[] = {"intercom_1"};
		acre_eventInfantryPhone = "acre_sys_intercom_fnc_noApiFunction";
	};
};
