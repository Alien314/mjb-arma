class CfgPatches {
  class mjb_maxwomen_additions {
    ammo[] = {};
    magazines[] = {};
    units[] = {"mjb_WBSoldier_W_F"};
    weapons[] = {"U_B_CombatUniform_mcamW_W"};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "Max Women Additions";
	requiredAddons[]=
    {
        "Max_WS"
	};
    skipWhenMissingDependencies = 1;
  };
};

class CfgWeapons {
	class UniformItem;
	class Uniform_Base;
	class U_B_CombatUniform_mcam_W : Uniform_Base { class ItemInfo; };
	class U_B_CombatUniform_mcamW_W : U_B_CombatUniform_mcam_W {
		displayName = "Combat Fatigues Woman (MTP-Winter)";
		hiddenSelectionsTextures[] = {"\z\mjb\addons\flags\data\suitpack_soldier_blufor_w_co.paa"};
		class ItemInfo : ItemInfo {
			uniformClass = "mjb_WB_Soldier_W_F";
		};
	};
};
#define MAG_2(a) a, a
#define MAG_3(a) a, a, a
#define MAG_10(a) a, a, a, a, a, a, a, a, a, a
class CfgVehicles {
	class WB_Soldier_F;
	class mjb_WB_Soldier_W_F : WB_Soldier_F {
		displayName = "Riflewoman Winter";
		hiddenSelectionsTextures[] = {"\z\mjb\addons\flags\data\clothing1W_co.paa"};
		linkedItems[] = { "V_PlateCarrier2_blk", "mjb_H_HelmetSpecB_winter", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "CUP_NVG_PVS15_winter" };
		magazines[] = { MAG_10(30Rnd_65x39_caseless_black_mag), MAG_3(16Rnd_9x21_Mag), "SmokeShell", "mjb_SmokeShellLightBlue", "Chemlight_green", "Chemlight_green", MAG_2(HandGrenade) };
		respawnMagazines[] = { MAG_10(30Rnd_65x39_caseless_black_mag), MAG_3(16Rnd_9x21_Mag), "SmokeShell", "mjb_SmokeShellLightBlue", "Chemlight_green", "Chemlight_green", MAG_2(HandGrenade) };
		weapons[] = { "arifle_MX_Black_ACO_Pointer_F", "hgun_P07_blk_F", "Throw", "Put" };
		respawnWeapons[] = { "arifle_MX_Black_ACO_Pointer_F", "hgun_P07_blk_F", "Throw", "Put" };
		uniformClass = "U_B_CombatUniform_mcamW_W";
	};
};