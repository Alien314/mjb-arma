class CfgPatches {
  class mjb_GOT_Map_IslaPera_tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "Isla Pera tweak";
	requiredAddons[]=
    {
        "GOT_Map_IslaPera"
	};
    skipWhenMissingDependencies = 1;
  };
};

class CfgWorlds {
	class CAWorld;
	class IslaPera : CAWorld {
		class Names {
			class LagunaClara {
				name = "Laguna Awawawawawawa";
				position[] = {5965,4634};
			};
		};
	};
};