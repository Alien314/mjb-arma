private _title = "MJB Arma";

[
    "mjb_ratsServerIP",
    "EDITBOX",
    ["RATS Server IP", "Sets the server IP that the spotlight button in main menu connects to."],
    [_title, "Player QoL"],
    ['23.246.128.10',true],
    false,
	{
		params ['_value'];
		profileNamespace setVariable ["mjb_ratsServerIP",_value];
	}
] call CBA_fnc_addSetting;

[
    "mjb_ratsServerPort",
    "EDITBOX",
    ["RATS Server Port", "Sets the server port that the spotlight button in main menu connects to."],
    [_title, "Player QoL"],
    ['2302',true],
    false,
	{
		params ['_value'];
		profileNamespace setVariable ["mjb_ratsServerPort",_value];
	}
] call CBA_fnc_addSetting;
