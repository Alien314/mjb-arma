class CfgPatches {
  class mjb_js_jc_FA18FTweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "FA18F Tweaks";
	requiredAddons[]=
        {
            "js_jc_fa18_core"
        };
    skipWhenMissingDependencies = 1;
  };
};

class CfgVehicles {
	class Plane_Base_F;
	class JS_JC_FA18F : Plane_Base_F {
		class UserActions {
			class stab_disable {
				condition = "private _lock = this lockedCameraTo [0]; player isEqualTo (gunner this) && {!isNil '_lock' || { this directionStabilizationEnabled [0] }}";
				displayName = "Disable Camera Stabilization";
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
				condition = "private _lock = this lockedCameraTo [0]; player isEqualTo (gunner this) && {isNil '_lock' && { !(this directionStabilizationEnabled [0]) }}";
				displayName = "Enable Camera Stabilization";
				displayNameDefault = "";
				hideOnUse = 1;
				onlyforplayer = 1;
				position = "";
				priority = 1;
				radius = 15;
				shortcut = "vehLockTurretView";
				showWindow = 0;
				statement = "this enableDirectionStabilization [true, [0]]; this spawn { while { _this directionStabilizationEnabled [0] } do { if (cursorObject isKindOf 'AllVehicles') then { _this lockCameraTo [AGLToASL (unitAimPositionVisual cursorObject),[0],true]; }; sleep 0.2; }; };";
			};
		};//*/
	};//*/
};