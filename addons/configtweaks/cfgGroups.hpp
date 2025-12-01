
class CfgFactionClasses {
    class mjb_customFaction {
        displayName = "MJB Factions";
        priority = 2;
        side = 0;
    };
};

class CfgGroups {
	class East { // East - Opfor, Empty - Civ, Independent, West - Blufor
		/*/
		Submit a config like the below 'mjb_customFaction' example, renaming any customX entries,
		and a tmf loadout named similarly to the faction or group.
		Using these I should be able to add custom groups for zeus use.
		Tools > Config Viewer, then CfgGroups for more examples.
		//*/
		class mjb_customFaction {
			name = "Custom Faction"; // maybe include your handle
			class Infantry {
				name = "Infantry";
				class mjb_O_customGroup {
					faction = "mjb_customFaction";
					icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
					name = "CustomGroup";
					rarityGroup = 0.1; // ???
					side = 0; // 0 - Opfor, 1 - Blufor, 2 - Independent, 3 - civilian
					class Unit0 {
						position[] = {0,0,0}; // x,y,z relative to placement location
						rank = "CORPORAL";
						side = 0;
						vehicle = "mjb_O_customSoldier"; // O - Opfor, B - Blufor, I - Independent
						tmfRole = "r";
					};
					class Unit1 : Unit0 {
						position[] = {5,-5,0}; // ~5m east, 5m south of leader
						rank = "PRIVATE";
						vehicle = "mjb_O_customSoldier_mg";
						tmfRole = "mg";
					};
				};
			};
		};
	};

	class Empty { // civ

	};

	class Indep {

	};

	class West {

	};
};