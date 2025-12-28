

// Vanilla
class Plane_Base_F;
class Plane;

/*
class Plane_CAS_02_base_F : Plane_Base_F { // yak-130
maxSpeed = 1060; // def 900 kph
};

class Plane_Fighter_03_base_F : Plane_Base_F { // L159 ALCA
//acceleration = 300; // def 220
maxSpeed = 940; // def 800 kph
//thrustCoef[] = {1.42,1.38,1.34,1.3,1.25,1.2,1.19,1.18,1.17,1.17,1.16,1.16,0.1,0,0,0,0};
};

// supersonic jets
class Plane_Fighter_01_Base_F : Plane_Base_F { // black wasp
//acceleration = 300; // def 200, not relevant to planes?
maxSpeed = 1900; // def 1200 kph
};
/*class B_Plane_Fighter_01_Stealth_F : Plane_Fighter_01_Base_F { // black wasp stealth
//acceleration = 300; // def 200
maxSpeed = 1900; // def 1200 kph
//thrustCoef[] = {1.76,1.69,1.62,1.68,1.74,1.81,1.89,1.95,1.96,1.96,1.92,1.4,0.4,0,0,0};
};//*/
/*
class Plane_Fighter_02_Base_F : Plane_Base_F { // Shikra
//acceleration = 300; // def 220
maxSpeed = 1900; // def 1500 kph
};
/*class O_Plane_Fighter_02_Stealth_F : Plane_Fighter_02_Base_F { // Shikra stealth
//acceleration = 300; // def 220
maxSpeed = 1900; // def 1500 kph
//thrustCoef[] = {2.06,2.02,1.99,1.94,1.96,1.99,2.1,2.22,2.4,2.55,2.76,1.71,0.15,0,0,0};
};*/
/*
class Plane_Fighter_04_base_F : Plane_Base_F { // gripen 2100 unladen
//acceleration = 300; // def 220
maxSpeed = 2100; // def 1000 kph
//thrustCoef[] = {1.6,1.58,1.57,1.68,1.76,1.81,1.86,1.91,1.94,1.95,1.52,0.9,0.1,0,0,0};
};
*/

// CUP

// CCIP fixes
class CUP_AV8B_Base : Plane {
	class MFD {
		class parallaxhud {
			class bones  {
				class ImpactPoint {
					pos0[] = {0.5,0.47};
					pos10[] = {0.94,0.92};
					source = "impactpointweaponRelative";
					type = "vector";
				};
				class Limit0109 {
					limits[] = {0.1,0.1,0.9,0.9};
					type = "limit";
				};
			};
			class draw {
				class Bomb {
					class Circle {
						points[] = {{"ImpactPoint",{0,-0.102273},1},{"ImpactPoint",{0.01736,-0.100718},1},{"ImpactPoint",{0.0342,-0.0961057},1},{"ImpactPoint",{0.05,-0.0885682},1},{"ImpactPoint",{0.06428,-0.0783409},1},{"ImpactPoint",{0.0766,-0.0657409},1},{"ImpactPoint",{0.0866,-0.0511364},1},{"ImpactPoint",{0.09397,-0.0349773},1},{"ImpactPoint",{0.09848,-0.0177545},1},{"ImpactPoint",{0.1,0},1},{"ImpactPoint",{0.09848,0.0177545},1},{"ImpactPoint",{0.09397,0.0349773},1},{"ImpactPoint",{0.0866,0.0511364},1},{"ImpactPoint",{0.0766,0.0657409},1},{"ImpactPoint",{0.06428,0.0783409},1},{"ImpactPoint",{0.05,0.0885682},1},{"ImpactPoint",{0.0342,0.0961057},1},{"ImpactPoint",{0.01736,0.100718},1},{"ImpactPoint",{0,0.102273},1},{"ImpactPoint",{-0.01736,0.100718},1},{"ImpactPoint",{-0.0342,0.0961057},1},{"ImpactPoint",{-0.05,0.0885682},1},{"ImpactPoint",{-0.06428,0.0783409},1},{"ImpactPoint",{-0.0766,0.0657409},1},{"ImpactPoint",{-0.0866,0.0511364},1},{"ImpactPoint",{-0.09397,0.0349773},1},{"ImpactPoint",{-0.09848,0.0177545},1},{"ImpactPoint",{-0.1,0},1},{"ImpactPoint",{-0.09848,-0.0177545},1},{"ImpactPoint",{-0.09397,-0.0349773},1},{"ImpactPoint",{-0.0866,-0.0511364},1},{"ImpactPoint",{-0.0766,-0.0657409},1},{"ImpactPoint",{-0.06428,-0.0783409},1},{"ImpactPoint",{-0.05,-0.0885682},1},{"ImpactPoint",{-0.0342,-0.0961057},1},{"ImpactPoint",{-0.01736,-0.100718},1},{"ImpactPoint",{0,-0.102273},1},{},{"ImpactPoint",1,"Limit0109",1,{0,-0.0204545},1},{"ImpactPoint",1,"Limit0109",1,{0.014,-0.0143182},1},{"ImpactPoint",1,"Limit0109",1,{"+ 0.02",0},1},{"ImpactPoint",1,"Limit0109",1,{0.014,0.0143182},1},{"ImpactPoint",1,"Limit0109",1,{0,0.0204545},1},{"ImpactPoint",1,"Limit0109",1,{-0.014,0.0143182},1},{"ImpactPoint",1,"Limit0109",1,{"- 0.02",0},1},{"ImpactPoint",1,"Limit0109",1,{-0.014,-0.0143182},1},{"ImpactPoint",1,"Limit0109",1,{0,-0.0204545},1},{},{"Velocity",0.001,"ImpactPoint",1,"Limit0109",1,{0,0},1},{"Velocity",1,"Limit0109",1,{0,0},1}};
						type = "line";
						width = 4;
					};
					class Distance {
						align = "center";
						down[] = {"ImpactPoint",{-0.002,0.15},1};
						max = 15;
						pos[] = {"ImpactPoint",{-0.002,0.11},1};
						right[] = {"ImpactPoint",{0.045,0.11},1};
						scale = 1;
						source = "ImpactDistance";
						sourcePrecision = 1;
						sourceScale = 0.001;
						type = "text";
					};
				};
			};
		};
	};
};
class CUP_A10_Base : Plane_Base_F {
	class MFD {
		#include "mfdFix.hpp"
	};
};
class CUP_Su25_base : Plane {
	#include "mfdFix_SU25_L39.hpp"
};
class CUP_L39_base : Plane {
	#include "mfdFix_SU25_L39.hpp"
};

