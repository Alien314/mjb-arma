//#include "script_component.hpp"
/*
	Name: cTab_fnc_open
	
	Author(s):
		Gundy
	
	Description:
		Handles dialog / display startup and registering of event handlers
		
		This function will define cTabIfOpen, using the following format:
			Parameter 0: Interface type, 0 = Main, 1 = Secondary, 2 = Tertiary
			Parameter 1: Name of uiNameSpace variable for display / dialog (i.e. "cTab_Tablet_dlg")
			Parameter 2: Unit we registered the killed eventhandler for
			Parameter 3: ID of registered eventhandler for killed event
			Parameter 4: Vehicle we registered the GetOut eventhandler for (even if no EH is registered)
			Parameter 5: ID of registered eventhandler for GetOut event (nil if no EH is registered)
			Parameter 6: ID of registered eventhandler for Draw3D event (nil if no EH is registered)
			Parameter 7: ID of registered eventhandler A.C.E medical_onUnconscious event (nil if no EH is registered)
			Parameter 8: ID of registered eventhandler A.C.E playerInventoryChanged event (nil if no EH is registered)
	
	Parameters:
		0: INTEGER - Interface type, 0 = Main, 1 = Secondary
		1: STRING  - Name of uiNameSpace variable for display / dialog (i.e. "cTab_Tablet_dlg")
		2: OBJECT  - Unit to register killed eventhandler for
		3: OBJECT  - Vehicle to register GetOut eventhandler for
	
	Returns:
		BOOLEAN - TRUE
	
	Example:
		// open TAD display as main interface type
		[0,"cTab_TAD_dsp",player,vehicle player] call cTab_fnc_open;
*/

//#include "\cTab\shared\cTab_gui_macros.hpp"
#define IDC_CTAB_OSD_TIME		2613
#define IDC_CTAB_OSD_GRID		2612
#define IDC_CTAB_OSD_DIR_DEGREE		2615
#define IDC_CTAB_OSD_DIR_OCTANT		2616
#define IDC_CTAB_OSD_ELEVATION		2623

if (cTabIfOpenStart || (!isNil "cTabIfOpen")) exitWith {false};
cTabIfOpenStart = true;

params ["_interfaceType","_displayName", "_player", "_vehicle"];

private _isDialog = [_displayName] call cTab_fnc_isDialog;

private _textures = call {
		if (!_isDialog && {mjb_ctab_noBorderDef}) exitWith {["",""]};
		if (_displayName in ["cTab_TAD_dsp","cTab_TAD_dlg"]) exitWith {
			["\cTab\img\TAD_background_ca.paa","\cTab\img\TAD_background_night_ca.paa"]
		};
		if (_displayName in ["cTab_Android_dsp","cTab_Android_dlg"]) exitWith {
			["\cTab\img\android_s7_ca.paa","\cTab\img\android_s7_night_ca.paa"]
		};
		if (_displayName in ["cTab_microDAGR_dsp","cTab_microDAGR_dlg"]) exitWith {
			["\cTab\img\microDAGR_background_ca.paa","\cTab\img\microDAGR_background_night_ca.paa"]
		};
		if (_displayName in ["cTab_Tablet_dlg"]) exitWith {
			["\cTab\img\tablet_background_ca.paa","\cTab\img\tablet_background_night_ca.paa"]
		};
		if (_displayName in ["cTab_FBCB2_dlg"]) exitWith {
			["\cTab\img\FBCB2.paa","\cTab\img\FBCB2.paa"]
		};
		["",""]
	};

cTabIfOpen = [_interfaceType,_displayName,_player,
	_player addEventHandler ["killed",{[] call cTab_fnc_close}],
	_vehicle,nil,nil,nil,nil,_textures];

if (_vehicle != _player && (_isDialog || _displayName in ["cTab_TAD_dsp"])) then {
	cTabIfOpen set [5,
		_vehicle addEventHandler ["GetOut",{if (_this select 2 == cTab_player) then {[] call cTab_fnc_close}}]
	];
};

