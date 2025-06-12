class RA_ASVAL_Base : RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new VSSRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_ASVAL_Black");

		return m_SprayPaintEntry;
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
		Rotor_43 rotor = Rotor_43.Cast(FindAttachmentBySlotName("weaponButtstockVAL"));
		if (rotor) { 
			SetObjectTexture(3,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (Rotor_43.Cast(item))
		{
			SetObjectTexture(3,"");
		}
	}
	#endif

    override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        if (slotId == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
			if (FindAttachmentBySlotName("Rail"))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("Rail"))
		{
			if (FindAttachmentBySlotName("weaponOpticsAK"))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
			if (!FindAttachmentBySlotName("Rail"))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponValSuppressor"))
		{
			if (attachment.FindAttachmentBySlotName("weaponForegrip"))
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
            return (FindAttachmentBySlotName("Rail") != NULL);
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
            return (!FindAttachmentBySlotName("Rail"));
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("Rail"))
		{
            return (!FindAttachmentBySlotName("weaponOpticsAK"));
		}
        return super.CanDisplayAttachmentSlot(slot_id);
    }
}

class RA_ASVAL: RA_ASVAL_Base
{
	#ifndef SERVER
	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (Rotor_43.Cast(item))
		{
			SetObjectTexture(3,"RearmedServer\\Firearms\\ASVAL\\data\\Grip_co.paa");
		}
	}
	#endif
};

class RA_ASVAL_Black: RA_ASVAL_Base
{
	#ifndef SERVER
	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (Rotor_43.Cast(item))
		{
			SetObjectTexture(3,"RearmedServer\\Firearms\\ASVAL\\data\\Grip_Black_co.paa");
		}
	}
	#endif
};