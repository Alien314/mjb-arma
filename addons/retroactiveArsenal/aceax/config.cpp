class CfgPatches {
  class mjb_aceax_arsenal {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "Mjb AceAX func tweak";
	requiredAddons[]=
        {
            "aceax_arsenal"
        };
    skipWhenMissingDependencies = 1;
  };
};

class Extended_PreInit_EventHandlers
{
	class aceax_arsenal {
		init="call compileScript ['z\mjb\addons\arsenal\aceax\XEH_preInit.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class aceax_arsenal {
		init="call compileScript ['z\mjb\addons\arsenal\aceax\XEH_preStart.sqf']";
	};
};