// Set up event handler to update display header / footer
if (_displayName in ["cTab_TAD_dsp","cTab_TAD_dlg"]) then {
	cTabIfOpen set [6,
		addMissionEventHandler ["Draw3D",{
			_display = uiNamespace getVariable (cTabIfOpen select 1);
			_veh = vehicle cTab_player;
			_playerPos = getPosASL _veh;
		
			// update time
			(_display displayCtrl IDC_CTAB_OSD_TIME) ctrlSetText call cTab_fnc_currentTime;
			
			// update grid position
			(_display displayCtrl IDC_CTAB_OSD_GRID) ctrlSetText format ["%1", mapGridPosition _playerPos];
			
			// update current heading
			(_display displayCtrl IDC_CTAB_OSD_DIR_DEGREE) ctrlSetText ([direction _veh] call ctab_core_fnc_formatHeading);
			
			// update current elevation (ASL) on TAD
			(_display displayCtrl IDC_CTAB_OSD_ELEVATION) ctrlSetText format ["%1m",[round (_playerPos select 2),4] call CBA_fnc_formatNumber];
		}]
	];
} else {
	cTabIfOpen set [6,
		addMissionEventHandler ["Draw3D",{
			_display = uiNamespace getVariable (cTabIfOpen select 1);
			_veh = vehicle cTab_player;
			_heading = direction _veh;
			// update time
			(_display displayCtrl IDC_CTAB_OSD_TIME) ctrlSetText call cTab_fnc_currentTime;
			
			// update grid position
			(_display displayCtrl IDC_CTAB_OSD_GRID) ctrlSetText ([getPosASL _veh] call ctab_core_fnc_gridPosition);
			
			// update current heading
			(_display displayCtrl IDC_CTAB_OSD_DIR_DEGREE) ctrlSetText ([_heading] call ctab_core_fnc_formatHeading);
			(_display displayCtrl IDC_CTAB_OSD_DIR_OCTANT) ctrlSetText format ["%1",[_heading] call cTab_fnc_degreeToOctant];
		}]
	];
};


// If ace_medical is used, register with medical_onUnconscious event
if (isClass (configfile >> "CfgPatches" >> "ace_medical")) then {
	cTabIfOpen set [7,
		["medical_onUnconscious",{
			if (_this select 0 == cTab_player && _this select 1) then {
				[] call cTab_fnc_close;
			};
		}] call ace_common_fnc_addEventHandler
	];
};

// If ace_common is used, register with playerInventoryChanged event
if (isClass (configfile >> "CfgPatches" >> "ace_common")) then {
	cTabIfOpen set [8,
		["playerInventoryChanged",{
			_this call cTab_fnc_onPlayerInventoryChanged;
		}] call ace_common_fnc_addEventHandler
	];
};

/*/ pos adjustment
if (!_isDialog && {!isNil 'mjb_animate_ctab' && {mjb_animate_ctab && {!isMultiplayer}}}) then {
	private _index = switch (_displayName) do {case 'cTab_Android_dsp': {0}; case 'cTab_microDAGR_dsp': {1}; default {2}; };
	private _model = (['cTab\data\itemAndroid.p3d','cTab\data\itemMicroDAGR.p3d','\A3\Props_F_Exp_A\Military\Equipment\Tablet_02_F.p3d'] select _index);
	//[+toward/-away,+left/-right,+up/-down]
	private _pos = ([[0.015,0.03,-0.04],[-0.00,0.02,-0.03],[-0.04,0.02,-0.07]] select _index);
	private _rot = ([[200,-50,-60],[200,-50,-70],[200,-50,10]] select _index);
	[playa, 'tsp_animate_map_in', 'tsp_animate_map_loop', _model, 'leftHand', _pos, _rot, {isNil "cTabIfOpen" || {'dlg' in (cTabIfOpen # 1)}}] spawn tsp_fnc_gesture_item;
};//*/

if (_isDialog) then {
	// Check if map and / or a dialog is open and close them
	if (visibleMap) then {openMap false};
	while {dialog} do {
 		closeDialog 0;
	};

	if (!isNil 'mjb_animate_ctab' && {mjb_animate_ctab}) then {
		private _index = switch (_displayName) do {case 'cTab_Android_dlg': {0}; case 'cTab_microDAGR_dlg': {1}; default {2}; };

		private _model = (['cTab\data\itemAndroid.p3d','cTab\data\itemMicroDAGR.p3d','\A3\Props_F_Exp_A\Military\Equipment\Tablet_02_F.p3d'] select _index);
		private _pos = ([[0.015,0.03,-0.04],[-0.00,0.02,-0.03],[-0.04,0.02,-0.07]] select _index);
		private _rot = ([[200,-50,-60],[200,-50,-70],[200,-50,10]] select _index);
		[playa, 'tsp_animate_map_in', 'tsp_animate_map_loop', _model, 'leftHand', _pos, _rot, {isNil "cTabIfOpen" || {'dsp' in (cTabIfOpen # 1)}}] spawn tsp_fnc_gesture_item;
	};
	
	// XXX: Switching to display would allow to walk even when device is open
	// (findDisplay 46) createDisplay _displayName;

	createDialog _displayName;
} else {
	cTabRscLayer cutRsc [_displayName,"PLAIN",0, false];
};

true