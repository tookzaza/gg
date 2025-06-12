class RA_M82A1_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
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
			SetObjectTexture(4,"");
		}

		if (FindAttachmentBySlotName("weaponOptics") ) { 
			SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);
		
		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(4,""); //grip
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
			SetObjectTexture(4,"RearmedServer\\Firearms\\M82A1\\data\\M82A1_2_Black_co.paa"); //grip
			return;
		}

		if (ItemOptics.Cast(item))
		{
			SetAnimationPhase("rotate", 0);
			return;
		}
	}
	#endif

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_M82A1_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_M82A1_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M82A1_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_M82A1");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_M82A1_Camo");

		return m_SprayPaintEntry;
	}

	override bool CanBeInspected()
	{
		return true;
	}
};

class RA_M82A1 : RA_M82A1_Base{};