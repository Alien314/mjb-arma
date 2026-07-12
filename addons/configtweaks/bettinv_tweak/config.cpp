class CfgPatches {
  class mjb_bettinv_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "Better Inventory tweak";
		requiredAddons[]=
		{
			//"bettinv_main"
		};
		//skipWhenMissingDependencies = 1;
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
	class mjb_bettinv_tweak
	{
				
#if __has_include("\z\mjb\addons\configtweaks\cfgMagazines.hpp")
		init="call compileScript ['\z\mjb\addons\configtweaks\bettinv_tweak\XEH_preInitServer.sqf']";
#else
		init="call compileScript ['\z\mjb\addons\bettinv_tweak\XEH_preInitServer.sqf']";
#endif
	};
	/*class bettinv_main
	{
		init="call compileScript ['\z\mjb\addons\configtweaks\bettinv_tweak\XEH_preInit.sqf']";
	};*/
};
class Extended_PreStart_EventHandlers
{
	/*class bettinv_main {
		init="call compileScript ['\z\mjb\addons\configtweaks\bettinv_tweak\XEH_preStart.sqf']";
	};*/
};