/**
    * Adds curated arsenal to player that disables itself under specified conditions.
    *
    * Faction: MJB ARMA default PMCs
    *
    * Usage - under initPlayerLocal.sqf
    * 0 = execVM 'loadouts\arsenal.sqf';
    *
    * New framework update by NotherDuck
    * Equipment and quality hat choices by MajorDanvers
    * Formatting by veerserif
    *
    * v0.5 - 2021-08-20:
        - Removed ACRE Radios
        - Removed EFT Uniforms with Beltstaff Pants (White LOD Issue)
        - Added weapons and attachments requested in framework doc.
        - Gave all roles access to tracers where possible.
        - Moved DMRs (M14, SR-25, SVDS) and Shortdot to seperate role (_itemWeaponSharpshooter).
        - Added LAT Equipment (_itemWeaponLAT).
    * v1.0 - 2021-08-21:
        - Fixed several typos with magazines and added some missing ones (150 rnd 7.62x54r Box)
        - Moved shotguns and smgs to seperate section (_itemWeaponCQB, still given to all classes with normal rifles)
        - Added section for high capacity rifle mags (_itemWeaponHighCapAmmo, given to SF)
    * v1.1 - 2021-08-26:
        - Added ACRE radios back to arsenal.
        - Removed CUP lasers.
        - Fixed some roles not having access to pistols.
        - Added NAPA drip hoodie.
    * v1.1a - 2021-08-31:
        - Removed heli coveralls from normal infantry roles.
        - Gave tank and air crews access to CQB weapons.
    * v1.2 - 2021-09-01:
        - Added carbine variants requested by VierLeger (VHS-K2, ACR-C, F2000 Tactical, Mk17 CQC, Mk18).
    * v1.2a - 2021-09-14:
        - Added the AK-104 and AK-74M.
        - Changed AK-105 variant to B-13 version (rail can be removed using CTRL+C by default to access dovetail sights)
        - Fixed LAT and HAT roles having access to binoculars.
    * v2.0 - 2021-10-08:
        - Replaced all RHS and T1 content with CUP versions
        - Added trivial cosmetics for specific roles (ex. AR, Leaders)
    * v2.1 - 2022-01-22:
        - AKA the RHS one
            - All AR-pattern rifles switched out for RHS variants
            - RHS AKs added to augment our CUP AKs(yay for folding stocks!)
            - RHS optics and accessories added
            - Some RHS cosmetics added
            - Added some vanilla fatigues to match our MWS fatigues
            - More backpack colors
            - M110 SASS and M14 EBR for sharpshooters
            - TAR-21 for vanilla troopers
    * v2.1a - 2022-01-30:
            - Left most CUP AR-pattern rifles for GL roles, some might prefer the holo dot gl sight
            - Prioritized model quality and variety when removing/replacing guns, CUP has nicer wood furniture usually.
            - Added RHS disposables and RPG-7 with similar AT strength rockets
            - ACE Vector and RHS Binocs
            - Couple RHSGREF camos
            - Winter variable to enable winter camo gear, these are currently weaker than our normal gear
            - Added RHS rifles to Sharpshooter and Sniper
            - Replaced CUP MP7 and added PP2000 and M590 in CQB weapons
            - Added M145 optic and a couple RHS AR options to ARs
            - Gave SF some vests from the pre-nuke arsenal, RHS AS Val, and a special pistol
            - Gave helo and tank crews pre-nuke vests (sorry air ;-;)
            - Blyat
            - Beltstaff yeeted (un-yeeted non-bugged shirts)
            - Added 20 round 9x39 mag and corrected 9x39 ammo box class name to ball
        - 2022-02-02:
            - Gave up trying to limit size and added a ton more weapons
            - Removed a few redundancies
        -2022-02-04:
            - Scav uniforms
        -2022-02-11:
            - MMG team (mjbLOVE to Banzerschreck), not shaking down AR yet
            - Moved non-base/med backpacks into _itemPackMedium and _itemPackHeavy

    * Arguments:
      * 0: Apply to JIPs, players coming in after will use these parameters to generate
              a personal arsenal, default: false <BOOLEAN> !!Must be Global Exec'd to work!!
      * 1: Role for the target(s) to use, nil or "" to use TMF, or unit type.
              default: TMF role, (typeOf _unit) if no TMF role set in editor <STRING>
      * 2: Remove existing Personal Arsenal, default: true <BOOLEAN>
      * 3: Additional gear to include <ARRAY> of <STRING> class names, default: []
      * 4: Winter camo available, default: true <BOOLEAN>

      !! JIP param true Must be Global Exec'd to work !!

    ex.: [true, nil, true, ["ACRE_BF888S","tier1_exps3_0_g33_black_up"]] call mjb_arsenal_fnc_arsenalAmmo;
*/

