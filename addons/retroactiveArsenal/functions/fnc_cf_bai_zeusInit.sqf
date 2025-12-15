params ["_unit"];

if (!mjb_cfBaiFix) exitWith {};

if (isServer && {!(local _unit)}) exitWith {
	_unit addEventHandler ["Local", {
		params ["_unit", "_isLocal"];

		if (cf_bai_suppression_disableSuppression) exitWith {};

		if (isPlayer _unit || {!_isLocal}) exitWith { };

		[_unit] spawn cf_bai_suppression_fnc_updateSuppression;
	}];
};

if (!(local _unit) || {isPlayer _unit}) exitWith {};

//if (isNil 'platecall') then {platecall = true; [{platecall = nil;},nil,2] call CBA_fnc_waitAndExecute; private _unit = ((curatorSelected select 0) select 0); if (isNil '_unit' || {!(_unit isKindOf 'CAManBase')}) exitWith {}; private _caller = player; [[_unit,_caller],{ params ['_unit','_caller']; private _return = [notMe skill "aimingAccuracy" toFixed 2,notMe skill "aimingShake" toFixed 2,notMe skill "aimingSpeed" toFixed 2,notMe skill "endurance" toFixed 2,notMe skill "spotDistance" toFixed 2]; [[_return],{params ['_return']; platecall = _return;}] remoteExec ['call',_caller]; }] remoteExec ['call',_unit];}; platecall

if (isNil 'mjb_cfbaiCache') then {
	mjb_cfbaiCache = true;

	missionNamespace setVariable ['mjb_arsenal_zeusBai',(
		0 spawn {
			private _reducingTerrains = ["Tree","Bush","SMALL TREE"];

			sleep cf_bai_subskills_sleep;

			while {true} do {
				private _maxTerrainCount = [] call cf_bai_subskills_fnc_terrainCount;

				private _startTime = diag_tickTime;
				{
					private _terrainCount = count nearestTerrainObjects [_x, _reducingTerrains, cf_bai_subskills_terrain_range,false,true];
					private _terrainImpact = (_terrainCount min _maxTerrainCount)/_maxTerrainCount;

					if (!isPlayer _x) then {
						[_x,_terrainImpact] call cf_bai_subskills_fnc_updateUnitPipelineSkills;
					} else {
						[_x,_terrainImpact] call cf_bai_subskills_fnc_setGroupTerrainImpact;	
					};
					sleep 0.02;
				} forEach allUnits;
				
				private _endTime = diag_tickTime;
				
				private _sleepTime = 10 - (_endTime-_startTime);
				if (_sleepTime > 0) then {
					sleep _sleepTime;
				};
			};
		}
	)];
};

[_unit, [cf_bai_subskills_maximum_aimingAccuracy, cf_bai_subskills_maximum_aimingShake, cf_bai_subskills_maximum_aimingSpeed, cf_bai_subskills_maximum_spotDistance, cf_bai_subskills_maximum_spotTime, cf_bai_subskills_maximum_courage, cf_bai_subskills_maximum_reloadSpeed, cf_bai_subskills_maximum_commanding, cf_bai_subskills_maximum_general]] call CF_BAI_fnc_setBaseSkills;