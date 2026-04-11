class CfgPatches {
  class mjb_zeusTweak {
		ammo[] = {};
		magazines[] = {};
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		author = "Alien314";
		name = "TMF zeus tweak";
		requiredAddons[]=
		{
			"TMF_zeus"
		};
	};
};

class RscControlsGroupNoScrollbars;
class RscDisplayCurator {
	class Controls {
		class TMF_zeus_zeusControls : RscControlsGroupNoScrollbars {
			class Controls {//3DEN_notificationWarning,defaultNotificationClose,hintCollapse,OMPhoneSMSsend,readoutClick,TacticalPing2,TacticalPing3,thunder_1,thunder_2
				class TMF_zeus_toggleStaticsZeus;
				class TMF_zeus_toggleACRESpectator : TMF_zeus_toggleStaticsZeus {
					onLoad = "params ['_control']; missionNamespace setVariable [('mjb_specCount' + str _control), _control spawn { sleep 1; if (isNil 'mjb_acreSpecCount') then { mjb_acreSpecCount = count (entities [['TMF_spectator_unit','ace_spectator_virtual','VirtualSpectator_F'],[]] select {isPlayer _x}); }; _this ctrlSetText ('ACRE Spectator: ' + (str mjb_acreSpecCount)); while {true} do { sleep 5; private _spectators = (entities [['TMF_spectator_unit','ace_spectator_virtual','VirtualSpectator_F'],[]] select {isPlayer _x}); private _specCount = count _spectators; if (_specCount > mjb_acreSpecCount) then {_this ctrlSetText ('ACRE Spectator: ' + (str _specCount)); systemChat ('Intermittent report: Identified Casualties: '); systemChat ( str (_spectators apply {name _x})); systemChat ('Remaining Operators: ' + str (count (allPlayers - _spectators - [player]))); playSoundUI ['TacticalPing3']; mjb_acreSpecCount = _specCount; }; }; }]";
					onDestroy = "params ['_control']; terminate (missionNamespace getVariable [('mjb_specCount' + str _control), scriptNull]); missionNamespace setVariable [('mjb_specCount' + str _control), nil];";
					onButtonClick = " [!(missionNamespace getVariable ['ACRE_IS_SPECTATOR', false])] call acre_api_fnc_setSpectator; true"
				};
			};
		};
	};
};