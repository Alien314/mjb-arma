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


	class KAR_100Rnd_Fury_RT_blk: KAR_100Rnd_Fury_RT
	{
		hiddenselectionstextures[]=
		{
			"KAR_XM250\tex\xm250_04_blk_co.paa"
		};
	};

	class KAR_100Rnd_Fury_YT_blk: KAR_100Rnd_Fury_YT
	{
		hiddenselectionstextures[]=
		{
			"KAR_XM250\tex\xm250_04_blk_co.paa"
		};
	};

	class KAR_100Rnd_Fury_GT_blk: KAR_100Rnd_Fury_GT
	{
		hiddenselectionstextures[]=
		{
			"KAR_XM250\tex\xm250_04_blk_co.paa"
		};
	};


	class KAR_20Rnd_Fury: CA_Magazine {
		greenmag_basicammo = "greenmag_ammo_762x51_basic_1Rnd";
		greenmag_canSpeedload = 1;
		greenmag_needBelt = 0;
		mass = 120;
	};
	class KAR_20Rnd_Fury_YT: KAR_20Rnd_Fury {
		tracersevery=1;
	};
	class KAR_20Rnd_Fury_GT: KAR_20Rnd_Fury {
		tracersevery=1;
	};
};
