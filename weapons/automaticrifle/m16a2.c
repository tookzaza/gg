class RA_M16A1_Base: RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId )
    {
		if (ItemOptics.Cast(attachment))
        {
            return FindAttachmentBySlotName("weaponM16Adapter") != NULL;
        }

		if (RA_CQR_Bttstck.Cast(attachment))
        {
            return false;
        }

		RA_Hndgrd_Base hg = RA_Hndgrd_Base.Cast(attachment);
		if (hg && !hg.IsLong())
        {
            return false;
        }
		
        return super.CanReceiveAttachment(attachment, slotId);
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
			SetObjectTexture(1,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\M4A1\\data\\Buffer_co.paa");
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}
	}
	#endif
};
class RA_M16A1: RA_M16A1_Base{};