private _tracer = "";
private _sideID = ((side player) call BIS_fnc_sideID);
private _blufor = _sideID isEqualTo 1;
if (_tracer isEqualTo "") then {_tracer = ['yellow','red'] select _blufor};

//if !(didJIP) then {
    if (isNil "mjb_arsenalAmmo") then {
        mjb_arsenalAmmo = "building" createVehicleLocal [0,0,0];
    };
	[mjb_arsenalAmmo, false] call ace_arsenal_fnc_removeBox;
//};

#include "_arsenalMacros.hpp"

// !!paste limit!!

//Define Arsenal Items

private _itemWeaponPistol =
[

    //Magazines
    "CUP_13Rnd_9x19_Browning_HP",
    "CUP_16Rnd_9x19_cz75",
    "CUP_17Rnd_9x19_M17_Black",
    "CUP_8Rnd_9x18_Makarov_M",
    "CUP_12Rnd_45ACP_mk23",
    "CUP_15Rnd_9x19_M9",
    "CUP_7Rnd_45ACP_1911",
    "CUP_17Rnd_9x19_glock17",
    "CUP_8Rnd_762x25_TT",

    "rhs_mag_9x19_17",

    "Tier1_15Rnd_9x19_JHP",
    "Tier1_17Rnd_9x19_P320_JHP",

    //Loose ammo
    "greenmag_ammo_9x19_basic_30Rnd",
    "greenmag_ammo_9x21_basic_30Rnd",
    "greenmag_ammo_45ACP_basic_30Rnd",
    "greenmag_ammo_9x18_basic_30Rnd",
    "greenmag_ammo_762x25_ball_30Rnd"
];

private _itemLeaderEquipment =
[

    "CUP_6Rnd_45ACP_M",
    "CUP_7Rnd_50AE_Deagle",
    "6Rnd_45ACP_Cylinder",

    "greenmag_ammo_50AE_ball_30Rnd"
];

private _itemWeaponAmmo =
[
    //============================================================
    //5.56x45mm
    //============================================================
    //Magazines
    "CUP_30Rnd_556x45_Emag",
    "CUP_30Rnd_556x45_PMAG_QP",
    "CUP_30Rnd_556x45_PMAG_BLACK_PULL",
    "CUP_30Rnd_556x45_XM8",
    "CUP_25Rnd_556x45_Famas",
    "CUP_30Rnd_556x45_AK",
    "CUP_20Rnd_556x45_Stanag",

    //Loose ammo
    "greenmag_ammo_556x45_basic_60Rnd",

    //============================================================
    //5.45x39mm
    //============================================================
    //Magazines
    "CUP_30Rnd_545x39_Fort224_M",
    "CUP_30Rnd_545x39_AK_M",
    "CUP_30Rnd_545x39_AK74M_M",

    //Loose ammo
    "greenmag_ammo_545x39_basic_60Rnd",

    //============================================================
    //7.62x39mm
    //============================================================
    //Magazines
    "CUP_30Rnd_762x39_AK47_bakelite_M",
    "CUP_30Rnd_762x39_AK47_M",
    "CUP_30Rnd_Sa58_M",

    "rhs_30Rnd_762x39mm_Savz58",

    //Loose ammo
    "greenmag_ammo_762x39_basic_60Rnd",

    //============================================================
    //7.62x51mm
    //============================================================
    //Magazines
    "CUP_20Rnd_762x51_FNFAL_M",
    "CUP_20Rnd_762x51_B_SCAR",
    "CUP_20Rnd_762x51_HK417",
    "CUP_20Rnd_762x51_G3",

    //Loose ammo
    "greenmag_ammo_762x51_basic_60Rnd",

    //============================================================
    //7.62x54mm
    //============================================================
    //Magazines
    //Loose ammo
    "greenmag_ammo_762x54_basic_60Rnd",

    //============================================================
    //Grenades
    //============================================================
    //HE and frags
    "HandGrenade",

    //Smokes
    "SmokeShell",
    "SmokeShellGreen",
    "SmokeShellRed",
    "SmokeShellPurple",
    "SmokeShellBlue",

    //Make eyeballs hurt
    "ACE_M84",
    "ACE_Chemlight_HiGreen",
	"ACE_Chemlight_IR"
];


