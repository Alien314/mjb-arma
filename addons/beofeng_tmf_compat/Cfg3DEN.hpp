#include "\a3\3DEN\UI\macros.inc"
#include "\a3\3DEN\UI\resincl.inc"

class ctrlToolbox;

class cfgScriptPaths 
{
    TMF_acre2 = "z\bfn\addons\tmf_compat\ui_scripts\"; //"
};

class Cfg3DEN {
	class Attributes {
		class Toolbox;
		class RadioChannels : Toolbox {
			class Controls {
				class EditChannelRadioChooser: ctrlToolbox {
                    columns = 8;
                    strings[] += {
						"\idi\acre\addons\sys_bf888s\Data\static\bf888s_icon.paa"
                    };
                    tooltips[] += {
                        "Beofeng 888S"
                    };
				};
			};
		};
    };
};