if (isNil 'mjb_reSpecPlayer') then {
	findDisplay 49 closeDisplay 2;
	findDisplay 312 closeDisplay 2;
	mjb_reSpecPlayer = player;
	mjb_reSpecEnabled = (missionNamespace getVariable ["BIS_fnc_feedback_allowDeathScreen",false]);
	missionNamespace setVariable ["BIS_fnc_feedback_allowDeathScreen",true];
	[player,player] call tmf_spectator_fnc_init;
	[mjb_reSpecPlayer, false] remoteExec ['enableSimulationGlobal',2];
	systemChat 'Spectating from TV, Esc > Configure > ACE Headbug Fix to exit.';
	if !(isNil 'mjb_reSpecExitEH') exitWith {};
    mjb_reSpecExitEH = ( ['ace_common_headbugFixUsed', {
		if (!isNil 'mjb_reSpecPlayer') then {
			0 spawn {
				findDisplay 49 closeDisplay 2;
				sleep 0.1;
				while {dialog} do {closeDialog 0;};
				private _spectator = player;
				selectPlayer mjb_reSpecPlayer;
				mjb_reSpecPlayer = nil;
				deleteVehicle _spectator;
				private _radioChannelIndexSpectator = missionNamespace getVariable ['tmf_spectator_radioChannel', -1];
				if (_radioChannelIndexSpectator != -1) then {
					_radioChannelIndexSpectator radioChannelRemove [player];
					{
						_x enableChannel true;
					} forEach [1,2,3,4,5];
				};
				missionNamespace setVariable ["BIS_fnc_feedback_allowDeathScreen",mjb_reSpecEnabled];
				[player, true] remoteExec ['enableSimulationGlobal',2];
				[false] call acre_api_fnc_setSpectator;
			};
		};
	}] call CBA_fnc_addEventHandler);
};