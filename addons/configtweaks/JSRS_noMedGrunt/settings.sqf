
["z\jsrs2025\addons\functions\functions\fn_onFiredMagazineEmpty.sqf", "mjb_jsrs_fnc_onFiredMagazineEmpty"] call CBA_fnc_compileFunction;
["z\jsrs2025\addons\functions\functions\fn_onFired.sqf", "mjb_jsrs_fnc_onFired"] call CBA_fnc_compileFunction;

[
    "mjb_disableJSRSMagEmpty",
    "CHECKBOX",
    ["Disable JSRS Empty Magazine Sounds", "Prevents noise when magazine emptied."],
    ["JSRS", "Settings"],
    false,
    false
] call CBA_fnc_addSetting;

[
    "mjb_disableJSRSEcho",
    "CHECKBOX",
    ["Disable JSRS Echo Effect", "Disables echo in hilly terrain, reducing some calculation overhead and potentially confusion."],
    ["JSRS", "Settings"],
    false,
    false
] call CBA_fnc_addSetting;