private ['_itemWeaponTracerAmmo','_itemWeaponHighCapAmmo','_itemWeaponARAmmo'];
//Red Tracer
if (_tracer isEqualTo 'red') then {
	_itemWeaponTracerAmmo =
	[
		"CUP_64Rnd_Red_Tracer_9x19_Bizon_M",

		//============================================================
		//5.56x45mm
		//============================================================
		"CUP_30Rnd_556x45_Emag_Tracer_Red",
		"CUP_30Rnd_556x45_PMAG_BLACK_PULL_Tracer_Red",
		"CUP_30Rnd_556x45_PMAG_QP_Tracer_Red",
		"CUP_30Rnd_TE1_Red_Tracer_556x45_XM8",
		"CUP_25Rnd_556x45_Famas_Tracer_Red",
		"CUP_30Rnd_TE1_Red_Tracer_556x45_AK",
		"CUP_30Rnd_556x45_Tracer_Red_AK19_M",
		"CUP_20Rnd_556x45_Stanag_Tracer_Red",

		//============================================================
		//5.45x39mm
		//============================================================
		"CUP_30Rnd_TE1_Red_Tracer_545x39_Fort224_M",
		"CUP_30Rnd_TE1_Red_Tracer_545x39_AK74M_M",

		//============================================================
		//7.62x39mm
		//============================================================
		"CUP_30Rnd_TE1_Red_Tracer_762x39_AK47_bakelite_M",
		"CUP_30Rnd_Sa58_M_TracerR",
		"CUP_30Rnd_TE1_Red_Tracer_762x39_AK47_M",

		"rhs_30Rnd_762x39mm_Savz58_tracer",

		//============================================================
		//7.62x51mm
		//============================================================
		"CUP_20Rnd_TE1_Red_Tracer_762x51_FNFAL_M",
		"CUP_20Rnd_TE1_Red_Tracer_762x51_SCAR",
		"CUP_20Rnd_TE1_Red_Tracer_762x51_HK417",
		"CUP_20Rnd_TE1_Red_Tracer_762x51_G3"

		//============================================================
		//7.62x54mm
		//============================================================

		//============================================================
		//Misc Calibers (SMGs, Shotguns, Etc.)
		//============================================================
	];

	_itemWeaponHighCapAmmo =
	[
		//============================================================
		//5.56x45mm
		//============================================================
		"CUP_60Rnd_556x45_SureFire",
		"CUP_60Rnd_556x45_SureFire_Tracer_Red",
		"CUP_50Rnd_556x45_Red_Tracer_Galil_Mag",

		//============================================================
		//5.45x39mm
		//============================================================
		"CUP_45Rnd_TE4_LRT4_Green_Tracer_545x39_RPK74M_M",
		"CUP_60Rnd_545x39_AK74M_M",
		"CUP_60Rnd_TE1_Red_Tracer_545x39_AK74M_M",

		//============================================================
		//7.62x39mm
		//============================================================
		"CUP_40Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M",
		"CUP_45Rnd_Sa58_M",
		"CUP_45Rnd_Sa58_M_TracerR",
		"CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M",

		//============================================================
		//7.62x51mm
		//============================================================
		"CUP_30Rnd_762x51_FNFAL_M",
		"CUP_30Rnd_TE1_Red_Tracer_762x51_FNFAL_M"

		//============================================================
		//7.62x54mm
		//============================================================
	];

	_itemWeaponARAmmo =
	[
		//============================================================
		//5.56x45mm
		//============================================================
		//Boxes
		"CUP_200Rnd_TE4_Red_Tracer_556x45_M249",
		"CUP_100Rnd_TE4_Red_Tracer_556x45_M249",
		//Loose belts
		GREENMAG_BELT(556x45),

		//============================================================
		//7.62x51mm
		//============================================================
		//Boxes
		"CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
		"CUP_120Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
		//Loose belts
		GREENMAG_BELT(762x51),

		//============================================================
		//7.62x54mmR
		//============================================================
		//Boxes
		"CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Red_M",

		//Loose belts
		GREENMAG_BELT(762x54)
	];
} else {

// yellow trace
	_itemWeaponTracerAmmo =
	[
		"CUP_64Rnd_Yellow_Tracer_9x19_Bizon_M",

		//============================================================
		//5.56x45mm
		//============================================================
		"CUP_30Rnd_556x45_Emag_Tracer_Yellow",
		"CUP_30Rnd_556x45_PMAG_BLACK_PULL_Tracer_Yellow",
		"CUP_30Rnd_556x45_PMAG_QP_Tracer_Yellow",
		"CUP_30Rnd_TE1_Yellow_Tracer_556x45_XM8",
		"CUP_25Rnd_556x45_Famas_Tracer_Yellow",
		"CUP_30Rnd_TE1_Yellow_Tracer_556x45_AK",
		"CUP_30Rnd_556x45_TE1_Tracer_Green_AK19_Tan_M",
		"CUP_20Rnd_556x45_Stanag_Tracer_Yellow",

		//============================================================
		//5.45x39mm
		//============================================================
		"CUP_30Rnd_TE1_Yellow_Tracer_545x39_Fort224_M",
		"CUP_30Rnd_TE1_Yellow_Tracer_545x39_AK74M_M",

		//============================================================
		//7.62x39mm
		//============================================================
		"CUP_30Rnd_TE1_Yellow_Tracer_762x39_AK47_bakelite_M",
		"CUP_30Rnd_Sa58_M_TracerY",
		"CUP_30Rnd_TE1_Yellow_Tracer_762x39_AK47_M",

		"rhs_30Rnd_762x39mm_Savz58_tracer",

		//============================================================
		//7.62x51mm
		//============================================================
		"CUP_20Rnd_TE1_Yellow_Tracer_762x51_FNFAL_M",
		"CUP_20Rnd_TE1_Yellow_Tracer_762x51_SCAR",
		"CUP_20Rnd_TE1_Yellow_Tracer_762x51_HK417",
		"CUP_20Rnd_TE1_Yellow_Tracer_762x51_G3"

		//============================================================
		//7.62x54mm
		//============================================================

		//============================================================
		//Misc Calibers (SMGs, Shotguns, Etc.)
		//============================================================
	];

	_itemWeaponHighCapAmmo =
	[
		//============================================================
		//5.56x45mm
		//============================================================
		"CUP_60Rnd_556x45_SureFire",
		"CUP_60Rnd_556x45_SureFire_Tracer_Yellow",
		"CUP_50Rnd_556x45_Green_Tracer_Galil_Mag",

		//============================================================
		//5.45x39mm
		//============================================================
		"CUP_45Rnd_TE4_LRT4_Green_Tracer_545x39_RPK74M_M",
		"CUP_60Rnd_545x39_AK74M_M",
		"CUP_60Rnd_TE1_Yellow_Tracer_545x39_AK74M_M",

		//============================================================
		//7.62x39mm
		//============================================================
		"CUP_40Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M",
		"CUP_45Rnd_Sa58_M",
		"CUP_45Rnd_Sa58_M_TracerY",
		"CUP_75Rnd_TE4_LRT4_Green_Tracer_762x39_RPK_M",

		//============================================================
		//7.62x51mm
		//============================================================
		"CUP_30Rnd_762x51_FNFAL_M",
		"CUP_30Rnd_TE1_Yellow_Tracer_762x51_FNFAL_M"

		//============================================================
		//7.62x54mm
		//============================================================
	];

	_itemWeaponARAmmo =
	[
		//============================================================
		//5.56x45mm
		//============================================================
		//Boxes
		"CUP_200Rnd_TE4_Yellow_Tracer_556x45_M249",
		"CUP_100Rnd_TE4_Yellow_Tracer_556x45_M249",
		//Loose belts
		GREENMAG_BELT(556x45),

		//============================================================
		//7.62x51mm
		//============================================================
		//Boxes
		"CUP_100Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M",
		"CUP_120Rnd_TE4_LRT4_Yellow_Tracer_762x51_Belt_M",
		//Loose belts
		GREENMAG_BELT(762x51),

		//============================================================
		//7.62x54mmR
		//============================================================
		//Boxes
		"CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Yellow_M",

		//Loose belts
		GREENMAG_BELT(762x54)
	];
};

