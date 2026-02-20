["z\mjb\addons\perks\functions\fnc_canDrag.sqf", "ace_dragging_fnc_canDrag"] call CBA_fnc_compileFunction;
["z\mjb\addons\perks\functions\fnc_canCarry.sqf", "ace_dragging_fnc_canCarry"] call CBA_fnc_compileFunction;
//["z\mjb\addons\perks\functions\fnc_handleUnconscious.sqf", "ace_dragging_fnc_handleUnconscious"] call CBA_fnc_compileFunction;

call compile preprocessFileLineNumbers "z\ace\addons\dragging\XEH_preInit.sqf";