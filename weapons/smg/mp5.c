class RA_MP5_Base : RifleBoltFree_Base
{	
	override RecoilBase SpawnRecoilObject()
	{
		return new Mp5kRecoil(this);
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        if (ItemOptics.Cast(attachment))
        {
            if (!FindAttachmentBySlotName("MP5Rail"))
            {
                return false;
            }
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
		if (FindAttachmentBySlotName("weaponButtstockMP5")) { 
			SetObjectTexture(2,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item, slot_name);
		
		if (item.IsInherited(RA_MP5_Buttstock))
		{
			SetObjectTexture(2,""); //cap
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (item.IsInherited(RA_MP5_Buttstock))
		{
			SetObjectTexture(2,"rearmedserver\\firearms\\mp5\\data\\cap_co.paa"); //cap
			return;
		}
	}
	#endif
};