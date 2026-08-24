class CfgPatches {
  class mjb_flags {
    units[] = {"mjb_Flag_RATS_F","Flag_CA_F","mjb_Soldier_W_F"/*,"mjb_I_BTR80_RATS","mjb_I_BTR80A_RATS"*/};
    weapons[] = {"mjb_arifle_C7Alpha","mjb_arifle_C7Bravo","mjb_H_Cap_Voin","mjb_H_HelmetSpecB_winter","U_B_CombatUniform_mcamW"};
    requiredVersion = 0.1;
    author = "Alien314, Flamebunny, MajorDanvers";
    name = "Flags";
    requiredAddons[]=
		{
			"cba_main"
		};
	};
};

class CfgUnitInsignia
{
	class RATS
	{
		author = "Beagle, Flamebunny";
		displayName = "RATS PMC";
		material = "\A3\ui_f\data\GUI\Cfg\UnitInsignia\default_insignia.rvmat";
		texture = "z\mjb\addons\flags\data\rats_insignia.paa";
	};
};

class CfgMarkers {
	
	class flag_NATO;
	class mjb_flag_RATS : flag_NATO
	{
		icon = "z\mjb\addons\flags\data\rats_ca.paa";
		name = "RATS";
		texture = "z\mjb\addons\flags\data\rats_ca.paa";
	};
	class flag_CA : flag_NATO
	{
		icon = "z\mjb\addons\flags\data\canada_ca.paa";
		name = "CanadaHeightfixed";
		texture = "z\mjb\addons\flags\data\canada_ca.paa";
	};
};

class CfgFactionClasses 
{
	class mjb_I_RATS 
	{
		displayName = "RATS";
		flag = "z\mjb\addons\flags\data\ratsFlag_ca.paa";
		icon = "z\mjb\addons\flags\data\ratsFlag_ca.paa";
		priority = 9;
		side = 2;
	};
};

class CfgVehicles {
	class FlagCarrier;
	class mjb_Flag_RATS_F : FlagCarrier
	{
		_generalMacro = "mjb_Flag_RATS_F";
		author = "Flamebunny, Alien314";
		displayName = "Flag (RATS)";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\FlagPole_F.jpg";
		hiddenSelectionsMaterials[] = {"\A3\Structures_F\Mil\Flags\Data\Mast_mil.rvmat"};
		hiddenSelectionsTextures[] = {"\A3\Structures_F\Mil\Flags\Data\Mast_mil_CO.paa"};
		scope = 2;
		scopeCurator = 2;
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""\z\mjb\addons\flags\data\ratsFlag_ca.paa""";
		};
	};
	class Flag_CA_F : FlagCarrier
	{
		_generalMacro = "Flag_CA_F";
		author = "Canada";
		displayName = "Flag (Canada)";
		editorPreview = "\A3\EditorPreviews_F\Data\CfgVehicles\FlagPole_F.jpg";
		hiddenSelectionsMaterials[] = {"\A3\Structures_F\Mil\Flags\Data\Mast_mil.rvmat"};
		hiddenSelectionsTextures[] = {"\A3\Structures_F\Mil\Flags\Data\Mast_mil_CO.paa"};
		scope = 2;
		scopeCurator = 2;
		class EventHandlers
		{
			init = "(_this select 0) setFlagTexture ""\z\mjb\addons\flags\data\canadaFlag_ca.paa""";
		};
	};

