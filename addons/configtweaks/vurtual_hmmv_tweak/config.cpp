class CfgPatches {
  class mjb_vurt_hmmwv_tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "Vurtual Hmmwv Tweaks";
	requiredAddons[]=
    {
        "vurtual_m998","vurtual_m998_avenger","vurtual_m998_cargo","vurtual_m998_gmv",
		"vurtual_m998_m1025","vurtual_m998_m1100","vurtual_m998_trailer"
	};
    skipWhenMissingDependencies = 1;
  };
};

class CfgVehicles {
	class Car;
	class Car_F : Car { 
		class Hitpoints {
			class HitBody;
			class HitEngine;
			class HitHull;
		};
	};

	class vurtual_hmmwv_base : Car_F {
		armor = 60; // 80
		armorGlass = 0.6; // 0.99
		//armorStructural = 4; // 4
		armorWheels = 0.1; // 0.8
		crewCrashProtection = 1; // 1
		class Hitpoints : Hitpoints {
			class HitBody : HitBody {
				armor = 6;
				explosionShielding = 1.5;
				minimalHit = 0.01;
				passThrough = 1;
				radius = 0.25;
			};
			class HitEngine : HitEngine {
				armor = 0.5;
				explosionShielding = 0.2;
				minimalHit = 0.2;
				radius = 0.45;
			};
			class HitFuel {
				armor = 0.5;
				explosionShielding = 0.2;
				minimalHit = 0.2;
				passThrough = 0.5;
				radius = 0.25;
			};
			class HitHull : HitHull {
				armor = 1;
				explosionShielding = 0.6;
				minimalHit = 0.2;
				passThrough = 0.5;
				radius = 0.25;
			};
		};
	};
};