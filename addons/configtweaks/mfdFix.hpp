		class AirplaneHUD {
			class bones  {
				class ImpactPoint {
					pos0[] = {0.5,0.47};
					pos10[] = {0.94,0.92};
					source = "impactpointweaponRelative";
					type = "vector";
				};
				class Limit0109 {
					limits[] = {0.1,0.1,0.9,0.9};
					type = "limit";
				};
			};
			class draw {
				class BombCrosshairGroup {
					condition = "bomb";
					type = "group"
					class BombCrosshair {
						points[] = {{"ImpactPoint",{0,-0.102273},1},{"ImpactPoint",{0.01736,-0.100718},1},{"ImpactPoint",{0.0342,-0.0961057},1},{"ImpactPoint",{0.05,-0.0885682},1},{"ImpactPoint",{0.06428,-0.0783409},1},{"ImpactPoint",{0.0766,-0.0657409},1},{"ImpactPoint",{0.0866,-0.0511364},1},{"ImpactPoint",{0.09397,-0.0349773},1},{"ImpactPoint",{0.09848,-0.0177545},1},{"ImpactPoint",{0.1,0},1},{"ImpactPoint",{0.09848,0.0177545},1},{"ImpactPoint",{0.09397,0.0349773},1},{"ImpactPoint",{0.0866,0.0511364},1},{"ImpactPoint",{0.0766,0.0657409},1},{"ImpactPoint",{0.06428,0.0783409},1},{"ImpactPoint",{0.05,0.0885682},1},{"ImpactPoint",{0.0342,0.0961057},1},{"ImpactPoint",{0.01736,0.100718},1},{"ImpactPoint",{0,0.102273},1},{"ImpactPoint",{-0.01736,0.100718},1},{"ImpactPoint",{-0.0342,0.0961057},1},{"ImpactPoint",{-0.05,0.0885682},1},{"ImpactPoint",{-0.06428,0.0783409},1},{"ImpactPoint",{-0.0766,0.0657409},1},{"ImpactPoint",{-0.0866,0.0511364},1},{"ImpactPoint",{-0.09397,0.0349773},1},{"ImpactPoint",{-0.09848,0.0177545},1},{"ImpactPoint",{-0.1,0},1},{"ImpactPoint",{-0.09848,-0.0177545},1},{"ImpactPoint",{-0.09397,-0.0349773},1},{"ImpactPoint",{-0.0866,-0.0511364},1},{"ImpactPoint",{-0.0766,-0.0657409},1},{"ImpactPoint",{-0.06428,-0.0783409},1},{"ImpactPoint",{-0.05,-0.0885682},1},{"ImpactPoint",{-0.0342,-0.0961057},1},{"ImpactPoint",{-0.01736,-0.100718},1},{"ImpactPoint",{0,-0.102273},1},{},{"ImpactPoint",1,"Limit0109",1,{0,-0.0204545},1},{"ImpactPoint",1,"Limit0109",1,{0.014,-0.0143182},1},{"ImpactPoint",1,"Limit0109",1,{"+ 0.02",0},1},{"ImpactPoint",1,"Limit0109",1,{0.014,0.0143182},1},{"ImpactPoint",1,"Limit0109",1,{0,0.0204545},1},{"ImpactPoint",1,"Limit0109",1,{-0.014,0.0143182},1},{"ImpactPoint",1,"Limit0109",1,{"- 0.02",0},1},{"ImpactPoint",1,"Limit0109",1,{-0.014,-0.0143182},1},{"ImpactPoint",1,"Limit0109",1,{0,-0.0204545},1},{},{"Velocity",0.001,"ImpactPoint",1,"Limit0109",1,{0,0},1},{"Velocity",1,"Limit0109",1,{0,0},1}};
						type = "line";
						width = 4;
					};
					class Distance {
						align = "center";
						down[] = {"ImpactPoint",{-0.002,0.15},1};
						max = 15;
						pos[] = {"ImpactPoint",{-0.002,0.11},1};
						right[] = {"ImpactPoint",{0.045,0.11},1};
						scale = 1;
						source = "ImpactDistance";
						sourcePrecision = 1;
						sourceScale = 0.001;
						type = "text";
					};
				};
			};
		};