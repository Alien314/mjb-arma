params ['_medic','_patient'];

if (mjb_med_tweaks_stableOnly && { !([_patient] call ace_medical_status_fnc_isInStableCondition) } ) exitWith {};

if (!mjb_med_tweaks_stableOnly && { (!(alive _patient) || {(_patient getVariable ['ace_medical_inCardiacArrest',false])} ) } ) exitWith {};

if (mjb_med_tweaks_saltCD > 0) then {
	_patient setVariable ['mjb_med_tweaks_salty',true,true];

	[[_patient],{params ['_unit']; [{_this setVariable ['mjb_med_tweaks_salty',nil,true];},_unit,mjb_med_tweaks_saltCD] call CBA_fnc_waitAndExecute;}] remoteExec ['call',2];
};

[_patient, false] call ace_medical_fnc_setUnconscious;