params ["_logic"];

if (!hasInterface) exitWith {};

private _unit = attachedTo _logic;
private _pos = getPosASL _logic;

if (local _logic) then { _logic spawn {sleep 5; deleteVehicle _this; }; };

if (isNull _unit) exitWith {
	player setVariable ["startpos", _pos, true];
};

if (_unit isEqualTo player) then {	
	player setVariable ["startpos", _pos, true];
};