class RA_SCAR_20_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{		
		return new SvdRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_SCAR_20_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_SCAR_20_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_SCAR_20_Green");

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
		if (FindAttachmentBySlotName("weaponPistolGrip")) { 
			SetObjectTexture(1,"");
		}
		
		if (FindAttachmentBySlotName("weaponOptics")) { 
			SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);
		
		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(1,""); //grip
			return;
		}

		if (ItemOptics.Cast(item))
		{
			SetAnimationPhase("rotate", 1);
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(1,"rearmedserver\\firearms\\scar20\\data\\SSR_Receiver_Black_co.paa"); //grip
			return;
		}

		if (ItemOptics.Cast(item))
		{
			SetAnimationPhase("rotate", 0);
			return;
		}
	}
	#endif
};