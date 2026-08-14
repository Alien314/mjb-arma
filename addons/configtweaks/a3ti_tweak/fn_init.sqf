#include "\A3TI\constants.h"
/*A3TI_VisionChangedEH = 	["visionMode",	{"vision_changed"	call FLIR_Keypress_fnc; hintsilent str _this;}] call CBA_fnc_addPlayerEventHandler;
A3TI_ViewChangedEH = 		["cameraView",	{"view_changed" 	call FLIR_Keypress_fnc; hintsilent str _this;}] call CBA_fnc_addPlayerEventHandler;
A3TI_SeatChangedEH = 		["turret",		{"seat_changed"		call FLIR_Keypress_fnc; hintsilent str _this;}] call CBA_fnc_addPlayerEventHandler;*/
private _zeusIDD = (configfile >> "RscDisplayCurator" >> "idd") call BIS_fnc_getCfgData;

_id = 						["unit", 		{"unit_switched" spawn FNC(cameraViewEH);}] call CBA_fnc_addPlayerEventHandler;
_id2 = 						["cameraView", 	{params ["_unit","_currentView","_prevView"]; 	null = _this spawn FNC(cameraViewEH);}] call CBA_fnc_addPlayerEventHandler;
//_id3 = 						["turret", 		{params ["_unit","_currentView","_prevView"]; 	null = _this spawn FNC(cameraViewEH);}] call CBA_fnc_addPlayerEventHandler;
_id4 =						["KeyDown", { params ['','_keyCode']; if !(_keyCode in (actionKeys "nightVision" + actionKeys "TransportNightVision")) exitWith {}; _this spawn FNC(vanillaCycleVisionEH); }] call CBA_fnc_addDisplayHandler;
//_id5 =						["loadout", {systemChat str _this}] call CBA_fnc_addPlayerEventHandler; //to be used for when unit changes uniform using subscriber pattern
_id6 =						["turret", { [] spawn FNC(cycleVision); }] call CBA_fnc_addPlayerEventHandler;

//add key press EH to zeus
if !(isNil {_zeusIDD}) then {
	null = [_zeusIDD] spawn {
		params ["_zeusIDD"];
		while {true} do {
			waitUntil{sleep 0.1; !isNull(findDisplay _zeusIDD)};
			[] spawn FNC(cameraViewEH);
			//for when they change from vanilla DTV TO vanilla NV
			(findDisplay (_zeusIDD)) displayAddEventHandler ["KeyDown", { if !(_keyCode in (actionKeys "curatorNightvision")) exitWith {}; _this spawn FNC(vanillaCycleVisionEH); }];
			waitUntil{sleep 0.1; isNull(findDisplay _zeusIDD)};
			//exit view, reset vision
			[] spawn FNC(cameraViewEH);
		};
	};
};

//raven is loaded
if (isClass (configfile >> "CfgPatches" >> "rhsusf_c_uav")) then {
	//while loop for checking if in Raven
	//uiNamespace getVariable "d_rhsusf_RQ11_display";
	null = [] spawn {
		while {true} do {
			waitUntil{sleep 0.1; !isNull(uiNamespace getVariable ["d_rhsusf_RQ11_display",displayNull])};
			[] spawn FNC(cameraViewEH);
			//for when they change from vanilla DTV TO vanilla NV
			(uiNamespace getVariable ["d_rhsusf_RQ11_display",displayNull]) displayAddEventHandler ["KeyDown", { _this spawn FNC(vanillaCycleVisionEH); }];
			waitUntil{sleep 0.1; isNull(uiNamespace getVariable ["d_rhsusf_RQ11_display",displayNull])};
			//exit view, reset vision
			[] spawn FNC(cameraViewEH);
		};
	};
};

//this is for when people are switching in and out of UAV,
//had to be a loop as I couldn't find an EH what would work
[] spawn {
	_prevCameraOn = cameraOn;
	while {true} do {
		if !(_prevCameraOn isEqualTo cameraOn) then {
			null = [] spawn FNC(cycleVision);
			//LTM module
			null = [] spawn FNC(pfhLTM);
			_prevCameraOn = cameraOn;
			//loop to update textures every 10 seconds
		};
		if !(isNil {(UNAMESPACE getVariable ["A3TI_obj_params",nil])}) then {
			if (time > (UNAMESPACE getVariable ["A3TI_obj_nextTime",0])) then {
				(UNAMESPACE getVariable "A3TI_obj_params") spawn FNC(setObjects);
				UNAMESPACE setVariable ["A3TI_obj_nextTime",time+10];
			};
		};
		sleep 5e-2;
	};
};
