class RA_DVL_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ527Recoil(this);
	}

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		if (FindAttachmentBySlotName("weaponMuzzleDVL")) { 
			SetObjectTexture(5,"");
		}

		if (FindAttachmentBySlotName("weaponPistolGrip")) { 
			SetObjectTexture(4,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (SuppressorBase.Cast(item))
		{ 
			SetObjectTexture(5,""); //normal barrel
			return;
		}

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(4,""); //grip
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (SuppressorBase.Cast(item))
		{ 
			SetObjectTexture(5,"RearmedServer\\Firearms\\DVL\\data\\Barrel_co.paa"); //normal barrel
			return;
		}

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(4,"RearmedServer\\Firearms\\DVL\\data\\Lower_co.paa"); //grip
			return;
		}
	}
	#endif
};
class RA_DVL: RA_DVL_Base{};