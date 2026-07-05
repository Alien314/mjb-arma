class CfgPatches {
  class mjb_ace_nv_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "ACE Nightvision tweak";
		requiredAddons[]=
		{
			"ace_nightvision"
		};
		skipWhenMissingDependencies = 1;
	};
};


class Extended_PostInit_EventHandlers
{
	class mjb_ace_nv_tweak
	{
		init="call compileScript ['\z\mjb\addons\configtweaks\ace_nv_tweak\XEH_postInit.sqf']";
	};
};
class Extended_PreInit_EventHandlers
{
	class ace_nightvision
	{
		init="call compileScript ['\z\mjb\addons\configtweaks\ace_nv_tweak\XEH_preInit.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class ace_nightvision {
		init="call compileScript ['\z\mjb\addons\configtweaks\ace_nv_tweak\XEH_preStart.sqf']";
	};
};

class CfgWeapons {
	class NVGoggles;
	class Integrated_NVG_F : NVGoggles {
		ace_nightvision_border = "";
		ace_nightvision_generation = 4;
	};
	class Integrated_NVG_TI_0_F : NVGoggles {
		ace_nightvision_border = "";
		ace_nightvision_generation = 4;
	};
	class Integrated_NVG_TI_1_F : NVGoggles {
		ace_nightvision_border = "";
		ace_nightvision_generation = 4;
	};
};