class CfgPatches {
  class swu_novo_sunFix {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "Novo Sun fix";
	requiredAddons[]=
    {
        "swu_public_novogorsk_map"
	};
    skipWhenMissingDependencies = 1;
  };
};

class CfgWorlds {
	class CAWorld;
	class Altis : CAWorld {
		class DefaultLighting {
			access = 3;
			endSunset = 10;
			nightAngle = 5;
			sunSunset = 20;
		};
		/*class Lighting : DefaultLighting {
			access = 3;
			endSunset = 10;
			//groundReflection[] = {0.132,0.133,0.122};
			//moonHaloObjectColorFull[] = {465,477,475,1};
			//moonObjectColorFull[] = {460,440,400,1};
			//moonsetHaloObjectColor[] = {515,517,525,1};
			//moonsetObjectColor[] = {375,350,325,1};
			nightAngle = 5;
			//starEmissivity = 40;
			sunSunset = 20;
			class ThunderBoltLight {
				ambient[] = {0.001,0.001,0.001};
				diffuse[] = {2120,3170,5550};
				intensity = 120000;
				class Attenuation {
					constant = 0;
					linear = 0;
					quadratic = 1;
					start = 0;
				};
			};
		};*/
	};
	/*
	class swu_public_novogorsk_map : Altis {
		class DefaultLighting {
			access = 3;
			endSunset = 10;
			nightAngle = 5;
			sunSunset = 20;
		};
	};*/
};
/*
//sunSunset = 20;
20:30:31 Warning Message: No entry 'bin\config.bin/CfgWorlds/Altis/Lighting.sunSunset'
20:30:31 Warning Message: '/' is not a value
//endSunset = 10;
20:30:31 Warning Message: No entry 'bin\config.bin/CfgWorlds/Altis/Lighting.endSunset'
20:30:31 Warning Message: '/' is not a value
//nightAngle = 5;
20:30:31 Warning Message: No entry 'bin\config.bin/CfgWorlds/Altis/Lighting.nightAngle'
20:30:31 Warning Message: '/' is not a value
//access = 3;
*/