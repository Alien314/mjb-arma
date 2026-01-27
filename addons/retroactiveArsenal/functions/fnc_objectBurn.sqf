params ['_object','_duration','_radius','_intensity'];

private _pos = getPosASLW _object;
if (_pos # 2 <= 0) exitWith {};
private _pos = getPosATL _object;
private _moduleGroup = createGroup [sideLogic, true];
private _hash = ("ace_fire_wreck" + (hashValue _object));
//private _duration = (3 + (random 7));
"ModuleEffectsFire_F" createUnit [
	_pos,
	_moduleGroup,
	(format ["this setPosATL %2; this setVariable ['fireDamage', 0];  this setVariable ['particleLifetime', 0.4]; this setVariable ['effectSize', (%3 * 5)]; this setVariable ['timeout', %1]; this setVariable ['BIS_fnc_initModules_disableAutoActivation', false, true]; if (local this) then {mjb_burnEff = this; this spawn {sleep (1 + %1); deleteVehicle _this;};}; ", _duration, _pos, _radius, _hash])
];
private _module = mjb_burnEff;
mjb_burnEff = nil;

["ace_fire_addFireSource", [_object, _radius, _intensity, _hash, {alive _this},_module]] call CBA_fnc_serverEvent;