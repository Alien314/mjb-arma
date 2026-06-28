class CfgPatches {
  class mjb_adminTweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "TMF Admin tweak";
		requiredAddons[]=
		{
			"TMF_adminMenu"
		};
	};
};

class TMF_adminMenu_authorized_players {
    class Momo {
        uid = "76561198002473874";
    };
    class KrazyKat {
        uid = "76561197985152127";
    };
};


class Extended_PreInit_EventHandlers
{
	class tmf_adminmenu
	{
		init="call compileScript ['\z\mjb\addons\configtweaks\tmf_admin_tweak\XEH_preInit.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class tmf_adminmenu {
		init="call compileScript ['\z\mjb\addons\configtweaks\tmf_admin_tweak\XEH_preStart.sqf']";
	};
};