#define MAG_2(a) a, a
#define MAG_3(a) a, a, a
#define MAG_10(a) a, a, a, a, a, a, a, a, a, a
	// Uniform Soldiers
	class B_Soldier_F;
	class mjb_Soldier_W_F : B_Soldier_F {
		displayName = "Rifleman Winter";
		hiddenSelectionsTextures[] = {"\z\mjb\addons\flags\data\clothing1W_co.paa"};
		linkedItems[] = { "V_PlateCarrier2_blk", "mjb_H_HelmetSpecB_winter", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_NVG_PVS15_winter" };
		magazines[] = { MAG_10(30Rnd_65x39_caseless_black_mag), MAG_3(16Rnd_9x21_Mag), "SmokeShell", "mjb_SmokeShellLightBlue", "Chemlight_green", "Chemlight_green", MAG_2(HandGrenade) };
		respawnMagazines[] = { MAG_10(30Rnd_65x39_caseless_black_mag), MAG_3(16Rnd_9x21_Mag), "SmokeShell", "mjb_SmokeShellLightBlue", "Chemlight_green", "Chemlight_green", MAG_2(HandGrenade) };
		weapons[] = { "arifle_MX_Black_ACO_Pointer_F", "hgun_P07_blk_F", "Throw", "Put" };
		respawnWeapons[] = { "arifle_MX_Black_ACO_Pointer_F", "hgun_P07_blk_F", "Throw", "Put" };
		uniformClass = "U_B_CombatUniform_mcamW";
	};


	class CUP_CRYE_MCAM_NP2_Full;
	class mjb_CUP_B_US_SpecOps_W : CUP_CRYE_MCAM_NP2_Full {
		displayName = "Rifleman Winter";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\crye_mcam_patchless_winter_co.paa"};
		backpack = "CUP_B_US_IIID_UCP";
		linkedItems[] = {"CUP_V_CPC_Fastbelt_mc","mjb_H_OpsCore_Covered_MM14_SF_winter","CUP_G_WatchGPSCombo","ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","CUP_NVG_PVS15_winter"};
		respawnLinkedItems[] = {"CUP_V_CPC_Fastbelt_mc","mjb_H_OpsCore_Covered_MM14_SF_winter","CUP_G_WatchGPSCombo","ItemGPS","ItemMap","ItemCompass","ItemWatch","ItemRadio","CUP_NVG_PVS15_winter"};
		magazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_HandGrenade_M67","B_IR_Grenade","SmokeShellRed","SmokeShellGreen","CUP_15Rnd_9x19_M9","CUP_15Rnd_9x19_M9"};
		respawnMagazines[] = {"CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_30Rnd_556x45_Stanag","CUP_HandGrenade_M67","B_IR_Grenade","SmokeShellRed","SmokeShellGreen","CUP_15Rnd_9x19_M9","CUP_15Rnd_9x19_M9"};
		weapons[] = {"CUP_arifle_mk18_tan_holo_laserflash","CUP_Vector21Nite","Throw","Put","CUP_hgun_M9"};
		respawnWeapons[] = {"CUP_arifle_mk18_tan_holo_laserflash","CUP_Vector21Nite","Throw","Put","CUP_hgun_M9"};
		uniformClass = "mjb_U_CRYE_MCAM_NP_FULL_winter";
	};

	// backpacks
	class B_AssaultPack_blk;      
    class mjb_B_AssaultPack_OCP_winter : B_AssaultPack_blk
    {
        displayName = "Assault Pack OCP (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_assaultpack_OCP_Winter.paa"};
    };
     
    class mjb_B_AssaultPack_OEFCP_winter : B_AssaultPack_blk
    {
        displayName = "Assault Pack OEFCP (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_assaultpack_oefcp_winter.paa"};
    };
      
    class mjb_B_AssaultPack_OEFCP_winterdark : B_AssaultPack_blk
    {
        displayName = "Assault Pack OEFCP (Winter/Dark)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_assaultpack_oefcp_winterDark.paa"};
    };
  
    class mjb_B_AssaultPack_UCP_winter : B_AssaultPack_blk
    {
        displayName = "Assault Pack UCP (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_assaultpack_ucp_Winter.paa"};
    };

	class CUP_BTR80_Common_Base;
	class CUP_BTR80_Base : CUP_BTR80_Common_Base
	{
		class textureSources
		{
			class ION;
			class RATS : ION
			{
                author = "MajorDanvers, CUP";
				displayName = "Granmobile";
				textures[] = {"z\mjb\addons\flags\data\granmobile.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_BTR80\data\un\kpvt_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_BTR80\data\ion\Wheels_co.paa"};
			};
		}
	};
	class CUP_BTR80A_Base : CUP_BTR80_Common_Base
	{
		class textureSources
		{
			class ION;
			class RATS : ION
			{
                author = "MajorDanvers, CUP";
				displayName = "Granmobile";
				textures[] = {"z\mjb\addons\flags\data\granmobile.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_BTR80\data\un\bppu_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_BTR80\data\ion\Wheels_co.paa"};
			};
		}
	};
    	
	class CUP_M2Bradley_Base;
	class CUP_B_M2Bradley_USA_D : CUP_M2Bradley_Base
	{
		class textureSources
		{
			class Woodland;
			class RATS : Woodland
			{
                author = "MajorDanvers";
				displayName = "Limebacker";
				textures[] = {"z\mjb\addons\flags\data\cadpat_base.paa","z\mjb\addons\flags\data\cadpat_co.paa","cup\TrackedVehicles\CUP_TrackedVehicles_Bradley\data\ultralp_wdl_co.paa"};
			};
		}
	};
	class CUP_B_M7Bradley_USA_D : CUP_B_M2Bradley_USA_D
	{
		class textureSources
		{
			class Woodland;
			class RATS : Woodland
			{
                author = "MajorDanvers";
				displayName = "Limebacker";
				textures[] = {"z\mjb\addons\flags\data\cadpat_base.paa","z\mjb\addons\flags\data\cadpat_co.paa","cup\TrackedVehicles\CUP_TrackedVehicles_Bradley\data\m7\bfist_wdl_co.paa"};
			};
		}
	};
	class CUP_B_M7Bradley_USA_W : CUP_B_M2Bradley_USA_D
	{
		class textureSources
		{
			class Woodland;
			class RATS : Woodland
			{
                author = "MajorDanvers";
				displayName = "Limebacker";
				textures[] = {"z\mjb\addons\flags\data\cadpat_base.paa","z\mjb\addons\flags\data\cadpat_co.paa","cup\TrackedVehicles\CUP_TrackedVehicles_Bradley\data\m7\bfist_wdl_co.paa"};
			};
		}
	};
	
	/*class CUP_I_BTR80_ION;
	class mjb_I_BTR80_RATS : CUP_I_BTR80_ION
	{
		faction = "mjb_I_RATS";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\granmobile.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_BTR80\data\un\kpvt_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_BTR80\data\ion\Wheels_co.paa"};
	};
	class CUP_I_BTR80A_ION;
	class mjb_I_BTR80A_RATS : CUP_I_BTR80A_ION
	{
		faction = "mjb_I_RATS";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\granmobile.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_BTR80\data\un\bppu_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_BTR80\data\ion\Wheels_co.paa"};
	};*/
};

