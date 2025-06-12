class RA_9A91_Base : RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new VSSRecoil(this);
	}

	override bool CanEnterIronsights()
	{
		ItemOptics optic = GetAttachedOptics();
		if ( optic && PSO1Optic.Cast(optic) || PSO11Optic.Cast(optic) || KashtanOptic.Cast(optic) || KazuarOptic.Cast(optic) || RA_PSO_Optic.Cast(optic))
			return true;
		return super.CanEnterIronsights();
	}

	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
    {
        if ( slotId == InventorySlots.GetSlotIdFromString("weaponOpticsAK") )
		{
			if ( FindAttachmentBySlotName("Rail") == NULL )
			{
				return true;
			}
			return false;
		}
		if ( slotId == InventorySlots.GetSlotIdFromString("Rail") )
		{
			if ( FindAttachmentBySlotName("weaponOpticsAK") == NULL )
			{
				return true;
			}
			return false;
		}
		if ( slotId == InventorySlots.GetSlotIdFromString("weaponOptics") )
		{
			if ( FindAttachmentBySlotName("Rail") != NULL )
			{
				return true;
			}
			return false;
		}
        return true;
    }

    override bool CanDisplayAttachmentSlot(int slot_id)
    {
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
            return (FindAttachmentBySlotName("Rail") != NULL);
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
            return (FindAttachmentBySlotName("Rail") == NULL);
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("Rail"))
		{
            return (FindAttachmentBySlotName("weaponOpticsAK") == NULL);
		}
        return super.CanDisplayAttachmentSlot(slot_id);
    }
}

class RA_9A91 : RA_9A91_Base{};
