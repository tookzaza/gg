class SR25_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{		
		return new SvdRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "SR25_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "SR25_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "SR25_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "SR25_Snow");

		return m_SprayPaintEntry;
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
			SetObjectTexture(3,"");
		}

		if (stock && stock.IsInherited(UBR_Bttstck_Base) || stock.IsInherited(RA_CQB7_Bttstck_Base) || stock.IsInherited(M16A2_Bttstck_Base))
		{
			SetObjectTexture(2,"");
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardAR10"));
		ItemOptics optic = ItemOptics.Cast(FindAttachmentBySlotName("weaponOptics"));
		if (handgrd && optic && !optic.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);
		
		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(3,""); //grip
			return;
		}

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(2,"");
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(3,""); //grip
			return;
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardAR10"));
		ItemOptics optic = ItemOptics.Cast(item);
		if (handgrd && optic && !optic.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 1);
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(3,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}

		if (UBR_Bttstck_Base.Cast(item) || RA_CQB7_Bttstck_Base.Cast(item) || M16A2_Bttstck_Base.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\M4A1\\data\\Buffer_co.paa");
			return;
		}
		
		if (RA_CQR_Bttstck.Cast(item))
		{
			SetObjectTexture(3,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
			return;
		}

		RA_Hndgrd_Base handgrd = RA_Hndgrd_Base.Cast(FindAttachmentBySlotName("weaponHandguardAR10"));
		ItemOptics optic = ItemOptics.Cast(item);
		if (handgrd && optic && !optic.IsInherited(RA_RearSight_Base))
		{
			handgrd.SetAnimationPhase("rotate", 0);
		}
	}
	#endif
};