

(_this select 0) addEventHandler ["AnimStateChanged", { params ["_unit","_anim"];
	if (mjb_slideTackle && {local _unit && {_anim in ["mainweapon_slide","pistol_slide","unarmed_slide"]}}) then {
		_this spawn {
			params ["_unit", "_anim"]; 
			while {animationState _unit isEqualTo _anim} do {
				sleep 0.1;
				private _vector = (velocity _unit);
				//_vector = _vector vectorMultiply 0.5;//0.1 / ((_vector # 2) )
				private _vectorP = _vector vectorMultiply 10;
				_vectorP set [2,(_vector # 2) + 400];
				private _pos = _unit modelToWorld (_unit selectionPosition "leftfoot");
				{
					[	_x,
						[
							( [ [(_vector # 0) * 10, (_vector # 1) * 10, (_vector # 2) + (getMass _x / 2)], _vectorP] select (_x isKindOf "CAManBase") ),
							(_x selectionPosition "rightFoot"),
							false
						]
					] remoteExec ["addForce", _x];
				} forEach ( ( (nearestObjects [_pos,[], 0.8]) select { 
					!(_x isKindOf "CAManBase") && { (_x isKindOf "thingX") && { speed _x < 0.1 }} || { side _x isNotEqualTo side _unit && {(!(alive _x) || {isAwake _x})}}
				}) - [_unit]);
			};
		};
	};
}];