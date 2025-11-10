
private _curator = (getAssignedCuratorLogic player);

private _wargamer = _curator getVariable ['jac_canEditUnitsZeus',nil];
if (isNil '_wargamer') exitWith {};

_curator remoteExec ['mjb_arsenal_fnc_openedZeusServer',2];