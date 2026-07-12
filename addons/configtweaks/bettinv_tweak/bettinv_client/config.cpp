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
		init="call compileScript ['\z\mjb\addons\configtweaks\bettinv_tweak\XEH_postInit.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class bettinv_main
	{
		init="call compileScript ['\z\mjb\addons\configtweaks\bettinv_tweak\XEH_preInit.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class bettinv_main {
		init="call compileScript ['\z\mjb\addons\configtweaks\bettinv_tweak\XEH_preStart.sqf']";
	};
};