
if ((isNull (_this # 0)) || ((_this # 1) == "")) exitWith {};
[_this,{
	if (isDedicated) exitWith {};
	params [
		["_source", objNull],
		["_sound", ""],
		["_distance",100],
		["_volume", 2]
	];
	private _screm = _source isKindOf 'CAManBase';
	if ( _screm && { sfx_r_scremDisable } ) exitWith {};
	if ( _screm ) then {_volume = _volume * (missionNamespace getVariable ['sfx_r_scremVolume',1]);};
	playSound3D [_sound, _source,if (insideBuilding _source == 1) then{true}else{false}, aimPos _source, _volume, 1,if (insideBuilding _source == 1) then{_distance / 2}else{_distance}, 0, true];
}] remoteExec ["call",0];