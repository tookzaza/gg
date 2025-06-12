class RA_AK12_Base: AKM_Base
{
    override RecoilBase SpawnRecoilObject()
	{
		return new Ak74Recoil(this);
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
			SetObjectTexture(1,"RearmedServer\\Firearms\\AKM\\data\\Grip_co.paa"); //grip
		}
	}
	#endif
};