//if __has_include ("z\dzn_xpi\main\ui\btn_flashlight_on.paa")

//#else
class CfgPatches {
  class mjb_steppers_tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "Steppers Tweak";
    requiredAddons[] = {"jsrs_soundmod_2025_Beta"};
    skipWhenMissingDependencies = 1;
  };
};

// dragon must roar
class CfgAmmo {
  class ShellBase;
  class ace_dragon_serviceCharge : ShellBase {
//"jsrs_2025_explosion_shock_small_soundset","jsrs_2025_explosion_stereo_small_soundset",
    soundsetexplosion[] = {"jsrs_2025_explosion_shock_small_soundset","jsrs_2025_small_explosion_tails_soundset"}; // gooood
    //soundsetexplosion[] = {"jsrs_2025_explosion_shock_medium_soundset","jsrs_2025_explosion_stereo_generic_soundset","jsrs_2025_small_explosion_tails_soundset"};
    //soundsetexplosion[] = {"jsrs_2025_rocket_epl_soundset","jsrs_2025_explosion_stereo_generic_soundset","jsrs_2025_rockets_explosion_tails_soundset"};
    //soundsetexplosion[] = {"jsrs_2025_rockets_explosion_tails_soundset"}; //not as rumbly
    //soundsetexplosion[] = {"jsrs_2025_explosion_stereo_big_soundset","jsrs_2025_explosion_stereo_generic_soundset","jsrs_2025_cannon_tails_soundset"};
    //soundsetexplosion[] = {"jsrs_2025_cannon_tails_soundset"}; // stuttery
    //soundsetexplosion[] = {"jsrs_2025_shell_epl_soundset","jsrs_2025_explosion_stereo_small_soundset","jsrs_2025_small_explosion_tails_soundset"};
    //soundsetexplosion[] = {"jsrs_2025_missile_epl_soundset","jsrs_shell_explosion_stereo_soundset","jsrs_2025_small_explosion_tails_soundset"};
    //soundsetexplosion[] = {"jsrs_shell_explosion_soundset","jsrs_shell_explosion_stereo_soundset","jsrs_shell_explosion_reverb_soundset"}; // old JSRS
  };
};

/*class CfgDistanceFilters {
  class jsrs_2025_footstep_distancefilter {
	//powerFactor = 5;
  };
};*/

class CfgSoundSets {
#define CRAWL(NAME,PARENT) \
  class ##NAME## : ##PARENT## { \
	volumeFactor = 0.35; \
	occlusionFactor = 0.7; \
  }
#define CRAWLIN(NAME,PARENT) \
  class ##NAME## : ##PARENT## { \
	volumeFactor = 0.35; \
	occlusionFactor = 0.0; \
  }
#define SPRINT(NAME,PARENT) \
  class ##NAME## : ##PARENT## { \
	volumeFactor = 0.8; \
	occlusionFactor = 0.3; \
  }
#define SPRINTIN(NAME,PARENT) \
  class ##NAME## : ##PARENT## { \
	volumeFactor = 0.8; \
	occlusionFactor = 0.0; \
  }
#define RUN(NAME,PARENT) \
  class ##NAME## : ##PARENT## { \
	volumeFactor = 0.7; \
	occlusionFactor = 0.4; \
  }
#define RUNIN(NAME,PARENT) \
  class ##NAME## : ##PARENT## { \
	volumeFactor = 0.7; \
	occlusionFactor = 0.0; \
  }
#define TACT(NAME,PARENT) \
  class ##NAME## : ##PARENT## { \
	volumeFactor = 0.5; \
	occlusionFactor = 0.6; \
  }
#define WALKIN(NAME,PARENT) \
  class ##NAME## : ##PARENT## { \
	volumeFactor = 0.45; \
	occlusionFactor = 0.0; \
  }
#define WALK(NAME,PARENT) \
  class ##NAME## : ##PARENT## { \
	volumeFactor = 0.45; \
	occlusionFactor = 0.7; \
  }

  class jsrs_2025_basic_movement_soundset;
  TACT(jsrs_2025_basic_gear_tactical_SoundSet,jsrs_2025_basic_movement_SoundSet);
  RUN(jsrs_2025_basic_gear_run_SoundSet,jsrs_2025_basic_movement_SoundSet);
  SPRINT(jsrs_2025_basic_gear_sprint_SoundSet,jsrs_2025_basic_movement_SoundSet);
  //CRAWL(jsrs_2025_basic_movement_crawl_SoundSet,jsrs_2025_basic_movement_SoundSet);
  //CRAWLIN(jsrs_2025_basic_movement_int_rev_crawl_SoundSet,jsrs_2025_basic_movement_SoundSet);
  //WALK(jsrs_2025_basic_movement_walk_SoundSet,jsrs_2025_basic_movement_SoundSet);
  //WALKIN(jsrs_2025_basic_movemen_int_revt_walk_SoundSet,jsrs_2025_basic_movement_SoundSet);
  TACT(jsrs_2025_basic_movement_tactical_SoundSet,jsrs_2025_basic_movement_SoundSet);
  RUN(jsrs_2025_basic_movement_run_SoundSet,jsrs_2025_basic_movement_SoundSet);
  RUNIN(jsrs_2025_basic_movement_int_run_SoundSet,jsrs_2025_basic_movement_SoundSet);
  SPRINT(jsrs_2025_basic_movement_sprint_SoundSet,jsrs_2025_basic_movement_SoundSet);
  SPRINTIN(jsrs_2025_basic_movement_int_sprint_SoundSet,jsrs_2025_basic_movement_SoundSet);
};


//#endif