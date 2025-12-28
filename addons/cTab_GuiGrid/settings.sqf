
[
    "mjb_ctab_fix",
    "CHECKBOX",
    ["Ctab BFT activation fix", "Activates ctab BFT in initPost when enabled in ctab's settings, currently it's only activated on setting changes."],
    ["cTab", "Fixes"],
    true,
    true,
    { },
    true
] call CBA_fnc_addSetting;

[
    "mjb_ctab_noBorderDef",
    "CHECKBOX",
    ["Hide Ctab border in GPS mode", "Hides border of cTab devices when not focused."],
    ["cTab", "GUI Settings"],
    true,
    false,
    { },
    true
] call CBA_fnc_addSetting;

/*[
    "mjb_ctab_delayAceMapHandler",
    "CHECKBOX",
    ["Delay ACE map handler", "Re-adds Ace map handler making sure it's added after cTab's so ace map gesture works."],
    ["cTab", "GUI Settings"],
    true,
    false,
    { },
    true
] call CBA_fnc_addSetting;
*/