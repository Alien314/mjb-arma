params ["_logic"];

if (isServer) then {
	if !(isNil 'mjb_noMagnifiedJIP') then { remoteExec ['','mjb_noMagnifiedJIP']; mjb_noMagnifiedJIP = nil;};
	mjb_noMagnifiedJIP = true;
	[[], {
		if !(hasInterface) exitWith {};
		["unit", {
			if !(player isKindOf "CAManBase") exitWith {};
			0 spawn {
				waitUntil {!isNull player};

				private _magnified = [
					//============================================================
					// Magnified Optics (2-3x)
					//============================================================
					//Vanilla
					"optic_arco_blk_F",
					"optic_hamr",
					"optic_Hamr_khk_F",
					"optic_Arco",
					"optic_Arco_ghex_F",
					"optic_Arco_arid_F",
					"optic_Arco_lush_F",
					"optic_mrco",
					"optic_ERCO_blk_F",
					"optic_ERCO_khk_F",
					"optic_ERCO_snd_F",

					//CUP Magnified Sights
					"cup_optic_aimm_microt1_blk",
					"cup_optic_aimm_compm2_blk",
					"cup_optic_aimm_compm4_blk",
					"cup_optic_aimm_zddot_blk",
					"CUP_optic_G33_HWS_BLK",

					"CUP_optic_AIMM_COMPM4_BLK_DWN",
					"CUP_optic_AIMM_MICROT1_BLK_DWN",
					"CUP_optic_G33_HWS_BLK_DWN",
					"CUP_optic_AIMM_COMPM2_BLK_DWN",
					"CUP_optic_AIMM_ZDDOT_BLK_DWN",

					"tier1_exps3_0_g33_black_up",
					"tier1_exps3_0_g33_riser_black_up",
					"tier1_exps3_0_g33_tano_up",
					"Tier1_EXPS3_0_G33_Riser_Tano_Up",
					"Tier1_Romeo4T_BCD_G33_Black_Up",
					"Tier1_Romeo4T_BCD_G33_Riser_Black_Up",
					"Tier1_Romeo4T_BCQ_G33_Black_Up",
					"Tier1_Romeo4T_BCQ_G33_Riser_Black_Up",
					"Tier1_Microt2_G33_Black_Up",
					"Tier1_Microt2_G33_Riser_Black_Up",

					//JCA Optics
					"JCA_optic_MROS_black_magnifier",
					"JCA_optic_MROS_olive_magnifier",
					"JCA_optic_MROS_sand_magnifier",
					"JCA_optic_MROS_black_magnifier_UP",
					"JCA_optic_MROS_olive_magnifier_UP",
					"JCA_optic_MROS_sand_magnifier_UP",

					//MCC 3x
					"MCC_EXPS3_BLK_Down",
					"MCC_EXPS3_BLK_Up",
					"MCC_EXPS3_FDE_Down",
					"MCC_EXPS3_FDE_Up",
					"MCC_EXPS3_UnityX_BLK_Up",
					"MCC_EXPS3_UnityX_FDE_Up",
					"MCC_EXPS3_UnityX_BLK_Down",
					"MCC_EXPS3_UnityX_FDE_Down",
					"MCC_GBRS_EXPS3_Mag_Up_BLK",
					"MCC_GBRS_EXPS3_Mag_Up_FDE",
					"MCC_GBRS_EXPS3_Mag_Down_BLK",
					"MCC_GBRS_EXPS3_Mag_Down_FDE",
					"MCC_MicroT2_UnityX_BLK_Up",
					"MCC_MicroT2_UnityX_FDE_Up",
					"MCC_MicroT2_UnityX_BLK_Down",
					"MCC_MicroT2_UnityX_FDE_Down",
					"MCC_GBRS_T2_Mag_Up_BLK",
					"MCC_GBRS_T2_Mag_Up_FDE",
					"MCC_Romeo9T_BLK_Up",
					"MCC_Romeo9T_FDE_Up",
					"MCC_GBRS_T2_Mag_Down_BLK",
					"MCC_GBRS_T2_Mag_Down_FDE",
					"MCC_Romeo9T_BLK_Down",
					"MCC_Romeo9T_FDE_Down",

					"MCC_LCO_PRO_F2_UnityX_blk_Up",
					"MCC_LCO_PRO_F2_UnityX_FDE_Up",
					"MCC_AMG_UH1_BLK_Up",
					"MCC_AMG_UH1_FDE_Up",
					"MCC_EXPS3HD_BLK_Up",
					"MCC_EXPS3HD_UnityX_BLK_Up",
					"MCC_EXPS3HD_UnityX_FDE_Up",
					"MCC_CompM5_Up",
					"MCC_CompM5_UnityX_BLK_Up",
					"MCC_CompM5_UnityX_FDE_Up",
					"MCC_CompM5B_BLK_Up",
					"MCC_CompM5B_FDE_Up",
					"MCC_MicroT2_Up",
					"MCC_MicroT2_Spuhr_BLK_Up",
					"MCC_MicroT2_Spuhr_FDE_Up",
					"MCC_MicroT2_UnityX_BLK_Up",
					"MCC_MicroT2_UnityX_DFDE_Up",
					"MCC_MicroT2_UnityX_FDE_Up",
					"MCC_GBRS_T2_Mag_Up_BLK",
					"MCC_GBRS_T2_Mag_Up_FDE",

					"MCC_LCO_PRO_F2_UnityX_blk_Down",
					"MCC_LCO_PRO_F2_UnityX_FDE_Down",
					"MCC_AMG_UH1_BLK_Down",
					"MCC_AMG_UH1_FDE_Down",
					"MCC_EXPS3HD_BLK_Down",
					"MCC_EXPS3HD_UnityX_BLK_Down",
					"MCC_EXPS3HD_UnityX_FDE_Down",
					"MCC_CompM5_Down",
					"MCC_CompM5_UnityX_BLK_Down",
					"MCC_CompM5_UnityX_FDE_Down",
					"MCC_CompM5B_BLK_Down",
					"MCC_CompM5B_FDE_Down",
					"MCC_MicroT2_Down",
					"MCC_MicroT2_Spuhr_BLK_Down",
					"MCC_MicroT2_Spuhr_FDE_Down",
					"MCC_MicroT2_UnityX_BLK_Down",
					"MCC_MicroT2_UnityX_DFDE_Down",
					"MCC_MicroT2_UnityX_FDE_Down",
					"MCC_GBRS_T2_Mag_Down_BLK",
					"MCC_GBRS_T2_Mag_Down_FDE",

					//Dovetail (Ak Sights)
					"CUP_optic_pechenegscope", // 2.8x
					"CUP_optic_PGO7V3",

					"optic_DMS",
					"optic_LRPS",
					"CUP_optic_LeupoldMk4_25x50_LRT",
					"CUP_optic_SB_3_12x50_PMII",
					"MCC_ZCO_10_BLK_DMR",
					"MCC_Vortex_Elanor_Acro_BLK",
					"MCC_Mark5_10_BLK",
					"CUP_optic_ACOG",
					"CUP_optic_ACOG_TA01NSN_RMR_Black",
					"CUP_optic_SB_11_4x20_PM",
					"CUP_optic_Elcan_SpecterDR_RMR_black",
					"CUP_optic_Elcan_SpecterDR_KF_black",
					"optic_DMS_weathered_F"
				];

				{ 
					private _did = true;
					while {_did} do {
						_did = ([player, _x] call CBA_fnc_removeItem);
						sleep 0.01;
					}; 
					player removePrimaryWeaponItem _x;
				} forEach _magnified;

				waitUntil {!isNil 'arsenal'}; sleep 1;

				if !(isNil 'arsenal') then {
					[arsenal, _magnified] call ace_arsenal_fnc_removeVirtualItems;
				};
				if !(isNil 'missionArsenal') then {
					[missionArsenal, _magnified] call ace_arsenal_fnc_removeVirtualItems;
				};
				[true,true] call ace_arsenal_fnc_refresh;
			};
		},true] call CBA_fnc_addPlayerEventHandler;
	}] remoteExec ['call',0,'mjb_noMagnifiedJIP'];
};

if !(local _logic) exitWith {};

deleteVehicle _logic;