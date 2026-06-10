class CfgPatches {
  class mjb_project_sfx_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "Project SFX tweak";
		requiredAddons[]=
		{
			"SFX_Project_Remastered"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgAmmo
{
	class Default;
	class Grenade;
	class GrenadeHand: Grenade
	{

		impactArmor[] = {"soundImpactIron1",0.3,"soundImpactIron2",0.3,"soundImpactIron3",0.3,"soundImpactIron4",0.3,"soundImpactIron5",0.3};
		impactBuilding[] = {"soundImpactHard1",0.3,"soundImpactHard2",0.3,"soundImpactHard3",0.3,"soundImpactHard4",0.2,"soundImpactHard5",0.2,"soundImpactHard6",0.2,"soundImpactHard7",0.2};
		impactConcrete[] = {"soundImpactHard1",0.3,"soundImpactHard2",0.3,"soundImpactHard3",0.3,"soundImpactHard4",0.2,"soundImpactHard5",0.2,"soundImpactHard6",0.2,"soundImpactHard7",0.2};
		impactDefault[] = {"soundImpactHard1",0.3,"soundImpactHard2",0.3,"soundImpactHard3",0.3,"soundImpactHard4",0.2,"soundImpactHard5",0.2,"soundImpactHard6",0.2,"soundImpactHard7",0.2};
		impactFoliage[] = {"soundImpactSoft1",0.3,"soundImpactSoft2",0.3,"soundImpactSoft3",0.3,"soundImpactSoft4",0.2,"soundImpactSoft5",0.2,"soundImpactSoft6",0.2,"soundImpactSoft7",0.2};
		impactGlass[] = {"soundImpactHard1",0.3,"soundImpactHard2",0.3,"soundImpactHard3",0.3,"soundImpactHard4",0.2,"soundImpactHard5",0.2,"soundImpactHard6",0.2,"soundImpactHard7",0.2};
		impactGlassArmored[] = {"soundImpactHard1",0.3,"soundImpactHard2",0.3,"soundImpactHard3",0.3,"soundImpactHard4",0.2,"soundImpactHard5",0.2,"soundImpactHard6",0.2,"soundImpactHard7",0.2};
		impactGroundHard[] = {"soundImpactHard1",0.3,"soundImpactHard2",0.3,"soundImpactHard3",0.3,"soundImpactHard4",0.2,"soundImpactHard5",0.2,"soundImpactHard6",0.2,"soundImpactHard7",0.2};
		impactGroundSoft[] = {"soundImpactSoft1",0.2,"soundImpactSoft2",0.2,"soundImpactSoft3",0.2,"soundImpactSoft4",0.1,"soundImpactSoft5",0.1,"soundImpactSoft6",0.1,"soundImpactSoft7",0.1};
		impactIron[] = {"soundImpactIron1",0.3,"soundImpactIron2",0.3,"soundImpactIron3",0.3,"soundImpactIron4",0.3,"soundImpactIron5",0.3};
		impactMan[] = {"soundImpactMan1",0.35,"soundImpactMan2",0.35,"soundImpactMan3",0.35,"soundImpactMan4",0.35};
		impactMetal[] = {"soundImpactIron1",0.3,"soundImpactIron2",0.3,"soundImpactIron3",0.3,"soundImpactIron4",0.3,"soundImpactIron5",0.3};
		impactMetalplate[] = {"soundImpactIron1",0.3,"soundImpactIron2",0.3,"soundImpactIron3",0.3,"soundImpactIron4",0.3,"soundImpactIron5",0.3};
		impactPlastic[] = {"soundImpactSoft1",0.3,"soundImpactSoft2",0.3,"soundImpactSoft3",0.3,"soundImpactSoft4",0.2,"soundImpactSoft5",0.2,"soundImpactSoft6",0.2,"soundImpactSoft7",0.2};
		impactRubber[] = {"soundImpactSoft1",0.3,"soundImpactSoft2",0.3,"soundImpactSoft3",0.3,"soundImpactSoft4",0.2,"soundImpactSoft5",0.2,"soundImpactSoft6",0.2,"soundImpactSoft7",0.2};
		impactTyre[] = {"soundImpactSoft1",0.3,"soundImpactSoft2",0.3,"soundImpactSoft3",0.3,"soundImpactSoft4",0.2,"soundImpactSoft5",0.2,"soundImpactSoft6",0.2,"soundImpactSoft7",0.2};
		impactWater[] = {"soundImpactWater1",0.36,"soundImpactWater2",0.36,"soundImpactWater3",0.31};
		impactWood[] = {"soundImpactWoodExt1",0.35,"soundImpactWoodExt2",0.35,"soundImpactWoodExt3",0.35,"soundImpactWoodExt4",0.35};
/*
		soundGlass1[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_glass_01.wav",
			2,
			1,
			65
		};
		soundGlass2[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_glass_02.wav",
			2,
			1,
			65
		};
		soundGlass3[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_glass_03.wav",
			2,
			1,
			65
		};
		soundGlass4[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_glass_01.wav",
			2,
			1,
			65
		};
		soundGlass5[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_glass_02.wav",
			2,
			1,
			65
		};
		soundGlass6[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_glass_03.wav",
			2,
			1,
			65
		};
		soundGlass7[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_glass_01.wav",
			2,
			1,
			65
		};
		soundGlass8[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_glass_02.wav",
			2,
			1,
			65
		};
		soundImpactHard1[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_01.wav",
			2,
			1,
			65
		};
		soundImpactHard2[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_02.wav",
			2,
			1,
			65
		};
		soundImpactHard3[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_03.wav",
			2,
			1,
			65
		};
		soundImpactHard4[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_02.wav",
			2,
			1,
			65
		};
		soundImpactHard5[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_03.wav",
			2,
			1,
			65
		};
		soundImpactHard6[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_01.wav",
			2,
			1,
			65
		};
		soundImpactHard7[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_02.wav",
			2,
			1,
			65
		};
		soundImpactIron1[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_metal_02.wav",
			2,
			1,
			65
		};
		soundImpactIron2[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_metal_01.wav",
			2,
			1,
			65
		};
		soundImpactIron3[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_metal_03.wav",
			2,
			1,
			65
		};
		soundImpactIron4[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_metal_02.wav",
			2,
			1,
			65
		};
		soundImpactIron5[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_metal_01.wav",
			2,
			1,
			65
		};
		soundImpactSoft1[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_02.wav",
			2,
			1,
			65
		};
		soundImpactSoft2[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_03.wav",
			2,
			1,
			65
		};
		soundImpactSoft3[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_01.wav",
			2,
			1,
			65
		};
		soundImpactSoft4[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_02.wav",
			2,
			1,
			65
		};
		soundImpactSoft5[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_03.wav",
			2,
			1,
			65
		};
		soundImpactSoft6[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_01.wav",
			2,
			1,
			65
		};
		soundImpactSoft7[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_02.wav",
			2,
			1,
			65
		};
		soundImpactWoodExt1[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_wood_01.wav",
			2,
			1,
			75
		};
		soundImpactWoodExt2[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_wood_02.wav",
			2,
			1,
			75
		};
		soundImpactWoodExt3[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_wood_03.wav",
			2,
			1,
			75
		};
		soundImpactWoodExt4[]=
		{
			"\SFX_ProjectR\SFX\player\mills_bounce_wood_04.wav",
			2,
			1,
			75
		};
*/
	};

	class SmokeShell;
	class Chemlight_base : SmokeShell {
		// restore vanilla/JSRS?
		soundGlass1[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_01",1.77828,1,100};
		soundGlass2[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_02",1.77828,1,100};
		soundGlass3[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_03",1.77828,1,100};
		soundGlass4[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_04",1.77828,1,100};
		soundGlass5[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_05",1.77828,1,100};
		soundGlass6[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_06",1.77828,1,100};
		soundGlass7[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_07",1.77828,1,100};
		soundGlass8[] = {"A3\Sounds_F\arsenal\sfx\bullet_hits\glass_08",1.77828,1,100};
		soundImpactSoft1[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_1",1.41254,1,45};
		soundImpactSoft2[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_2",1.41254,1,45};
		soundImpactSoft3[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_3",1.41254,1,45};
		soundImpactSoft4[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_4",1.41254,1,45};
		soundImpactSoft5[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_5",1.41254,1,45};
		soundImpactSoft6[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_6",1.41254,1,45};
		soundImpactSoft7[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_grass_7",1.41254,1,45};
		soundImpactWater1[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_water_1",1.41254,1,55};
		soundImpactWater2[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_water_2",1.41254,1,55};
		soundImpactWater3[] = {"A3\Sounds_F\weapons\Grenades\handgrenade_drops\handg_drop_water_3",1.41254,1,55};
	};
};