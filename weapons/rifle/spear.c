class RA_Spear_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Spear_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Spear_Tan");

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
		ItemBase stock = ItemBase.Cast(FindAttachmentBySlotName("weaponButtstockM4"));
		if (FindAttachmentBySlotName("weaponPistolGrip") || stock && stock.IsInherited(RA_CQR_Bttstck)) { 
			SetObjectTexture(1,"");
		}

		if (FindAttachmentBySlotName("weaponForegrip")) { 
			SetObjectTexture(2,"");
		}

		if (FindAttachmentBySlotName("weaponFlashlight")) { 
			SetObjectTexture(4,"");
		}

		if (FindAttachmentBySlotName("weaponFlashlight2")) { 
			SetObjectTexture(3,"");
		}

		if (FindAttachmentBySlotName("weaponBipod")) { 
			SetObjectTexture(5,"");
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
		}

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(2,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail11_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(4,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(3,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
		if (slot_name == "weaponBipod")
		{
			SetObjectTexture(5,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}

		if (ItemOptics.Cast(item))
		{
			SetAnimationPhase("rotate", 0);
		}

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(2,"");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(4,"");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(3,"");
			return;
		}
		if (slot_name == "weaponBipod")
		{
			SetObjectTexture(5,"");
			return;
		}
	}
	#endif
};