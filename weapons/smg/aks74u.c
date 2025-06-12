class RA_AKS74U_Base: RifleBoltFree_Base
{
    override RecoilBase SpawnRecoilObject()
	{
		return new Aks74uRecoil(this);
	}

	#ifndef SERVER
	void RA_AKS74U_Base()
	{
		SetObjectTexture(1,"RearmedServer\\Firearms\\AKS74U\\data\\AKS74U_co.paa");
	}
	#endif

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
		if (FindAttachmentBySlotName("weaponPistolGripAK")) { 
			SetObjectTexture(1,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (RA_AK_Pistol_Grip_Base.Cast(item))
		{
			SetObjectTexture(1,"");
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (RA_AK_Pistol_Grip_Base.Cast(item))
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\AKS74U\\data\\AKS74U_co.paa"); //grip
		}
	}
	#endif

    override bool CanReceiveAttachment( EntityAI attachment, int slotId )
    {
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
			if (FindAttachmentBySlotName("Rail") || RA_AKS74U_CAAHndgrd_RIS.Cast(FindAttachmentBySlotName("weaponHandguardAKSU")))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOpticsHandguard"))
		{
			if (!FindAttachmentBySlotName("weaponHandguardAKSU") || !FindAttachmentBySlotName("weaponHandguardAKSU").ConfigGetBool("hasOpticFunctionality"))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOpticsCover"))
		{
			if (!FindAttachmentBySlotName("Rail") || !RA_AKS74u_RIS_Mount.Cast(FindAttachmentBySlotName("Rail")))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("Rail"))
		{
			if (FindAttachmentBySlotName("weaponOpticsAK") || RA_AKS74U_CAAHndgrd_RIS.Cast(FindAttachmentBySlotName("weaponHandguardAKSU")))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
			if (!FindAttachmentBySlotName("Rail") || !FindAttachmentBySlotName("weaponHandguardAKSU") || !RA_AKS74U_CAAHndgrd_RIS.Cast(FindAttachmentBySlotName("weaponHandguardAKSU")))
			{
				return false;
			}
		}
        return super.CanReceiveAttachment(attachment, slotId);
    }

    override bool CanDisplayAttachmentSlot(int slot_id)
    {
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
            if (FindAttachmentBySlotName("Rail") || RA_AKS74U_CAAHndgrd_RIS.Cast(FindAttachmentBySlotName("weaponHandguardAKSU")))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsHandguard"))
		{
            if (!FindAttachmentBySlotName("weaponHandguardAKSU") || !FindAttachmentBySlotName("weaponHandguardAKSU").ConfigGetBool("hasOpticFunctionality"))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsCover"))
		{
            if ((FindAttachmentBySlotName("Rail") == NULL) || !RA_AKS74u_RIS_Mount.Cast(FindAttachmentBySlotName("Rail")))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("Rail"))
		{
            if (FindAttachmentBySlotName("weaponOpticsAK") || RA_AKS74U_CAAHndgrd_RIS.Cast(FindAttachmentBySlotName("weaponHandguardAKSU")))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
            if (!FindAttachmentBySlotName("Rail") || !FindAttachmentBySlotName("weaponHandguardAKSU") || !RA_AKS74U_CAAHndgrd_RIS.Cast(FindAttachmentBySlotName("weaponHandguardAKSU")))
			{
				return false;
			}
		}	
        return super.CanDisplayAttachmentSlot(slot_id);
    }
};