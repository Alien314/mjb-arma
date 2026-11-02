
["z\mjb\addons\configtweaks\avs_tweak\XEH_postInit.sqf", "mjb_avs_fnc_addEH"] call CBA_fnc_compileFunction;

[
    "mjb_slideTackle",
    "CHECKBOX",
    ["Allow Slide Tackle", "Allow players to slide into units and objects and physics/ragdoll them."],
    ["MJB Arma", "xSlideTackle"],
    false,
    true
] call CBA_fnc_addSetting;
