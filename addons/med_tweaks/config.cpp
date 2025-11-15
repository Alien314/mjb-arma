#if __has_include("\z\ace\addons\nomedical\script_component.hpp")

#else
class CfgPatches {
  class mjb_med_tweaks {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "MJB Med tweaks";
    requiredAddons[] = {"ace_medical_treatment"};
    skipWhenMissingDependencies = 1;
  };
};

class Extended_PostInit_EventHandlers
{
	class mjb_med_tweaks
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_postInit.sqf']";
	};
};

class Extended_PreInit_EventHandlers
{
	class mjb_med_tweaks
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_preInit.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class mjb_med_tweaks
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_preStart.sqf']";
	};
};

// morphine tolerance
class ace_medical_treatment {
  class Medication {
    class Morphine {
      hrIncreaseHigh[] = {-12,-35};
      hrIncreaseLow[] = {-5,-10};
      hrIncreaseNormal[] = {-8,-18};
      viscosityChange = -5;
    };
  };
};

// Smelling salts
class ace_medical_treatment_actions {
  class Painkillers;
  class Salts : Painkillers {
    displayName = "Administer Smelling Salts";
    displayNameProgress = "Administering Smelling Salts...";
    icon = "z\mjb\addons\med_tweaks\ui\salts.paa";
    items[] = {}; //"mjb_salts"
    treatmentTime = 3;
    callbackSuccess = "mjb_med_tweaks_fnc_salts";
	condition = "mjb_med_tweaks_fnc_canSalt";
	consumeItem = 0;
  };
};

#endif