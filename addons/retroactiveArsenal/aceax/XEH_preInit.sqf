["z\mjb\addons\arsenal\aceax\fnc_generateOptionsUI.sqf", "aceax_arsenal_fnc_generateOptionsUI"] call CBA_fnc_compileFunction;

[
    "mjb_aceax_factionFilter",
    "CHECKBOX",
    ["Disable AceAX Faction filter", "Disables faction filtering allowing players to see other factions' versions of items in Ace Arsenal."],
    ["MJB Arma", "xAceAX"],
    true,
    true
] call CBA_fnc_addSetting;

call compile preprocessFileLineNumbers "z\aceax\addons\arsenal\XEH_preInit.sqf";