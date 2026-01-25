//#include "..\script_component.hpp"
/*

 */

params ["_unit"];

private _knockTime = cba_missionTime;
private _delay = mjb_med_tweaks_unstableWakeDelay;
_unit setVariable ['mjb_unstableWake',_knockTime];
sleep _delay;
if (10e9 < (_unit getVariable ['ace_medical_lastWakeUpCheck',0])) exitWith {};
while {alive _unit && { (_unit getVariable ['ace_isUnconscious',false]) }} do {
	private _blood = (_unit getVariable ['ace_medical_bloodVolume',6.0]);
	private _bleed = (_unit getVariable ['ace_medical_woundBleeding',0]);
	private _pulse = (_unit getVariable ['ace_medical_heartRate',80]);
	if ((_unit getVariable ['mjb_unstableWake',0]) isNotEqualTo _knockTime) exitWith {};
	private _roll = (random 1);
	if (_roll < mjb_med_tweaks_unstableWakeChance && {(!mjb_med_tweaks_unstableWakeNeedsPulse || {_pulse > 0}) && { 3.6 < _blood && { ( mjb_med_tweaks_unstableWakeIgnoreBleed || {ace_medical_const_bloodLossKnockOutThreshold > _bleed } ) } } }) exitWith {
		if (mjb_med_tweaks_unstableWakeLog) then {
			[format ["MJB Unstable Wake success: %1, heartrate: %2, blood: %3, bleeding: %4, roll: %5/%6, time uncon: %7", name player, _pulse, _blood, _bleed, _roll, mjb_med_tweaks_unstableWakeChance, (cba_missionTime - _knockTime)]] remoteExec ['diag_log',([0,-2] select isDedicated)];
		};
		if (_pulse < 40) then {
			['ace_medical_CPRSucceeded',_unit] call CBA_fnc_localEvent;
			//[_unit, false] call ace_medical_status_fnc_setCardiacArrestState; // leaves you in arrest state but sets pulse temporarily?
		};
		[_unit, false] call ace_medical_status_fnc_setUnconsciousState;
		//['ace_medical_WakeUp', _unit] call CBA_fnc_localEvent; //only works when stable
		_unit setVariable ['mjb_unstableWake',nil];
	};
	sleep _delay;
};
if !(alive _unit) then {_unit setVariable ['mjb_unstableWake',nil];};