private _itemWeaponARAmmo =
[
    //============================================================
    //5.56x45mm
    //============================================================
    //Boxes
    "CUP_200Rnd_TE4_Red_Tracer_556x45_M249",
    "CUP_100Rnd_TE4_Red_Tracer_556x45_M249",
    //Loose belts
    GREENMAG_BELT(556x45),

    //============================================================
    //7.62x51mm
    //============================================================
    //Boxes
    "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
    "CUP_120Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
    //Loose belts
    GREENMAG_BELT(762x51),

    //============================================================
    //7.62x54mmR
    //============================================================
    //Boxes
    "CUP_100Rnd_TE4_LRT4_762x54_PK_Tracer_Red_M",

    //Loose belts
    GREENMAG_BELT(762x54)
];

private _itemWeaponSharpshooter =
[

    //============================================================
    //Magazines
    //============================================================
    //7.62x51mm
    "ace_20rnd_762x51_m118lr_mag",
    "ace_20rnd_762x51_mag_tracer",

    "rhsusf_20Rnd_762x51_SR25_m993_Mag",

    //7.62x54mmR
    "ace_10rnd_762x54_tracer_mag",
	"CUP_10Rnd_762x54_SVD_M",

    "rhs_10Rnd_762x54mmR_7N14"
];

private _itemSniper =
[

    "ace_5rnd_127x99_api_mag",

    "CUP_10Rnd_127x99_M107",
    "CUP_5Rnd_127x99_as50_M",
    "CUP_10Rnd_762x51_CZ750",
    "CUP_5Rnd_86x70_L115A1",
    "CUP_5Rnd_127x108_KSVK_M",
    "CUP_5Rnd_762x51_M24",

    "rhsusf_5Rnd_762x51_m118_special_Mag",
    "rhsusf_5Rnd_762x51_m993_Mag",
    "rhsusf_10Rnd_762x51_m118_special_Mag",
    "rhsusf_10Rnd_762x51_m993_Mag",
    "rhs_5Rnd_338lapua_t5000",

    "CUP_40Rnd_46x30_MP7"
];
private _itemSniperAmmo = [
    "greenmag_ammo_127x99_basic_30Rnd",
    "greenmag_ammo_127x99_basic_60Rnd",
    "greenmag_ammo_127x108_basic_30Rnd",
    "greenmag_ammo_127x108_basic_60Rnd",
    "greenmag_ammo_338_basic_30Rnd",
    "greenmag_ammo_338_basic_60Rnd",
    "greenmag_ammo_46x30_basic_60Rnd",
    "greenmag_ammo_93x64_basic_60Rnd"
];

