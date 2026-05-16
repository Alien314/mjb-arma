
if (is3DEN) exitWith {};

params [["_mode", "", [""]], ["_input", [], [[]]]];
_input params [["_logic", objNull, [objNull]], ["_isActivated", true, [true]], ["_isCuratorPlaced", false, [true]]];

if (_isCuratorPlaced) then {
	if !(local _logic) exitWith {};
	private _pos = getPosASL _logic;
	deleteVehicle _logic;

	if (isNil "zen_dialog") exitWith {};

	["Lock Doors",
		[
			["SLIDER", "Chance House:", [0,1,1,2]],
			["SLIDER", "Chance to Lock Doors:", [0,1,0.2,2]],
			["SLIDER:RADIUS", "Radius:", [20,2000,300,0,_pos]]
		], {  params ["_values", "_pos"];
			_values params ["_chanceH","_chanceDoor","_area"];

			[_pos,_area,_chanceH,_chanceDoor] call tsp_fnc_breach_lock;
	},{},_pos] call zen_dialog_fnc_create;
} else {
	if !(local _logic && {_isActivated}) exitWith {};

    private _objects = (synchronizedObjects _logic);
    private _triggers = (_objects select {_x isKindOf "EmptyDetector"});
	_objects = (_objects select {_x isKindOf "Static"});

	private _pos = getPosASL _logic;

    private _area = ([_logic] + (_logic getVariable ['objectarea',[1000,1000,0,false,-1]]));
	private _radius =  ((_area select 1) max (_area select 2)) * 1.42;
    private _chanceH = _logic getVariable ['mjb_lockDoors_chanceHouse',1];
    private _chanceDoor = _logic getVariable ['mjb_lockDoors_chanceDoor',0.2];

	_objects append ((nearestTerrainObjects [_logic, ["BUILDING","HOUSE","CHURCH","CHAPEL","FUELSTATION","HOSPITAL","RUIN","BUNKER"],_radius,false,true]) inAreaArray _area);

	_objects append ((8 allObjects 0) inAreaArray _area);

	{
		if (_x getVariable ["breach_blacklist_lock", false] || (typeOf _x) in tsp_cba_breach_lock_blacklist) then {continue};  //--  Skip
		for "_i" from 0 to (count (configfile >> "CfgVehicles" >> typeOf _x >> "UserActions")) do {
			if (random 1 <= _chanceDoor) then {_x setVariable [format ["bis_disabled_Door_%1", _i], 1, true]};
		};
	} forEach (_objects);
};
