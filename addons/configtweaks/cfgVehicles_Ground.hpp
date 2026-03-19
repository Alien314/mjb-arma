class LandVehicle;
class Car : LandVehicle {
	class EventHandlers {
		class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_Base {};
	};
};
class Car_F;

// ACRE intercompartment attenuation
#define ATT_INT 0.6  // attenutation to other compartments
#define ATT_OUT 0.3  // attenutation to own compartment while turned out
#define ATT_ONT 0.75 // attenutation to other compartments while turned out
#define COMPART(var)	class Compartment##var { \
	Compartment1 = ATT_INT; \
	Compartment2 = ATT_INT; \
	Compartment3 = ATT_INT; \
	Compartment4 = ATT_INT; \
}
#define COMPARTOUT1	class Compartment1 { \
	Compartment1 = ATT_OUT; \
	Compartment2 = ATT_ONT; \
	Compartment3 = ATT_ONT; \
	Compartment4 = ATT_ONT; \
}
#define COMPARTOUT2	class Compartment2 { \
	Compartment1 = ATT_ONT; \
	Compartment2 = ATT_OUT; \
	Compartment3 = ATT_ONT; \
	Compartment4 = ATT_ONT; \
}
#define COMPARTOUT3	class Compartment3 { \
	Compartment1 = ATT_ONT; \
	Compartment2 = ATT_ONT; \
	Compartment3 = ATT_OUT; \
	Compartment4 = ATT_ONT; \
}
#define COMPARTOUT4	class Compartment4 { \
	Compartment1 = ATT_ONT; \
	Compartment2 = ATT_ONT; \
	Compartment3 = ATT_ONT; \
	Compartment4 = ATT_OUT; \
}

class Wheeled_APC_F: Car_F {
	class ACRE {
		class attenuation {
			COMPART(1);
			COMPART(2);
			COMPART(3);
			COMPART(4);
		};

		class attenuationTurnedOut {
			COMPARTOUT1;
			COMPARTOUT2;
			COMPARTOUT3;
			COMPARTOUT4;
		};
	};
};

class Tank: LandVehicle {
	class ACRE {
		class attenuation {
			COMPART(1);
			COMPART(2);
			COMPART(3);
			COMPART(4);
		};

		class attenuationTurnedOut {
			COMPARTOUT1;
			COMPARTOUT2;
			COMPARTOUT3;
			COMPARTOUT4;
		};
	};
	class EventHandlers {
		class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_Base {};
	};
};

class Tank_F;
class APC_Tracked_02_base_F;

// CUP
class CUP_BTR60_Base : Wheeled_APC_F {
	class ACRE : ACRE {
		class attenuationTurnedOut : attenuationTurnedOut {
			class Compartment1 : Compartment1 {
				Compartment2 = 0.1; // less attenuation to ride on tops while turned out
			};
		};
	};
};
class CUP_BTR80_Common_Base : Wheeled_APC_F {
	class ACRE : ACRE {
		class attenuationTurnedOut : attenuationTurnedOut {
			class Compartment1 : Compartment1 {
				Compartment2 = 0.1;
			};
		};
	};
};

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

/*/ mis-positioned in center of tank?
class CUP_T72_Base : Tank_F {
	driverForceOptics = 0;
};*/

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
