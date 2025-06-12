class RA_G36_Base : RifleBoltLock_Base
{	
	override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
	}

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		if (FindAttachmentBySlotName("weaponOptics")) { 
			SetObjectTexture(2,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (RA_G36_Optic.Cast(item)) { 
			SetObjectTexture(2,""); //carryhandle
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (RA_G36_Optic.Cast(item)) { 
			SetObjectTexture(2,"RearmedServer\\Firearms\\G36\\data\\G36_co.paa"); //carryhandle
			return;
		}

	}
	#endif
};
class RA_G36: RA_G36_Base{};