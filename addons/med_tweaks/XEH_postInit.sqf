#include "settings.sqf"

if !(hasInterface) exitWith {};

['ace_unconscious',{ params ['_unit','_active'];
	if !(_active && {local _unit}) exitWith { };

	private _att = attachedObjects _unit;
	if ((count _att) isNotEqualTo 0) then {
		[{
			{
				if (isPlayer _x) then {
					if (attachedTo _x isNotEqualTo _unit) exitWith { };

					if (_unit getVariable ['ace_dragging_isDragging',false]) exitWith {
						[_unit, _x] call ace_dragging_fnc_dropObject;
					};
					if (_unit getVariable ['ace_dragging_isCarrying',false]) exitWith {
						[_unit, _x] call ace_dragging_fnc_dropObject_carry;
					};

					detach _x;
				};
			} forEach _this;
		},_att,2] call CBA_fnc_waitAndExecute;
	};

	if !(mjb_med_tweaks_unstableWakeChance > 0) exitWith { };
	[_unit] spawn mjb_med_tweaks_fnc_unstableWake;
}] call cba_fnc_addEventHandler;