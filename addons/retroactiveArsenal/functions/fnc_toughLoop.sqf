params ["_hitCheck",['_skip',false]];

private _vest = vest player;
if (_vest isEqualTo "" || {_vest in diw_armor_plates_main_vestBlacklist}) exitWith {};

private _delay = mjb_plateDelay;
if (!_skip) then {sleep _delay;};
if (_hitCheck isNotEqualTo (player getVariable ["mjb_hitTime", 0])) exitWith {};
private _full = true;
private _plateCarrier = (vestContainer player);
if (!alive player || {_plateCarrier isEqualTo objNull}) exitWith {};
private _plates = _plateCarrier getVariable ["diw_armor_plates_main_plates", [0]];
private _plateCnt = count _plates;
private _maxPlates = diw_armor_plates_main_numWearablePlates;
private _plateRegenCount = (mjb_plateRegenCount - 1) min (_maxPlates - 1);

for '_i' from _plateCnt to _plateRegenCount do {
	_plates pushBack 0;
};

private _plateMaxHp = diw_armor_plates_main_maxPlateHealth;
_plateCnt = _plates findIf {_x < _plateMaxHp};
_plateCarrier setVariable ["diw_armor_plates_main_plates", _plates];
private _tickRegen = mjb_plateRegenPerTick;
private _waitTime = (mjb_plateRegenSpeed/_plateMaxHp) * _tickRegen;
private _inter = mjb_plateDelayInter;
//private _tick = 0.1;
while {_plateCnt isNotEqualTo -1} do {
	private _skip = false;
    private _toughPlate = _plates # _plateCnt;
    while {alive player} do {
        sleep _waitTime;
        if (_hitCheck isNotEqualTo (player getVariable ["mjb_hitTime", 0])) exitWith {_full = false; break}; //?
		_plates = (_plateCarrier getVariable ["diw_armor_plates_main_plates", [0]]);
        private _plateChk = _plates # _plateCnt;
        //if (_plateChk < _toughPlate) exitWith {break}; // non-hit damage source
       // if (_plateChk >= _plateMaxHp) then {
        //    _plates = _plateCarrier getVariable ["diw_armor_plates_main_plates", [0]];
        //    break
       // }; //if (_plateChk > _toughPlate) then {_toughPlate = _plateChk};
		if (_plateChk > _toughPlate) exitWith {_skip = true};
        _toughPlate = _toughPlate + _tickRegen;
        _plates set [_plateCnt, (_toughPlate min _plateMaxHp)];
        _plateCarrier setVariable ["diw_armor_plates_main_plates", _plates];
        [player] call diw_armor_plates_main_fnc_updatePlateUi;
        if (_toughPlate >= _plateMaxHp) then {break};
    };
    if (_inter && {!_skip}) then {
        sleep _delay;
		if (_hitCheck isNotEqualTo (player getVariable ["mjb_hitTime", 0])) exitWith {_full = false; break}; //?
		_plates = _plateCarrier getVariable ["diw_armor_plates_main_plates", []];
        private _plateChk = _plates # _plateCnt;
		if (_plateChk > _toughPlate) exitWith {_skip = true};
		_plateCnt = (count _plates - 1) max 0;
		for '_i' from _plateCnt to (_plateRegenCount - 1) do {
			_plates pushBack 0;
		};
    };
    _plateCnt = _plates findIf {_x < _plateMaxHp};
};
if (_full) then {player setVariable ["mjb_hitTime", nil]};