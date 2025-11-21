/*
	*Example Loadout for players
	*This is an example loadout made to use as a template for creating loadouts.
	*Faction: Example Russian Forces (EMR Flora)
*/

// CHANGES HERE WILL NOT BE REFLECTED UNLESS A LINE IN DESCRIPTION.ext IS UNCOMMENTED

// Weaponless Baseclass
class baseMan 
{
	displayName = "Unarmed";
	// All Randomized. Use LIST_X("className") for multiple items in an array. 
	uniform[] = 
	{
		LIST_2("CUP_U_O_RUS_Soldier_Reversible_Suit_6Sh122_Summer_1"),
		LIST_2("CUP_U_O_RUS_Soldier_Reversible_Suit_6Sh122_Summer_2"),
		LIST_2("CUP_U_O_RUS_Soldier_Reversible_Suit_6Sh122_Summer_3"),
		LIST_2("CUP_U_O_RUS_Soldier_Reversible_Suit_6Sh122_Summer_4")
	};
	vest[] = 
	{
		LIST_3("CUP_V_O_RUS_6B45_6Sh117_SPP_AK_Summer"),
        LIST_2("CUP_V_O_RUS_6B45_6Sh117_AK_Summer"),
		"CUP_V_O_RUS_6B45_6Sh117_AK_Radio_Summer"
	};
	backpack[] = 
	{
		LIST_1("")
	};
	headgear[] = 
	{
		LIST_2("CUP_H_RUS_6B47_Summer"),
		LIST_2("CUP_H_RUS_6B47_NV_Summer"),
		LIST_2("CUP_H_RUS_6B47_6M2_Summer"),
		LIST_2("CUP_H_RUS_6B47_6B34U_Summer"),
		"CUP_H_RUS_6B47_6B34D_Summer",
		"CUP_H_RUS_6B47_6M21_Summer"
	};
	goggles[] = {"default"};
	hmd[] = {};
	// Leave empty to not change faces and Insignias -> example: faces[] = {};
	faces[] = {};
	insignias[] = {};
	
	//All Randomized. Add Primary Weapon and attachments.
	//Leave Empty to remove all. {"Default"} for using original items the character start with.
	primaryWeapon[] = {};
	scope[] = {};
	bipod[] = {};
	attachment[] = {};
	silencer[] = {};
	
	// *WARNING* secondaryAttachments[] arrays are NOT randomized.
	secondaryWeapon[] = {};
	secondaryAttachments[] = {};
	sidearmWeapon[] = {};
	sidearmAttachments[] = {};
	
	// These are added to the uniform or vest first - overflow goes to backpack if there's any.
	magazines[] = {};
	items[] = 
	{
		#if __has_include("\z\ace\addons\medical_engine\script_component.hpp")
			#if __has_include("\z\ace\addons\nomedical\script_component.hpp")
				LIST_2("FirstAidKit")
			#else
				LIST_2("ACE_fieldDressing"),
				LIST_2("ACE_packingBandage"),
				LIST_2("ACE_quikclot"),
				"ACE_tourniquet",
				"ACE_morphine",
				"ACE_splint"
			#endif
		#else
			LIST_2("FirstAidKit")
		#endif
	};
	
	// These are added directly into their respective slots
	linkedItems[] = 
	{
		"ItemWatch",
		"ItemMap",
		"ItemCompass",
		"ItemRadio"
	};
	
	// These are put directly into the backpack.
	backpackItems[] = {};
	
	// This is executed (server-side) after the unit init is complete. Argument: _this = _unit.
	code = "if !(local _this) exitWith {}; _this spawn mjb_arsenal_fnc_tmfSpawnFix;";//"0 = _this execVM ""loadouts\TMFspawnFix.sqf"";"; //
    /* tmfSpawnFix sets stam/fatigue off, iFatigue sway, and adds APS stuff for TMF Respawns */
};

//Since this a loadout used by enemies only - we don't need to define a bunch of different classes, roles such as AAR, Team Leader, and etc are redundant.
class r : baseMan
{
	displayName = "Rifleman";
	primaryWeapon[] = 
	{
		"CUP_arifle_AK12_black"
	};
	scope[] = 
	{
		LIST_6(""),
		"CUP_optic_1P87_RIS"
	};
	silencer[] = {};
	magazines[] = 
	{
		"CUP_HandGrenade_RGD5",
		LIST_4("CUP_30Rnd_545x39_AK12_M")
	};
};

