class RA_M4A1_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_M4A1");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M4A1_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_M4A1_Green");

		return m_SprayPaintEntry;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId )
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

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardM4"));
		if (handgrd && handgrd.IsLong())
		{
			SetObjectTexture(3,""); //gasblock M4 Specific
		}

		ItemOptics optic = ItemOptics.Cast(FindAttachmentBySlotName("weaponOptics"));
		if (handgrd && handgrd.IsLong() && optic && !optic.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		RA_Hndgrd_Base hg = RA_Hndgrd_Base.Cast(item);
		if (hg && hg.IsLong())
		{
			SetObjectTexture(3,""); //gasblock M4 Specific
			return;
		}
		
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

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardM4"));
		if (handgrd && handgrd.IsLong() && ItemOptics.Cast(item) && !item.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		RA_Hndgrd_Base hg = RA_Hndgrd_Base.Cast(item);
		if (hg && hg.IsLong())
		{
			SetObjectTexture(3,"RearmedServer\\Firearms\\M4A1\\data\\GasBlock_co.paa"); //gasblock
			return;
		}

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(4,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(6,"RearmedServer\\Firearms\\M4A1\\data\\Buffer_co.paa");
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(4,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardM4"));
		if (handgrd && handgrd.IsLong() && ItemOptics.Cast(item) && !item.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 0);
		}
	}
	#endif

	override bool CanBeInspected()
	{
		return true;
	}

	override void OnDebugSpawn()
	{
		
		GetInventory().CreateInInventory("RA_Hndgrd_MK16_13_Black");
	}
};

class RA_M4A1 : RA_M4A1_Base {};

class RA_AR15 : RA_M4A1
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AR15");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AR15_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_AR15_Green");

		return m_SprayPaintEntry;
	}
};