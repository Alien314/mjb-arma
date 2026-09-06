params ['_unit','_target'];

if (!isNil 'mjb_dragDummy') then {
	ropeDestroy mjb_rope;
	deleteVehicle mjb_dragDummyTg;
	deleteVehicle mjb_dragDummy;
	[mjb_dragStrapPFH] call CBA_fnc_removePerFrameHandler;
};

mjb_dragDummy = createVehicle ['ace_fastroping_helper', [0,0,0], [], 0];
mjb_dragDummy attachTo [_unit,[0,0,1]];
mjb_dragDummy allowDamage false;
mjb_dragDummyTg = createVehicle ['ace_fastroping_helper', [0,0,0], [], 0];
mjb_dragDummyTg allowDamage false;
mjb_dragDummyTg attachTo [_target,[0,0,0.3]];
detach mjb_dragDummyTg;
mjb_rope = ropeCreate [mjb_dragDummy,[0,0,0],mjb_dragDummyTg,[0,0,0],3];
mjb_dragStrapPFH = ([{ params ['_args','_handle'];
	_args params ['_unit','_target'];
	if (isNil "mjb_dragDummyTg") exitWith {
		_unit forceWalk false; // use ace thing
		[_handle] call CBA_fnc_removePerFrameHandler;
	};
	private _aPos = (_unit worldToModelVisual (getPos mjb_dragDummyTg));
    _aPos vectorDiff (_unit selectionPosition "pelvis");
	_aPos set [2,((_aPos # 2) + 0.3)]; // +?
	_target attachTo [_unit, _aPos,"Pelvis",false];
	if ((_unit distance _target) > ((ropeLength mjb_rope) - 1)) then {
		_unit forceWalk true;
		_target setDir ( (getDir _target + (_target getRelDir (getPos _unit) ) ) mod 360); // LA needs to run on dragged unit
	} else { _unit forceWalk false; };
	_segs = ropeSegments mjb_rope;
}, 0, [_unit,_target]] call CBA_fnc_addPerFrameHandler);