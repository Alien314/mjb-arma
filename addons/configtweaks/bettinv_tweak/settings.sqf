
[
    "mjb_disableStackMove",
    "CHECKBOX",
    ["Disable Stack Move", "Prevents stack moving items entirely."],
    ["Better Inventory", "Stacks"],
    true,
    true,
    { },
    true
] call CBA_fnc_addSetting;

[
    "mjb_stackMoveCooldown",
    "SLIDER",
    ["Stack Move Cooldown", "Seconds before able to stack move again, multiplied by 1/5 of the item limit, so full stack will always be 20 times this number at 100 stack limit. 0 disables."],
    ["Better Inventory", "Stacks"],
    [0, 600, 1, 1],
    true,
    {
        params ["_value"];
        mjb_StackMoveCooldown = _value;
    }
] call CBA_fnc_addSetting;

[
    "mjb_stackLimit",
    "SLIDER",
    ["Stack Move Item Limit", "Originally limited to 100."],
    ["Better Inventory", "Stacks"],
    [1, 100, 100, 1],
    true,
    {
        params ["_value"];
        mjb_StackLimit = _value;
    }
] call CBA_fnc_addSetting;