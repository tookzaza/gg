class RA_Kivaari_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Kivaari_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Kivaari_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Kivaari_Tan");

		return m_SprayPaintEntry;
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

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		ItemBase stock = ItemBase.Cast(FindAttachmentBySlotName("weaponButtstockM4"));
		if (FindAttachmentBySlotName("weaponPistolGrip") || stock && stock.IsInherited(RA_CQR_Bttstck)) { 
			SetObjectTexture(1,"");
		}

		if (stock && stock.IsInherited(UBR_Bttstck_Base) || stock.IsInherited(RA_CQB7_Bttstck_Base) || stock.IsInherited(M16A2_Bttstck_Base))
		{
			SetObjectTexture(2,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(1,""); //grip
			return;
		}

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(2,"");
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

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\M4A1\\data\\Buffer_co.paa");
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\Kivaari\\data\\Grip_co.paa"); //grip
			return;
		}
	}
	#endif
};

class RA_Kivaari_Black : RA_Kivaari_Base {};
class RA_Kivaari_Tan : RA_Kivaari_Base {};
class RA_Kivaari_Green : RA_Kivaari_Base {};
