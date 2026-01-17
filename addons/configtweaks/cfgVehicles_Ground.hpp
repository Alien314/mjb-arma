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