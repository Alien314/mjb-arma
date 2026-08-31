class CfgPatches {
  class mjb_vs_m320_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {"mjb_hkm320_nostock","mjb_hkm320tan_nostock","mjb_hkm320haki_nostock","mjb_hkm320_pistol_nostock","mjb_hkm320tan_pistol_nostock","mjb_hkm320khaki_pistol_nostock"};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "vs_m320 tweak";
		requiredAddons[]=
		{
			"sar_109_series"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgWeapons {
	class hkm320;
	class mjb_hkm320_nostock : hkm320 {
		baseWeapon = "mjb_hkm320_nostock";
		displayname = "Hk M320 (stockless)";
		hiddenSelectionsMaterials[] = {"","varkion_hkm320\data\hkgrip.rvmat","varkion_hkm320\data\hkkapak.rvmat","varkion_hkm320\data\hknisangah2.rvmat","varkion_hkm320\data\hknisangah.rvmat","varkion_hkm320\data\hktop.rvmat"};
		hiddenSelectionsTextures[]=
		{
			"",
			"varkion_hkm320\data\hkgrip_co.paa",
			"varkion_hkm320\data\hkkapak_co.paa",
			"varkion_hkm320\data\hknisangah2_co.paa",
			"varkion_hkm320\data\hknisangah_co.paa",
			"varkion_hkm320\data\hktop_co.paa"
		};
	};
	class m320tan;
	class mjb_hkm320tan_nostock : m320tan {
		baseWeapon = "mjb_hkm320tan_nostock";
		displayname = "Hk M320 Tan (stockless)";
		hiddenSelectionsMaterials[] = {"","varkion_hkm320\data\tan\hkgriptan.rvmat","varkion_hkm320\data\tan\hkkapaktan.rvmat","varkion_hkm320\data\hknisangah2.rvmat","varkion_hkm320\data\tan\hknisangahtan.rvmat","varkion_hkm320\data\hktop.rvmat"};
		hiddenSelectionsTextures[]=
		{
			"",
			"varkion_hkm320\data\tan\hkgriptan_co.paa",
			"varkion_hkm320\data\tan\hkkapaktan_co.paa",
			"varkion_hkm320\data\hknisangah2_co.paa",
			"varkion_hkm320\data\tan\hknisangahtan_co.paa",
			"varkion_hkm320\data\hktop_co.paa"
		};
	};
	class m320haki;
	class mjb_hkm320haki_nostock : m320tan {
		baseWeapon = "mjb_hkm320haki_nostock";
		displayname = "Hk M320 Khaki (stockless)";
		hiddenSelectionsMaterials[] = {"","varkion_hkm320\data\tan\hkgriptan.rvmat","varkion_hkm320\data\tan\hkkapaktan.rvmat","varkion_hkm320\data\hknisangah2.rvmat","varkion_hkm320\data\tan\hknisangahtan.rvmat","varkion_hkm320\data\hktop.rvmat"};
		hiddenSelectionsTextures[]=
		{
			"",
			"varkion_hkm320\data\tan\hkgriptan_co.paa",
			"varkion_hkm320\data\khaki\hkkapakkhaki_co.paa",
			"varkion_hkm320\data\hknisangah2_co.paa",
			"varkion_hkm320\data\tan\hknisangahtan_co.paa",
			"varkion_hkm320\data\hktop_co.paa"
		};
	};
	class hkm320_pistol;
	class mjb_hkm320_pistol_nostock : hkm320_pistol {
		baseWeapon = "mjb_hkm320_pistol_nostock";
		displayname = "Hk M320 (Pistol/stockless)";
		hiddenSelectionsMaterials[] = {"","varkion_hkm320\data\hkgrip.rvmat","varkion_hkm320\data\hkkapak.rvmat","varkion_hkm320\data\hknisangah2.rvmat","varkion_hkm320\data\hknisangah.rvmat","varkion_hkm320\data\hktop.rvmat"};
		hiddenSelectionsTextures[]=
		{
			"",
			"varkion_hkm320\data\hkgrip_co.paa",
			"varkion_hkm320\data\hkkapak_co.paa",
			"varkion_hkm320\data\hknisangah2_co.paa",
			"varkion_hkm320\data\hknisangah_co.paa",
			"varkion_hkm320\data\hktop_co.paa"
		};
	};
	class hkm320tan_pistol;
	class mjb_hkm320tan_pistol_nostock : hkm320tan_pistol {
		baseWeapon = "mjb_hkm320tan_pistol_nostock";
		displayname = "Hk M320 Tan (Pistol/stockless)";
		hiddenSelectionsMaterials[] = {"","varkion_hkm320\data\tan\hkgriptan.rvmat","varkion_hkm320\data\tan\hkkapaktan.rvmat","varkion_hkm320\data\hknisangah2.rvmat","varkion_hkm320\data\tan\hknisangahtan.rvmat","varkion_hkm320\data\hktop.rvmat"};
		hiddenSelectionsTextures[]=
		{
			"",
			"varkion_hkm320\data\tan\hkgriptan_co.paa",
			"varkion_hkm320\data\tan\hkkapaktan_co.paa",
			"varkion_hkm320\data\hknisangah2_co.paa",
			"varkion_hkm320\data\tan\hknisangahtan_co.paa",
			"varkion_hkm320\data\hktop_co.paa"
		};
	};
	class hkm320khaki_pistol;
	class mjb_hkm320khaki_pistol_nostock : hkm320khaki_pistol {
		baseWeapon = "mjb_hkm320khaki_pistol_nostock";
		displayname = "Hk M320 Khaki (Pistol/stockless)";
		hiddenSelectionsMaterials[] = {"","varkion_hkm320\data\tan\hkgriptan.rvmat","varkion_hkm320\data\tan\hkkapaktan.rvmat","varkion_hkm320\data\hknisangah2.rvmat","varkion_hkm320\data\tan\hknisangahtan.rvmat","varkion_hkm320\data\hktop.rvmat"};
		hiddenSelectionsTextures[]=
		{
			"",
			"varkion_hkm320\data\tan\hkgriptan_co.paa",
			"varkion_hkm320\data\khaki\hkkapakkhaki_co.paa",
			"varkion_hkm320\data\hknisangah2_co.paa",
			"varkion_hkm320\data\tan\hknisangahtan_co.paa",
			"varkion_hkm320\data\hktop_co.paa"
		};
	};
};