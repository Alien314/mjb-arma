["z\mjb\addons\ctab_gui_settings\fnc_open.sqf", "ctab_fnc_open"] call CBA_fnc_compileFunction;

[
    "mjb_ctab_noBorder",
    "CHECKBOX",
    ["Hide Ctab border in GPS mode", "Hides border of cTab devices when not focused."],
    ["cTab", "GUI Settings"],
    false,
    false,
    { },
    true
] call CBA_fnc_addSetting;

call compile preprocessFileLineNumbers "z\ctab\addons\core\XEH_preInit.sqf";