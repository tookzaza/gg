modded class ModItemRegisterCallbacks
{
	override void RegisterFireArms(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
        super.RegisterFireArms(pType, pBehavior);
        pType.AddItemInHandsProfileIK("RA_HoneyBadger_Base", "RearmedServer/Animations/Firearms/M4A1/M4A1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
  		pType.AddItemInHandsProfileIK("RA_SCAR_H_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_SCAR_L_Base", "RearmedServer/Scripts/anims/SCAR/player_main_scar.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_SCAR_20_Base", "RearmedServer/Scripts/anims/SCAR/player_main_scar.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_SCAR_L_CQC_Base", "RearmedServer/Scripts/anims/SCAR/player_main_scar.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_SCAR_H_CQC_Base", "RearmedServer/Scripts/anims/SCAR/player_main_scar.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
  		pType.AddItemInHandsProfileIK("RA_M82A1_Base",	"RearmedServer/Animations/Firearms/M82A1/M82A1.asi",	pBehavior, "RearmedServer/Animations/Firearms/M82A1/M82A1_IK.anm","RearmedServer/Animations/Firearms/M82A1/M82A1_IK_States.anm");
		pType.AddItemInHandsProfileIK("RA_R700_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz550.asi", pBehavior, "dz/anims/anm/player/ik/weapons/cz550.anm", "dz/anims/anm/player/reloads/cz550/w_CZ550_states.anm");
		pType.AddItemInHandsProfileIK("RA_C14_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz550.asi", pBehavior, "dz/anims/anm/player/ik/weapons/cz550.anm", "dz/anims/anm/player/reloads/cz550/w_CZ550_states.anm");
		pType.AddItemInHandsProfileIK("RA_AWM_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz550.asi", pBehavior, "dz/anims/anm/player/ik/weapons/cz550.anm", "dz/anims/anm/player/reloads/cz550/w_CZ550_states.anm");
		pType.AddItemInHandsProfileIK("RA_KS23_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_mp133.asi", pBehavior, "dz/anims/anm/player/ik/weapons/mp133.anm",  "DZ/anims/anm/player/reloads/MP133/w_mp133_states.anm");		
		pType.AddItemInHandsProfileIK("RA_M200_Base", "RearmedServer/Animations/Firearms/M200/M200.asi", pBehavior, "RearmedServer/Animations/Firearms/M200/M200_IK.anm",  "dz/anims/anm/player/reloads/cz550/w_CZ550_states.anm");
		pType.AddItemInHandsProfileIK("RA_RSASS_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_Dracarys_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_G28_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_Spear_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_M110_Base", "RearmedServer/Animations/Firearms/M4A1/M4A1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm",  "DZ/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
		pType.AddItemInHandsProfileIK("RA_SV98_Base",	"dz/anims/workspaces/player/player_main/weapons/player_main_SV98.asi",	pBehavior, "dz/anims/anm/player/ik/weapons/SV98.anm","dz/anims/anm/player/reloads/SV98/w_SV98_states.anm");
		pType.AddItemInHandsProfileIK("RA_Vector_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ump45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ump.anm","dz/anims/anm/player/reloads/UMP45/w_UMP45_states.anm");
		pType.AddItemInHandsProfileIK("RA_Auga3_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_famas.asi", pBehavior, "dz/anims/anm/player/ik/weapons/famas.anm", "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_ASH12_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_famas.asi", pBehavior, "dz/anims/anm/player/ik/weapons/famas.anm", "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_AK74_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_akm.asi", pBehavior, "dz/anims/anm/player/ik/weapons/akm.anm", "dz/anims/anm/player/reloads/AKM/w_akm_states.anm");
		pType.AddItemInHandsProfileIK("RA_AK12_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_akm.asi", pBehavior, "dz/anims/anm/player/ik/weapons/akm.anm", "dz/anims/anm/player/reloads/AKM/w_akm_states.anm");
		pType.AddItemInHandsProfileIK("RA_AKS74U_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ak74u.asi", pBehavior, "dz/anims/anm/player/ik/weapons/AKS74U.anm", "dz/anims/anm/player/reloads/AK74U/w_AKS74U_states.anm");
		pType.AddItemInHandsProfileIK("RA_PP19_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ak74u.asi", pBehavior, "dz/anims/anm/player/ik/weapons/AKS74U.anm", "dz/anims/anm/player/reloads/AK74U/w_AKS74U_states.anm");
		pType.AddItemInHandsProfileIK("RA_DT_SRS_A2_Base", "RearmedServer/Animations/Firearms/SRS/SRS.asi", pBehavior, "RearmedServer/Animations/Firearms/SRS/SRS_IK.anm", "dz/anims/anm/player/reloads/cz550/w_CZ550_states.anm");
		pType.AddItemInHandsProfileIK("RA_DT_SRS_HTI_Base", "RearmedServer/Animations/Firearms/SRS/SRS.asi", pBehavior, "RearmedServer/Animations/Firearms/SRS/SRS_IK.anm", "dz/anims/anm/player/reloads/cz550/w_CZ550_states.anm");
		pType.AddItemInHandsProfileIK("RA_DVL_Base", "RearmedServer/Firearms/DVL/DVL10.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
        pType.AddItemInHandsProfileIK("RA_MK12_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_m16a2.asi", pBehavior, "dz/anims/anm/player/ik/weapons/M16A2_ik.anm", "dz/anims/anm/player/reloads/m16a2/w_m16a2_states.anm");
        pType.AddItemInHandsProfileIK("RA_M16A1_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_m16a2.asi", pBehavior, "dz/anims/anm/player/ik/weapons/M16A2_ik.anm", "dz/anims/anm/player/reloads/m16a2/w_m16a2_states.anm");
		pType.AddItemInHandsProfileIK("RA_M4A1_Base", "RearmedServer/Animations/Firearms/M4A1/M4A1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
		pType.AddItemInHandsProfileIK("RA_MK18_Base", "RearmedServer/Animations/Firearms/MK18/MK18.asi", pBehavior, "RearmedServer/Animations/Firearms/MK18/MK18_IK.anm", "RearmedServer/Animations/Firearms/MK18/MK18_States.anm");
		pType.AddItemInHandsProfileIK("RA_AK5C_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_akm.asi", pBehavior, "dz/anims/anm/player/ik/weapons/akm.anm", "dz/anims/anm/player/reloads/AKM/w_akm_states.anm");
		pType.AddItemInHandsProfileIK("RA_G36_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_m4a1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
		pType.AddItemInHandsProfileIK("RA_MCX_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_m4a1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
		pType.AddItemInHandsProfileIK("RA_VSS", "dz/anims/workspaces/player/player_main/weapons/player_main_vss.asi", pBehavior, "dz/anims/anm/player/ik/weapons/VSS.anm",  "dz/anims/anm/player/reloads/VSS/w_VSS_states.anm");
		pType.AddItemInHandsProfileIK("RA_AKM_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_akm.asi", pBehavior, "dz/anims/anm/player/ik/weapons/akm.anm", "dz/anims/anm/player/reloads/AKM/w_akm_states.anm");
		pType.AddItemInHandsProfileIK("RA_M24_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz527.asi", pBehavior, "dz/anims/anm/player/ik/weapons/cz527.anm", "dz/anims/anm/player/reloads/cz527/w_CZ527_states.anm");
		pType.AddItemInHandsProfileIK("RA_SSG69_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz527.asi", pBehavior, "dz/anims/anm/player/ik/weapons/cz527.anm", "dz/anims/anm/player/reloads/cz527/w_CZ527_states.anm");
		pType.AddItemInHandsProfileIK("RA_McMillan_CS5_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz527.asi", pBehavior, "dz/anims/anm/player/ik/weapons/cz527.anm", "dz/anims/anm/player/reloads/cz527/w_CZ527_states.anm");
		pType.AddItemInHandsProfileIK("RA_SVD_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_svd.asi", pBehavior, "dz/anims/anm/player/ik/weapons/svd.anm",  "dz/anims/anm/player/reloads/SVD/w_SVD_states.anm");
		pType.AddItemInHandsProfileIK("RA_OPSKS_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_svd.asi", pBehavior, "dz/anims/anm/player/ik/weapons/svd.anm",  "dz/anims/anm/player/reloads/SVD/w_SVD_states.anm");
		pType.AddItemInHandsProfileIK("RA_Kivaari_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_MK47_Base", "RearmedServer/Animations/Firearms/M4A1/M4A1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
        pType.AddItemInHandsProfileIK("RA_ASVAL_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_as_val.asi", pBehavior, "dz/anims/anm/player/ik/weapons/VAL.anm","dz/anims/anm/player/reloads/VAL/w_VAL_states.anm");
        pType.AddItemInHandsProfileIK("RA_9A91", "dz/anims/workspaces/player/player_main/weapons/player_main_as_val.asi", pBehavior, "dz/anims/anm/player/ik/weapons/VAL.anm","dz/anims/anm/player/reloads/VAL/w_VAL_states.anm");
		pType.AddItemInHandsProfileIK("RA_SR3_Base",	"dz/anims/workspaces/player/player_main/weapons/player_main_Vikhr.asi",	pBehavior, "dz/anims/anm/player/ik/weapons/Vikhr.anm","dz/anims/anm/player/reloads/Vikhr/w_Vikhr_states.anm");
		pType.AddItemInHandsProfileIK("RA_SVCh", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_M249_Base", "RearmedServer/Animations/Firearms/M249/M249.asi", pBehavior, "RearmedServer/Animations/Firearms/M249/M249_IK.anm","RearmedServer/Animations/Firearms/M249/w_M249_States.anm");
		pType.AddItemInHandsProfileIK("RA_UMP45_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ump45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ump.anm","dz/anims/anm/player/reloads/UMP45/w_UMP45_states.anm");
		pType.AddItemInHandsProfileIK("RA_FAL_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_Mini14_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_AK101_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_akm.asi", pBehavior, "dz/anims/anm/player/ik/weapons/akm.anm",  "DZ/anims/anm/player/reloads/akm/w_AKM_states.anm");
		pType.AddItemInHandsProfileIK("M32_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_m4a1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
		pType.AddItemInHandsProfileIK("AX50_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz527.asi", pBehavior, "dz/anims/anm/player/ik/weapons/cz527.anm", "dz/anims/anm/player/reloads/cz527/w_CZ527_states.anm");
		pType.AddItemInHandsProfileIK("M300_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz527.asi", pBehavior, "dz/anims/anm/player/ik/weapons/cz550.anm", "dz/anims/anm/player/reloads/cz527/w_CZ527_states.anm");
		pType.AddItemInHandsProfileIK("SA58_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm", "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RPK16_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_akm.asi", pBehavior, "dz/anims/anm/player/ik/weapons/akm.anm", "dz/anims/anm/player/reloads/AKM/w_akm_states.anm");
		pType.AddItemInHandsProfileIK("SR25_Base", "RearmedServer/Animations/Firearms/M4A1/M4A1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
        pType.AddItemInHandsProfileIK("RA_RPG7_Base", "RearmedServer/Animations/Firearms/RPG7/RPG7.asi", pBehavior, "RearmedServer/Animations/Firearms/RPG7/RPG_IK.anm", "RearmedServer/Animations/Firearms/RPG7/w_RPG_States.anm");
		pType.AddItemInHandsProfileIK("RA_Galil_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_akm.asi", pBehavior, "dz/anims/anm/player/ik/weapons/akm.anm", "dz/anims/anm/player/reloads/AKM/w_akm_states.anm");
		pType.AddItemInHandsProfileIK("RA_HK416_Base", "RearmedServer/Animations/Firearms/M4A1/M4A1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
		pType.AddItemInHandsProfileIK("RA_AA12_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_Saiga.asi", pBehavior, "dz/anims/anm/player/ik/weapons/Saiga.anm", "dz/anims/anm/player/reloads/Saiga/w_Saiga_states.anm");
		pType.AddItemInHandsProfileIK("RA_Vepr12_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_Saiga.asi", pBehavior, "dz/anims/anm/player/ik/weapons/Saiga.anm", "dz/anims/anm/player/reloads/Saiga/w_Saiga_states.anm");
		pType.AddItemInHandsProfileIK("RA_BenelliM4_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_R12.asi", pBehavior,	"dz/anims/anm/player/ik/weapons/R12.anm", "dz/anims/anm/player/reloads/R12/w_R12_states.anm");
		pType.AddItemInHandsProfileIK("RA_SPAS12_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_R12.asi", pBehavior,	"dz/anims/anm/player/ik/weapons/R12.anm", "dz/anims/anm/player/reloads/R12/w_R12_states.anm");
		pType.AddItemInHandsProfileIK("St_Kedr_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_cz61.asi", pBehavior, "dz/anims/anm/player/ik/weapons/CZ61.anm", "dz/anims/anm/player/reloads/cz61/w_cz61_states.anm");
		pType.AddItemInHandsProfileIK("RA_Kriss_Vector_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ump45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ump.anm","dz/anims/anm/player/reloads/UMP45/w_UMP45_states.anm");
		pType.AddItemInHandsProfileIK("RA_MP5_Base", "RearmedServer/Firearms/MP5.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ump.anm","dz/anims/anm/player/reloads/mp5/w_mp5k_states.anm");
		pType.AddItemInHandsProfileIK("RA_P90_Base", "RearmedServer/Animations/Firearms/P90/JD/P90.asi", pBehavior, "RearmedServer/Animations/Firearms/P90/JD/JDP90.anm", "RearmedServer/Animations/Firearms/P90/JD/w_JDP90_states.anm");
		pType.AddItemInHandsProfileIK("RA_MDR_556_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_famas.asi", pBehavior, "dz/anims/anm/player/ik/weapons/famas.anm", "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_MDR_308_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_famas.asi", pBehavior, "dz/anims/anm/player/ik/weapons/famas.anm", "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
		pType.AddItemInHandsProfileIK("RA_PKM", "RearmedServer/Animations/Firearms/M249/M249.asi", pBehavior, "RearmedServer/Animations/Firearms/M249/M249_IK.anm","RearmedServer/Animations/Firearms/M249/w_M249_States.anm");
		pType.AddItemInHandsProfileIK("Railgun_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_izh18.asi", pBehavior, "dz/anims/anm/player/ik/weapons/izh18.anm", "dz/anims/anm/player/reloads/IZH18/w_izh18_states.anm");
		pType.AddItemInHandsProfileIK("RA_MP7A1_Base", "RearmedServer/Animations/Firearms/MP7A2/MP7A2.asi", pBehavior, "RearmedServer/Animations/Firearms/MP7A2/MP7A2_IK.anm", "dz/anims/anm/player/reloads/cz61/w_cz61_states.anm");
		pType.AddItemInHandsProfileIK("RA_MP7A2_Base", "RearmedServer/Animations/Firearms/MP7A2/MP7A2.asi", pBehavior, "RearmedServer/Animations/Firearms/MP7A2/MP7A2_IK.anm", "dz/anims/anm/player/reloads/cz61/w_cz61_states.anm");
		pType.AddItemInHandsProfileIK("RA_AXMK3_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_Scout.asi", pBehavior, "dz/anims/anm/player/ik/weapons/Scout.anm", "dz/anims/anm/player/reloads/Scout/w_scout_states.anm");
		pType.AddItemInHandsProfileIK("RA_SVT40_Base", "RearmedServer/Firearms/SVT40.asi", pBehavior, "dz/anims/anm/player/ik/weapons/SKS.anm","dz/anims/anm/player/reloads/SVD/w_SVD_states.anm");  
		pType.AddItemInHandsProfileIK("RA_PPSH_Base","dz/anims/workspaces/player/player_main/weapons/player_main_ruger1022.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ruger1022.anm", "dz/anims/anm/player/reloads/ruger1022/w_Ruger1022_states.anm");
		pType.AddItemInHandsProfileIK("RA_OTS14", "RearmedServer/Animations/Firearms/Groza/Groza.asi", pBehavior, "RearmedServer/Animations/Firearms/Groza/Groza_IK.anm", "RearmedServer/Animations/Firearms/Groza/w_JDGroza_States.anm");
		pType.AddItemInHandsProfileIK("RA_OTS14_Suppressed", "RearmedServer/Firearms/OTS14/anims/player_main_grozasuppressed.asi", pBehavior, "dz/anims/anm/player/ik/weapons/famas.anm", "dz/anims/anm/player/reloads/famas/w_famas_states.anm");
		pType.AddItemInHandsProfileIK("RA_VSSK_Base", "RearmedServer/Firearms/OTS14/anims/player_main_grozasuppressed.asi", pBehavior, "dz/anims/anm/player/ik/weapons/famas.anm", "dz/anims/anm/player/reloads/famas/w_famas_states.anm");
        //pType.AddItemInHandsProfileIK("RA_M32_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_m4a1.asi", pBehavior, "dz/anims/anm/player/ik/weapons/m4a1_ik.anm", "dz/anims/anm/player/reloads/M4A1/w_M4A1_states.anm");
        pType.AddItemInHandsProfileIK("RA_RG6_Base", "RearmedServer/Animations/Firearms/RG6/RG6.asi", pBehavior, "RearmedServer/Animations/Firearms/RG6/RG6_IK.anm", "RearmedServer/Animations/Firearms/RG6/RG6_IK_States.anm");
		pType.AddItemInHandsProfileIK("RA_Model1887_Base",	"dz/anims/workspaces/player/player_main/weapons/player_main_repeater.asi", pBehavior, "dz/anims/anm/player/ik/weapons/repeater.anm", "dz/anims/anm/player/reloads/repeater/w_repeater_states.anm");
		pType.AddItemInHandsProfileIK("RA_M14_DMR_Base",	"dz/anims/workspaces/player/player_main/weapons/player_main_m14.asi",	pBehavior, "dz/anims/anm/player/ik/weapons/M14_ik.anm","dz/anims/anm/player/reloads/M14/w_M14_states.anm");
		pType.AddItemInHandsProfileIK("RA_M14_EBR_Base",	"dz/anims/workspaces/player/player_main/weapons/player_main_m14.asi",	pBehavior, "dz/anims/anm/player/ik/weapons/M14_ik.anm","dz/anims/anm/player/reloads/M14/w_M14_states.anm");
		pType.AddItemInHandsProfileIK("RA_M1A_Base",	"dz/anims/workspaces/player/player_main/weapons/player_main_m14.asi",	pBehavior, "dz/anims/anm/player/ik/weapons/M14_ik.anm","dz/anims/anm/player/reloads/M14/w_M14_states.anm");
		pType.AddItemInHandsProfileIK("RA_M14_Base",	"dz/anims/workspaces/player/player_main/weapons/player_main_m14.asi",	pBehavior, "dz/anims/anm/player/ik/weapons/M14_ik.anm","dz/anims/anm/player/reloads/M14/w_M14_states.anm");
		pType.AddItemInHandsProfileIK("RA_L85_Base", "RearmedServer/Firearms/OTS14/anims/player_main_grozasuppressed.asi", pBehavior, "dz/anims/anm/player/ik/weapons/famas.anm", "dz/anims/anm/player/reloads/famas/w_famas_states.anm");
		pType.AddItemInHandsProfileIK("RA_MP9_Base", "RearmedServer/Firearms/MP9.asi", pBehavior, "dz/anims/anm/player/ik/weapons/CZ61.anm", "dz/anims/anm/player/reloads/cz61/w_cz61_states.anm");
		pType.AddItemInHandsProfileIK("RA_Mossberg_590_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_mp133.asi", pBehavior, "dz/anims/anm/player/ik/weapons/mp133.anm","dz/anims/anm/player/reloads/MP133/w_mp133_states.anm");
        pType.AddItemInHandsProfileIK("RA_MP153_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_R12.asi", pBehavior,	"dz/anims/anm/player/ik/weapons/R12.anm", "dz/anims/anm/player/reloads/R12/w_R12_states.anm");
        pType.AddItemInHandsProfileIK("RA_HenrySS_Shotgun_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_izh18_Spartan.asi",	pBehavior,	"dz/anims/anm/player/ik/weapons/izh18_Spartan.anm", "dz/anims/anm/player/reloads/IZH18Spartan/w_izh18Spartan_states.anm");
        pType.AddItemInHandsProfileIK("RA_Mosin9130_Base",		"dz/anims/workspaces/player/player_main/weapons/player_main_mosin1903.asi",		pBehavior, "dz/anims/anm/player/ik/weapons/mosin9130.anm","dz/anims/anm/player/reloads/Mosin_1903/w_mosin1903_states.anm");
		pType.AddItemInHandsProfileIK("RA_Mk18Mjolnir_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnfal.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fn_fal.anm",  "dz/anims/anm/player/reloads/FNFal/w_FNFal_states.anm");
    }

	override void CustomBoneRemapping( DayZPlayerType pType )
    {
        super.CustomBoneRemapping( pType );
		array<string> railgunBoneRemap = { "release", "Weapon_Bone_02", "barrel", "Weapon_Bone_01", "trigger", "Weapon_Trigger","extractor","Weapon_Bone_03","bullet", "Weapon_Bullet", "charging", "Weapon_Bone_04", };
        array<string> shotgunBoneRemap ={ "bolt", "Weapon_Bolt", "pump", "Weapon_Bone_01","feedRamp", "Weapon_Bone_02", "trigger", "Weapon_Trigger","bullet", "Weapon_Bullet", "boltrelease", "Weapon_Bone_03"};
		pType.AddItemBoneRemap("Railgun_Base", railgunBoneRemap);      
		pType.AddItemBoneRemap("RA_RPG7_Base", { "hammer", "Weapon_Bone_01", "trigger", "Weapon_Trigger", "bullet", "Weapon_Bullet" });
		pType.AddItemBoneRemap("RA_RG6_Base", { "bolt", "Weapon_Bolt", "magazine", "Weapon_Magazine", "bullet","Weapon_Bullet", "trigger", "Weapon_Trigger", "hammer", "Weapon_Bone_01","cylinder_arm", "Weapon_Bone_03" ,"ejector", "Weapon_Bone_04" }); 
		pType.AddItemBoneRemap("RA_M249_Base", { "bolt", "Weapon_Bolt", "magazine", "Weapon_Magazine", "charging", "Weapon_Bone_01", "cover", "Weapon_Bone_02", "trigger", "Weapon_Trigger", "bullet", "Weapon_Bullet", "flap", "Weapon_Bone_06", "beltpart3", "Weapon_Bone_03", "beltpart2", "Weapon_Bone_04", "beltpart1", "Weapon_Bone_05" });

    	pType.AddItemBoneRemap("RA_Mossberg_590_Base", shotgunBoneRemap);
    	pType.AddItemBoneRemap("RA_MP153_Base", shotgunBoneRemap);
		pType.AddItemBoneRemap("RA_HenrySS_Shotgun_Base", { "release", "Weapon_Bone_02", "barrel", "Weapon_Bone_01", "trigger", "Weapon_Trigger","ejector","Weapon_Bone_03","bullet", "Weapon_Bullet" });
    };

	override void RegisterPistol(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterPistol( pType, pBehavior );
		
		pType.AddItemInHandsProfileIK("RA_Glock18_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_glock.asi", pBehavior, "dz/anims/anm/player/ik/weapons/Glock19.anm", "dz/anims/anm/player/reloads/Glock/w_Glock19_states.anm");
		pType.AddItemInHandsProfileIK("RA_P226_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_glock.asi", pBehavior, "dz/anims/anm/player/ik/weapons/Glock19.anm", "dz/anims/anm/player/reloads/Glock/w_Glock19_states.anm");
		pType.AddItemInHandsProfileIK("RA_P320_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_glock.asi", pBehavior, "dz/anims/anm/player/ik/weapons/Glock19.anm", "dz/anims/anm/player/reloads/Glock/w_Glock19_states.anm");
		pType.AddItemInHandsProfileIK("FiveSeven_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_glock.asi", pBehavior, "dz/anims/anm/player/ik/weapons/Glock19.anm", "dz/anims/anm/player/reloads/Glock/w_Glock19_states.anm");
		pType.AddItemInHandsProfileIK("RA_Beretta_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnp45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fnp45.anm", "dz/anims/anm/player/reloads/FNP45/w_fnp45_states.anm");
		pType.AddItemInHandsProfileIK("RA_PP2000_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_fnp45.asi", pBehavior, "dz/anims/anm/player/ik/weapons/fnp45.anm", "dz/anims/anm/player/reloads/FNP45/w_fnp45_states.anm");
		pType.AddItemInHandsProfileIK("RA_APS_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ij70.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ij70.anm", "dz/anims/anm/player/reloads/IJ70/w_IJ70_states.anm");
		pType.AddItemInHandsProfileIK("RA_PB_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ij70.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ij70.anm", "dz/anims/anm/player/reloads/IJ70/w_IJ70_states.anm");
		pType.AddItemInHandsProfileIK("RA_PM_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_ij70.asi", pBehavior, "dz/anims/anm/player/ik/weapons/ij70.anm", "dz/anims/anm/player/reloads/IJ70/w_IJ70_states.anm");
		pType.AddItemInHandsProfileIK("RA_Fort12_Base",	"dz/anims/workspaces/player/player_main/weapons/player_main_cz75.asi", pBehavior, "dz/anims/anm/player/ik/weapons/CZ75.anm", "dz/anims/anm/player/reloads/CZ75/w_CZ75_states.anm");
		pType.AddItemInHandsProfileIK("RA_TT_Base",	"dz/anims/workspaces/player/player_main/weapons/player_main_cz75.asi", pBehavior, "dz/anims/anm/player/ik/weapons/CZ75.anm", "dz/anims/anm/player/reloads/CZ75/w_CZ75_states.anm");
		pType.AddItemInHandsProfileIK("RA_MK23_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_glock.asi", pBehavior, "dz/anims/anm/player/ik/weapons/Glock19.anm", "dz/anims/anm/player/reloads/Glock/w_Glock19_states.anm");
	}

	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
        pType.AddItemInHandsProfileIK("RA_AimpointT2", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior, "dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_XPS3_Holosight", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_PK06", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_Vortex_UH1", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_Pilad", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_SRS", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_PKAS", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_Prism", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_RMR_Base", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_ATACR", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_ACOG", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_Tango6", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_46x", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_VortexRazorOptic_Base", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_Vudu_Optic", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_LeupoldMk4Optic", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_PM2", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_Hamr_Optic", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_PSO_Optic", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/optic/optic_pso1.anm");
		pType.AddItemInHandsProfileIK("RA_Specter_Elcan", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_Romeo4TOptic",   "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_hunting_scope_12x.anm");
		pType.AddItemInHandsProfileIK("RA_Bravo4", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/optic/optic_acog.anm");
		pType.AddItemInHandsProfileIK("RA_Holosun_HS510C_Optic", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior, "dz/anims/anm/player/ik/attachments/optic/optic_reflex.anm");

		//magazines
		pType.AddItemInHandsProfileIK("RA_M249_Magazine", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/attachments/magazines/magazine_akm_drum.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_PKM_100Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,"dz/anims/anm/player/ik/attachments/magazines/magazine_akm_drum.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_M24_5Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_cz527.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_McMillan_CS5_10Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_cz527.anm");
		pType.AddItemInHandsProfileIK("Mag_M82A1_10Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("Mag_OPSKS_20Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("Mag_R700_8Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("Mag_R700_5Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("Mag_SV98_10Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("Mag_R700_762_7Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("Mag_R700_762_10Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_M200_7rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("Mag_HoneyBadger_PMAG_20Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_VSSK_10Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("Mag_RSASS_20Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("RA_PMAG_Drum_60Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("Mag_SR3M130_30Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_vss_10rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_Glock_33Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_Glock18_50Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_P226_15Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_P320_15Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_TT_8Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Fort12_12Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_MK23_10Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_Vector_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_Vector_13Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_Vector_Drum_50Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_SRS_7Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_SRS_5Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_SRS_HTI_5Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_DVL_10Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_cmag_10rnd.anm");    
		pType.AddItemInHandsProfileIK("Mag_FiveSeven_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("RA_APS_Mag_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_ij70.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Kivaari_5Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("Mag_M32_6Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30_coupled.anm");
		pType.AddItemInHandsProfileIK("SR25_Magazine", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("AX50_Magazine", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("M300_Magazine", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("Mag_60Rnd_545x39", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30_coupled.anm");
		pType.AddItemInHandsProfileIK("RPK16_DrumMagazine", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30_coupled.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Galil_35Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_G36_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_AA12_Drum32Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, 		        "dz/anims/anm/player/ik/attachments/magazines/magazine_saiga_drum.anm");
		pType.AddItemInHandsProfileIK("St_Mag_Kedr_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_ump45.anm");
		pType.AddItemInHandsProfileIK("St_Mag_Kedr_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_ump45.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_P90_50Rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_ump45.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Scar_H_20Rnd_Base", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Scar_H_10Rnd_Base", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_G28_20Rnd_Base", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Spear_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Dracarys_10Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_X10_50Rnd_308win_Base", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_XFAL_50Rnd_308win_Base", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_M14_10Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_M14_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Mini14_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_FAL_10Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_SA58_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_FAL_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_M110_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_308_PMAG_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Spear_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Spear_20Rnd_Tan", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_9A91_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_SVD_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_MP7_40rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_MP7_20rnd", "dz/anims/workspaces/player/player_main/props/player_main_fnp45_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_glock19_15rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_AXMK3_10rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_cz527.anm");
		pType.AddItemInHandsProfileIK("Mag_PP19_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior,			"dz/anims/anm/player/ik/attachments/magazines/magazine_mp5_30rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_SVT40_10Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_fal_20rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_PPSH_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_ump45.anm");
		pType.AddItemInHandsProfileIK("Mag_PPSH_Drum_71Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30_coupled.anm");
		pType.AddItemInHandsProfileIK("Mag_ASH12_10Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_AK74_PMAG_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_akm_30rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_AK12_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_akm_30rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_ASH12_20Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 		"dz/anims/anm/player/ik/attachments/magazines/magazine_svd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_AKM_PMAG_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_akm_30rnd.anm");
		pType.AddItemInHandsProfileIK("Mag_Waffle_MP5_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_mp5k_mag.asi", pBehavior,			"dz/anims/anm/player/ik/attachments/magazines/magazine_mp5_30rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Vepr12_10Rnd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, 		            "dz/anims/anm/player/ik/attachments/magazines/magazine_saiga_8rnd.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_Mk18Mjolnir_10Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		pType.AddItemInHandsProfileIK("RA_Mag_AK5C_30Rnd", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, 	"dz/anims/anm/player/ik/attachments/magazines/magazine_stanag30.anm");
		//handguards
		pType.AddItemInHandsProfileIK("NcSTAR_Blue_Laser", "dz/anims/workspaces/player/player_main/props/player_main_1h_flashlight.asi", pBehavior, "dz/anims/anm/player/ik/attachments/light/universallight.anm");
		pType.AddItemInHandsProfileIK("RA_ANPEQ_Black", "dz/anims/workspaces/player/player_main/props/player_main_1h_flashlight.asi", pBehavior, "dz/anims/anm/player/ik/attachments/light/universallight.anm");
		pType.AddItemInHandsProfileIK("RA_ANPEQ_Green", "dz/anims/workspaces/player/player_main/props/player_main_1h_flashlight.asi", pBehavior, "dz/anims/anm/player/ik/attachments/light/universallight.anm");
		pType.AddItemInHandsProfileIK("RA_ANPEQ_Tan", "dz/anims/workspaces/player/player_main/props/player_main_1h_flashlight.asi", pBehavior, "dz/anims/anm/player/ik/attachments/light/universallight.anm");
		pType.AddItemInHandsProfileIK("RA_AK_MagpulHndgrd", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_Raptar_Rangefinder", "dz/anims/workspaces/player/player_main/props/player_main_1h_flashlight.asi", pBehavior, "dz/anims/anm/player/ik/attachments/light/universallight.anm");

		//buttstocks
		pType.AddItemInHandsProfileIK("RA_Bttstck_SPAS12", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_AK_MPBttstck", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("PRS_Bttstck", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("UBR_Bttstck", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_Bttstk_AK_AK12", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_Bttstk_AK_AK12M", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_Bttstk_M4_Fortis", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_Bttstk_AK_Magpul", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_Bttstk_AK_Tact2", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_Bttstk_AK_Tact", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_Bttstk_AK_Zenit_Black", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");

		//Suppressor
		pType.AddItemInHandsProfileIK("RA_Salvo_Muzzle", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/muzzle/compensator_mosin.anm");
		pType.AddItemInHandsProfileIK("RA_CMB_ShotgunMuzzle", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/muzzle/compensator_mosin.anm");
		pType.AddItemInHandsProfileIK("RA_QDJK_ShotgunMuzzle", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/muzzle/compensator_mosin.anm");
		pType.AddItemInHandsProfileIK("RA_Salvo_Suppressor", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,	"dz/anims/anm/player/ik/attachments/muzzle/suppressor_556.anm");
		pType.AddItemInHandsProfileIK("RA_PBS1_Suppressor", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,		"dz/anims/anm/player/ik/attachments/muzzle/suppressor_545.anm");
		pType.AddItemInHandsProfileIK("RA_PBS4_Suppressor", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior,		"dz/anims/anm/player/ik/attachments/muzzle/suppressor_545.anm");
		
		pType.AddItemInHandsProfileIK("RA_MP153_Forearm_Plastic", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/handguard_m4_ris.anm");
		pType.AddItemInHandsProfileIK("RA_Mossberg_Buttstock_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/buttstock_ak_wood.anm");
		pType.AddItemInHandsProfileIK("RA_Mossberg_Forearm_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/handguard_m4_ris.anm");
		pType.AddItemInHandsProfileIK("RA_Mossberg_OpticMount_Base", "dz/anims/workspaces/player/player_main/props/player_main_1h_scope.asi", pBehavior, "dz/anims/anm/player/ik/attachments/optic/optic_pso1.anm");
		pType.AddItemInHandsProfileIK("RA_Mossberg_Shroud_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/attachments/support/handguard_m4_ris.anm");

		//medical
		pType.AddItemInHandsProfileIK("RA_BandageDressing", "RearmedServer/Animations/Medical/Bandage/Bandage.asi", pBehavior, "dz/anims/anm/player/ik/gear/bandage_dressing.anm");
	}
};