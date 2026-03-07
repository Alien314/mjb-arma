class CfgPatches
{
	class mjb_spotlight
	{
		name="MJB Spotlight";
		author="blah2355";
		url="";
		requiredAddons[]=
		{
			"A3_Data_F_Oldman_Loadorder",
			"cba_main",
			"mjb_flags"
		};
		requiredVersion=2.02;
		units[]={};
		weapons[]={};
		magazines[]={};
		version=1;
		versionStr="1.0.1.20240401";
		versionAr[]={1,0,1,20240401};
	};
};

class CfgFunctions
{
	class mjb_spotlight
	{
		class server {
			file = "z\mjb\addons\spotlight\functions";
			class joinServer {};
		};
	};
};

class CfgMainMenuSpotlight
{
	class JoinMJB
	{
		text="RATS Server";
		picture="\z\mjb\addons\flags\data\rats_insignia.paa";
		action="['115.42.46.194', 2306] call (uiNamespace getVariable 'mjb_spotlight_fnc_joinServer')";
		actionText="Connect to the RATS Server";
		condition="true";
	};

	// remove other Spotlights
	delete ApexProtocol;
    delete BootCamp;
    delete EastWind;
    delete Orange_CampaignGerman;
    delete Orange_Showcase_IDAP;
    delete Orange_Showcase_LoW;
    delete Orange_Campaign;
    delete Showcase_TankDestroyers;
    delete Tacops_Campaign_03;
    delete Tacops_Campaign_02;
    delete Tacops_Campaign_01;
    delete Tanks_Campaign_01;
    delete OldMan;
    delete Contact_Campaign;
    delete gm_campaign_01;
    delete SP_FD14;
    delete AoW_Showcase_AoW;
    delete AoW_Showcase_Future;
    delete Scenario_TrainingDay_RF;
    delete Scenario_FireSeason_RF;
    delete Scenario_AirControl_RF;
    delete Extraction_lxWS;
    delete Showcase_Alchemist_lxWS;
    delete Showcase_VR_lxWS;
    delete vn_showcase_macv;
    delete vn_showcase_macv_13;
    delete vn_showcase_pavn;
    delete vn_showcase_pavn_13;
    delete vn_sogba;
    delete SPE_Arsenal;
    delete SPE_Campagin_OperationCobra_04;
    delete SPE_Coop_DerZahnarzt;
    delete SPE_Faction_Showcase_GER;
    delete SPE_Faction_Showcase_US;
};
