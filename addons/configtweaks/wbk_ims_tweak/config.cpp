class CfgPatches {
  class WBK_IMS_Mechanics_ver {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "MJB IMS Versioning";
		requiredAddons[]=
		{
			//"WBK_IMS_Mechanics"
		};
		skipWhenMissingDependencies = 1;
#if __has_include("\WBK_IMS_Mechanics\XEH_preInit.sqf")
		version = 1.11;
		versionAr[] = {1,1,1,1};
		versionStr = "1.1.1.1";
#else
		version = 0.00;
		versionAr[] = {0,0,0,0};
		versionStr = "0.0.0.0";
#endif
	};
};

class CfgSettings {
	class CBA {
		class Versioning {
			class WBK_IMS_Mechanics_ver { main_addon = "WBK_IMS_Mechanics_ver"; };
		};
	};
};
