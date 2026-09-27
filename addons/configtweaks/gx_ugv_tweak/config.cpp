class CfgPatches {
  class mjb_gx_ugv_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "gx_ugv tweak";
		requiredAddons[]=
		{
			"gx_drones_ugv_themis"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgVehicles {
	class Tank;
	class Tank_F {
		class EventHandlers;
	};
	class GX_THEMIS_UGV_BASE : Tank_F {
		ace_cookoff_canHaveFireJet = 0;
		class EventHandlers : EventHandlers {
			class GX_UGV_THeMIS {
				init = "";
				//postinit = "[_this#0] spawn GX_fnc_drone_postInit; [(_this select 0)] call GX_fnc_themis_init; (_this select 0) animateSource ['hide_lights_as', 1, true]; (_this select 0) switchLight 'OFF'; driver (_this select 0) disableAI 'LIGHTS'; (_this select 0) setHitPointDamage ['#light_red_r', 0.9]; (_this select 0) setHitPointDamage ['#light_red_l', 0.9];";
			};
		};
		class Hitpoints {
			class HitEngine {
				//armor = 7.0; // 5.2
				minimalHit = -0.021;
			};
			class HitFuel {
				//armor = 4.4; // 3.6?
				minimalHit = -0.02;
			};
			class HitHull {
				minimalHit = -0.025;
			};
		};
	};
};
