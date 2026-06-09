#include "settings.sqf"

if (mjb_ctab_fix) then {
	0 spawn {sleep 1;
		if (!isNil 'ctab_core_drawMainMap') then {
			if ( ctab_core_drawMainMap ) then {
				if !(isNil 'ctab_core_drawMainMapHandler') then {
					if (ctab_core_drawMainMapHandler isEqualTo -1) exitWith {};
					(findDisplay 12 displayCtrl 51) ctrlRemoveEventHandler ["draw",ctab_core_drawMainMapHandler];
				};
				ctab_core_drawMainMapHandler = ((findDisplay 12 displayCtrl 51) ctrlAddEventHandler ["draw", { 
					params ["_ctrl"];
					if ((missionNamespace getVariable ['mjb_cTab_delayMap',0]) < 2) exitWith {
						if (isNil 'mjb_cTab_delayMap') then { 0 spawn {waitUntil {!visibleMap}; mjb_cTab_delayMap = nil; }; };
						missionNamespace setVariable ['mjb_cTab_delayMap',(missionNamespace getVariable ['mjb_cTab_delayMap',0] ) + 1];
					}; 
					private _visBounds = [_ctrl] call cTab_fnc_ctrlMapVisibleBounds;
					[_ctrl,false,_visBounds] call cTab_fnc_drawUserMarkers;
					[_ctrl,0,_visBounds] call cTab_fnc_drawBftMarkers;
				}]);
			};
		};
	};
};