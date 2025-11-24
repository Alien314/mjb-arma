class CfgPatches {
  class mjb_jca_helmetTweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "JCA Helmet Tweaks";
	requiredAddons[]=
        {
            "Headwear_F_JCA_MHRP"
        };
    skipWhenMissingDependencies = 1;
  };
};
/*
class CfgWeapons {
  class JCA_H_HelmetHBK_base_F;
  class JCA_H_HelmetHBK_olive_F : JCA_H_HelmetHBK_base_F {
    hiddenSelectionsTextures[] = {"headwear_f_JCA_MHRP\Data\H_Helmet_HBK\H_HelmetHBK_01_olive_CO.paa","#(rgb,256,128,1)Text(0.55,1,""PuristaSemibold"",0.4,""#1919197f"",""#bbbbbb"",""Momo"")","#(rgb,256,128,1)Text(0.55,1,""PuristaSemibold"",0.4,""#1919197f"",""#bbbbbb"",""Momo"")"};
  };
};*/