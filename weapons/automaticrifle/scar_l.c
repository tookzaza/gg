class RA_SCAR_L_Base : RifleBoltLock_Base
{ 
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Scar_L_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Scar_L_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Scar_L_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_Scar_L_Snow");

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
			SetObjectTexture(2,"");
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
			SetObjectTexture(2,""); //grip
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
			SetObjectTexture(2,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
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