class CfgWorlds
{
	class CAWorld;
	class Altis : CAWorld
	{
		class Names
		{
			class CapKategidis
			{
				name = "Cape Katgirls";
			};
			class CapThelos
			{
				name = "Cape Katfellows";
			};
		};
	};
};

class CfgWeapons
{
	class UniformItem;
	class Uniform_Base;
	class U_B_CombatUniform_mcam : Uniform_Base { class ItemInfo; };
	class U_B_CombatUniform_mcamW : U_B_CombatUniform_mcam {
		displayName = "Combat Fatigues (MTP-Winter)";
		hiddenSelectionsTextures[] = {"\z\mjb\addons\flags\data\suitpack_soldier_blufor_w_co.paa"};
		class ItemInfo : ItemInfo {
			uniformClass = "mjb_Soldier_W_F";
		};
	};
    class H_Cap_red;
    class mjb_H_Cap_Voin : H_Cap_red
    {
        author = "Alien314";
        displayName = "Cap (Voin)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\capb_voin_co.paa"};
        picture = "\A3\Characters_F_Bootcamp\Data\UI\icon_H_Cap_oli_ca.paa";
    };

    class H_HelmetSpecB;
    class mjb_H_HelmetSpecB_winter : H_HelmetSpecB
    {
        displayName = "Enhanced Combat Helmet (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\equip1winter_co.paa"};
    };

  class CUP_arifle_M4A1;
  class mjb_arifle_C7Alpha : CUP_arifle_M4A1
  {
	  baseWeapon = "mjb_arifle_C7Alpha";
	  displayName = "C7Alpha";
	  aimTransitionSpeed = 1.1;
	  inertia = 0.5;
	  initSpeed = -1.02717;
	  handAnim[] = {"OFP2_ManSkeleton","CUP\Weapons\CUP_Weapons_M16\data\anim\M16.rtm"};
	  hiddenSelections[] = {"camo","CamoFrontSight","CamoHandguard"};
	  hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\c7a2_co.paa","cup\weapons\cup_weapons_m16\data\m16a1_body_co.paa","z\mjb\addons\flags\data\c7a2_handguard_co.paa"};
	  model = "\CUP\Weapons\CUP_Weapons_M16\CUP_M16A2.p3d";
	  picture = "\CUP\Weapons\CUP_Weapons_M16\data\ui\gear_M16A2_X_ca.paa";
	  recoil = "Recoil_CUP_M16";
	  reloadMagazineSound[] = {"CUP\Weapons\CUP_Weapons_M16\data\sfx\M16_Reload",1,1,10};
  };
  class CUP_arifle_Colt727_M203;
  class mjb_arifle_C7Bravo : CUP_arifle_Colt727_M203
  {
	  baseWeapon = "mjb_arifle_C7Bravo";
	  displayName = "C7Bravo";
	  hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\c7a2_co.paa","CUP\Weapons\CUP_Weapons_M16\data\tigg_m203_m4_co.paa","z\mjb\addons\flags\data\colt727_furniture_co.paa","cup\weapons\cup_weapons_m16\data\tigg_m4barrel_co.paa","cup\weapons\cup_weapons_m16\data\m16a1_body_co.paa"};
  };

    class CUP_H_OpsCore_Covered_MM14_NoHS;
    class CUP_H_OpsCore_Covered_MM14;    
    class CUP_H_OpsCore_Covered_MM14_SF;        
    class mjb_H_OpsCore_Covered_MM14_NoHS_winter : CUP_H_OpsCore_Covered_MM14_NoHS
    {
        displayName = "Ops Core Fast (MM-14/Covered/No Headset) (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_ops_core_covered_mm14snow_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_part_1_tan_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_parts_2_co.paa",""};
    };

      class mjb_H_OpsCore_Covered_MM14_winter : CUP_H_OpsCore_Covered_MM14
    {
        displayName = "Ops Core Fast (MM-14/Covered) (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_ops_core_covered_mm14snow_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_part_1_tan_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_parts_2_co.paa",""};
    };

      class mjb_H_OpsCore_Covered_MM14_SF_winter : CUP_H_OpsCore_Covered_MM14_SF
    {
        displayName = "Ops Core Fast (MM-14/Covered/No Headset) (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_ops_core_covered_mm14snow_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_part_1_tan_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_parts_2_co.paa",""};
    };

    class CUP_H_OpsCore_Covered_Tropen_NoHS;
    class CUP_H_OpsCore_Covered_Tropen;
    class CUP_H_OpsCore_Covered_Tropen_SF;        
    class mjb_H_OpsCore_Covered_Tropen_NoHS_winter : CUP_H_OpsCore_Covered_Tropen_NoHS
    {
        displayName = "Ops Core Fast (BW Tropen/Covered/No Headset) (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_ops_core_covered_tropentarnsnow_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_part_1_tan_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_parts_2_co.paa",""};
    };

      class mjb_H_OpsCore_Covered_Tropen_winter : CUP_H_OpsCore_Covered_Tropen
    {
        displayName = "Ops Core Fast (BW Tropen/Covered) (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_ops_core_covered_tropentarnsnow_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_part_1_tan_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_parts_2_co.paa",""};
    };

      class mjb_H_OpsCore_Covered_Tropen_SF_winter : CUP_H_OpsCore_Covered_Tropen_SF
    {
        displayName = "Ops Core Fast (BW Tropen/Covered/No Headset) (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\CUP_ops_core_covered_tropentarnsnow_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_part_1_tan_co.paa","\CUP\Creatures\People\Military\CUP_Creatures_People_Military_Extra\opscore\data\CUP_ops_core_parts_2_co.paa",""};
    };

	class CUP_U_B_US_BDU;
    class CUP_U_CRYE_MCAM_NP_FULL : CUP_U_B_US_BDU { class ItemInfo; };
    class CUP_U_CRYE_MCAM_NP_Roll : CUP_U_B_US_BDU { class ItemInfo; };
    class mjb_U_CRYE_MCAM_NP_FULL_winter : CUP_U_CRYE_MCAM_NP_FULL
    {//uniformClass = "CUP_CRYE_MCAM_NP_Full";hiddenSelectionsMaterials[] = {"\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USarmy\data\delta\crye_g3_mcam_v2.rvmat"};hiddenSelectionsTextures[] = {"\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USarmy\data\delta\crye_mcam_patchless_co.paa"};
        displayName = "Crye MCAM v2 Patchless Full (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\crye_mcam_patchless_winter_co.paa"};
		class ItemInfo : ItemInfo {
			uniformClass = "mjb_CUP_B_US_SpecOps_W";
		};
    };

      class mjb_U_CRYE_MCAM_NP_Roll_winter : CUP_U_CRYE_MCAM_NP_Roll
    {//uniformClass = "CUP_CRYE_MCAM_NP_Roll";hiddenSelectionsTextures[] = {"\CUP\Creatures\People\Military\CUP_Creatures_People_Military_USarmy\data\delta\crye_mcam_patchless_co.paa"};
        displayName = "Crye MCAM v2 Patchless Roll (Winter)";
        hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\crye_mcam_patchless_winter_co.paa"};
		class ItemInfo : ItemInfo {
			uniformClass = "mjb_CUP_B_US_SpecOps_W";
		};
    };


