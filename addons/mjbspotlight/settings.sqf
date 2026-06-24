private _title = "MJB Arma";

[
    "mjb_ratsServerIP",
    "EDITBOX",
    ["RATS Server IP", "Sets the server IP that the spotlight button in main menu connects to."],
    [_title, "Player QoL"],
    ['38.147.105.134',true],
    false
] call CBA_fnc_addSetting;

[
    "mjb_ratsServerPort",
    "EDITBOX",
    ["RATS Server Port", "Sets the server port that the spotlight button in main menu connects to."],
    [_title, "Player QoL"],
    ['2302',true],
    false
] call CBA_fnc_addSetting;
