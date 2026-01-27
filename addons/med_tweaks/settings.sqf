#include "script_component.hpp"

private _title = "MJB Arma Medical";

[
    "mjb_med_tweaks_enableSalts",
    "CHECKBOX",
    ["Enable Smelling Salts", "Allow treatment with smelling salts, instantly waking a patient."],
    [_title, "Salts"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_requireItemSalt",
    "CHECKBOX",
    ["Require Surgical Kit", "Must have surgical kit to use smelling salts (may add it's own item later)."],
    [_title, "Salts"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_saltCD",
    "SLIDER",
    ["Salty Rat Cooldown", "Seconds before smelling salts can be used on a unit again."],
    [_title,"Salts"],
    [0, 3600, 0, 0],
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_stableOnly",
    "CHECKBOX",
    ["Require Stable for Smelling Salts", "Prevents instant wake up with smelling salts when patient is not stable, patient may immediately fall unconscious again if disabled."],
    [_title, "Salts"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_unstableWakeChance",
    "SLIDER",
    ["Unstable Wake Chance", "Chance to wake up while in unstable condition."],
    [_title,"Unstable Wake"],
    [0, 1, 0.05, 4],
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_unstableWakeDelay",
    "SLIDER",
    ["Unstable Wake Roll Frequency", "Time before and between unstable wake up rolls."],
    [_title,"Unstable Wake"],
    [0, 180, 15, 0],
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_unstableWakeSoftCap",
    "SLIDER",
    ["Unstable Wake Uncon Soft Cap", "Time after which chance to wake up starts increasing based on time spent unconscious. +50% at double this value, +100% at triple this value."],
    [_title,"Unstable Wake"],
    [1, 600, 120, 0],
    true
] call CBA_fnc_addSetting;
//
[
    "mjb_med_tweaks_unstableWakeModScale",
    "SLIDER",
    ["Unstable Wake Uncon Cap Modifier Scale", "Higher number adds less chance over time. At double the softCap: 1:+100%, 2:+50%, 3:+33%. At triple the softCap 2:+100%, 3:+66%."],
    [_title,"Unstable Wake"],
    [0.10, 10, 2, 2],
    true
] call CBA_fnc_addSetting;
//*/

[
    "mjb_med_tweaks_unstableWakeNeedsPulse",
    "CHECKBOX",
    ["Require Pulse for Unstable Wake", "Whether a pulse is required, CPR counts as pulse."],
    [_title, "Unstable Wake"],
    false,
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_unstableWakeIgnoreBleed",
    "CHECKBOX",
    ["Ignore Severe Bleeding", "Allow wake up with dangerous bleeding, will cause faster bleedout, and might immediately lose consciousness again."],
    [_title, "Unstable Wake"],
    false,
    false
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_unstableWakeFaint",
    "CHECKBOX",
    ["Faint While Unstable", "Whether a player will faint after waking in an unstable condition if the player remains unstable."],
    [_title, "Unstable Wake"],
    true,
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_unstableWakeMin",
    "SLIDER",
    ["Faint Min Wake Time", "Minimum time to be awake after a successful wake roll, while vitals are still unstable."],
    [_title,"Unstable Wake"],
    [1, 180, 15, 0],
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_unstableWakeMax",
    "SLIDER",
    ["Faint Max Wake Time", "Maximum time to be awake after a successful wake roll, while vitals are still unstable."],
    [_title,"Unstable Wake"],
    [1, 600, 45, 0],
    true
] call CBA_fnc_addSetting;

[
    "mjb_med_tweaks_unstableWakeLog",
    "CHECKBOX",
    ["Debug Info", "Logs player condition on wake up, also sends to server."],
    [_title, "Unstable Wake"],
    false,
    true
] call CBA_fnc_addSetting;

// ACE Constants variables
[
    QEGVAR(medical,const_stableVitalsBloodThreshold),
    "SLIDER",
    ["[ACE] Minimum Blood for Stable Vitals", "Blood volume where patient is considered stable."],
    [_title, "xAce Constants variables"],
    [0, 6, MINIMUM_BLOOD_FOR_STABLE_VITALS_DEFAULT, 3, false],
    true
] call CBA_fnc_addSetting;

[
    QEGVAR(medical,const_bloodLossKnockOutThreshold),
    "SLIDER",
    ["[ACE] Blood Loss Knock Out Threshold", "Bleed rate that knocks out a unit, as percent of cardiac output."],
    [_title, "xAce Constants variables"],
    [0, 1, BLOOD_LOSS_KNOCK_OUT_THRESHOLD_DEFAULT, 2, true],
    true
] call CBA_fnc_addSetting;

[
    QEGVAR(medical,const_penetrationThreshold),
    "SLIDER",
    ["[ACE] Penetrating Wound Threshold", "Minimum amount of damage required for penetrating wounds (also minDamage for velocity wounds)."],
    [_title, "xAce Constants variables"],
    [0, 1, PENETRATION_THRESHOLD_DEFAULT, 2],
    true
] call CBA_fnc_addSetting;

[
    QEGVAR(medical,const_limpingDamageThreshold),
    "SLIDER",
    ["[ACE] Limping Damage Threshold", "Single hit minimum leg damage required for limping."],
    [_title, "xAce Constants variables"],
    [0, 1, LIMPING_DAMAGE_THRESHOLD_DEFAULT, 2],
    true
] call CBA_fnc_addSetting;

[
    QEGVAR(medical,const_fractureDamageThreshold),
    "SLIDER",
    ["[ACE] Fracture Damage Threshold", "Single hit minimum limb damage required for fracture."],
    [_title, "xAce Constants variables"],
    [0, 1, FRACTURE_DAMAGE_THRESHOLD_DEFAULT, 2],
    true
] call CBA_fnc_addSetting;

[
    QEGVAR(medical,const_headDamageThreshold),
    "SLIDER",
    ["[ACE] Fatal Head Damage Threshold", "Single hit able to cause fatal damage to head."],
    [_title, "xAce Constants variables"],
    [0, 4, HEAD_DAMAGE_THRESHOLD_DEFAULT, 2],
    true
] call CBA_fnc_addSetting;

[
    QEGVAR(medical,const_organDamageThreshold),
    "SLIDER",
    ["[ACE] Fatal Body Damage Threshold", "Single hit able to cause fatal damage to torso."],
    [_title, "xAce Constants variables"],
    [0, 4, ORGAN_DAMAGE_THRESHOLD_DEFAULT, 2],
    true
] call CBA_fnc_addSetting;

[
    QEGVAR(medical,const_heartHitChance),
    "SLIDER",
    ["[ACE] Heart Hit Chance", "Chance to hit heart when hitting torso."],
    [_title, "xAce Constants variables"],
    [0, 1, HEART_HIT_CHANCE_DEFAULT, 4],
    true
] call CBA_fnc_addSetting;

[
    QEGVAR(medical,const_painFadeTime),
    "SLIDER",
    ["[ACE] Pain Fade Time", "Pain fade out time (time it takes until pain is guaranteed to be completly gone) in seconds."],
    [_title, "xAce Constants variables"],
    [0, 1800, PAIN_FADE_TIME_DEFAULT, 0],
    true
] call CBA_fnc_addSetting;