class RA_M200_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{		
		return new CZ527Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_M200_Intervention");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M200_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_M200_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_M200_Camo");

		return m_SprayPaintEntry;
	}

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		if (FindAttachmentBySlotName("weaponPistolGrip") ) { 
			SetObjectTexture(2,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);
		
		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(2,""); //grip
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\M200\\data\\Grip_co.paa"); //grip
			return;
		}
	}
	#endif
}