#if __has_include("\Armbands\Facewear\Data\Colors\G_Armband_blk_CO.paa")
	class G_Armband_NVG_blk_F;
	class G_Armband_NVG_blk_alt_F;
	class G_Armband_NVG_rats_F : G_Armband_NVG_blk_F {
		displayName = "Armband [RATS]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_rats_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_armband_blk_CA.paa";
	};
	class G_Armband_NVG_rats_alt_F : G_Armband_NVG_blk_alt_F {
		displayName = "Armband [RATS, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_rats_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_armband_blk_CA.paa";
	};
	class G_Armband_NVG_canada_F : G_Armband_NVG_blk_F {
		displayName = "Armband [Canada]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_canada_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_red_ca.paa";
	};
	class G_Armband_NVG_canada_alt_F : G_Armband_NVG_blk_alt_F {
		displayName = "Armband [Canada, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_canada_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_red_ca.paa";
	};
	class G_Armband_NVG_pride_F : G_Armband_NVG_blk_F {
		displayName = "Armband [Pride]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_pride_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_red_ca.paa";
	};
	class G_Armband_NVG_pride_alt_F : G_Armband_NVG_blk_alt_F {
		displayName = "Armband [Pride, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_pride_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_red_ca.paa";
	};
	class G_Armband_NVG_trans_F : G_Armband_NVG_blk_F {
		displayName = "Armband [Trans]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_trans_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_red_ca.paa";
	};
	class G_Armband_NVG_trans_alt_F : G_Armband_NVG_blk_alt_F {
		displayName = "Armband [Trans, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_trans_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_red_ca.paa";
	};
	class G_Armband_NVG_glxy_F : G_Armband_NVG_blk_F {
		displayName = "Armband [Galaxy]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_glxy_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_yel_ca.paa";
	};
	class G_Armband_NVG_glxy_alt_F : G_Armband_NVG_blk_alt_F {
		displayName = "Armband [Galaxy, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_glxy_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_yel_ca.paa";
	};
