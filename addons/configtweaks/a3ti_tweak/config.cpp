class CfgPatches {
  class mjb_a3ti_tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "A3TI tweak";
	requiredAddons[]=
    {
        "A3TI"
	};
    skipWhenMissingDependencies = 1;
  };
};


class CfgFunctions {
	class A3TI
	{
		class init
		{
			file = "A3TI";
			class init
			{
				file = "z\mjb\addons\configtweaks\a3ti_tweak\fn_init.sqf";
				postInit = 1;
			};
		};
	};
};