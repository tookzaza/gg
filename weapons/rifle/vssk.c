class RA_VSSK_Base : RifleBoltFree_Base
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
		if (FindAttachmentBySlotName("weaponOptics")) { 
			SetObjectTexture(2,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (ItemOptics.Cast(item)) { 
			SetObjectTexture(2,"");
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item,slot_name);

		if (ItemOptics.Cast(item)) { 
			SetObjectTexture(2,"RearmedServer\\Firearms\\ASH12\\data\\ASH12_co.paa");
			return;
		}
	}
	#endif
};