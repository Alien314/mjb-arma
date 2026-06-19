
// Vanilla
//class AllVehicles;

//class Air : AllVehicles {
//	class EventHandlers {
//		class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_Base {};
//	};
//};

// Above is available from Planes

class VTOL_Base_F : Plane_Base_F {
	maxFordingDepth = 1;
};


class Helicopter : Air {
	maxFordingDepth = 1;
};
class Helicopter_Base_F : Helicopter {
	class UserActions {
		class stab_disable {
			condition = "private _lock = this lockedCameraTo [0]; mjb_enableStabToggle && { (getNumber (([this, (this unitTurret player)] call BIS_fnc_turretConfig) >> 'isCopilot') isEqualTo 1)  && {!isNil '_lock' || { this directionStabilizationEnabled [0] }}}";
			displayName = "Disable Camera Stabilization";
			displayNameDefault = "";
			hideOnUse = 1;
			onlyforplayer = 1;
			position = "";
			priority = 1;
			radius = 15;
			shortcut = "vehLockTurretView";
			showWindow = 0;
			statement = "this lockCameraTo [objNull,[0]]; this enableDirectionStabilization [false, [0]];";
		};
		class stab_enable {
			condition = "private _lock = this lockedCameraTo [0]; mjb_enableStabToggle && { (getNumber (([this, (this unitTurret player)] call BIS_fnc_turretConfig) >> 'isCopilot') isEqualTo 1) && {isNil '_lock' && { !(this directionStabilizationEnabled [0]) }}}";
			displayName = "Enable Camera Stabilization";
			displayNameDefault = "";
			hideOnUse = 1;
			onlyforplayer = 1;
			position = "";
			priority = 1;
			radius = 15;
			shortcut = "vehLockTurretView";
			showWindow = 0;
			statement = "[this] call mjb_arsenal_fnc_copilotStabilizeToggle";
		};
	};
};
class Helicopter_Base_H : Helicopter_Base_F {
	class UserActions {
		class stab_disable {
			condition = "private _lock = this lockedCameraTo [0]; mjb_enableStabToggle && { (getNumber (([this, (this unitTurret player)] call BIS_fnc_turretConfig) >> 'isCopilot') isEqualTo 1)  && {!isNil '_lock' || { this directionStabilizationEnabled [0] }}}";
			displayName = "Disable Camera Stabilization";
			displayNameDefault = "";
			hideOnUse = 1;
			onlyforplayer = 1;
			position = "";
			priority = 1;
			radius = 15;
			shortcut = "vehLockTurretView";
			showWindow = 0;
			statement = "this lockCameraTo [objNull,[0]]; this enableDirectionStabilization [false, [0]];";
		};
		class stab_enable {
			condition = "private _lock = this lockedCameraTo [0]; mjb_enableStabToggle && { (getNumber (([this, (this unitTurret player)] call BIS_fnc_turretConfig) >> 'isCopilot') isEqualTo 1) && {isNil '_lock' && { !(this directionStabilizationEnabled [0]) }}}";
			displayName = "Enable Camera Stabilization";
			displayNameDefault = "";
			hideOnUse = 1;
			onlyforplayer = 1;
			position = "";
			priority = 1;
			radius = 15;
			shortcut = "vehLockTurretView";
			showWindow = 0;
			statement = "[this] call mjb_arsenal_fnc_copilotStabilizeToggle";
		};
	};
};