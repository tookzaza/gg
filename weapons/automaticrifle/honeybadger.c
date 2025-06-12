class RA_HoneyBadger_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new VSSRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_HoneyBadger_Grey");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_HoneyBadger");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_HoneyBadger_Green");

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
			SetObjectTexture(GetHiddenSelectionIndex("grip"),"");
		}

		if (FindAttachmentBySlotName("weaponForegrip")) { 
			SetObjectTexture(2,"");
		}

		if (FindAttachmentBySlotName("weaponFlashlight")) { 
			SetObjectTexture(3,"");
		}

		if (FindAttachmentBySlotName("weaponFlashlight2")) { 
			SetObjectTexture(4,"");
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
			SetObjectTexture(GetHiddenSelectionIndex("grip"),"");
			return;
		}

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\Honeybadger\\data\\camo_gun_co.paa"); //pic
			return;
		}

		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,"RearmedServer\\Firearms\\Honeybadger\\data\\camo_gun_co.paa"); //pic
			return;
		}

		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(4,"RearmedServer\\Firearms\\Honeybadger\\data\\camo_gun_co.paa"); //pic
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
			SetObjectTexture(GetHiddenSelectionIndex("grip"),"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(2,""); //pic
			return;
		}

		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,""); //pic
			return;
		}

		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(4,""); //pic
			return;
		}

		if (ItemOptics.Cast(item))
		{
			SetAnimationPhase("rotate", 0);
			return;
		}
	}
	#endif

	override bool CanBeInspected()
	{
		return true;
	}
};

class RA_HoneyBadger : RA_HoneyBadger_Base {};
class RA_HoneyBadger_Grey : RA_HoneyBadger_Base {};
class RA_HoneyBadger_Green : RA_HoneyBadger_Base {};