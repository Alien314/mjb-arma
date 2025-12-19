//#include "..\script_component.hpp"
/*
 * Author: BaerMitUmlaut
 * Condition for an execution caused death (fatal injury received in cardiac arrest).
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call ace_medical_statemachine_fnc_conditionExecutionDeath
 *
 * Public: No
 */
// edited to check unit var
params ["_unit"];

(if (isPlayer _unit) then {
   (_unit getVariable ['ace_medical_statemachine_fatalInjuriesPlayer',ace_medical_statemachine_fatalInjuriesPlayer]) isNotEqualTo 2
} else {
	(_unit getVariable ['ace_medical_statemachine_fatalInjuriesAI',ace_medical_statemachine_fatalInjuriesAI]) isNotEqualTo 2
})
&& {!(_unit getVariable ['ace_medical_deathBlocked', false])}
