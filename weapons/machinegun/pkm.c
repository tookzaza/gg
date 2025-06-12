class RA_PKM: RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MachineGunRecoil(this);
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
			SetObjectTexture(0,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (item.IsInherited(RA_AK_Pistol_Grip_Base))
		{
			SetObjectTexture(0,"");
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item,slot_name);

		if (item.IsInherited(RA_AK_Pistol_Grip_Base))
		{
			SetObjectTexture(0,"RearmedServer\\Firearms\\PKM\\data\\Grip\\Grip_co.paa");
		}
	}
	#endif
}
