params ['_medic'];

private _endInAnim = "AmovP[pos]MstpS[stn]W[wpn]Dnon";

private _pos = ["knl", "pne"] select (stance _medic == "PRONE");
private _stn = "non";
private _wpn = ["non", "rfl", "lnr", "pst"] param [["", primaryWeapon _medic, secondaryWeapon _medic, handgunWeapon _medic] find currentWeapon _medic, "non"];
if (_wpn != "non") then {
	_stn = ["ras", "low"] select (weaponLowered _medic);
};

_endInAnim = [_endInAnim, "[pos]", _pos] call CBA_fnc_replace;
_endInAnim = [_endInAnim, "[stn]", _stn] call CBA_fnc_replace;
_endInAnim = [_endInAnim, "[wpn]", _wpn] call CBA_fnc_replace;

[_medic, 'AinvPknlMstpSnonWnonDnon_medic0'] call ace_common_fnc_doAnimation;
[_medic, _endInAnim] call ace_common_fnc_doAnimation;
_medic setVariable ["mjb_endInAnim", _endInAnim];

[mjb_clutterTime, [_medic],
	{   params ['_args'];
		_args params ['_medic'];
		_obj = createVehicle [(['Land_ClutterCutter_medium_F','Land_ClutterCutter_large_F'] select mjb_clutterArea), ace_player, [], 0, 'CAN_COLLIDE'];
		private _endInAnim = _medic getVariable "mjb_endInAnim";

		if (!isNil "_endInAnim") then {
			if (animationState _medic != _endInAnim) then {
				[_medic, _endInAnim, 2] call ace_common_fnc_doAnimation;
			};

			_medic setVariable ["mjb_endInAnim", nil];
		};
	},
	{	params ['_args'];
		_args params ['_medic'];
		private _endInAnim = _medic getVariable "mjb_endInAnim";

		if (!isNil "_endInAnim") then {
			if (animationState _medic != _endInAnim) then {
				[_medic, _endInAnim, 2] call ace_common_fnc_doAnimation;
			};

			_medic setVariable ["mjb_endInAnim", nil];
		};
	},
	 'Removing clutter...'
] call ace_common_fnc_progressBar