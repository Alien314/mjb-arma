class CfgPatches {
  class mjb_ifatigue_tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "iFatigue tweak";
	requiredAddons[]=
    {
        "fatigue_core"
	};
    skipWhenMissingDependencies = 1;
  };
};


class Extended_InitPost_EventHandlers
{
	class CAManBase
	{
		class fatigue_core
		{
            init = "if (hasInterface && {local (_this select 0)}) then { systemChat str _this; [_this] execVM '\x\fatigue\addons\core\functions\fnc_applyFatigue.sqf'}";
		};
	};
};