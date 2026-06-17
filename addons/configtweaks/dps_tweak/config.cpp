class CfgPatches {
  class mjb_DPS_tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "DPS tweak";
	requiredAddons[]=
    {
        "DPS_Main"
	};
    skipWhenMissingDependencies = 1;
  };
};


class CfgFunctions {
    class DPS {
        tag = "DPS";

        class Main {
			class controlledDisembark
			{
				file = "z\mjb\addons\configtweaks\dps_tweak\fn_controlledDisembark.sqf";
			};
		};
	};
};