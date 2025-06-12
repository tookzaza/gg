class RA_Galil_Base: RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new AkmRecoil(this);
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        if (slotId == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
			return (FindAttachmentBySlotName("weaponGalilAdapter") != NULL);
		}
        return super.CanReceiveAttachment(attachment, slotId);
    }

	override bool CanDisplayAttachmentSlot(int slot_id)
    {
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
            return (FindAttachmentBySlotName("weaponGalilAdapter") != NULL);
		}
        return super.CanDisplayAttachmentSlot(slot_id);
    }
}; 