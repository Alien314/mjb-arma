class CfgPatches {
  class mjb_bettinv_client {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "Better Inventory Client tweak";
		requiredAddons[]=
		{
			"bettinv_main"
		};
		skipWhenMissingDependencies = 1;
	};
};


class Extended_PostInit_EventHandlers
{
	class mjb_bettinv_tweak
	{
#if __has_include("\z\mjb\addons\configtweaks\cfgMagazines.hpp")
		init="call compileScript ['\z\mjb\addons\configtweaks\bettinv_tweak\XEH_postInit.sqf']";
#else
		init="call compileScript ['\z\mjb\addons\bettinv_tweak\XEH_postInit.sqf']";
#endif
	};
};
class Extended_PreInit_EventHandlers
{
	class bettinv_main
	{
#if __has_include("\z\mjb\addons\configtweaks\cfgMagazines.hpp")
		init="call compileScript ['\z\mjb\addons\configtweaks\bettinv_tweak\XEH_preInit.sqf']";
#endif
		init="call compileScript ['\z\mjb\addons\bettinv_tweak\XEH_preInit.sqf']";
#else
	};
};
class Extended_PreStart_EventHandlers
{
#if __has_include("\z\mjb\addons\configtweaks\cfgMagazines.hpp")
	class bettinv_main {
		init="call compileScript ['\z\mjb\addons\configtweaks\bettinv_tweak\XEH_preStart.sqf']";
#endif
		init="call compileScript ['\z\mjb\addons\bettinv_tweak\XEH_preStart.sqf']";
#else
	};
};