private _itemWeaponGL =
[
    // Fancy mags
    "CUP_30Rnd_TE1_Green_Tracer_545x39_AK12_Tan_M",
    "CUP_30Rnd_TE1_Green_Tracer_762x39_AK15_Tan_M",
    "CUP_30Rnd_556x45_TE1_Tracer_Green_AK19_Tan_M",//*///only green
	"CUP_30Rnd_556x45_AK19_Tan_M",
    "CUP_30Rnd_680x43_Stanag_Tracer_Red",

    "greenmag_ammo_680x43_tracer_60Rnd",

    //============================================================
    //Grenade Rounds
    //============================================================
    //NATO
    "1Rnd_HE_Grenade_shell",
    "ACE_40mm_Flare_white",
    "ACE_40mm_Flare_ir",
    "1Rnd_Smoke_Grenade_shell",
    "1Rnd_SmokeRed_Grenade_shell",
    "1Rnd_SmokeBlue_Grenade_shell",
    "1Rnd_SmokeGreen_Grenade_shell",

	"CUP_1Rnd_HEDP_M203",
	"rhs_mag_M433_HEDP",

	"mjb_blug",

    //Rusfor
    "CUP_1Rnd_HE_GP25_M",
    "CUP_IlumFlareWhite_GP25_M",
    "CUP_1Rnd_SMOKE_GP25_M",
    "CUP_1Rnd_SmokeRed_GP25_M",
    "CUP_1Rnd_SmokeGreen_GP25_M",
    "rhs_VOG25",
    "rhs_VG40TB",

	"mjb_VOGMDP",
	"mjb_slog"
];