#endif
};

#if __has_include("\Armbands\Facewear\Data\Colors\G_Armband_blk_CO.paa")
class CfgGlasses {
	class G_Armband_blk_F;
	class G_Armband_blk_alt_F;
	class G_Armband_rats_F : G_Armband_blk_F {
		displayName = "Armband [RATS]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_rats_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_armband_blk_CA.paa";
	};
	class G_Armband_rats_alt_F : G_Armband_blk_alt_F {
		displayName = "Armband [RATS, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_rats_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_armband_blk_CA.paa";
	};
	class G_Armband_canada_F : G_Armband_blk_F {
		displayName = "Armband [Canada]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_canada_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_red_ca.paa";
	};
	class G_Armband_canada_alt_F : G_Armband_blk_alt_F {
		displayName = "Armband [Canada, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_canada_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_red_ca.paa";
	};
	class G_Armband_pride_F : G_Armband_blk_F {
		displayName = "Armband [Pride]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_pride_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_yel_ca.paa";
	};
	class G_Armband_pride_alt_F : G_Armband_blk_alt_F {
		displayName = "Armband [Pride, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_pride_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_yel_ca.paa";
	};
	class G_Armband_trans_F : G_Armband_blk_F {
		displayName = "Armband [Trans]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_trans_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_pnk_ca.paa";
	};
	class G_Armband_trans_alt_F : G_Armband_blk_alt_F {
		displayName = "Armband [Trans, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_trans_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_pnk_ca.paa";
	};
	class G_Armband_glxy_F : G_Armband_blk_F {
		displayName = "Armband [Galaxy]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_glxy_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_yel_ca.paa";
	};
	class G_Armband_glxy_alt_F : G_Armband_blk_alt_F {
		displayName = "Armband [Galaxy, alt]";
		hiddenSelectionsTextures[] = {"z\mjb\addons\flags\data\G_Armband_glxy_CO.paa"};
		picture = "\Armbands\Facewear\Data\UI\icon_Armband_yel_ca.paa";
	};
};
#endif