["z\mjb\addons\perks\functions\fnc_canDrag.sqf", "ace_dragging_fnc_canDrag"] call CBA_fnc_compileFunction;
["z\mjb\addons\perks\functions\fnc_canCarry.sqf", "ace_dragging_fnc_canCarry"] call CBA_fnc_compileFunction;
["z\mjb\addons\perks\functions\fnc_initPerson.sqf", "ace_dragging_fnc_initPerson"] call CBA_fnc_compileFunction;
//["z\mjb\addons\perks\functions\fnc_handleUnconscious.sqf", "ace_dragging_fnc_handleUnconscious"] call CBA_fnc_compileFunction;
["z\mjb\addons\perks\functions\fnc_startDragLocal.sqf", "ace_dragging_fnc_startDragLocal"] call CBA_fnc_compileFunction;
["z\mjb\addons\perks\functions\fnc_dragObject.sqf", "ace_dragging_fnc_dragObject"] call CBA_fnc_compileFunction;
["z\mjb\addons\perks\functions\fnc_dropObject.sqf", "ace_dragging_fnc_dropObject"] call CBA_fnc_compileFunction;
["z\mjb\addons\perks\functions\fnc_startDragPFH.sqf", "ace_dragging_fnc_startDragPFH"] call CBA_fnc_compileFunction;
["z\mjb\addons\perks\functions\fnc_handleAnimChanged.sqf", "ace_dragging_fnc_handleAnimChanged"] call CBA_fnc_compileFunction;

call compile preprocessFileLineNumbers "z\ace\addons\dragging\XEH_preInit.sqf";