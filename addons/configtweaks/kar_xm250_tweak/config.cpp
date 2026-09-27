class CfgPatches {
  class mjb_kar_xm250_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "KAR_XM250 tweak";
		requiredAddons[]=
		{
			"KAR_XM7","KAR_XM250"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgAmmo {
	class KAR_65x51_Fury_Ammo_YT;
	class mjb_KAR_65x51_Fury_Ammo_IR : KAR_65x51_Fury_Ammo_YT {
		nvgOnly = 1;
		tracerScale = 0.4;
	};
};

class CfgMagazines {
	class CA_Magazine;
	class KAR_100Rnd_Fury: CA_Magazine {
		greenmag_basicammo = "greenmag_beltlinked_762x51_basic";
		greenmag_canSpeedload = 0;
		greenmag_needBelt = 1;
		lastroundstracer=5;
	};

	class KAR_100Rnd_Fury_RT : KAR_100Rnd_Fury {
		lastroundstracer=5;
	};

	class KAR_100Rnd_Fury_YT : KAR_100Rnd_Fury {
		tracersevery=1;
	};

	class KAR_100Rnd_Fury_GT : KAR_100Rnd_Fury {
		tracersevery=1;
	};

	class mjb_KAR_100Rnd_Fury_IR : KAR_100Rnd_Fury_YT {
		displayname = "100rnd .277 Fury (IR-DIM Tracer)";
		ammo = "mjb_KAR_65x51_Fury_Ammo_IR";
	};

	class mjb_KAR_100Rnd_Fury_IR_TE4 : mjb_KAR_100Rnd_Fury_IR {
		displayname = "100rnd .277 Fury (IR-DIM Mixed)";
		tracersevery=4;
	};

	class mjb_KAR_100Rnd_Fury_YT_TE4 : KAR_100Rnd_Fury_YT {
		displayname = "100rnd .277 Fury (Yellow Mixed)";
		tracersevery=4;
	};

	class mjb_KAR_100Rnd_Fury_RT_TE4 : KAR_100Rnd_Fury_RT {
		displayname = "100rnd .277 Fury (Red Mixed)";
		tracersevery=4;
	};

	class mjb_KAR_100Rnd_Fury_GT_TE4 : KAR_100Rnd_Fury_GT {
		displayname = "100rnd .277 Fury (Green Mixed)";
		tracersevery=4;
	};


	class KAR_20Rnd_Fury: CA_Magazine {
		greenmag_basicammo = "greenmag_ammo_762x51_basic_1Rnd";
		greenmag_canSpeedload = 1;
		greenmag_needBelt = 0;
		mass = 12;
	};
	class KAR_20Rnd_Fury_YT: KAR_20Rnd_Fury {
		tracersevery=1;
	};
	class KAR_20Rnd_Fury_GT: KAR_20Rnd_Fury {
		tracersevery=1;
	};

	class mjb_KAR_20Rnd_Fury_IR : KAR_20Rnd_Fury_YT {
		displayname = "20rnd .277 Fury (IR-DIM Tracer)";
		ammo = "mjb_KAR_65x51_Fury_Ammo_IR";
	};
	class mjb_KAR_20Rnd_Fury_IR_blk : mjb_KAR_20Rnd_Fury_IR {
		displayname = "20rnd .277 Fury (Black/IR-DIM Tracer)";
		hiddenselectionstextures[] = {"KAR_XM7\data\tex\magazine_blk_co.paa"};
		picture = "\KAR_XM7\data\ui\KAR_XM7_Mag_blk_ca.paa";
	};
};

class CfgMagazineWells {
	class KAR_XM250_MW {
		mjb_mags[] = {"mjb_KAR_100Rnd_Fury_IR","mjb_KAR_100Rnd_Fury_IR_TE4","mjb_KAR_100Rnd_Fury_RT_TE4","mjb_KAR_100Rnd_Fury_YT_TE4","mjb_KAR_100Rnd_Fury_GT_TE4"};
	};
	class KAR_XM7_MW {
		mjb_mags[] = {"mjb_KAR_20Rnd_Fury_IR","mjb_KAR_20Rnd_Fury_IR_blk"};
	};
};

class Mode_SemiAuto;
class Mode_FullAuto;
class CfgWeapons {
	class Rifle_Base_F;
	class KAR_XM250 : Rifle_Base_F {
		class single : Mode_SemiAuto {
			class BaseSoundModeType;
			class SilencedSound : BaseSoundModeType {
				SoundSetShot[] = {"MMG02_silencerShot_SoundSet","jsrs_2025_tailsystem_65mm_lmg_silenced_soundset"};
				//SoundSetShot[] = {"MMG02_silencerShot_SoundSet","MMG02_silencerTail_SoundSet","MMG02_silencerInteriorTail_SoundSet"};
			};
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = {"MMG02_Shot_SoundSet","jsrs_2025_tailsystem_65mm_lmg_soundset"};
				//soundSetShot[] = {"MMG02_Shot_SoundSet","MMG02_Tail_SoundSet","MMG02_InteriorTail_SoundSet"};
			};
		};
		class manual : Mode_FullAuto {
			class BaseSoundModeType;
			class SilencedSound : BaseSoundModeType {
				SoundSetShot[] = {"MMG02_silencerShot_SoundSet","jsrs_2025_tailsystem_65mm_lmg_silenced_soundset"};
				//SoundSetShot[] = {"MMG02_silencerShot_SoundSet","MMG02_silencerTail_SoundSet","MMG02_silencerInteriorTail_SoundSet"};
			};
			class StandardSound : BaseSoundModeType {
				soundSetShot[] = {"MMG02_Shot_SoundSet","jsrs_2025_tailsystem_65mm_lmg_soundset"};
				//soundSetShot[] = {"MMG02_Shot_SoundSet","MMG02_Tail_SoundSet","MMG02_InteriorTail_SoundSet"};
			};
		};
	};
	class KAR_XM7 : Rifle_Base_F {
		class Single : Mode_SemiAuto {
			class SilencedSound {
				soundSetShot[] = {"KAR_XM7_silencerShot_SoundSet","jsrs_2025_tailsystem_65mm_rifle_silenced_soundset"};
				//soundSetShot[] = {"KAR_XM7_silencerShot_SoundSet","KAR_XM7_silencerTail_SoundSet"};
			};
			class StandardSound {
				soundSetShot[] = {"jsrs_2025_mk20_shot_soundset","jsrs_2025_tailsystem_65mm_rifle_soundset"};
				//soundSetShot[] = {"Msbs65_01_Shot_SoundSet","Msbs65_01_Tail_SoundSet","Mx_Tail_Contact_SoundSet"};
			};
		};
		class FullAuto : Mode_FullAuto {
			class SilencedSound {
				soundSetShot[] = {"KAR_XM7_silencerShot_SoundSet","jsrs_2025_tailsystem_65mm_rifle_silenced_soundset"};
				//soundSetShot[] = {"KAR_XM7_silencerShot_SoundSet","KAR_XM7_silencerTail_SoundSet"};
			};
			class StandardSound {
				soundSetShot[] = {"jsrs_2025_mk20_shot_soundset","jsrs_2025_tailsystem_65mm_rifle_soundset"};
				//soundSetShot[] = {"Msbs65_01_Shot_SoundSet","Msbs65_01_Tail_SoundSet","Mx_Tail_Contact_SoundSet"};
			};
		};
	};
};
