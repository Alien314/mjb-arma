class LandVehicle;
class Car : LandVehicle {
	class EventHandlers {
		class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_Base {};
	};
};
class Car_F;

delete MainTurret; // useless turret def

class Wheeled_APC_F;

class Tank : LandVehicle {
	class EventHandlers {
		class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_Base {};
	};
};

class Tank_F : Tank {
	class Hitpoints;
	class Turrets;
};
class APC_Tracked_02_base_F;

// CUP

// Unforced Optics
// interior but no vis, unopenable front hatch. addAction?
class CUP_2S6_Base : Tank_F {
	driverForceOptics = 0;
};

// PIP windows provide full front to left arc split, blank forward window
class CUP_BMP1_base : APC_Tracked_02_base_F {
	driverForceOptics = 0;
};

/*/ void
class CUP_BMP2_base : CUP_BMP1_base {
	driverForceOptics = 0;
};*/

/*/ no visibily low res interior
class CUP_BMP3_Base : Tank_F {
	driverForceOptics = 0;
};*/

/* full invisible 360
class CUP_Challenger2_base : Tank_F {
	driverForceOptics = 0;
};*/

/*/ no visibily void interior
class CUP_FV432_Bulldog_Base : Tank_F {
	driverForceOptics = 0;
};*/

/* full invisible 360
class CUP_FV510_Base : Tank_F {
	driverForceOptics = 0;
};*/

// turned out
class CUP_LAV25_Base : Wheeled_APC_F {
	driverForceOptics = 0;
};

/* tracks and turret block LoS but otherwise invisible
class CUP_Leopard2_Base : Tank_F {
	driverForceOptics = 0;
};*/

/*/ unnecessary?
class CUP_M1_Abrams_base : Tank_F {
	driverForceOptics = 0;
};*/

/* unnecessary? has full internal
class CUP_M113_Base : Tank_F {
	driverForceOptics = 0;
};
*/

// front arc and roof invis
class CUP_M2Bradley_Base : Tank_F {
	driverForceOptics = 0;
};

/* full invisible 360, except turret
class CUP_M60A3_Base : Tank_F {
	driverForceOptics = 0;
};*/

/* full invisible 360
class CUP_MCV80_Base : Tank_F {
	driverForceOptics = 0;
};*/

// turned out
class CUP_T34_Base : Tank_F {
	driverForceOptics = 0;
};

// turned out
class CUP_T55_Base : Tank_F {
	driverForceOptics = 0;
};

// mis-positioned in center of tank?
class CUP_T72_Base : Tank_F {
	//driverForceOptics = 0;
	class Hitpoints : Hitpoints {
		class HitEngine {armor = 0.6; armorComponent = "hit_engine"; explosionShielding = 0.2; material = -1; minimalHit = 0.2; name = "hit_engine_point"; passThrough = 0.2; radius = 0.3; visual = "-";};
	};
};

/* pretty limited but clippy into roof, little vis forward
class CUP_T90_Base : Tank_F {
	driverForceOptics = 0;
};*/

/*/ void
class CUP_ZSU23_Base : Tank_F {
	driverForceOptics = 0;
};*/

/*/ void
class CDF_Ext_T72_BASE : Tank_F {
	driverForceOptics = 0;
};*/

// fix can't slot commander
class CUP_T90M_Base : Tank_F {
	class NewTurret;
	class MainTurret;
	class Turrets : Turrets {
		class MainTurret : MainTurret {
			class Turrets : Turrets {
				class CommanderPeriscope : NewTurret {
					primaryObserver = 0;
				};
			};
		};
	};
};
