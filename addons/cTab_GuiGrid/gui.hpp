#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02

class RscActiveText;
class RscText;
class RscPicture;
class RscMapControl {
    class hospital;
    class church;
    class lighthouse;
    class power;
    class fuelstation;
    class transmitter;
};
class RscMapControlEmpty;
class RscControlsGroupNoScrollbars;
class RscEdit;
class RscButton;
class RscListBox;

/*/Redfine Scaling for the Dialog
#define X_PART(num) QUOTE((((60 - 25)/2) + (num)) * (safeZoneH / 64) + (safeZoneX + (safeZoneW - safeZoneH)/2))
#define Y_PART(num) QUOTE((0 + (num)) * (safeZoneH / 36) + (safeZoneY + (safeZoneH - (safeZoneH / 1.2))/2))
#define W_PART(num) QUOTE((num) * (safeZoneH / 64))
#define H_PART(num) QUOTE((num) * (safeZoneH / 36))

class cTab_microDAGR_dlg {
    #include "gui_controls.hpp"
};
*/


//Redfine Scaling for the RscTitle
#define PROFILE_X (profilenamespace getVariable ['IGUI_grid_cTab_microDagr_X', 0])
#define PROFILE_Y (profilenamespace getVariable ['IGUI_grid_cTab_microDagr_Y', 0])
#define PROFILE_W (profilenamespace getVariable ['IGUI_grid_cTab_microDagr_W', 1])
#define PROFILE_H ((16/9) * (profilenamespace getVariable ['IGUI_grid_cTab_microDagr_W', 1]))

#define PROFILE_Xtab (profilenamespace getVariable ['IGUI_grid_cTab_tab_X', 0])
#define PROFILE_Ytab (profilenamespace getVariable ['IGUI_grid_cTab_tab_Y', 0])
#define PROFILE_Wtab (profilenamespace getVariable ['IGUI_grid_cTab_tab_W', 1])
#define PROFILE_Htab ((16/9) * (profilenamespace getVariable ['IGUI_grid_cTab_tab_W', 1]))

#define PROFILE_Xs7 (profilenamespace getVariable ['IGUI_grid_cTab_s7_X', 0])
#define PROFILE_Ys7 (profilenamespace getVariable ['IGUI_grid_cTab_s7_Y', 0])
#define PROFILE_Ws7 (profilenamespace getVariable ['IGUI_grid_cTab_s7_W', 1])
#define PROFILE_Hs7 ((16/9) * (profilenamespace getVariable ['IGUI_grid_cTab_s7_W', 1]))

//Need undef's for pboProject
#undef X_PART
#undef Y_PART
#undef W_PART
#undef H_PART
#define X_PART(num) QUOTE((num) / 25 * PROFILE_W + PROFILE_X)
#define Y_PART(num) QUOTE((num) / 25 * PROFILE_H + PROFILE_Y)
#define W_PART(num) QUOTE((num) / 25 * PROFILE_W)
#define H_PART(num) QUOTE((num) / 25 * PROFILE_H)

class RscTitles {
    class cTab_microDAGR_dsp {
        #include "gui_controls_microDAGR.hpp"
    };
   /*class cTab_Android_dsp {
        #include "gui_controls_s7.hpp"
    };
    class cTab_TAD_dsp {
        #include "gui_controls_tab.hpp"
    };*/
};
