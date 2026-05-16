if !(hasInterface) exitWith {};
if (ssd_scremDisable) exitWith {};

_sound = _this select 0;			// String
_soundObject = _this select 1;		// Object
_type1 = _this select 2;			// Number - 0 for head, 1 for chest, 2 for stomach, 3 for general
_type2 = _this select 3;			// Number - 0 for hit, 1 for death, 2 for rattle
_dummy = _this select 4;
_unconscious = _soundObject getVariable ["ACE_isUnconscious", false];

if (_unconscious AND !(SSD_DS_enable_unconscious)) exitWith {};

if (( (_type2 == 0) AND !(SSD_DS_enable_hit) ) OR ( (_type2 == 1) AND !(SSD_DS_enable_death) ) OR (_type2 == 2) AND !(SSD_DS_enable_rattle)) exitWith {};

_type1N = switch (_type1) do {case 0: {"head"};	case 1: {"chest"}; case 2: {"stomach"};	case 3: {"general"};};

_type2N = switch (_type2) do {case 0: {"h"}; case 1: {"k"};	case 2:	{"r"};};

_probability = missionNamespace getVariable (format ["SSD_DS_%2_%1",_type1N,_type2N]);

if (random 1 > _probability) exitWith {};
private _distance = 140;
//private _inside = (insideBuilding _dummy == 1);
//private _soundConfig = getArray (configFile >> 'CfgSounds' >> _sound >> 'sound');
//_soundConfig params ['_soundFile','_volume'];
//_soundFile = _soundFile trim ['\',1];
//systemChat _soundFile;
//if (_soundObject isKindOf 'CAManBase') then {_volume = _volume * (missionNamespace getVariable ['ssd_scremVolume',1]);};
//if (_soundObject isKindOf 'CAManBase') then {_distance = _distance * (missionNamespace getVariable ['ssd_scremVolume',1]);};
//playSound3D [_soundFile, _dummy, false, getPosASL _dummy, _volume, 1,1000, 0, true];
_dummy say3D [_sound, _distance,1,parseNumber ssd_scremVolume];