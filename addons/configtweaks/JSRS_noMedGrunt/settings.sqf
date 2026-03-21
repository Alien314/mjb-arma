
["z\jsrs2025\addons\functions\functions\fn_onFiredMagazineEmpty.sqf", "mjb_jsrs_fnc_onFiredMagazineEmpty"] call CBA_fnc_compileFunction;

[
    "mjb_disableJSRSMagEmpty",
    "CHECKBOX",
    ["Disable JSRS Empty Magazine Sounds", "Prevents noise when magazine emptied."],
    ["JSRS", "Settings"],
    false,
    false
] call CBA_fnc_addSetting;