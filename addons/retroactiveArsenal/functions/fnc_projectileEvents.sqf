params ['_proj'];

/*
_proj addEventHandler ["SubmunitionCreated", {
	params ["","_subProj"];
	_subProj call mjb_subRecursion;
}];
_proj addEventHandler ["HitPart", {
	params ["", "_hitEntity", "", "", "", "", "_components", "_radius" ,"", ""];
	if (_components isEqualTo []) exitWith {};
	systemChat format ["Hit %1 in %2, radius: %3",typeOf _hitEntity,_components,_radius];
}];
_proj addEventHandler ['HitExplosion', {
	params ['', '_hitEntity', '','_components'];
	systemChat format ['Hit %1 in %2, radius: %3',_hitEntity,_components apply {[(_x select 2),(_x select 3)]}];
}];
*/
_proj addEventHandler ["Penetrated", {
	params ["_proj", "_hitObject", "", "", "", ""];
	if (_hitObject isKindOf "Land_CanisterFuel_F") then {
		private _incendiary = getNumber (configFile >> "CfgAmmo" >> (typeOf _proj) >> "ace_vehicle_damage_incendiary");
		if (_incendiary isEqualTo 0 || {_incendiary < (random 1)}) exitWith {};
		private _mult = ((_hitObject getVariable ['ace_refuel_capacity',20]) / 20);
		if (_mult isEqualTo 0) exitWith {};
		[_hitObject,(10 * _mult),2,(3 * _mult)] call mjb_arsenal_fnc_objectBurn;
		_hitObject setVariable ['ace_refuel_capacity',0];
	};
}];