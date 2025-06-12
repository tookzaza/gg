class RA_MP153_Base: ChamberFirst_InnerMagazine_SemiAutomatic_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Mp133Recoil(this);
	}

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		if (FindAttachmentBySlotName("MossbergStock")) {
			SetObjectTexture(1,"");
		}

		if (FindAttachmentBySlotName("MP153Forearm")) {
			SetObjectTexture(2,"");
		}

		RA_Mossberg_Shroud_Rail shroud = RA_Mossberg_Shroud_Rail.Cast(FindAttachmentBySlotName("MossbergOpticMount"));
		if (shroud) { 
			SetAnimationPhase("translation", 1);
		}
	}

	// magic insert here
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (RA_Mossberg_Shroud_Rail.Cast(item))
		{
			SetAnimationPhase("translation", 1);
		}		

		if (RA_Mossberg_Buttstock_Base.Cast(item))
		{
			SetObjectTexture(1,"");
			SetObjectMaterial(1,"");
		}

		if (RA_MP153_Forearm_Plastic.Cast(item))
		{
			SetObjectTexture(2,"");
			SetObjectMaterial(2,"");
		}
	}
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item,slot_name);	

		if (RA_Mossberg_Shroud_Rail.Cast(item))
		{
			SetAnimationPhase("translation", 0);
		}

		if (RA_Mossberg_Buttstock_Base.Cast(item))
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\Mossberg\\data\\camo_pistolgrip_2_co.paa");
			SetObjectMaterial(1,"RearmedServer\\Firearms\\Mossberg\\data\\camo_pistolgrip_2.rvmat");
		}

		if (RA_MP153_Forearm_Plastic.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\MP153\\data\\camo_mp153_co.paa");
			SetObjectMaterial(2,"RearmedServer\\Firearms\\MP153\\data\\camo_mp153.rvmat");
		}
	}	
	#endif

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (attachment.IsInherited(ItemOptics)) {
			return FindAttachmentBySlotName("MossbergOpticMount") != NULL;
		}

        return super.CanReceiveAttachment(attachment, slotId);
	}

	override bool CanDisplayAttachmentSlot(string slot_name)
    {    
        if (slot_name == "weaponOptics") {
            return FindAttachmentBySlotName("MossbergOpticMount") != NULL;    
        }

        return super.CanDisplayAttachmentSlot(slot_name);
    } 
};  
class RA_MP153: RA_MP153_Base {};

class RA_MP153_Forearm_Plastic: ItemBase {}