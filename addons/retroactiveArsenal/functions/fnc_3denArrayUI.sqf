//params [ ["_display", displayNull], ["_mode", "onLoad"], ["_params", []] ];

private _unit = (get3DENSelected '' #0#0);
if (isNil "zen_dialog") exitWith {systemChat "Zeus Enhanced not loaded."};
if (isNil '_unit'|| { !_unit isEqualType objNull || { isNull _unit }}) exitWith {
    systemChat "No object selected.";
};

["3DEN Array Object", 
	[
		["SLIDER", "Grid X width:", [-100,100,1,0], true],
		["SLIDER", "Grid Y length:", [-100,100,1,0], true],
		["SLIDER", "Z step height:", [-100,100,0,0], true],
		["CHECKBOX", "Step with width:", false, true],
		["SLIDER", "Grid X gap:", [-100,100,0,0], true],
		["SLIDER", "Grid Y gap:", [-100,100,0,0], true]
	], {  params ["_values", "_args"];
//['_object',objNull],['_xCount',1],['_yCount',1],['_zStep',0],['_stepX',false],['_xAdd',0],['_yAdd',0]
		_values params ["_xCount","_yCount","_zStep","_stepX","_xAdd","_yAdd"];
		_args params ["_object"];
		(_args + _values) call mjb_arsenal_fnc_3denArrayObject;
		
},{},[_unit]] call zen_dialog_fnc_create;