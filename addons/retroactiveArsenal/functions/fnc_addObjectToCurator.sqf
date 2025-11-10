/*
 * Author: Glowbal
 * Adds an object to curator upon spawn
 *
 * Arguments:
 * Object <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [object] call ace_zeus_fnc_addObjectToCurator
 *
 * Public: No
 */

params ["_object"];

if !(_object getVariable ['ace_zeus_addObject', ace_zeus_autoAddObjects]) exitWith {};

[{
    {
        _x addCuratorEditableObjects [[_this], true];
    } forEach ([allCurators,(allCurators select {private _wgz = _x getVariable ['jac_canEditUnitsZeus',nil]; isNil '_wgz'})] select mjb_arsenal_preventAddObjectWargame);
}, _object] call CBA_fnc_execNextFrame;