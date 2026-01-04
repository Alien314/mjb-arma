#if __has_include("\z\ace\addons\nomedical\script_component.hpp")

#else
class CfgPatches {
  class mjb_med_tweaks {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "MJB Med tweaks";
    requiredAddons[] = {"ace_medical_statemachine","ace_medical_treatment"};
    skipWhenMissingDependencies = 1;
  };
};

class Extended_PostInit_EventHandlers
{
	class mjb_med_tweaks
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_postInit.sqf']";
	};
};

class Extended_PreInit_EventHandlers
{
	class mjb_med_tweaks
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_preInit.sqf']";
	};
	class ace_medical_treatment
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_preInitMedTreatment.sqf']";
	};
};
class Extended_PreStart_EventHandlers
{
	class mjb_med_tweaks
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_preStart.sqf']";
	};
	class ace_medical_treatment
	{
		init="call compileScript ['z\mjb\addons\med_tweaks\XEH_preStartMedTreatment.sqf']";
	};
};

// morphine tolerance
class ace_medical_treatment {
  class Medication {
    class Morphine {
      hrIncreaseHigh[] = {-8,-20};
      hrIncreaseLow[] = {-2,-5};
      hrIncreaseNormal[] = {-4,-10};
      viscosityChange = -5;
    };
  };
};

class ACE_Medical_StateMachine {
	class FatalInjury {
        class SecondChance {
			condition = "_this call mjb_med_tweaks_fnc_conditionSecondChance";
			//condition = "isPlayer _this && {(_this getVariable [""ace_medical_statemachine_fatalInjuriesPlayer"",ace_medical_statemachine_fatalInjuriesPlayer]) != 0} || { (_this getVariable [""ace_medical_statemachine_fatalInjuriesAI"",ace_medical_statemachine_fatalInjuriesAI]) != 0 }";
		};
	};
	class CardiacArrest {
		class DeathAI {
			condition = "_this call mjb_med_tweaks_fnc_conditionDeathAI";
			//condition = "!(_this getVariable [""ace_medical_statemachine_AIUnconsciousness"", ace_medical_statemachine_AIUnconsciousness]) && {!isPlayer _this}";
		};
        class Execution {
			condition = "_this call mjb_med_tweaks_fnc_conditionExecutionDeath";
            //condition = "(isPlayer _this && {(_this getVariable [""ace_medical_statemachine_fatalInjuriesPlayer"",ace_medical_statemachine_fatalInjuriesPlayer]) != 2} || { (_this getVariable [""ace_medical_statemachine_fatalInjuriesAI"",ace_medical_statemachine_fatalInjuriesAI]) != 2 }) && { !(_this getVariable [""ace_medical_deathBlocked"",false])}";
        };
	};
};

// Smelling salts
class ace_medical_treatment_actions {
  class Painkillers;
  class Salts : Painkillers {
    displayName = "Administer Smelling Salts";
    displayNameProgress = "Administering Smelling Salts...";
    icon = "z\mjb\addons\med_tweaks\ui\salts.paa";
    items[] = {}; //"mjb_salts"
    treatmentTime = 3;
    callbackSuccess = "mjb_med_tweaks_fnc_salts";
	condition = "mjb_med_tweaks_fnc_canSalt";
	consumeItem = 0;
  };
};

#endif