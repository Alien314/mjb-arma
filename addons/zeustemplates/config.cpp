class CfgPatches {
  class mjb_zeustemplate {
	ammo[] = {};
	magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "RATS Zeus Templates";
    requiredAddons[]=
		{
		};
	};
};

class CfgMissions {

	class MPMissions {

        // Firing Range
		class mjb_rzt_stratisFR2 {
			author = "NotherDuck, MajorDanvers, Inquietude";
			briefingName = "Stratis Firing Range v2,3";
			directory = "z\mjb\addons\zeustemplates\missions\Stratis_Firing_Range_V2,3_96.Stratis";
			overview = "z\mjb\addons\zeustemplates\overview.paa";
			overviewText = "Firing Range for RATS pre-session and testing.";
		};

      class MJB_ZeusTemplates {
		class mjb_rzt_vr2 {
			author = "NotherDuck, MajorDanvers";
			briefingName = "MJB Zeus Template 2,2";
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,2_447.VR";
			overview = "z\mjb\addons\zeustemplates\overview.paa";
			overviewText = "Zeus template for RATS.";
		};
		class mjb_rzt_vr2_CA : mjb_rzt_vr2 {
			briefingName = "MJB Zeus Combined Arms 2,2";
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_CombinedArms_V2,2_402.VR";
			overviewText = "Combined Arms Zeus template for RATS.";
		};

		#define VARC(EXT) z\mjb\addons\zeustemplates\missions\MJB_Zeus_CombinedArms_V2,2_402.##EXT
		#define VARD(EXT) z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,2_447.##EXT
		#define QUOTE(var1) #var1
		#define COMMA , // does this work? Rosche, Germany
		#define MISH(EXT,NAME) \
		class mjb_rzt_##EXT##2 : mjb_rzt_vr2 { \
			directory = QUOTE(VARD(EXT)); \
		}; \
		class mjb_rzt_##EXT##2_CA : mjb_rzt_vr2_CA { \
			directory = QUOTE(VARC(EXT)); \
		}

        // islands
		class mjb_rzt_Altis : mjb_rzt_vr2 {
			briefingName = "MJB Zeus Template 2,1";
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.Altis";
		};
		MISH(Altis,Altis);
		//class mjb_rzt_Altis2 : mjb_rzt_vr2 {
		//	directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,2_447.Altis";
		//};
		//class mjb_rzt_Altis2_CA : mjb_rzt_vr2_CA {
		//	directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,2_402.Altis";
		//};
		MISH(atolls_gdc,Atolls GDC);
		MISH(intro,Rahmadi);
		MISH(Malden,Malden);
		MISH(Porto,Porto);
		MISH(pulau,Pulau);
		MISH(sara,Sahrani);
		MISH(saralite,Southern Sahrani);
		MISH(Stratis,Stratis);
		MISH(Tanoa,Tanoa);
		MISH(utes,Utes);

        // coastal
		MISH(chernarus,Chernarus (Autumn));
		MISH(chernarus_summer,Chernarus (Summer));
		MISH(chernarus_winter,Chernarus (Winter));
		MISH(chernarus_A3,Chernarus 2020);
		MISH(Maksniemi,Maksniemi);
		MISH(oski_corran,Scottish Highlands);
		MISH(tem_vinjesvingenc,Vinjesvingen);

        //landlocked
		MISH(Bootcamp_ACR,Bukovina);
		class mjb_rzt_Bootcamp_ACR : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.Bootcamp_ACR";
		};
		MISH(Desert_E,Desert);
		class mjb_rzt_Desert_E : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.Desert_E";
		};
		MISH(Enoch,Livonia);
		class mjb_rzt_Enoch : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.Enoch";
		};
		MISH(hellanmaa,Hellanmaa);
		class mjb_rzt_hellanmaa : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.hellanmaa";
		};
		MISH(hellanmaaw,Hellanmaa Winter);
		class mjb_rzt_hellanmaaw : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.hellanmaaw";
		};
		MISH(Mountains_ACR,Takistan Mountains);
		class mjb_rzt_Mountains_ACR : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.Mountains_ACR";
		};
		MISH(ProvingGrounds_PMC,Proving Grounds);
		class mjb_rzt_ProvingGrounds_PMC : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.ProvingGrounds_PMC";
		};
		MISH(rhspkl,Prei Khmaoch Luong);
		class mjb_rzt_rhspkl : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.rhspkl";
		};
		MISH(ruha,Ruha);
		class mjb_rzt_ruha : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.ruha";
		};
		MISH(Shapur_BAF,Shapur);
		class mjb_rzt_Shapur_BAF : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.Shapur_BAF";
		};
		MISH(takistan,Takistan);
		class mjb_rzt_takistan : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.takistan";
		};
		MISH(tem_anizay,Anizay);
		class mjb_rzt_tem_anizay : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.tem_anizay";
		};
		MISH(tem_kujari,Kujari);
		class mjb_rzt_tem_kujari : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.tem_kujari";
		};
		MISH(tem_summa,Summa);
		class mjb_rzt_tem_summa : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.tem_summa";
		};
		MISH(tem_summawcup,Summa Winter);
		class mjb_rzt_tem_summawcup : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.tem_summawcup";
		};
		MISH(WL_Rosche,Rosche##COMMA Germany);
		class mjb_rzt_WL_Rosche : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.WL_Rosche";
		};
		MISH(Woodland_ACR,Bystrica);
		class mjb_rzt_Woodland_ACR : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.Woodland_ACR";
		};
		MISH(zargabad,Zargabad);
		class mjb_rzt_zargabad : mjb_rzt_Altis {
			directory = "z\mjb\addons\zeustemplates\missions\MJB_Zeus_Template_V2,1_387.zargabad";
		};
	  };
	};

	/*class Campaigns {

		class ZeusTemplates {

			class NoEndings
			{
				// Arma 3
				endDefault = ;
			};

			class MissionDefault : NoEndings
			{
				lives		= -1;	// this sets your "lives" to none - old OFP setting where you would lose a "life" every time you retried the mission, never used
				noAward		=  1;	// TBD
				cutscene	= ;		// mandatory definition
			};

			directory = "z\mjb\addons\zeustemplates";
			weaponPool = 1;

			class Campaign
			{
				briefingName	= "Zeus Templates";
				author			= "NotherDuck, MajorDanvers, Alien314";
				overviewText	= "Missions for Zeuses to use to create missions.";
				overviewPicture	= "z\mjb\addons\zeustemplates\overview.paa";

				firstBattle	= Chapter1;
				disableMP	= 0;

				class Chapter1 : NoEndings
				{
					firstMission = Chapter1_Mission1;
					name = "Zeus Templates";
					cutscene = ;

					
				};				
			};
		};
	};*/
};