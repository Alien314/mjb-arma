class CfgPatches {
  class bfn_tmf_compat {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Snippers, Alien314";
    name = "Beofeng TMF compatibility";
    requiredAddons[] = {"acre_sys_bf888s","TMF_acre2"};
    skipWhenMissingDependencies = 1;
  };
};

class Extended_PostInit_EventHandlers
{
	class tmf_acre2 {
		init="call compileScript ['z\bfn\addons\tmf_compat\XEH_postInitTMF_ACRE2.sqf']";
	};
};

class Extended_PreInit_EventHandlers
{
	class tmf_acre2 {
		init="call compileScript ['z\bfn\addons\tmf_compat\XEH_preInitTMF_ACRE2.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class tmf_acre2 {
		init="call compileScript ['z\bfn\addons\tmf_compat\XEH_preStartTMF_ACRE2.sqf']";
	};
};

#include "Cfg3DEN.hpp"