private _itemWeaponMMGAmmo =
[
	"ace_150rnd_762x54_box_red",
	"CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
    "150Rnd_762x51_Box_Tracer",
    "130Rnd_338_Mag",
    "mjb_130Rnd_338_Mag_trc_red",
    "150Rnd_93x64_Mag",
    "mjb_150Rnd_93x64_Mag_trc_red",
    GREENMAG_BELT(338),
    GREENMAG_BELT(93x64)
];

private _itemSF =
[
    "CUP_20Rnd_B_AA12_Buck_00",
    "CUP_20Rnd_B_AA12_Slug",
    "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",

    "mjb_13Rnd_65x25_Browning_HP",
    "mjb_16Rnd_65x25_cz75",
    "mjb_17Rnd_65x25_M17",
    "mjb_15Rnd_65x25_M9",
    "mjb_17Rnd_65x25_glock17",
    "mjb_30Rnd_65x25_MP5",
    "mjb_30Rnd_65x25_Vityaz",
    "rhs_20rnd_9x39mm_SP6",
    "rhs_18rnd_9x21mm_7BT3",
    "rhs_18rnd_9x21mm_7N29",

    "Tier1_SIG_MCX_115_Virtus_300BLK",
    "Tier1_30Rnd_762x35_300BLK_RNBT_EMag",
    "Tier1_30Rnd_762x35_300BLK_SMK_EMag",
    "Tier1_30Rnd_762x35_300BLK_EMag"
];

if (canSuspend) then {waitUntil { !isNull player };};

private _exWeap = (magazines player + [currentMagazine player]);

_exWeap apply {	
	private _return = _x;
	private _ammo = getText (configFile >> "CfgMagazines" >> _x >> 'ammo');
	{
		if (_ammo isKindOf [_x,configFile >> "CfgAmmo"]) exitWith {_return = ""}
	} forEach ["RocketBase","MissileBase","TimeBombCore"];
	_return
};

_itemWeaponAmmo append _exWeap;

private _greenmagArray = "'basic' in (configName _x) && {getNumber (_x >> 'scopeArsenal') > 1 && {getNumber (_x >> 'greenmag_bullets') in [24,60,100,200]}}" configClasses (configFile >> "CfgWeapons") apply {configName _x};
_greenmagArray append ['greenmag_ammo_9x39_ball_60Rnd','greenmag_ammo_303_ball_60Rnd','greenmag_ammo_50AE_ball_60Rnd','greenmag_ammo_765x17_ball_60Rnd'];

[mjb_arsenalAmmo, (_greenmagArray + _itemWeaponPistol + _itemWeaponAmmo + _itemWeaponTracerAmmo + _itemWeaponMMGAmmo + _itemWeaponARAmmo + _itemLeaderEquipment + _itemSF + _itemWeaponSharpshooter + _itemWeaponGL + _itemSniper + _itemSniperAmmo /*+ _itemWeaponSFAR*/)] call ace_arsenal_fnc_initBox;

if (isClass (configFile >> "CfgPatches" >> "greenmag_main")) then {
  if (isNil "mjb_greenmagButtonId") then {mjb_greenmagButtonId = -1;};
  mjb_greenmagButtonId = [_greenmagArray, "Greenmag","\A3\ui_f\data\igui\cfg\weaponicons\MG_ca.paa", mjb_greenmagButtonId] call ace_arsenal_fnc_addRightPanelButton;
};

[mjb_arsenalAmmo, player] call ace_arsenal_fnc_openBox;