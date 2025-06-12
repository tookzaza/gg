class RA_SVD_Base : RifleBoltLock_Base
{
    override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}

	override bool CanEnterIronsights()
	{
		ItemOptics optic = GetAttachedOptics();
		if (optic && PSO1Optic.Cast(optic) || PSO11Optic.Cast(optic) || KashtanOptic.Cast(optic) || KazuarOptic.Cast(optic) || RA_PSO_Optic.Cast(optic))
			return true;
		return super.CanEnterIronsights();
	}

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		if (FindAttachmentBySlotName("weaponButtstockSVD")) { 
			SetObjectTexture(1,"");
		}

		if (FindAttachmentBySlotName("weaponHandguardSVD")) { 
			SetObjectTexture(2,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (SVD_M4Adapter.Cast(item))
		{
			SetObjectTexture(1,"");
		}

		if (RA_Hndgrd_ChassisMK1_Base.Cast(item))
		{
			SetObjectTexture(2,"");
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (SVD_M4Adapter.Cast(item))
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\SVD\\data\\Stock_co.paa"); //stock
		}

		if (RA_Hndgrd_ChassisMK1_Base.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\SVD\\data\\DustCover_co.paa"); //DustCover/Handguard
		}
	}
	#endif

    override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
			if (!FindAttachmentBySlotName("Rail") && !FindAttachmentBySlotName("weaponHandguardSVD"))
			{
				return false;
			}
		}
        if (slotId == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
			if (FindAttachmentBySlotName("Rail")  || FindAttachmentBySlotName("weaponHandguardSVD"))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("Rail"))
		{
			if (FindAttachmentBySlotName("weaponOpticsAK") || FindAttachmentBySlotName("weaponHandguardSVD"))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponHandguardSVD"))
		{
			if (FindAttachmentBySlotName("weaponOpticsAK") || FindAttachmentBySlotName("Rail"))
			{
				return false;
			}
		}
        return true;
    }

    override bool CanDisplayAttachmentSlot(int slot_id)
    {
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
			if (!FindAttachmentBySlotName("Rail") && !FindAttachmentBySlotName("weaponHandguardSVD"))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
            if (FindAttachmentBySlotName("Rail") || FindAttachmentBySlotName("weaponHandguardSVD"))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("Rail"))
		{
            if (FindAttachmentBySlotName("weaponOpticsAK") || FindAttachmentBySlotName("weaponHandguardSVD"))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponHandguardSVD"))
		{
            if (FindAttachmentBySlotName("weaponOpticsAK") || FindAttachmentBySlotName("Rail"))
			{
				return false;
			}
		}
        return super.CanDisplayAttachmentSlot(slot_id);
    }
}

class RA_SVD: RA_SVD_Base{}