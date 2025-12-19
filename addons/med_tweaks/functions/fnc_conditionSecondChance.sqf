//#include "..\script_component.hpp"
/*
 * Author: mharis001
 * Condition for going into cardiac arrest upon receiving a fatal injury.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call ace_medical_statemachine_fnc_conditionSecondChance
 *
 * Public: No
 */
// edited to check unit var
params ["_unit"];

if (isPlayer _unit) exitWith {
   (_unit getVariable ['ace_medical_statemachine_fatalInjuriesPlayer',ace_medical_statemachine_fatalInjuriesPlayer]) isNotEqualTo 0
};
(_unit getVariable ['ace_medical_statemachine_fatalInjuriesAI',ace_medical_statemachine_fatalInjuriesAI]) isNotEqualTo 0
