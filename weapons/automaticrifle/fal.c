class RA_FAL_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{		
		return new FALRecoil(this);
	}
	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		if (FindAttachmentBySlotName("weaponPistolGripFAL")) { 
			SetObjectTexture(3,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (RA_FAL_Pistol_Grip_Base.Cast(item))
		{
			SetObjectTexture(3,"");
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (RA_FAL_Pistol_Grip_Base.Cast(item))
		{
			SetObjectTexture(3,"RearmedServer\\Firearms\\FAL\\data\\WoodGrip_co.paa"); //grip
		}
	}
	#endif
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        if (slotId == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
			return FindAttachmentBySlotName("weaponUpperFal") != NULL;
		}
        return super.CanReceiveAttachment(attachment, slotId);
    }
};
