class CfgPatches {
  class mjb_izlid_tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "MJB izlid tweak";
	requiredAddons[]=
    {
        "Worm_izlid"
	};
    skipWhenMissingDependencies = 1;
  };
};

class Extended_PreInit_EventHandlers
{
	class mjb_izlid_tweak
	{
		init="call compileScript ['z\mjb\addons\configtweaks\izlid_tweak\XEH_preInit.sqf']";
	};
};


class CfgFunctions {
	class WORM_IZLID
	{
		class Core
		{
			class postInit
			{
				file = "z\mjb\addons\configtweaks\izlid_tweak\fn_postInit.sqf";
				postInit=1;
			};
		};
	};
};