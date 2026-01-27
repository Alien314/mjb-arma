//#include "..\script_component.hpp"
/*

 */

params ["_unit"];

private _knockTime = cba_missionTime;
private _delay = mjb_med_tweaks_unstableWakeDelay;
private _softCap = mjb_med_tweaks_unstableWakeSoftCap;
_unit setVariable ['mjb_unstableWake',_knockTime];
sleep _delay;
if (10e9 < (_unit getVariable ['ace_medical_lastWakeUpCheck',0])) exitWith {};
while {alive _unit && { (_unit getVariable ['ace_isUnconscious',false]) }} do {
	if ((_unit getVariable ['mjb_unstableWake',0]) isNotEqualTo _knockTime) exitWith {};
	private _blood = (_unit getVariable ['ace_medical_bloodVolume',6.0]);
	private _bleed = (_unit getVariable ['ace_medical_woundBleeding',0]);
	private _pulse = (_unit getVariable ['ace_medical_heartRate',80]);
	private _timeAsleep = (cba_missionTime - _knockTime);
	private _modScale = mjb_med_tweaks_unstableWakeModScale;
	private _modifier = ( ( (_timeAsleep / (_modScale * _softCap) ) - (1/2)) max 0 );
	private _roll = (random 1);
	private _chance = (mjb_med_tweaks_unstableWakeChance + _modifier);
	if (_roll < _chance && {(!mjb_med_tweaks_unstableWakeNeedsPulse || {_pulse > 0}) && { 3.6 < _blood && { ( mjb_med_tweaks_unstableWakeIgnoreBleed || {ace_medical_const_bloodLossKnockOutThreshold > _bleed } ) } } }) exitWith {
		if (mjb_med_tweaks_unstableWakeLog) then {
			[format ["MJB Unstable Wake success: %1, heartrate: %2, blood: %3, bleeding: %4, roll: %5/%6, time uncon: %7", name player, _pulse, _blood, _bleed, _roll, _chance, _timeAsleep]] remoteExec ['diag_log',([0,-2] select isDedicated)];
		};
		if (_pulse < 40) then {
			['ace_medical_CPRSucceeded',_unit] call CBA_fnc_localEvent;
			//[_unit, false] call ace_medical_status_fnc_setCardiacArrestState; // leaves you in arrest state but sets pulse temporarily?
		};
		//[_unit, false] call ace_medical_status_fnc_setUnconsciousState;
		[_unit, ace_medical_STATE_MACHINE, "Unconscious", "Injured",{
			[_this, false] call ace_medical_status_fnc_setUnconsciousState;
		},"UnstableWake"] call CBA_statemachine_fnc_manualTransition;
		//['ace_medical_WakeUp', _unit] call CBA_fnc_localEvent; //only works when stable
		if !(mjb_med_tweaks_unstableWakeFaint) exitWith {_unit setVariable ['mjb_unstableWake',nil];};
		private _faintTime = ((random mjb_med_tweaks_unstableWakeMax) + mjb_med_tweaks_unstableWakeMin);
		[{
			([(_this select 0)] call ace_medical_status_fnc_hasStableVitals)
		},
		{
			(_this select 0) setVariable ['mjb_unstableWake',nil];
		}, [_unit,_knockTime], _faintTime,
		{ params ['_unit','_knockTime'];
			if (!alive _unit || {_knockTime isNotEqualTo (_unit getVariable ['mjb_unstableWake',0])}) exitWith { };
			_unit setVariable ['mjb_unstableWake',nil];
			[_unit,true] call ace_medical_fnc_setUnconscious;
		}] call CBA_fnc_waitUntilAndExecute;
	};
	
	sleep _delay;
};
if !(alive _unit) then {_unit setVariable ['mjb_unstableWake',nil];};