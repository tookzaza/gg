class RA_HK416_Base : RifleBoltLock_Base
{	
	override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_HK416");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_HK416_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_HK416_Green");

		return m_SprayPaintEntry;
	}

	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
    {
		if (RA_M4_Pistol_Grip_Base.Cast(attachment))
        {
            if (FindAttachmentBySlotName("WeaponButtstockM4"))
            {
                return !RA_CQR_Bttstck.Cast(FindAttachmentBySlotName("WeaponButtstockM4"));
            }
            return true;
        }
		if (RA_CQR_Bttstck.Cast(attachment))
        {
            if (FindAttachmentBySlotName("weaponPistolGrip"))
            {
                return false;
            }
            return true;
        }
        return true;
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
			SetObjectTexture(4,"");
		}

		if (stock && stock.IsInherited(UBR_Bttstck_Base) || stock.IsInherited(RA_CQB7_Bttstck_Base) || stock.IsInherited(M16A2_Bttstck_Base))
		{
			SetObjectTexture(6,"");
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardHK"));
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
			SetObjectTexture(4,""); //grip
			return;
		}

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(6,"");
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(4,""); //grip
			return;
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardHK"));
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
			SetObjectTexture(4,"RearmedServer\\Firearms\\HK416\\data\\Grip_co.paa"); //grip
			return;
		}

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(6,"RearmedServer\\Firearms\\HK416\\data\\Buffer_co.paa");
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(4,"RearmedServer\\Firearms\\HK416\\data\\Grip_co.paa"); //grip
			return;
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardHK"));
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
}

class RA_HK416 : RA_HK416_Base{};