class RA_AK74_Base: RifleBoltFree_Base
{
    override RecoilBase SpawnRecoilObject()
	{
		return new Ak74Recoil(this);
	}

    override bool CanEnterIronsights()
	{
		ItemOptics optic = GetAttachedOptics();
		if ( optic && PSO1Optic.Cast(optic) || PSO11Optic.Cast(optic) || KashtanOptic.Cast(optic) || KazuarOptic.Cast(optic) || RA_PSO_Optic.Cast(optic))
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
		if (FindAttachmentBySlotName("weaponPistolGripAK")) { 
			SetObjectTexture(2,"");
		}

		RA_AK_Sport4_Handguard sport4 = RA_AK_Sport4_Handguard.Cast(FindAttachmentBySlotName("weaponHandguardAK"));
		if (sport4) { 
			SetObjectTexture(3,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (RA_AK_Pistol_Grip_Base.Cast(item))
		{
			SetObjectTexture(2,"");
		}

		if (RA_AK_Sport4_Handguard.Cast(item))
		{
			SetObjectTexture(3,"");
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (RA_AK_Pistol_Grip_Base.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\AKM\\data\\Grip_co.paa"); //grip
		}

		if (RA_AK_Sport4_Handguard.Cast(item))
		{
			SetObjectTexture(3,"RearmedServer\\Firearms\\AK74\\data\\Barrel_co.paa"); //tube
		}
	}
	#endif

    override bool CanReceiveAttachment( EntityAI attachment, int slotId )
    {
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
			if (FindAttachmentBySlotName("Rail") || RailDustCover_Base.Cast(FindAttachmentBySlotName("weaponCoverAK")))
			{
				return false;
			}
		}
		if (RailDustCover_Base.Cast(attachment))
		{
			if (FindAttachmentBySlotName("Rail") || FindAttachmentBySlotName("weaponOpticsAK"))
			{
				return false;
			}
			if (RA_AK_B33Receiver.Cast(attachment) && !Zenit_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardAK")))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOpticsHandguard"))
		{
			if (!FindAttachmentBySlotName("weaponHandguardAK") || !FindAttachmentBySlotName("weaponHandguardAK").ConfigGetBool("hasOpticFunctionality"))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOpticsCover"))
		{
			if (!FindAttachmentBySlotName("weaponCoverAK") || !FindAttachmentBySlotName("weaponCoverAK").ConfigGetBool("hasOpticFunctionality"))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("Rail"))
		{
			if (FindAttachmentBySlotName("weaponOpticsAK") || RailDustCover_Base.Cast(FindAttachmentBySlotName("weaponCoverAK")))
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
        return super.CanReceiveAttachment(attachment, slotId);
    }

    override bool CanDisplayAttachmentSlot(int slot_id)
    {
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
            return (FindAttachmentBySlotName("Rail") != NULL);
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
			if (FindAttachmentBySlotName("Rail") != NULL)
			{
				return false;
			}
			
			if (FindAttachmentBySlotName("weaponCoverAK") && RailDustCover_Base.Cast(FindAttachmentBySlotName("weaponCoverAK")))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsCover"))
		{
			if (!FindAttachmentBySlotName("weaponCoverAK") || !RailDustCover_Base.Cast(FindAttachmentBySlotName("weaponCoverAK")))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsHandguard"))
		{
			if (!FindAttachmentBySlotName("weaponHandguardAK") || !FindAttachmentBySlotName("weaponHandguardAK").ConfigGetBool("hasOpticFunctionality"))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("Rail"))
		{
			if (FindAttachmentBySlotName("weaponOpticsAK") != NULL)
			{
				return false;
			}

			if (FindAttachmentBySlotName("weaponCoverAK") || RailDustCover_Base.Cast(FindAttachmentBySlotName("weaponCoverAK")))
			{
				return false;
			}
		}
        return super.CanDisplayAttachmentSlot(slot_id);
    }
};