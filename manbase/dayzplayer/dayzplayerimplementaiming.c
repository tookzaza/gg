modded class DayZPlayerImplementAiming
{
	override void OnRaiseBegin(DayZPlayerImplement player)
	{
		super.OnRaiseBegin(player);
		
		Weapon_Base weapon = Weapon_Base.Cast(player.GetHumanInventory().GetEntityInHands());
		if (weapon) {
			m_SwayModifier = "1 1 1";
			weapon.ApplyTotalSwayModifier(m_SwayModifier);
			
			vector ads_modifier = "1 1 1";
            weapon.ApplyTotalADSModifier(ads_modifier);
            DayZPlayerCameras.RegisterTransitionTime(DayZPlayerCameras.DAYZCAMERA_1ST, DayZPlayerCameras.DAYZCAMERA_OPTICS, ads_modifier[0], false);
            DayZPlayerCameras.RegisterTransitionTime(DayZPlayerCameras.DAYZCAMERA_1ST, DayZPlayerCameras.DAYZCAMERA_IRONSIGHTS, ads_modifier[1], false);
            DayZPlayerCameras.RegisterTransitionTime(DayZPlayerCameras.DAYZCAMERA_IRONSIGHTS, DayZPlayerCameras.DAYZCAMERA_OPTICS, ads_modifier[2], true);
		}
	}
}