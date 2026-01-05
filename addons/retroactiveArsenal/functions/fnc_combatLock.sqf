params ['_vehicle',['_side',-1]];

if (!isServer) exitWith {_this remoteExec ['mjb_arsenal_fnc_combatLock',2];};
if (!canSuspend) exitWith {_this spawn mjb_arsenal_fnc_combatLock};

_vehicle setVariable ['mjb_combatLock',true,true];
while {((crew _vehicle) select {alive _x}) isEqualTo []} do {
	private _clock = (_vehicle getVariable ['mjb_combatLock',nil]);
	if (isNil '_clock') exitWith {};
	private _lock = false;
	if (count ((_vehicle nearEntities [["CAManBase"],20]) select {isPlayer _x}) isEqualTo 0) then {
		_lock = true;
	};
	[_vehicle, _lock] remoteExec ["lock",_vehicle];
	sleep 5;
};
private _clock = (_vehicle getVariable ['mjb_combatLock',nil]);
if !(isNil '_clock') then {
	[_vehicle, false] remoteExec ["lock",_vehicle];
};

_vehicle setVariable ['mjb_combatLock',nil,true];