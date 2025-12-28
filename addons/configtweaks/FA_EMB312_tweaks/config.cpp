class CfgPatches {
  class mjb_fa_emb312Tweak {
    ammo[] = {};
    magazines[] = {};
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.1;
    author = "Alien314";
    name = "FA EMB312 Tucano Tweaks";
	requiredAddons[]=
        {
            "FA_EMB312"
        };
    skipWhenMissingDependencies = 1;
  };
};

class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;

class CfgVehicles {
	class Plane_Base_F;
	class FA_EMB312_BASE : Plane_Base_F {
		class Components;
		class NewTurret;

		class pilotCamera {
			class OpticsIn {
				showMiniMapInOptics = 1;
				showSlingLoadManagerInOptics = 0;
				showUAVViewInOptics = 0;
			};
		};

		class Turrets {
			class MainTurret : NewTurret {
				class OpticsIn { // error
					delete showMiniMapInOptics;
					delete showSlingLoadManagerInOptics;
					delete showUAVViewInOptics;
				};
				class Components : Components {
					class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft {
						class Components {
							class MinimapDisplay {componentType = "MinimapDisplayComponent"; resource = "RscCustomInfoMiniMap";};
							class SensorDisplay {componentType = "SensorsDisplayComponent"; range[] = {4000,3000,2000,1000}; resource = "RscCustomInfoSensors";};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight {
						class Components {
							class MinimapDisplay {componentType = "MinimapDisplayComponent"; resource = "RscCustomInfoMiniMap";};
							class SensorDisplay {componentType = "SensorsDisplayComponent"; range[] = {4000,3000,2000,1000}; resource = "RscCustomInfoSensors";};
						};
					};
				};
			};
		};
		class UserActions;
	};
	class FA_EMB312_AT27M35_AAF : FA_EMB312_BASE {
		//
		class NewTurret;
		class Turrets : Turrets {
			class MainTurret : MainTurret {
				primaryGunner = 1;
			};
		};//*/

		/*/ fix weird permanent stabilization
		class EventHandlers {
			class mjb_configTweaks {
				init="params ['_this']; _this spawn {sleep 1; _this enableDirectionStabilization [false, [0]]; };";
			};
		};*/
		class UserActions : UserActions {
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
				statement = "if (!isNull cursorObject && {cursorObject isKindOf 'AllVehicles'}) exitWith { systemChat ('Stabilzed on Vehicle at ' + (mapGridPosition cursorObject)); this lockCameraTo [AGLToASL (unitAimPositionVisual cursorObject),[0]] }; if (!isNull cursorObject) exitWith { systemChat ('Stabilzed on Object at ' + (mapGridPosition cursorObject)); this lockCameraTo [AGLToASL (unitAimPositionVisual cursorObject),[0]] }; private _loc = terrainIntersectAtASL [(AGLToASL positionCameraToWorld [0,0,0]), (AGLToASL positionCameraToWorld [0,0,10000])]; if (_loc isEqualTo [0,0,0]) exitWith { systemChat 'No target in range'; this enableDirectionStabilization [true, [0]]; }; systemChat ('Stabilzed on Position: ' + mapGridPosition _loc); this lockCameraTo [_loc,[0],true]; this spawn {sleep 0.1; _this enableDirectionStabilization [true, [0]];};";
			};
		};//*/
	};//*/
};