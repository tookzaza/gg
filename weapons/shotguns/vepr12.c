class RA_Vepr12_Base : RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new AkmRecoil(this);
	}
	
	override bool CanEnterIronsights()
	{
		ItemOptics optic = GetAttachedOptics();
		if ( optic && PSO1Optic.Cast(optic) || PSO11Optic.Cast(optic) || KashtanOptic.Cast(optic) || KazuarOptic.Cast(optic) )
			return true;
		return super.CanEnterIronsights();
	}

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		if (FindAttachmentBySlotName("weaponPistolGripAK")) { 
			SetObjectTexture(1,"");
		}
		
		if (FindAttachmentBySlotName("weaponMuzzleShotGun") ) { 
			SetObjectTexture(2,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (RA_AK_Pistol_Grip_Base.Cast(item))
		{
			SetObjectTexture(1,"");
		}

		if (ItemSuppressor.Cast(item))
		{
			SetObjectTexture(2,"");
		}	
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (RA_AK_Pistol_Grip_Base.Cast(item))
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\AKM\\data\\Grip_co.paa"); //grip
		}

		if (ItemSuppressor.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\Vepr12\\data\\vepr12_co.paa");
		}	
	}
	#endif
}
class RA_Vepr12: RA_Vepr12_Base{};