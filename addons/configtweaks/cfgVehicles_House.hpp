class NonStrategic;


// create new CfgDamageAround, replace HouseBase's and House's,
// vanilla structures mostly inherit from House_F
//class House_EP1;
//*/
class HouseBase : NonStrategic {

	class DestructionEffects {
		class DamageAround1 {
			intensity = 1;
			interval = 1;
			lifeTime = 1;
			position = "";
			simulation = "damageAround";
			//start = 10;
			//enable = 1;
			type = "MJB_DamageAroundCUP";
		};
		class DestroyPhase1 {
			intensity = 1;
			interval = 1;
			lifeTime = 2.5;
			position = "";
			simulation = "destroy";
			type = "DelayedDestruction";
		};
		class Sound {
			intensity = 1;
			interval = 1;
			lifeTime = 0.125;
			position = "destructionEffect1";
			simulation = "sound";
			type = "DestrHouse";
		};
	};
};

class House : HouseBase {
	class DestructionEffects : DestructionEffects {
		class DamageAround1 : DamageAround1 {
			type = "MJB_DamageAroundCUP";
		};
	};
};

class House_EP1 : House {
	class DestructionEffects : DestructionEffects {
		class DamageAround1 : DamageAround1 {
			type = "MJB_DamageAroundCUP";
		};
	};
};
class House_F : House {

	class DestructionEffects : DestructionEffects {
		class DamageAround1 : DamageAround1 {
			type = "DamageAroundHouse";
		};
	};
};
class House_Small_F : House_F {
	class DestructionEffects : DestructionEffects {
		class DamageAround1 : DamageAround1 {
			type = "DamageAroundHouse";
		};
	};
};

class Church : House {
	class DestructionEffects : DestructionEffects {
		class DamageAround1 : DamageAround1 {
			type = "DamageAroundHouse";
		};
	};
};//*/

//*/

// takistan gas missing ace refuel
#define REFUEL_INFINITE_FUEL -10
class Land_Ind_FuelStation_Feed_EP1 : House_EP1 {
	transportFuel = 0;
	ace_refuel_hooks[] = {{0.35, 0, -0.4}, {-0.35, 0, -0.4}};
	ace_refuel_fuelCargo = REFUEL_INFINITE_FUEL;
};