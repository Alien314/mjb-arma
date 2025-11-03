params ["_logic"];

private _unit = attachedTo _logic;

if (isNull _unit) exitWith {
	if (isServer) then {
		[{ player setUnitTrait ["Medic", true]; }] remoteExec ["call", 0, "mjb_allPlayersMedic"];
	};

	if !(local _logic) exitWith {};

	deleteVehicle _logic;
};

if (_unit isEqualTo player) then {
	_unit setUnitTrait ["Medic", true];
};

if !(local _logic) exitWith {};

deleteVehicle _logic;