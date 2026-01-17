class ctrlMenuStrip;
class Display3DEN {
	class Controls {
		class MenuStrip: ctrlMenuStrip {
			class Items {
				items[] += {"MJB_Array"};

				class MJB_Array {
					text = "MJB Array/Grid Place";
					items[] += {"MJB_Array_Object"};
				};
				class MJB_Array_Object {
					text = "Array Selected Object...";
					action = "call mjb_arsenal_fnc_3denArrayUI";
				};
			};
		};
	};
};