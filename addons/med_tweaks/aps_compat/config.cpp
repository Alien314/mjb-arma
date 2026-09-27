

class CfgPatches {
  class mjb_med_tweaks_aps {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "MJB Med tweaks APS";
    requiredAddons[] = {"diw_armor_plates"};
    skipWhenMissingDependencies = 1;
  };
};

/*class Extended_PostInit_EventHandlers
{
	class mjb_med_tweaks_aps
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_postInit.sqf']";
	};
};*/

class Extended_PreInit_EventHandlers
{
	class mjb_med_tweaks_aps
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_preInit.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class mjb_med_tweaks_aps
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_preStart.sqf']";
	};
};

#include "ACE_Medical_Injuries.hpp"
