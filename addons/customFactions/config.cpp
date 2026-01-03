class CfgPatches {
  class mjb_CustomFactions {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "Custom Factions";
	requiredAddons[]=
        {
            
        };
    };
	skipWhenMissingDependencies = 1;
};

// Groups/TMF
class CfgVehicles {
	#include "CfgVehicles_customUnits.hpp"
};
#include "CfgGroups.hpp" // Custom Faction Group config
#include "Extended_InitPost_EventHandlers.hpp" // Custom Faction Group loadout assignment through TMF
#include "CfgLoadouts.hpp" // Custom Faction Group TMF loadouts

class CfgFactionClasses {
	#include "factionCategories.hpp"
};

// Compositions
class CfgEditorCategories
{
	#include "factionCategories.hpp"
};

class CfgEditorSubcategories
{
	class mjb_air
	{
		displayName = "Planes";
	};
	class mjb_Arm
	{
		displayName = "Armored";
	};
	class mjb_Hel
	{
		displayName = "Helicopters";
	};
	class mjb_Inf
	{
		displayName = "Infantry";
	};
	class mjb_Mec
	{
		displayName = "Mechanized";
	};
	class mjb_Mot
	{
		displayName = "Motorized";
	};
	class mjb_Tur
	{
		displayName = "Turrets";
	};
};

class Cfg3DEN
{
	class Compositions
	{
		/*
		class ModTag_MyComposition1 // one class per composition
		{
			path = "edenCompositionTestmod\compositionTank";	// pbo path to a folder containing header.sqe/composition.sqe files
			side = 0;											// 0 opfor, 1 blufor, 2 indfor, 3 civ, 8 Empty/Props
			editorCategory = "EdCat_NATO";						// link to CfgEditorCategories
			editorSubcategory = "EdSubcat_Armored";				// link to CfgEditorSubcategories
			displayName = "$STR_Composition_Armored01";
			icon = "\A3\ui_f\data\map\markers\nato\b_inf.paa";	// left side icon in groups list
			useSideColorOnIcon = 1;								// 1 == icon is always colored in faction color
		};
		*/
		/*class mjb_customTeam1
		{
			path = "z\mjb\addons\customfactions\custom\CustomTeam";
			side = 0;
			editorCategory = "mjb_customFaction";
			editorSubcategory = "mjb_inf";
			displayName = "CustomTeam";
			icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
			useSideColorOnIcon = 1;
		};
		class mjb_customTeam2 : mjb_customTeam1
		{
			path = "z\mjb\addons\customfactions\custom\CustomTeam2_1";
			displayName = "CustomTeam 2";
		};*/
		
		#include "comps_Beagle_Motostrelki.hpp"
		#include "comps_Beagle_AAF.hpp"
	};
};