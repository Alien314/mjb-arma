// Infantry
class mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Team";	// pbo path to a folder containing header.sqe/composition.sqe files
	displayName = "AAF Team";
	icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";	// left side icon in groups list
	side = 2;											// 0 opfor, 1 blufor, 2 indfor, 3 civ, 8 Empty/Props
	editorCategory = "mjb_BeagleAAF";					// link to CfgEditorCategories
	editorSubcategory = "mjb_Inf";				// link to CfgEditorSubcategories
	useSideColorOnIcon = 1;	 // 1 == icon is always colored in faction color
};
class mjb_BeagleAAF_Squad : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Squad";
	displayName = "AAF Squad";
};
class mjb_BeagleAAF_Plt : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Infantry%20Platoon";
	displayName = "AAF Infantry Platoon";
};
class mjb_BeagleAAF_MAT : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20MAT%20Team";
	displayName = "MAT Team";
};
class mjb_BeagleAAF_MMG : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20MMG%20Team";
	displayName = "MMG Team";
};

// Recon
class mjb_BeagleAAF_DMRTeam : mjb_BeagleAAF_Team
{
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20DMR%20Team";
	displayName = "DMR Team";
	icon = "\A3\ui_f\data\map\markers\nato\n_recon.paa";
};

// HQ
class mjb_BeagleAAF_HQTeam : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20HQ%20Team";
	displayName = "HQ Team";
	icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
};

// Turret
class mjb_BeagleAAF_HMG : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Deployable%20HMG";
	displayName = "Deployable HMG";
	editorSubcategory = "mjb_Tur";
	icon = "\A3\ui_f\data\map\markers\nato\o_installation.paa";
};

// Motorized
class mjb_BeagleAAF_ACarAGL : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20AGL%20Armored%20Car";
	displayName = "AGL Armored Car";
	editorSubcategory = "mjb_Mot";
	icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
};
class mjb_BeagleAAF_ACarHMG : mjb_BeagleAAF_ACarAGL {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20HMG%20Armored%20Car";
	displayName = "HMG Armored Car";
};
class mjb_BeagleAAF_AGLJeep : mjb_BeagleAAF_ACarAGL {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20AGL%20Jeep";
	displayName = "AGL Jeep";
};
class mjb_BeagleAAF_HMGJeep : mjb_BeagleAAF_ACarAGL {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20HMG%20Jeep";
	displayName = "HMG Jeep";
};
class mjb_BeagleAAF_MPADJeep : mjb_BeagleAAF_ACarAGL {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20MANPAD%20Jeep";
	displayName = "MANPAD Jeep";
};
class mjb_BeagleAAF_RepairTruck : mjb_BeagleAAF_ACarAGL {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Repair%20Truck";
	displayName = "Repair Truck";
};

// Mechanized
class mjb_BeagleAAF_IFV : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Warrior%20IFV";
	displayName = "Warrior IFV";
	editorSubcategory = "mjb_Mec";
	icon = "\A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
};
class mjb_BeagleAAF_Pandur : mjb_BeagleAAF_IFV {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Pandur%20IFV";
	displayName = "Pandur IFV";
};
class mjb_BeagleAAF_HMGM113 : mjb_BeagleAAF_IFV {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20HMG%20M113";
	displayName = "HMG M113";
};
class mjb_BeagleAAF_HQM113 : mjb_BeagleAAF_IFV {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20HQ%20M113";
	displayName = "HQ M113";
	icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
};
class mjb_BeagleAAF_Shilka : mjb_BeagleAAF_IFV {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Shilka";
	displayName = "Shilka";
	icon = "\A3\ui_f\data\map\markers\nato\o_antiair.paa";
};

// Armored
class mjb_BeagleAAF_LeoMBT : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Leopard%20MBT";
	displayName = "Leopard MBT";
	editorSubcategory = "mjb_Arm";
	icon = "\A3\ui_f\data\map\markers\nato\o_armor.paa";
};

// Air
class mjb_BeagleAAF_Mi24D : mjb_BeagleAAF_Team {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Mi-24D%20Gunship";
	displayName = "Mi-24D Gunship";
	editorSubcategory = "mjb_Hel";
	icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
};
class mjb_BeagleAAF_Wildcat : mjb_BeagleAAF_Mi24D {
	path = "z\mjb\addons\customfactions\Beagle\AAF\AAF%20Armed%20Helo%20(Wildcat)";
	displayName = "Armed Helo (Wildcat)";
	editorSubcategory = "mjb_Hel";
	icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
};