params [['_curator',objNull]];

if (isNull _curator) exitWith {};

waitUntil {!isNil 'tmf_zeus_curatorsToGivePlayersTo'};

private _index = -1;
waitUntil {sleep 0.05; _index = tmf_zeus_curatorsToGivePlayersTo find _curator; _index > -1};

_curator removeCuratorEditableObjects [(playableUnits - [(getAssignedCuratorUnit _curator)])];

tmf_zeus_curatorsToGivePlayersTo deleteAt _index;