class g : r 
{
	displayName = "Grenadier";
	primaryWeapon[] = 
	{
		"CUP_arifle_AK12_GP34_black"
	};
	vest[] = 
	{
		LIST_2("CUP_V_O_RUS_6B45_1_6Sh117_VOG_Summer"),
        LIST_2("CUP_V_O_RUS_6B45_1_6Sh117_SPP_VOG_Summer"),
		"CUP_V_O_RUS_6B45_1_6Sh117_SPP_VOG_Radio_Light_Summer",
		"CUP_V_O_RUS_6B45_1_6Sh117_VOG_Radio_Light_Summer",
		"CUP_V_O_RUS_6B45_1_6Sh117_VOG_Radio_Summer"
	};
	magazines[] += 
	{
		LIST_5("CUP_1Rnd_HE_GP25_M"),
		LIST_2("CUP_1Rnd_SMOKE_GP25_M"),
		LIST_2("CUP_IlumFlareWhite_GP25_M"),
		LIST_2("CUP_30Rnd_TE1_Green_Tracer_545x39_AK12_M")
	};
};

class mg : r
{
	displayName = "Machine Gunner";
	primaryWeapon[] = 
	{
		"CUP_lmg_Pecheneg"
	};
	scope[] = 
	{
		LIST_6(""),
		LIST_2("CUP_optic_1p63"),
		LIST_2("CUP_optic_OKP_7"),
		"CUP_optic_PechenegScope"
	};
	sidearmWeapon[] = {
		"hgun_Rook40_F"
	};
	silencer[] = {};
	vest[] = 
	{
		LIST_5("CUP_V_O_RUS_6B45_6Sh117_SPP_PKP_Summer"),
		"CUP_V_O_RUS_6B45_6Sh117_SPP_PKP_Radio_Summer"
	};
	magazines[] = 
	{
		LIST_3("CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Green_M"),
		LIST_1("16Rnd_9x21_Mag")
	};
};

class rat : r 
{
	displayName = "Rifleman (LAT)";
	secondaryWeapon[] = 
	{
		"CUP_launch_RPG26"
	};
};

class rrpg : r
{
	displayName = "Rifleman (RPG)";
	backpack[] = 
	{
		"CUP_B_RUS_Patrol_bag_Summer"
	};
	secondaryWeapon[] = 
	{
		"CUP_launch_RPG7V"
	};
	secondaryAttachments[] = 
	{
		LIST_6(""),
		"CUP_optic_PGO7V3"
	};
	backpackItems[] = 
	{
		LIST_2("CUP_PG7V_M"),
		"CUP_PG7VL_M",
		"CUP_OG7_M",
		"CUP_PG7VR_M"
	};
};

class m : r
{
	displayName = "Medic";
	backpack[] = 
	{
		"CUP_B_RUS_Patrol_bag_Summer"
	};
	vest[] = 
	{
		LIST_5("CUP_V_O_RUS_6B45_6Sh117_SPP_AK_Med_Summer"),
		"CUP_V_O_RUS_6B45_6Sh117_SPP_AK_Med_Radio_Summer"
	};
	backpackItems[] = 
	{
		#if __has_include("\z\ace\addons\medical_engine\script_component.hpp")
			#if __has_include("\z\ace\addons\nomedical\script_component.hpp")
				LIST_10("FirstAidKit"),
				"Medikit"
			#else
				LIST_20("ACE_fieldDressing"),
				LIST_10("ACE_elasticBandage"),
				LIST_4("ACE_morphine"),
				LIST_4("ACE_epinephrine"),
				LIST_4("ACE_tourniquet"),
				LIST_4("ACE_suture"),
				LIST_4("ACE_splint"),
				LIST_4("ACE_bloodIV_500"),
				LIST_2("ACE_bloodIV")
				
			#endif
		#else
			LIST_10("FirstAidKit"),
			"Medikit"
		#endif
	};
};
