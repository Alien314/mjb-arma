class CfgPatches {
  class mjb_avs_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "MJB AVS slide tackle";
		requiredAddons[]=
		{
			"APS_System"
		};
		skipWhenMissingDependencies = 1;
	};
};

class Extended_PreInit_EventHandlers
{
	class mjb_avs_tweak
	{
		init="call compileScript ['z\mjb\addons\configtweaks\avs_tweak\XEH_preInit.sqf']";
	};
};
/*
class Extended_PostInit_EventHandlers
{
	class mjb_avs_tweak
	{
		init="call compileScript ['z\mjb\addons\configtweaks\avs_tweak\XEH_postInit.sqf']";
	};
};
*/

class Extended_InitPost_EventHandlers {
    class CAManBase {
        class mjb_avs_tweak {
            init="_this call mjb_avs_fnc_addEH";
        };
    };
};