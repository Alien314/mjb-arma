class CfgPatches {
  class mjb_sb_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {"O_SwitchBlade_300","O_SwitchBlade_600","O_SwitchBlade_300_LaunchTube_Desert","O_SwitchBlade_300_LaunchTube_Woodland","O_SwitchBlade_600_LaunchTube_Desert","O_SwitchBlade_600_LaunchTube_Woodland"};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "SwitchBlade tweak";
		requiredAddons[]=
		{
			"switchblade"
		};
		skipWhenMissingDependencies = 1;
	};
};


class CfgFunctions
{
	class SWB
	{
		class util
		{
			class sideToSwitchbladeFaction
			{
				file="z\mjb\addons\configtweaks\sb_tweak\fn_sideToSwitchbladeFaction.sqf";
			};
		};
	};
};

class CfgVehicles {
	class I_SwitchBlade_300;
	class I_SwitchBlade_600;
	class B_SwitchBlade_300_LaunchTube_Desert;
	class B_SwitchBlade_300_LaunchTube_Woodland;
	class B_SwitchBlade_600_LaunchTube_Desert;
	class B_SwitchBlade_600_LaunchTube_Woodland;
	class I_SwitchBlade_300_LaunchTube_Desert : B_SwitchBlade_300_LaunchTube_Desert {crew = "I_Soldier_F";};
	class I_SwitchBlade_300_LaunchTube_Woodland : B_SwitchBlade_300_LaunchTube_Woodland {crew = "I_Soldier_F";};
	class I_SwitchBlade_600_LaunchTube_Desert : B_SwitchBlade_600_LaunchTube_Desert {crew = "I_Soldier_F";};
	class I_SwitchBlade_600_LaunchTube_Woodland : B_SwitchBlade_600_LaunchTube_Woodland {crew = "I_Soldier_F";};
	class O_SwitchBlade_300 : I_SwitchBlade_300 {
		crew = "O_UAV_AI";
		faction = "OPF_F";
		side = 0;
		typicalCargo[] = {"O_UAV_AI"};
	};
	class O_SwitchBlade_600 : I_SwitchBlade_600 {
		crew = "O_UAV_AI";
		faction = "OPF_F";
		side = 0;
		typicalCargo[] = {"O_UAV_AI"};
	};

	class O_SwitchBlade_300_LaunchTube_Desert : I_SwitchBlade_300_LaunchTube_Desert {
		crew = "O_Soldier_F";
		faction = "OPF_F";
		side = 0;
	};
	class O_SwitchBlade_300_LaunchTube_Woodland : I_SwitchBlade_300_LaunchTube_Woodland {
		crew = "O_Soldier_F";
		faction = "OPF_F";
		side = 0;
	};
	class O_SwitchBlade_600_LaunchTube_Desert : I_SwitchBlade_600_LaunchTube_Desert {
		crew = "O_Soldier_F";
		faction = "OPF_F";
		side = 0;
	};
	class O_SwitchBlade_600_LaunchTube_Woodland : I_SwitchBlade_600_LaunchTube_Woodland {
		crew = "O_Soldier_F";
		faction = "OPF_F";
		side = 0;
	};
};