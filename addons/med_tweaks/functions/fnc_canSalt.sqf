params ['_medic','_patient'];

if !(mjb_med_tweaks_enableSalts) exitWith {false};

if (mjb_med_tweaks_requireItemSalt && {!([_medic, "ACE_surgicalKit"] call ace_common_fnc_hasItem)}) exitWith {false}; // mjb_salts

if (_patient getVariable ['mjb_med_tweaks_salty',false]) exitWith { false };

!(alive _patient) || {(_patient getVariable ['ACE_isUnconscious',false])}