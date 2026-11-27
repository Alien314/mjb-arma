if (!hasInterface) exitWith {};

WORM_IZLID_laserPerFrameHandler = -1;
WORM_IZLID_laserPerFrameList = [];

{
    if (_x getVariable ["WORM_IZLID_hasLaserOn", false]) then {
        WORM_IZLID_laserPerFrameList pushBack _x;
    };
} forEach allUnits;

//WORM_IZLID_OFFSET = [0.05, 0.1, 0.02];

//WORM_IZLID_MODE_HI = "High";

WORM_IZLID_laserPerFrameHandler = addMissionEventHandler ["Draw3D", {
	{
		private _unit = _x;
		if (alive _unit && {(_unit getVariable ['WORM_IZLID_hasLaserOn', false])}) then {
			private _currentWeapon = (currentWeapon _unit);
            private _currentMode = (currentWeaponMode _unit);
            private _skipFrame = _currentWeapon isNotEqualTo "Worm_IZLIDB";
            if (!_skipFrame && {_currentMode isEqualTo "Pulse"}) then {
                private _startTime = _unit getVariable ['WORM_IZLID_laserStartTime', -1];
                if (_startTime isEqualTo -1) then {
                    _unit setVariable ["WORM_IZLID_laserStartTime", cba_missionTime];
                };

                // full cycle is 1.5 seconds
                // laser is on for 1 second, and then of for 0.5
                if ( ((cba_missionTime - _startTime) mod 1.5) >= 1.0 ) then {
                    _skipFrame = true;
                }
            };

            if (!_skipFrame) then {

                private _gunDir = (_unit weaponDirection _currentWeapon);
                private _normalizedGunDir = vectorNormalized _gunDir;

                private _rightVector = (vectorNormalized (_normalizedGunDir vectorCrossProduct [0,0,-1]));

                private _modeLow = _currentMode isEqualTo "Low";

                drawLaser [
                    (_unit modelToWorldVisualWorld (_unit selectionPosition ['proxy:\a3\characters_f\proxies\pistol.001', 1])) vectorAdd (_rightVector vectorMultiply (0.05)) vectorAdd (_normalizedGunDir vectorMultiply (0.1)) vectorAdd ((vectorNormalized (_rightVector vectorCrossProduct _normalizedGunDir)) vectorMultiply (0.02)),
                    _gunDir,
                    [1000, 1000, 1000],
                    [],
                    ([2,1] select _modeLow),
                    ([0.58,0.05] select _modeLow),
                    -1,
                    true
                ];
            };
		} else {
			WORM_IZLID_laserPerFrameList deleteAt _forEachIndex;
		};
	} forEach WORM_IZLID_laserPerFrameList;
}];

