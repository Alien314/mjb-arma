params [['_class','',['']]];


if ((getNumber (configFile >> "CfgMagazines" >> _class >> 'count')) isEqualTo 1) exitWith {true};

if (getNumber (configFile >> "CfgMagazines" >> _class >> 'mjb_disableTacReload') isEqualTo 1) exitWith {true};

if (missionNamespace getVariable ['ace_reload',false]) exitWith {

	if (getNumber (configFile >> "CfgMagazines" >> _class >> 'ACE_isBelt') isEqualTo 1) exitWith {true};

	false
};

if (('belt' in toLower _class || {
	'box' in toLower _class || {
	'pouch' in toLower _class || {
	'box' in toLower (getText ( configFile >> 'CfgMagazines' >> _class >> "displayName")) || {
	'pouch' in toLower (getText ( configFile >> 'CfgMagazines' >> _class >> "displayName"))|| {
	'belt' in toLower (getText ( configFile >> 'CfgMagazines' >> _class >> "displayName"))}}}}}
)) exitWith {true};

false