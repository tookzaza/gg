class RA_AA12_Base : Saiga_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SiagaRecoil(this);
	}

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		if (FindAttachmentBySlotName("weaponMuzzleShotGun") ) { 
			SetObjectTexture(2,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (ItemSuppressor.Cast(item))
		{
			SetObjectTexture(2,"");
		}	
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (ItemSuppressor.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\AA12\\Data\\AA12_co.paa");
		}	
	}
	#endif
};  
class RA_AA12: RA_AA12_Base {};