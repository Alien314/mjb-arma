class CfgPatches {
  class jsrs_soundmod_complete_edition {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "JSRS No Kick Complete Editition";
	requiredAddons[]=
        {
            
        "jsrs2025_config_c","jsrs2025_sounds_character","jsrs2025_sounds_explosions"
	};
    skipWhenMissingDependencies = 1;
  };
};