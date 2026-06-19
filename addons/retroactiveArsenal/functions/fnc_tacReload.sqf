params ["_unit", "_weapon", "_muzzle", "_newMagazine", "_oldMagazine",["_class",'']];

if (_unit isNotEqualTo (call CBA_fnc_currentUnit) || {_weapon isEqualTo "Throw"}) exitWith {};

if (mjb_tacGestureFix) then {
	private _gesture = gestureState _unit;
    if (_gesture isEqualTo "" || {"non" in _gesture}) exitWith {};
	/*private _gestureEH = _unit addEventHandler ['GestureChanged',{ params ["_unit", "_gesture"];
		_unit removeEventHandler [_thisEvent,_thisEventHandler];
	}];*/
	[_unit, 'GestureDone', { params ["_unit", "_gesture"]; _thisArgs params ['_reload','_magazine'];
		if (_reload isNotEqualTo _gesture) then {
			if (mjb_tacDropMag) then {
				[_unit,_magazine] call mjb_arsenal_fnc_tacDropMag;
			} else {
				[_unit,_magazine] spawn { params ['_unit','_magazine']; _magazine params ['_class','_ammo'];
					sleep 1; [_unit,_class,_ammo] call CBA_fnc_addMagazine;
				};
			};
		};
		//_unit removeEventHandler ['GestureChanged',_gestureEH];
		_unit removeEventHandler [_thisEvent,_thisEventHandler];
	}, [_gesture,_newMagazine]] call CBA_fnc_addBISEventHandler;
};

if (isNil '_newMagazine') exitWith {};
scopeName "main";
if (isNil '_oldMagazine') then { _class = (_newMagazine select 0); } else {
	_class = (_oldMagazine select 0);
	if ((_oldMagazine select 1) isEqualTo 0) exitWith {};
	private _shells = (mjb_tacLoadHash getOrDefaultCall [(_class + '_shells'), {
		_class call mjb_arsenal_fnc_isShells
	}, true]);
	if (_shells isNotEqualTo false && {(mjb_tacLoadHash getOrDefaultCall [( (_newMagazine select 0) + '_shells'), {
		(_newMagazine select 0) call mjb_arsenal_fnc_isShells
	}, true]) isEqualTo _shells}) then {
		private _toLoad = abs ((_newMagazine select 1) - (_oldMagazine select 1));
		private _gesture = gestureState _unit;
		if (_toLoad isEqualTo 0) then {_unit switchGesture [_gesture, 0.95]; breakOut "main"};
		private _max = (mjb_tacLoadHash getOrDefaultCall [( (_newMagazine select 0) + '_shellMax'), {
			getNumber (configFile >> 'CfgMagazines' >> (_newMagazine select 0) >> 'count')
		}, true]);
		private _loadTime = 0.15 + ((0.69/_max) * _toLoad);
		[{
			((_this select 0) getUnitMovesInfo 5) > (_this select 1)
		},
		{
			(_this select 0) switchGesture [gestureState (_this select 0), 0.95];
		}, [_unit,_loadTime],((_unit getUnitMovesInfo 7) * (1.01)),{ }] call CBA_fnc_waitUntilAndExecute;

		// exit tacreload
		breakOut "main"
	};
};

if (!(mjb_tacReload) || {toLower _weapon in ['throw','put']}) exitWith {};
if (mjb_tacForbiddenMags isEqualType '') then { mjb_tacForbiddenMags = (mjb_tacForbiddenMags splitString ',')};
if (mjb_tacForbiddenMuzzles isEqualType '') then {mjb_tacForbiddenMuzzles = (mjb_tacForbiddenMuzzles splitString ',')};
if ( _muzzle in (mjb_tacForbiddenMuzzles) || { 
	_class in (mjb_tacForbiddenMags) || {
	(mjb_tacLoadHash getOrDefaultCall [(_class + '_notMagazine'), {
		_class call mjb_arsenal_fnc_notMagazine
	}, true]) } }
) exitWith { };

// Load empty, revolvers and belts are still excepted from this
if (isNil '_oldMagazine') exitWith {
	_unit switchGesture [gestureState _unit, 0.4];
};

private _curTime = cba_missionTime;
_unit setVariable ['mjb_tacReloadTime',_curTime];
// delay 0.15 and leave action until a tenth of reload time
private _aID = (_unit addAction ['Quick Reload', {
	params ['_unit','','_aID','_args'];
	_args params ['_oldMagazine','_rTime'];
	if ((_unit getVariable ['mjb_tacReloadTime',0]) isNotEqualTo _rTime) exitWith { _unit setVariable ['mjb_tacReloadTime',nil]; _unit removeAction _aID; };
	// wait until gesture is at 0.15 progress then drop magazine
	[{
		((_this select 0) getUnitMovesInfo 5) > 0.15
	},
	{
		params ['_unit','_oldMagazine','_rTime'];
		if ((_unit getVariable ['mjb_tacReloadTime',0]) isNotEqualTo _rTime) exitWith { };
		if (!isNil '_oldMagazine') then {
			[_unit,_oldMagazine] call mjb_arsenal_fnc_tacDropMag;
		};
		_unit switchGesture [gestureState _unit, 0.45];
		private _evID = ([player,"Reloaded", {
			params ["_unit", "_weapon", "_muzzle", "_newMagazine", "_oldMagazine"];
			if (!isNil '_oldMagazine') then {
				_oldMagazine params ['_class','_ammo'];
				if ((_unit getVariable ['mjb_tacReloadTime',0]) isNotEqualTo _thisArgs) exitWith {
					_unit removeEventHandler ["Reloaded",_thisID];
				};
				[{
					_this call CBA_fnc_removeMagazine;
				}, [_unit,_class,_ammo]] call CBA_fnc_execNextFrame;
			};
			_unit setVariable ['mjb_tacReloadTime',nil];
			_unit removeEventHandler ["Reloaded",_thisID];
		}, _rTime] call CBA_fnc_addBISEventHandler);
		// waitUntilAndExecute prevents removing the next reload's reloaded handler?
		[{	private _chk = (_this select 0) getVariable ['mjb_tacReloadTime',nil];
			isNil '_chk'
		},{ },
		[_unit,_evID],((_unit getUnitMovesInfo 7) * (1.05 - (0.45 - (_unit getUnitMovesInfo 5)))),
		{
			params ['_unit','_evID'];
			_unit removeEventHandler ['Reloaded', _evID];
		}] call CBA_fnc_waitUntilAndExecute;
	}, [_unit,_oldMagazine,_rTime],((_unit getUnitMovesInfo 7) * (1.01 - (_unit getUnitMovesInfo 5))),{ }] call CBA_fnc_waitUntilAndExecute;
	_unit removeAction _aID;
},[_oldMagazine,_curTime],-1,false,true,'reloadMagazine']);
// remove action after a part of gesture time elapsed
[{params ['_unit','_aID']; _unit removeAction _aID;},[_unit,_aID],(((_unit getUnitMovesInfo 7) * 0.15) max 0.6)] call CBA_fnc_waitAndExecute;