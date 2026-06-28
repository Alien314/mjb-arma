class CfgPatches {
  class mjb_tsp_animate_tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "TSP Animate tweak";
	requiredAddons[]=
    {
        "tsp_animate"
	};
    skipWhenMissingDependencies = 1;
  };
};

class Extended_PostInit_EventHandlers {class tsp_animate_init {init = "['CBA_settingsInitialized', {[] spawn compileScript ['\z\mjb\addons\configtweaks\tsp_animate_tweak\init.sqf']}] call CBA_fnc_addEventHandler;";};};  