class CUP_F35B_base : Plane {  // f35 1700 unladen
//maxSpeed = 1700;
/*
// thrustCoef[] = {1.5,1.2,1.1,1,1,1,1,0.9,0.7,0.5,0.3,0.1,0,0,0,0}; // default
// airFrictionCoefs0[] = {0,0,0};
// airFrictionCoefs1[] = {0.1,0.05,0.006};
// airFrictionCoefs2[] = {0.001,0.0005,6e-05};
*/

	class MFD {
		#include "mfdFix.hpp"
	};
};

class CUP_SU34_BASE : Plane {  // su34 1900
//maxSpeed = 1900;
/*
// thrustCoef[] = {}; // default
*/

	class MFD { // Doesn't show, so copilot required to do stuff accurately :/
		//#include "mfdFix.hpp"
	};

	// fix weird permanent stabilization
	class EventHandlers {
		class mjb_configTweaks {
			init="params ['_this']; _this spawn {sleep 1; if (local _this) then { _this enableDirectionStabilization [false, [0]]; }; };";
		};
	};
	class NewTurret;
	class Turrets {
		class MainTurret : NewTurret {
			class viewOptics {
				//horizontallyStabilized = 0;
				initAngleX = -30;
			};
			gunAimDown = 0;
			//gunnerUsesPilotView = 0;
			inGunnerMayFire = 1;
			//outGunnerMayFire = 0;
			//primaryObserver = 1;
			stabilizedInAxes = 3;
			//unitInfoType = "RscOptics_CAS_Pilot";
			//usePip = 1;
		};
	};//*/
	class UserActions {
		class stab_disable {
			condition = "private _lock = this lockedCameraTo [0]; player isEqualTo (gunner this) && {!isNil '_lock' || { this directionStabilizationEnabled [0] }}";
			displayName = "Disable Camera Stabilization";
			hideOnUse = 1;
			onlyforplayer = 1;
			position = "";
			priority = 3;
			radius = 15;
			shortcut = "vehLockTurretView";
			showWindow = 0;
			statement = "this lockCameraTo [objNull,[0]]; this enableDirectionStabilization [false, [0]];";
		};
		class stab_enable {
			condition = "private _lock = this lockedCameraTo [0]; player isEqualTo (gunner this) && {isNil '_lock' && { !(this directionStabilizationEnabled [0]) }}";
			displayName = "Enable Camera Stabilization";
			displayNameDefault = "";
			hideOnUse = 1;
			onlyforplayer = 1;
			position = "";
			priority = 3;
			radius = 15;
			shortcut = "vehLockTurretView";
			showWindow = 0;
			statement = "if (!isNull cursorObject && {cursorObject isKindOf 'AllVehicles'}) exitWith { systemChat ('Stabilzed on Vehicle at ' + (mapGridPosition cursorObject)); this lockCameraTo [getPosWorld cursorObject,[0]] }; if (!isNull cursorObject) exitWith { systemChat ('Stabilzed on Object at ' + (mapGridPosition cursorObject)); this lockCameraTo [getPosWorld cursorObject,[0]] }; private _loc = terrainIntersectAtASL [(AGLToASL positionCameraToWorld [0,0,0]), (AGLToASL positionCameraToWorld [0,0,10000])]; if (_loc isEqualTo [0,0,0]) exitWith { systemChat 'No target in range'; this enableDirectionStabilization [true, [0]]; }; systemChat ('Stabilzed on Position: ' + mapGridPosition _loc); this lockCameraTo [_loc,[0],true]; this spawn {sleep 0.1; _this enableDirectionStabilization [true, [0]];};";
		};
	};
};
//