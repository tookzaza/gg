class RA_M14_Base: RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOptics") || slotId == InventorySlots.GetSlotIdFromString("weaponOpticsHunting") && !FindAttachmentBySlotName("weaponDMRAdapter"))
		{
			return true;
		}
		return super.CanReceiveAttachment(attachment, slotId);
	}

	override bool CanDisplayAttachmentSlot(string slot_name)
	{
		if (slot_name == "weaponOptics")
		{
            return (FindAttachmentBySlotName("weaponDMRAdapter") && FindAttachmentBySlotName("weaponOpticsHunting") == NULL);
		}
		if (slot_name == "weaponOpticsHunting")
		{
            return (FindAttachmentBySlotName("weaponDMRAdapter") && FindAttachmentBySlotName("weaponOpticsHunting") != NULL);
		}
		return true;
	}
};
class RA_M14_DMR_Base: RA_M14_Base{};