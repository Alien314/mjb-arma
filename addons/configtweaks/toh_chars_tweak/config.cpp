class CfgPatches {
  class mjb_toh_chars_tweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "ToH Face 3den Fix";
		requiredAddons[]=
		{
			"HSim_Characters_H_Afth","HSim_Characters_H_Faces","HSim_Characters_H_A3_Faces"
		};
		skipWhenMissingDependencies = 1;
	};
};

class Cfg3DEN {
	class Object {
		class AttributeCategories {
			class Identity {
				class Attributes {
					class Face {
						defaultValue = " if ( ( getNumber (configFile >> 'CfgFaces' >> 'Man_A3' >> face _this >> 'disabled') ) isEqualTo 0 ) then { face _this } else { (face _this) select [0, (count face _this - 1)] }";
					};
				};
			};
		};
	};
};

/*
class CfgFaces {
	class Default;
	class Man_A3 : Default {
		#define NO_TYPE(BASE) class BASE; \
		class BASE##a : BASE { identityTypes[] = {}; }; \
		class BASE##b : BASE { identityTypes[] = {}; }; \
		class BASE##c : BASE { identityTypes[] = {}; }; \
		class BASE##d : BASE { identityTypes[] = {}; }; \
		class BASE##e : BASE { identityTypes[] = {}; }; \
		class BASE##f : BASE { identityTypes[] = {}; }; \
		class BASE##g : BASE { identityTypes[] = {}; }; \
		class BASE##h : BASE { identityTypes[] = {}; }; \
		class BASE##i : BASE { identityTypes[] = {}; }; \
		class BASE##j : BASE { identityTypes[] = {}; }; \
		class BASE##k : BASE { identityTypes[] = {}; }; \
		class BASE##l : BASE { identityTypes[] = {}; }; \
		class BASE##m : BASE { identityTypes[] = {}; }; \
		class BASE##n : BASE { identityTypes[] = {}; }; \
		class BASE##o : BASE { identityTypes[] = {}; }; \
		class BASE##p : BASE { identityTypes[] = {}; }; \
		class BASE##q : BASE { identityTypes[] = {}; }; \
		class BASE##r : BASE { identityTypes[] = {}; }; \
		class BASE##s : BASE { identityTypes[] = {}; }; \
		class BASE##t : BASE { identityTypes[] = {}; }; \
		class BASE##u : BASE { identityTypes[] = {}; }; \
		class BASE##v : BASE { identityTypes[] = {}; }; \
		class BASE##w : BASE { identityTypes[] = {}; }


		NO_TYPE(AfricanHead_01);
		NO_TYPE(AfricanHead_02);
		NO_TYPE(AfricanHead_03);

		class AsianHead_A3_01;
		class AsianHead_A3_01j : AsianHead_A3_01 { identityTypes[] = {}; };
		class AsianHead_A3_01w : AsianHead_A3_01 { identityTypes[] = {}; };

		class AsianHead_A3_02;
		class AsianHead_A3_02j : AsianHead_A3_02 { identityTypes[] = {}; };
		class AsianHead_A3_02w : AsianHead_A3_02 { identityTypes[] = {}; };

		class AsianHead_A3_03;
		class AsianHead_A3_03j : AsianHead_A3_03 { identityTypes[] = {}; };
		class AsianHead_A3_03w : AsianHead_A3_03 { identityTypes[] = {}; };

		class AsianHead_A3_04;
		class AsianHead_A3_04j : AsianHead_A3_04 { identityTypes[] = {}; };
		class AsianHead_A3_04w : AsianHead_A3_04 { identityTypes[] = {}; };

		class AsianHead_A3_05;
		class AsianHead_A3_05j : AsianHead_A3_05 { identityTypes[] = {}; };
		class AsianHead_A3_05w : AsianHead_A3_05 { identityTypes[] = {}; };

		class AsianHead_A3_06;
		class AsianHead_A3_06j : AsianHead_A3_06 { identityTypes[] = {}; };
		class AsianHead_A3_06w : AsianHead_A3_06 { identityTypes[] = {}; };

		class AsianHead_A3_07;
		class AsianHead_A3_07j : AsianHead_A3_07 { identityTypes[] = {}; };
		class AsianHead_A3_07w : AsianHead_A3_07 { identityTypes[] = {}; };

		NO_TYPE(Face01);
		NO_TYPE(Face01_BAF);
		NO_TYPE(Face01_EP1);
		NO_TYPE(Face02);
		NO_TYPE(Face02_BAF);
		NO_TYPE(Face02_EP1);
		NO_TYPE(Face03);
		NO_TYPE(Face03_BAF);
		NO_TYPE(Face03_EP1);
		NO_TYPE(Face04);
		NO_TYPE(Face04_BAF);
		NO_TYPE(Face04_EP1);
		NO_TYPE(Face05);
		NO_TYPE(Face05_BAF);
		NO_TYPE(Face05_EP1);
		NO_TYPE(Face06);
		NO_TYPE(Face06_BAF);
		NO_TYPE(Face06_EP1);
		NO_TYPE(Face07);
		NO_TYPE(Face07_BAF);
		NO_TYPE(Face07_EP1);
		NO_TYPE(Face08);
		NO_TYPE(Face08_BAF);
		NO_TYPE(Face08_EP1);
		NO_TYPE(Face09);
		NO_TYPE(Face09_BAF);
		NO_TYPE(Face09_EP1);

		NO_TYPE(Face10);
		NO_TYPE(Face10_EP1);
		NO_TYPE(Face11);
		NO_TYPE(Face11_EP1);
		NO_TYPE(Face12);
		NO_TYPE(Face12_EP1);
		NO_TYPE(Face13);
		NO_TYPE(Face13_EP1);
		NO_TYPE(Face14);
		NO_TYPE(Face14_EP1);
		NO_TYPE(Face15);
		NO_TYPE(Face15_EP1);
		NO_TYPE(Face16);
		NO_TYPE(Face16_EP1);
		NO_TYPE(Face17);
		NO_TYPE(Face17_EP1);
		NO_TYPE(Face18);
		NO_TYPE(Face18_EP1);
		NO_TYPE(Face19);
		NO_TYPE(Face19_EP1);
		NO_TYPE(Face20);
		NO_TYPE(Face20_EP1);

		NO_TYPE(Face21);
		NO_TYPE(Face22);
		NO_TYPE(Face23);
		NO_TYPE(Face24);
		NO_TYPE(Face25);
		NO_TYPE(Face26);
		NO_TYPE(Face27);
		NO_TYPE(Face28);
		NO_TYPE(Face29);
		NO_TYPE(Face30);
		NO_TYPE(Face31);
		NO_TYPE(Face32);
		NO_TYPE(Face33);
		NO_TYPE(Face34);
		NO_TYPE(Face35);
		NO_TYPE(Face36);
		NO_TYPE(Face37);
		NO_TYPE(Face38);
		NO_TYPE(Face39);
		NO_TYPE(Face40);
		NO_TYPE(Face41);
		NO_TYPE(Face42);
		NO_TYPE(Face43);
		NO_TYPE(Face44);
		NO_TYPE(Face45);
		NO_TYPE(Face46);
		NO_TYPE(Face47);
		NO_TYPE(Face48);
		NO_TYPE(Face49);
		NO_TYPE(Face50);
		NO_TYPE(Face51);
		NO_TYPE(Face52);
		NO_TYPE(Face53);
		NO_TYPE(Face54);
		NO_TYPE(Face55);
		NO_TYPE(Face56);
		NO_TYPE(Face57);
		NO_TYPE(Face58);
		NO_TYPE(Face59);
		NO_TYPE(Face60);
		NO_TYPE(Face60_Hair);
		NO_TYPE(Face61);
		NO_TYPE(Face61_Hair);
		NO_TYPE(Face62);
		NO_TYPE(Face63);
		NO_TYPE(Face64);
		NO_TYPE(Face65);
		NO_TYPE(Face66);
		NO_TYPE(Face67);
		NO_TYPE(Face68);
		NO_TYPE(Face69);
		NO_TYPE(Face70);
		NO_TYPE(Face71);
		NO_TYPE(Face72);
		NO_TYPE(Face73);
		NO_TYPE(Face74);
		NO_TYPE(Face75);
		NO_TYPE(Face76);
		NO_TYPE(Face77);
		NO_TYPE(Face78);
		NO_TYPE(Face79);
		NO_TYPE(Face80);
		NO_TYPE(Face81);
		NO_TYPE(Face82);
		NO_TYPE(Face83);
		NO_TYPE(Face84);
		NO_TYPE(Face85);
		NO_TYPE(Face86);
		NO_TYPE(Face87);
		NO_TYPE(Face88);
		NO_TYPE(Face89);
		NO_TYPE(Face90);
		NO_TYPE(Face91);
		NO_TYPE(Face92);
		NO_TYPE(Face93);
		NO_TYPE(Face94);
		NO_TYPE(Face95);
		NO_TYPE(Face96);
		NO_TYPE(Face97);
		NO_TYPE(Face98);
		NO_TYPE(Face99);
		NO_TYPE(Face100);
		NO_TYPE(Face101);
		NO_TYPE(Face102);
		NO_TYPE(Face103);
		NO_TYPE(Face104);
		NO_TYPE(Face105);
		NO_TYPE(Face106);
		NO_TYPE(Face107);
		NO_TYPE(Face108_PMC);
		NO_TYPE(Face109_PMC);
		NO_TYPE(Face110_PMC);
		NO_TYPE(Face111_PMC);
		NO_TYPE(Face112_PMC);
		NO_TYPE(Face113_PMC);
		NO_TYPE(Face114_PMC);
		NO_TYPE(Face115_PMC);
		NO_TYPE(Face116_PMC);
		NO_TYPE(Face117_PMC);
		NO_TYPE(Face118_PMC);
		NO_TYPE(Face119_PMC);
		NO_TYPE(Face120_PMC);
		NO_TYPE(Face121_PMC);
		NO_TYPE(Face122_PMC);
		NO_TYPE(Face123_PMC);
		NO_TYPE(Face124_PMC);

		NO_TYPE(GreekHead_A3_01);
		NO_TYPE(GreekHead_A3_02);
		NO_TYPE(GreekHead_A3_03);
		NO_TYPE(GreekHead_A3_04);
		NO_TYPE(GreekHead_A3_05);
		NO_TYPE(GreekHead_A3_06);
		NO_TYPE(GreekHead_A3_07);
		NO_TYPE(GreekHead_A3_08);
		NO_TYPE(GreekHead_A3_09);
		//NO_TYPE(GreekHead_A3_10); // face paints
		NO_TYPE(GreekHead_A3_11);
		NO_TYPE(GreekHead_A3_12);
		NO_TYPE(GreekHead_A3_13);
		NO_TYPE(GreekHead_A3_14);

		NO_TYPE(LivonianHead_1);
		NO_TYPE(LivonianHead_2);
		NO_TYPE(LivonianHead_3);
		NO_TYPE(LivonianHead_4);
		NO_TYPE(LivonianHead_5);
		NO_TYPE(LivonianHead_6);
		NO_TYPE(LivonianHead_7);
		NO_TYPE(LivonianHead_8);
		NO_TYPE(LivonianHead_9);
		NO_TYPE(LivonianHead_10);

		NO_TYPE(PersianHead_A3_01);
		NO_TYPE(PersianHead_A3_02);
		NO_TYPE(PersianHead_A3_03);
		//NO_TYPE(PersianHead_A3_04); // face paints

		NO_TYPE(RussianHead_1);
		NO_TYPE(RussianHead_2);
		NO_TYPE(RussianHead_3);
		NO_TYPE(RussianHead_4);
		NO_TYPE(RussianHead_5);

		NO_TYPE(TanoanHead_A3_01);
		NO_TYPE(TanoanHead_A3_02);
		NO_TYPE(TanoanHead_A3_03);
		NO_TYPE(TanoanHead_A3_04);
		NO_TYPE(TanoanHead_A3_05);
		NO_TYPE(TanoanHead_A3_06);
		NO_TYPE(TanoanHead_A3_07);
		NO_TYPE(TanoanHead_A3_08);
		NO_TYPE(TanoanHead_A3_09);

		NO_TYPE(WhiteHead_01);
		NO_TYPE(WhiteHead_02);
		NO_TYPE(WhiteHead_03);
		NO_TYPE(WhiteHead_04);
		NO_TYPE(WhiteHead_05);
		NO_TYPE(WhiteHead_06);
		NO_TYPE(WhiteHead_07);
		NO_TYPE(WhiteHead_08);
		NO_TYPE(WhiteHead_09);
		NO_TYPE(WhiteHead_10);
		NO_TYPE(WhiteHead_11);
		NO_TYPE(WhiteHead_12);
		NO_TYPE(WhiteHead_13);
		NO_TYPE(WhiteHead_14);
		NO_TYPE(WhiteHead_15);
		NO_TYPE(WhiteHead_16);
		NO_TYPE(WhiteHead_17);
		NO_TYPE(WhiteHead_18);
		NO_TYPE(WhiteHead_19);
		NO_TYPE(WhiteHead_20);
		NO_TYPE(WhiteHead_21);
		//NO_TYPE(WhiteHead_22); // face paints
		NO_TYPE(WhiteHead_23);
		//NO_TYPE(WhiteHead_24);
		//NO_TYPE(WhiteHead_25);
		//NO_TYPE(WhiteHead_26);
		//NO_TYPE(WhiteHead_27);
		//NO_TYPE(WhiteHead_28);
		//NO_TYPE(WhiteHead_29);
		NO_TYPE(WhiteHead_30);
		//NO_TYPE(WhiteHead_31);
		//NO_TYPE(WhiteHead_32);
	};
};
//*/
