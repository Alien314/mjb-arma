class NonStrategic;


// create new CfgDamageAround, replace HouseBase's and House's,
// vanilla structures mostly inherit from House_F
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
	};
};

class House : HouseBase {

	class DestructionEffects : DestructionEffects {
		class DamageAround1 : DamageAround1 {
			type = "MJB_DamageAroundCUP";
		};
	};
};

class House_F : House {

	class DestructionEffects : DestructionEffects {
		class DamageAround1 {
			intensity = 1;
			interval = 1;
			lifeTime = 1;
			position = "";
			simulation = "damageAround";
			type = "DamageAroundHouse";
		};
	};
};

class Church : House {

	class DestructionEffects : DestructionEffects {
		class DamageAround1 {
			intensity = 1;
			interval = 1;
			lifeTime = 1;
			position = "";
			simulation = "damageAround";
			type = "DamageAroundHouse";
		};
	};
};