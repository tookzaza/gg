modded class DayZPlayerCameraIronsights
{	
	override void SetupSightEntities()
	{		
		EntityAI entity_in_hands = m_pPlayer.GetHumanInventory().GetEntityInHands();
		if (!entity_in_hands) {
			return;
		}
		
		m_weaponUsed = Weapon_Base.Cast(entity_in_hands);
		if (!m_weaponUsed) {
			m_opticsUsed = ItemOptics.Cast(entity_in_hands);
			return;
		}
		
		m_SightMisalignmentModifier = "1 1 1";
		m_weaponUsed.ApplyTotalSightMisalignmentModifier(m_SightMisalignmentModifier);
		
		m_dynamicsStrength = m_dynamicsStrength * m_SightMisalignmentModifier[0];
		m_dynamicsSmoothTime = m_dynamicsSmoothTime * m_SightMisalignmentModifier[1];
		m_opticsUsed = m_weaponUsed.GetAttachedOptics();
		if (m_opticsUsed) {
			m_opticsHasWeaponOverride = m_opticsUsed.HasWeaponIronsightsOverride();
		}
	}
	
	override void OnUpdate(float pDt, out DayZPlayerCameraResult pOutResult)
	{
		super.OnUpdate(pDt, pOutResult);
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
		if (player && player.GetItemInHands() && player.GetItemInHands().GetAttachmentByType(OpticMagnifier_Base)) {
			OpticMagnifier_Base magnifier = OpticMagnifier_Base.Cast(player.GetItemInHands().GetAttachmentByType(OpticMagnifier_Base));
			pOutResult.m_fFovMultiplier = magnifier.GetSightMultiplier();
		}
	}
}