class CfgPatches {
  class mjb_blue_tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "Blue Tracers tweak";
	requiredAddons[]=
    {
        "Wentis13_Blue_Tracers"
	};
    skipWhenMissingDependencies = 1;
  };
};


class CfgMagazines {
	/*class rhsusf_100Rnd_762x51 {
		scope = 1;
		displayNameShort = "";
	};*/
	delete rhsusf_100Rnd_762x51_Tracer_Blue;
	delete rhsusf_100Rnd_762x51_Mixed_Tracer_Blue;
	delete rhsusf_100Rnd_762x51;

	class CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M;
	class rhsusf_100Rnd_762x51_Tracer_Blue : CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M {scope = 1;};
	class rhsusf_100Rnd_762x51_Mixed_Tracer_Blue : CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M {scope = 1;};

	delete rhsusf_200Rnd_556x45_tracer_blue_Mixed_soft_pouch;
	delete rhsusf_200Rnd_556x45_tracer_blue_soft_pouch;
	delete rhsusf_200Rnd_556x45_mixed_soft_pouch;
	/*class rhsusf_200Rnd_556x45_mixed_soft_pouch {
		scope = 1;
		displayNameShort = "";
		nameSound = "";
		type = ;
		maxLeadSpeed
	};*/
	class CUP_200Rnd_TE4_Red_Tracer_556x45_M249;
	class rhsusf_200Rnd_556x45_tracer_blue_soft_pouch : CUP_200Rnd_TE4_Red_Tracer_556x45_M249 {scope = 1;};
	class rhsusf_200Rnd_556x45_tracer_blue_Mixed_soft_pouch : CUP_200Rnd_TE4_Red_Tracer_556x45_M249 {scope = 1;};
};

class CfgMagazineWells {

};