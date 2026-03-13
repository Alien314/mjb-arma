class CfgPatches {
  class jsrs_soundmod_cup_weapons {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "JSRS No Kick CUP Weapons";
	requiredAddons[]=
        {
            
        "jsrs2025_config_c","jsrs2025_sounds_character","jsrs2025_sounds_explosions","CUP_Weapons_LoadOrder"
	};
    skipWhenMissingDependencies = 1;
  };
};