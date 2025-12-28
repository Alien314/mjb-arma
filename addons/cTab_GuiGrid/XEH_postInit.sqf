#include "settings.sqf"

if (mjb_ctab_fix) then {
	0 spawn {sleep 1;
		if (!isNil 'ctab_core_drawMainMap' && {isNil 'ctab_core_drawMainMapHandler' || {ctab_core_drawMainMapHandler isEqualTo -1}}) then {
			if ( ctab_core_drawMainMap ) then {
				ctab_core_drawMainMapHandler = (findDisplay 12 displayCtrl 51) ctrlAddEventHandler ["draw", { 
					params ["_ctrl"];
					[_ctrl,false] call cTab_fnc_drawUserMarkers;
					[_ctrl,0] call cTab_fnc_drawBftMarkers;
				}];
			};
		};
	};
};