class RA_G28_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_G28_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_G28_Tan");

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

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardG28"));
		ItemOptics optic = ItemOptics.Cast(FindAttachmentBySlotName("weaponOptics"));
		if (handgrd && optic)
		{
			handgrd.SetAnimationPhase("rotate", 1);
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
		}

		if (FindAttachmentBySlotName("weaponHandguardG28"))
		{
			RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardG28"));
			if (!handgrd){return;}
			if (ItemOptics.Cast(item)) { 
				handgrd.SetAnimationPhase("rotate", 1);
			}
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
		}

		if (FindAttachmentBySlotName("weaponHandguardG28"))
		{
			RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardG28"));
			if (!handgrd){return;}
			if (ItemOptics.Cast(item)) { 
				handgrd.SetAnimationPhase("rotate", 0);
			}
		}
	}
	#endif
};