class mjb_BeagleMoto_base
{
	path = "";	// pbo path to a folder containing header.sqe/composition.sqe files
	side = 0;											// 0 opfor, 1 blufor, 2 indfor, 3 civ, 8 Empty/Props
	editorCategory = "mjb_BeagleMoto";					// link to CfgEditorCategories
	editorSubcategory = "mjb_Inf";				// link to CfgEditorSubcategories
	displayName = "";
	icon = "";	// left side icon in groups list
	useSideColorOnIcon = 1;								// 1 == icon is always colored in faction color
};
// Infantry
class mjb_BeagleMoto_Team : mjb_BeagleMoto_base {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\Motostrelki%20Team";
	displayName = "Motostrelki Team";
	icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
};
class mjb_BeagleMoto_MATRPG : mjb_BeagleMoto_Team {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\MAT%20RPG-7%20Team";
	displayName = "MAT RPG-7 Team";
};
class mjb_BeagleMoto_MMGPKP : mjb_BeagleMoto_Team {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\MMG%20PKP%20Team";
	displayName = "MMG PKP Team";
};
class mjb_BeagleMoto_Plt : mjb_BeagleMoto_Team {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\Motostrelki%20Platoon";
	displayName = "Motostrelki Platoon";
};

// Recon
class mjb_BeagleMoto_DMRSVD : mjb_BeagleMoto_Team
{
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\DMR%20SVD%20Team";
	displayName = "DMR SVD Team";
	icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
};

// HQ
class mjb_BeagleMoto_HQSquad : mjb_BeagleMoto_Team {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\HQ%20Squad";
	displayName = "HQ Squad";
	icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
};

// Turret
class mjb_BeagleMoto_KORD : mjb_BeagleMoto_base {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\KORD%20Tripod";
	displayName = "KORD Tripod";
	editorSubcategory = "mjb_Tur";
	icon = "\A3\ui_f\data\map\markers\nato\o_installation.paa";
};

// Motorized
class mjb_BeagleMoto_SquadUral : mjb_BeagleMoto_base {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\Motostrelki%20Squad%20+%20Ural";
	displayName = "Motostrelki Squad + Ural";
	editorSubcategory = "mjb_Mot";
	icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
};
class mjb_BeagleMoto_SupplyUral : mjb_BeagleMoto_SquadUral {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\Supply%20Ural_1";
	displayName = "Supply Ural";
};
class mjb_BeagleMoto_UAZIgla : mjb_BeagleMoto_SquadUral {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\UAZ%20IGLA";
	displayName = "UAZ IGLA";
};
class mjb_BeagleMoto_UAZMG : mjb_BeagleMoto_SquadUral {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\UAZ%20MG";
	displayName = "UAZ MG";
};
class mjb_BeagleMoto_UAZSPG : mjb_BeagleMoto_SquadUral {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\UAZ%20SPG-9";
	displayName = "UAZ SPG-9";
};
class mjb_BeagleMoto_ZSUUral : mjb_BeagleMoto_SquadUral {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\ZSU%20Ural";
	displayName = "ZSU Ural";
};

// Mechanized
class mjb_BeagleMoto_BMP2 : mjb_BeagleMoto_base {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\BMP-2";
	displayName = "BMP-2";
	editorSubcategory = "mjb_Mec";
	icon = "\A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
};
class mjb_BeagleMoto_BRDMATGM : mjb_BeagleMoto_BMP2 {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\BRDM%20ATGM";
	displayName = "BRDM ATGM";
};
class mjb_BeagleMoto_BRDMMG : mjb_BeagleMoto_BMP2 {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\BRDM%20MG";
	displayName = "BRDM MG";
};
class mjb_BeagleMoto_BTRAC : mjb_BeagleMoto_BMP2 {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\BTR%20AC";
	displayName = "BTR AC";
};
class mjb_BeagleMoto_BTRACATGM : mjb_BeagleMoto_BMP2 {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\BTR%20AC%20ATGM";
	displayName = "BTR AC ATGM";
};
class mjb_BeagleMoto_BTRMG : mjb_BeagleMoto_BMP2 {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\BTR%20MG";
	displayName = "BTR MG";
};
class mjb_BeagleMoto_HQBRDM : mjb_BeagleMoto_BMP2 {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\HQ%20BRDM";
	displayName = "HQ BRDM";
	icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
};
class mjb_BeagleMoto_Shilka : mjb_BeagleMoto_BMP2 {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\Shilka";
	displayName = "Shilka";
	icon = "\A3\ui_f\data\map\markers\nato\o_antiair.paa";
};

// Armored
class mjb_BeagleMoto_T72: mjb_BeagleMoto_base {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\T-72_1";
	displayName = "T-72";
	editorSubcategory = "mjb_Arm";
	icon = "\A3\ui_f\data\map\markers\nato\o_armor.paa";
};

// Air
class mjb_BeagleMoto_Mi24V: mjb_BeagleMoto_base {
	path = "z\mjb\addons\customfactions\Beagle\RU Motostrelki\Mi-24V";
	displayName = "Mi-24V";
	editorSubcategory = "mjb_Hel";
	icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
};