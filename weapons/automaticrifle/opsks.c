class RA_OPSKS_Base : RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SKSRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_OPSKS_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_OPSKS_Tan");

		return m_SprayPaintEntry;
	}

	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
    {
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
			if (FindAttachmentBySlotName("SKSRail"))
			{
				return true;
			}
			return false;
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponBipod"))
		{
			if (FindAttachmentBySlotName("weaponForegrip"))
			{
				return false;
			}
			return true;
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponForegrip"))
		{
			if (FindAttachmentBySlotName("weaponBipod"))
			{
				return false;
			}
			return true;
		}
        return true;
    }
}