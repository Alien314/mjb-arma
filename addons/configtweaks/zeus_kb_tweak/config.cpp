class CfgPatches {
  class mjb_zeus_kb_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "zeus_keybinds tweak";
		requiredAddons[]=
		{
			"zeus_keybinds_main"
		};
		skipWhenMissingDependencies = 1;
	};
};

class CfgSettings {
	class CBA {
		class Versioning {
			delete zeus_keybinds;
		};
	};
};
