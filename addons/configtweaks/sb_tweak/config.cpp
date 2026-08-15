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
	class B_UAV_02_dynamicLoadout_F;
	class SwitchBlade_Base : B_UAV_02_dynamicLoadout_F {
		class Sounds {
			class EngineHighIn;
			class EngineHighOut;
			class EngineLowIn;
			class EngineLowOut;
			class ForsageIn;
			class ForsageOut;
		};
	};
	class B_SwitchBlade_300 : SwitchBlade_Base {
		soundEngineOffExt[] = {"z\jsrs2025\addons\sounds_air\sounds\drones\fpv_drones_small\stop_ext.ogg",2,1,50};
		soundEngineOffInt[] = {"z\jsrs2025\addons\sounds_air\sounds\drones\fpv_drones_small\stop_int.ogg",2,1};
		soundEngineOnExt[] = {"z\jsrs2025\addons\sounds_air\sounds\drones\fpv_drones_small\start_ext.ogg",2,1,50};
		soundEngineOnInt[] = {"z\jsrs2025\addons\sounds_air\sounds\drones\fpv_drones_small\start_int.ogg",2,1};
		//soundEngineOffExt[] = {"A3\Sounds_F_Orange\Vehicles\Air\UAV_01\Uav_01_Eng_Off_Ext",1.75849,1,50};
		//soundEngineOffInt[] = {"A3\Sounds_F_Orange\Vehicles\Air\UAV_01\Uav_01_Eng_Off_Ext",1.75849,1,10};
		//soundEngineOnExt[] = {"A3\Sounds_F_Orange\Vehicles\Air\Uav_01\Uav_01_Eng_On_Ext",1.75849,1,50};
		//soundEngineOnInt[] = {"A3\Sounds_F_Orange\Vehicles\Air\Uav_01\Uav_01_Eng_On_Int",1.75849,1,10};
		//soundFlapsDown[] = {"",0.630957,1,100};
		//soundFlapsUp[] = {"",0.630957,1,100};
		//soundGearDown[] = {"",1,1,120};
		//soundGearUp[] = {"",1,1,120};

		class Sounds : Sounds {
			soundsetsext[] = {"jsrs_2025_drones_fpv_small_engineext_soundset","jsrs_2025_drones_fpv_small_rotorext_soundset","jsrs_2025_drones_fpv_small_evr_soundset","jsrs_2025_drones_fpv_small_rotordistance_soundset"};
			soundsetsint[] = {"jsrs_2025_drones_fpv_small_engineint_soundset","jsrs_2025_drones_fpv_small_rotorint_soundset"};
			class EngineHighIn : EngineHighIn {
				frequency = "(rpm factor[0.5, 1.0])";
				sound[] = {"A3\Sounds_F\air\UAV_02\UAV_02_high_int",1,1};
				volume = "(1-camPos)*(rpm factor[0.2, 1.0])";
			};
			class EngineHighOut : EngineHighOut {
				frequency = "(rpm factor[0.5, 1.0])";
				sound[] = {"A3\Sounds_F\air\UAV_02\UAV_02_high_ext",1,1,250};
				volume = "camPos*(rpm factor[0.2, 1.0])";
			};
			class EngineLowIn : EngineLowIn {
				frequency = "1.0 min (rpm + 0.5)";
				sound[] = {"A3\Sounds_F\air\UAV_02\UAV_02_low_int",1,1};
				volume = "(1-camPos)*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineLowOut : EngineLowOut {
				frequency = "1.0 min (rpm + 0.5)";
				sound[] = {"A3\Sounds_F\air\UAV_02\UAV_02_low_ext",0.707946,1,175};
				volume = "camPos*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
		};
		class soundsext {
			class Sounds {
				soundsetsext[] = {"jsrs_2025_drones_fpv_small_engineext_soundset","jsrs_2025_drones_fpv_small_rotorext_soundset","jsrs_2025_drones_fpv_small_evr_soundset","jsrs_2025_drones_fpv_small_rotordistance_soundset"};
				soundsetsint[] = {"jsrs_2025_drones_fpv_small_engineint_soundset","jsrs_2025_drones_fpv_small_rotorint_soundset"};
			};
		};
	};
	class B_SwitchBlade_600 : SwitchBlade_Base {
		soundEngineOffExt[] = {"z\jsrs2025\addons\sounds_air\sounds\drones\fpv_drones_small\stop_ext.ogg",2,1,100};
		soundEngineOffInt[] = {"z\jsrs2025\addons\sounds_air\sounds\drones\fpv_drones_small\stop_int.ogg",2,1};
		soundEngineOnExt[] = {"z\jsrs2025\addons\sounds_air\sounds\drones\fpv_drones_small\start_ext.ogg",2,1,100};
		soundEngineOnInt[] = {"z\jsrs2025\addons\sounds_air\sounds\drones\fpv_drones_small\start_int.ogg",2,1};
		//soundEngineOffExt[] = {"A3\Sounds_F_Orange\Vehicles\Air\UAV_01\Uav_01_Eng_Off_Ext",1.75849,1,50};
		//soundEngineOffInt[] = {"A3\Sounds_F_Orange\Vehicles\Air\UAV_01\Uav_01_Eng_Off_Ext",1.75849,1,10};
		//soundEngineOnExt[] = {"A3\Sounds_F_Orange\Vehicles\Air\Uav_01\Uav_01_Eng_On_Ext",1.75849,1,50};
		//soundEngineOnInt[] = {"A3\Sounds_F_Orange\Vehicles\Air\Uav_01\Uav_01_Eng_On_Int",1.75849,1,10};
		//soundFlapsDown[] = {"",0.630957,1,100};
		//soundFlapsUp[] = {"",0.630957,1,100};
		//soundGearDown[] = {"",1,1,120};
		//soundGearUp[] = {"",1,1,120};

		class Sounds : Sounds {
			soundsetsext[] = {"jsrs_2025_drones_fpv_big_engineext_soundset","jsrs_2025_drones_fpv_big_rotorext_soundset","jsrs_2025_drones_fpv_big_evr_soundset","jsrs_2025_drones_fpv_big_rotordistance_soundset"};
			soundsetsint[] = {"jsrs_2025_drones_fpv_big_engineint_soundset","jsrs_2025_drones_fpv_big_rotorint_soundset"};
			class EngineHighIn : EngineHighIn {
				frequency = "(rpm factor[0.5, 1.0])";
				sound[] = {"A3\Sounds_F\air\UAV_02\UAV_02_high_int",1,1};
				volume = "(1-camPos)*(rpm factor[0.2, 1.0])";
			};
			class EngineHighOut : EngineHighOut {
				frequency = "(rpm factor[0.5, 1.0])";
				sound[] = {"A3\Sounds_F\air\UAV_02\UAV_02_high_ext",1,1,400};
				volume = "camPos*(rpm factor[0.2, 1.0])";
			};
			class EngineLowIn : EngineLowIn {
				frequency = "1.0 min (rpm + 0.5)";
				sound[] = {"A3\Sounds_F\air\UAV_02\UAV_02_low_int",1,1};
				volume = "(1-camPos)*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
			class EngineLowOut : EngineLowOut {
				frequency = "1.0 min (rpm + 0.5)";
				sound[] = {"A3\Sounds_F\air\UAV_02\UAV_02_low_ext",0.707946,1,250};
				volume = "camPos*(rpm factor[0.95, 0])*(rpm factor[0, 0.95])";
			};
		};
		class soundsext {
			class Sounds {
				soundsetsext[] = {"jsrs_2025_drones_fpv_big_engineext_soundset","jsrs_2025_drones_fpv_big_rotorext_soundset","jsrs_2025_drones_fpv_big_evr_soundset","jsrs_2025_drones_fpv_big_rotordistance_soundset"};
				soundsetsint[] = {"jsrs_2025_drones_fpv_big_engineint_soundset","jsrs_2025_drones_fpv_big_rotorint_soundset"};
			};
		};
	};
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