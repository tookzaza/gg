class RA_M249_Base: RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MachineGunRecoil(this);
	}

	ref TStringArray simpleHiddenSelections = new TStringArray;

	override void EEInit()
	{
		super.EEInit();
		ConfigGetTextArray("simpleHiddenSelections", simpleHiddenSelections);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(UpdateMagBullets, 50, false, 0);
	}

	override void EEFired(int muzzleType, int mode, string ammoType)
	{
		super.EEFired(muzzleType, mode, ammoType);
		int mi = GetCurrentMuzzle();
		Magazine mag = GetMagazine(mi);
		if (mag && mag.GetAmmoCount() < 13)
		{
			ModHideBullet(13 - mag.GetAmmoCount());
		}

	}

	void WeaponCocked()
	{
		UpdateMagBullets(-1);
	}

	void ModHideBullet(int bullet)
	{
		string bulletName = "bullet" + bullet.ToString();
		int bullet_id = simpleHiddenSelections.Find(bulletName);
		if (bullet_id >= 0)
		{
			#ifndef SERVER
			SetSimpleHiddenSelectionState(bullet_id, false);
			#endif
		}
	}

	void MagazineAttached()
	{
		UpdateMagBullets();
	}

	void MagazineDetached()
	{
		UpdateMagBullets();
	}

	void UpdateMagBullets(int diff = 0)
	{
		int i;
		string bulletName;
		int bullet_id;
		for (i = 1; i <= 13; i++)
		{
			bulletName = "bullet" + i.ToString();
			bullet_id = simpleHiddenSelections.Find(bulletName);
			if (bullet_id >= 0)
			{
				#ifndef SERVER
				SetSimpleHiddenSelectionState(bullet_id, false);
				#endif
			}
		}
		int muzzleType = GetCurrentMuzzle();		
		Magazine mag = GetMagazine(muzzleType);

		if(!mag)
			return;

		int bbbcount = mag.GetAmmoCount();
		
		bbbcount += diff;

		if (bbbcount > 13)
		{
			bbbcount = 13;
		}

		for (i = 13 - bbbcount + 1; i <= 13; i++)
		{
			bulletName = "bullet" + i.ToString();
			bullet_id = simpleHiddenSelections.Find(bulletName);
			if (bullet_id >= 0)
			{
				#ifndef SERVER
				SetSimpleHiddenSelectionState(bullet_id, true);
				#endif
			}
		}
	}

	override void AssembleGun()
	{
		super.AssembleGun();
		
		if ( !FindAttachmentBySlotName("JDM249Body") )
		{
			GetInventory().CreateAttachment("JDM249Body");
		}
		if ( !FindAttachmentBySlotName("JDM249Cover") )
		{
			GetInventory().CreateAttachment("JDM249Cover");
		}
	}
}

modded class WeaponEventAnimCocked extends WeaponEventAnimation
{
    void WeaponEventAnimCocked (DayZPlayer p = NULL, Magazine m = NULL) 
	{ 
		PlayerBase player = PlayerBase.Cast(p);
		if (!player)
		{
			return;
		}
		RA_M249_Base m249 = RA_M249_Base.Cast(player.GetItemInHands());
		if (m249)
		{
			m249.WeaponCocked();
		}	
	}
};

modded class RA_M249_Magazine
{	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		RA_M249_Base weapon = RA_M249_Base.Cast(parent);
		if (weapon)
		{
			weapon.MagazineAttached();
		}
		super.OnWasAttached(parent, slot_id);
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{	
		RA_M249_Base weapon = RA_M249_Base.Cast(parent);
		if (weapon)
		{
			weapon.MagazineDetached();
		}
		super.OnWasDetached(parent, slot_id);
	}
}