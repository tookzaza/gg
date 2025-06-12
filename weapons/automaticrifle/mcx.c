//zach forgive me for my coding sins
class RA_MCX_Base: RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
	}

	/*override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_M4A1");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M4A1_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_M4A1_Green");

		return m_SprayPaintEntry;
	}
    */

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		if (FindAttachmentBySlotName("weaponPistolGrip")) { 
			SetObjectTexture(3,"");
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardMCX"));
		ItemOptics optic = ItemOptics.Cast(FindAttachmentBySlotName("weaponOptics"));
		if (handgrd && optic && !optic.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(3,""); //grip
			return;
		}
		
		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardMCX"));
		if (handgrd && ItemOptics.Cast(item) && !item.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(3,"RearmedServer\\Firearms\\MCX\\data\\LVAW_GRIP_Black_co.paa"); //grip
			return;
		}


		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardMCX"));
		if (handgrd && ItemOptics.Cast(item) && !item.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 0);
		}
	}
	#endif

	override bool CanBeInspected()
	{
		return true;
	}
};
class RA_MCX_Grey: RA_MCX_Base{};
class RA_MCX_Black: RA_MCX_Base{};
class RA_MCX_OD: RA_MCX_Base{};
class RA_MCX_Tan: RA_MCX_Base{};
class RA_MCX_Rattle: RA_MCX_Base{};