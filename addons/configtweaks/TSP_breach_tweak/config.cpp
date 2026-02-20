class CfgPatches {
  class mjb_tsp_breachTweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "TSP breach Tweaks";
	requiredAddons[]=
        {
            "tsp_flashbang"
        };
    skipWhenMissingDependencies = 1;
  };
};

class CfgMagazines {
	// Redacted
	class tsp_flashbang_cts;
	class tsp_flashbang_cts99 : tsp_flashbang_cts {
		scopeArsenal = 0;
	};
};