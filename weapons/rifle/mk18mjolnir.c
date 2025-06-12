class RA_Mk18Mjolnir_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}


	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
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

		if (slotId == InventorySlots.GetSlotIdFromString("weaponOpticsHunting"))
		{
			if ( FindAttachmentBySlotName("weaponOpticsHunting") != NULL || FindAttachmentBySlotName("weaponOptics") == NULL)
			{
				return true;
			};
			if ( FindAttachmentBySlotName("weaponOpticsHunting") == NULL || FindAttachmentBySlotName("weaponOptics") != NULL)
			{
				return false;
			};
		};
		
		if (slotId == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
			if ( FindAttachmentBySlotName("weaponOptics") != NULL || FindAttachmentBySlotName("weaponOpticsHunting") == NULL)
			{
				return true;
			};
			if ( FindAttachmentBySlotName("weaponOptics") == NULL || FindAttachmentBySlotName("weaponOpticsHunting") != NULL)
			{
				return false;
			};
		};
        return true;
    }
/*
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(1,""); //grip
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(1,""); //grip
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\Kivaari\\data\\Grip_co.paa"); //grip
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\Kivaari\\data\\Grip_co.paa"); //grip
			return;
		}
	}
*/
};

class RA_Mk18Mjolnir_Black : RA_Mk18Mjolnir_Base {};
class RA_Mk18Mjolnir_Tan : RA_Mk18Mjolnir_Base {};
class RA_Mk18Mjolnir_Green : RA_Mk18Mjolnir_Base {};
