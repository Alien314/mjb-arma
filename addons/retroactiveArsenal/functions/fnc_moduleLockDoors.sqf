params ["_logic"];

if !(local _logic) exitWith {};
private _pos = getPosASL _logic;		
deleteVehicle _logic;

if (isNil "zen_dialog") exitWith {};

["Lock Doors", 
	[
		["SLIDER", "Chance House:", [0,1,1,2]],
		["SLIDER", "Chance to Lock Doors:", [0,1,0.2,2]],
		["SLIDER:RADIUS", "Area:", [20,2000,300,0,_pos]]
	], {  params ["_values", "_pos"];
		_values params ["_chanceH","_chanceDoor","_area"];

		[_pos,_area,_chanceH,_chanceDoor] call tsp_fnc_breach_lock;
},{},_pos] call zen_dialog_fnc_create;
