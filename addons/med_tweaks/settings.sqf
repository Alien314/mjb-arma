private _title = "MJB Arma";

[
    "mjb_med_tweaks_enableSalts",
    "CHECKBOX",
    ["Enable Smelling Salts", "Allow treatment with smelling salts, instantly waking a patient."],
    [_title, "Medical Tweaks"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_requireItemSalt",
    "CHECKBOX",
    ["Require Surgical Kit", "Must have surgical kit to use smelling salts (may add it's own item later)."],
    [_title, "Medical Tweaks"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_saltCD",
    "SLIDER",
    ["Salty Rat Cooldown", "Seconds before smelling salts can be used on a unit again."],
    [_title,"Medical Tweaks"],
    [0, 3600, 0, 0],
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_stableOnly",
    "CHECKBOX",
    ["Require Stable for Smelling Salts", "Prevents instant wake up with smelling salts when patient is not stable, patient may immediately fall unconscious again if disabled."],
    [_title, "Medical Tweaks"],
    true,
    true
] call CBA_fnc_addSetting;