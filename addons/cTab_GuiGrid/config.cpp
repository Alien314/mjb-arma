class CfgPatches {
  class ctab_gui_settings {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "cTab GUI Grid Settings";
	requiredAddons[]=
        {
            "ctab"
        };
    skipWhenMissingDependencies = 1;
  };
};

class Extended_PostInit_EventHandlers
{
	class ctab_gui_settings
	{
		init="call compileScript ['z\mjb\addons\ctab_gui_settings\XEH_postInit.sqf']";
	};
};

class Extended_PreInit_EventHandlers
{
	class ctab_core
	{
		init="call compileScript ['z\mjb\addons\ctab_gui_settings\XEH_preInit.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class ctab_core
	{
		init="call compileScript ['z\mjb\addons\ctab_gui_settings\XEH_preStart.sqf']";
	};
};

//#include "CfgUIGrids.hpp"

//#include "gui.hpp"