
/** 
	************** KEYBINDS **************
*/
["IZLID", 'WORM_IZLID_toggleIzlid', 'Toggle Izlid', {
	if ((currentWeapon player) isNotEqualTo "Worm_IZLIDB") exitWith {false};
    // toggle illuminator on/off
	[player] call WORM_IZLID_fnc_toggleIzlid;
	true;
}, {false}, [0xF0, [false, false, false]], false] call CBA_fnc_addKeybind;

["IZLID", 'WORM_IZLID_toggleIzlidMomentary', 'Toggle Izlid (momentary)', {
	if ((currentWeapon player) isNotEqualTo "Worm_IZLIDB") exitWith {false};
    // toggle illuminator on/off
	[player] call WORM_IZLID_fnc_toggleIzlid;
	true;
}, {
	if ((currentWeapon player) isNotEqualTo "Worm_IZLIDB") exitWith {false};
    [player] call WORM_IZLID_fnc_toggleIzlid;
	true;
}] call CBA_fnc_addKeybind;
