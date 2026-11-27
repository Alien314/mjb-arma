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

class CBA_Extended_EventHandlers_base;
class CfgVehicles {
	#define APPLYXEH(var,varBase) class var : varBase { \
		class EventHandlers { \
			class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base {}; \
		}; \
	}
	class B_CTRG_Soldier_M_tna_F;
	APPLYXEH(B_CTRG_Icebreak_F,B_CTRG_Soldier_M_tna_F);
	class B_G_Soldier_LAT_F;
	APPLYXEH(B_G_Ben_Tailor_F,B_G_Soldier_LAT_F);
	class B_T_Diver_Exp_F;
	APPLYXEH(B_T_Daniel_Deadman_F,B_T_Diver_Exp_F);

	class C_IDAP_Man_AidWorker_06_F;
	APPLYXEH(C_IDAP_Betty_Mynatt_F,C_IDAP_Man_AidWorker_06_F);
	class C_Man_smart_casual_2_F_euro;
	APPLYXEH(C_Peter_Fritz_F_euro,C_Man_smart_casual_2_F_euro);

	class I_C_Soldier_Bandit_7_F;
	APPLYXEH(I_C_Paul_Harris_F,I_C_Soldier_Bandit_7_F);
	class I_E_Soldier_lite_F;
	APPLYXEH(I_E_Vladimir_Nikitins_F,I_E_Soldier_lite_F);
	class I_G_officer_F;
	APPLYXEH(I_G_Andrew_Sfakianakis_F,I_G_officer_F);
	class I_L_Looter_SG_F;
	APPLYXEH(I_L_Korneel_Lewandowski_F,I_L_Looter_SG_F);

	class O_GEN_Soldier_F;
	APPLYXEH(O_GEN_Bill_Gudiki_F,O_GEN_Soldier_F);
	class O_R_Medic_F;
	APPLYXEH(O_R_Morten_Gregorius_F,O_R_Medic_F);
	class O_V_Soldier_TL_hex_F;
	APPLYXEH(O_V_Pin_Mei_F,O_V_Soldier_TL_hex_F);
};
