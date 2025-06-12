class RA_MK12_Base: RifleBoltLock_Base
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
		ItemBase stock = ItemBase.Cast(FindAttachmentBySlotName("weaponButtstockM4"));
		if (FindAttachmentBySlotName("weaponPistolGrip") || stock && stock.IsInherited(RA_CQR_Bttstck)) { 
			SetObjectTexture(2,"");
		}

		if (stock && stock.IsInherited(UBR_Bttstck_Base) || stock.IsInherited(RA_CQB7_Bttstck_Base) || stock.IsInherited(M16A2_Bttstck_Base))
		{
			SetObjectTexture(1,"");
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardM4"));
		ItemOptics optic = ItemOptics.Cast(FindAttachmentBySlotName("weaponOptics"));
		if (handgrd && handgrd.IsLong() && optic && !optic.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);
		
		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(2,""); //grip
			return;
		}

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(1,"");
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(2,""); //grip
			return;
		}
		
		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardM4"));
		if (handgrd && handgrd.IsLong() && ItemOptics.Cast(item) && !item.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(1,"RearmedServer\\Firearms\\M4A1\\data\\Buffer_co.paa");
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardM4"));
		if (handgrd && handgrd.IsLong() && ItemOptics.Cast(item) && !item.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 0);
		}
	}
	#endif
};
class RA_MK12: RA_MK12_Base{};