class RA_L85_Base: RifleBoltFree_Base
{
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

		if (FindAttachmentBySlotName("weaponHandguardL85")) { 
			SetObjectTexture(3,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);	
		
		if (ItemOptics.Cast(item))
		{ 
			SetObjectTexture(2, "");
		}	
		if (slot_name == "weaponHandguardL85")
		{ 
			SetObjectTexture(3, "");
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item,slot_name);	
		
		if (ItemOptics.Cast(item))
		{ 
			SetObjectTexture(2, "RearmedServer\\Firearms\\L85\\data\\Iron_Carryhandle_co.paa");
		}	
		if (slot_name == "weaponHandguardL85")
		{ 
			SetObjectTexture(3, "RearmedServer\\Firearms\\L85\\data\\A1Handguard_co.paa");
		}
	}
	#endif	
	
	override RecoilBase SpawnRecoilObject()
	{
		return new AUGRecoil(this);
	}
	
};
class RA_L85: RA_L85_Base {};