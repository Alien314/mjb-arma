#define GUI_MARGIN_X	(-0.05)
#define GUI_MARGIN_Y	(0.2)
#define GUI_microDAGR_W	(0.86)
#define GUI_microDAGR_H	(0.86)

#define cTab_microDAGR_DLGtoDSP_fctr (1)

#define GUI_GRID_X	(safeZoneX + GUI_MARGIN_X * 3/4)
#define GUI_GRID_Y	(safeZoneY + safeZoneH - GUI_microDAGR_H - GUI_MARGIN_Y)
#define GUI_GRID_W	(GUI_microDAGR_W * 3/4)
#define GUI_GRID_H	(GUI_microDAGR_H)

class CfgUIGrids {
    class IGUI {
        class Presets {
            class Arma3 {
                class Variables {
                    grid_cTab_microDagr[] = {{"(safeZoneX + safeZoneW - 11 * (((safeZoneW / safeZoneH) min 1.2) / 40))","(safeZoneY + safeZoneH - 15 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25))","(10 * (((safeZoneW / safeZoneH) min 1.2) / 40))","(10 * ((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25))"},"(((safeZoneW / safeZoneH) min 1.2) / 40)","((((safeZoneW / safeZoneH) min 1.2) / 1.2) / 25)"};
                };
            };
        };

        class Variables {
            class grid_cTab_microDagr {
                displayName = "cTab MicroDagr";
                description = "cTab MicroDagr";
                //preview = QPATHTOF(ui\IGUI_preview_ca.paa);
                saveToProfile[] = {0,1,2,3};
                canResize = 1;
            };
            /*class grid_cTab_s7 {
                displayName = "cTab Android S7";
                description = "cTab Android";
                //preview = QPATHTOF(ui\IGUI_preview_ca.paa);
                saveToProfile[] = {0,1,2,3};
                canResize = 1;
            };
            class grid_cTab_tab {
                displayName = "cTab Tablet";
                description = "cTab Tablet";
                //preview = QPATHTOF(ui\IGUI_preview_ca.paa);
                saveToProfile[] = {0,1,2,3};
                canResize = 1;
            };*/
        };
    };
};
