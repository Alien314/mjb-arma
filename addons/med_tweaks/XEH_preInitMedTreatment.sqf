["z\mjb\addons\med_tweaks\functions\fnc_getTriageStatus.sqf", "ace_medical_treatment_fnc_getTriageStatus"] call CBA_fnc_compileFunction;
["z\mjb\addons\med_tweaks\functions\fnc_loadUnit.sqf", "ace_medical_treatment_fnc_loadUnit"] call CBA_fnc_compileFunction;
["z\mjb\addons\med_tweaks\functions\fnc_canUnloadUnit.sqf", "ace_medical_treatment_fnc_canUnloadUnit"] call CBA_fnc_compileFunction;
["z\mjb\addons\med_tweaks\functions\fnc_unloadUnit.sqf", "ace_medical_treatment_fnc_unloadUnit"] call CBA_fnc_compileFunction;

call compile preprocessFileLineNumbers "z\ace\addons\medical_treatment\XEH_preInit.sqf";