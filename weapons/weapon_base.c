modded class Weapon_Base
{
	bool CanBeInspected()
	{
		return false;
	}
	
	override void EEFired(int muzzleType, int mode, string ammoType)
	{
		if (!IsCorrectAmmoType())
        {
            AddHealth(-1500);
			#ifndef SERVER
			SEffectManager.PlaySound("Crash_MetalPlank_SoundSet", GetPosition());
            ParticleManager.GetInstance().PlayInWorld(ParticleList.WRONG_AMMO_USE, GetPosition()); //GetMemoryPointPos("nabojnicestart")
			#endif
        }
		super.EEFired(muzzleType, mode, ammoType);
	}

	bool IsCorrectAmmoType()
    {
        //Manually need to define bulletType in the firearm if there's potential for 300blk to be loaded via a magazine
        string weaponAmmoTypeName = ConfigGetString("bulletType"); 
        if (weaponAmmoTypeName == string.Empty) { 
            return true;
        }

        string chamberedAmmoTypeName;
        float chamberedAmmoDmg;
        GetCartridgeInfo(0, chamberedAmmoDmg, chamberedAmmoTypeName);
		if (chamberedAmmoTypeName == string.Empty) {
			return true;
		}

        return (chamberedAmmoTypeName == weaponAmmoTypeName || chamberedAmmoTypeName == weaponAmmoTypeName+"Tracer");    
    }

	override void AssembleGun()
	{
		super.AssembleGun();
		
		//@ Integrated bipod handling
		if (HasIntegratedBipod() && !FindAttachmentBySlotName("weaponBipod")) {
			GetInventory().CreateAttachment(GetIntegratedBipodType());
		}
	}
	
	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if (HasIntegratedBipod() && attachment.IsKindOf(GetIntegratedBipodType())) {
			return false;
		}
		
		return super.CanReleaseAttachment(attachment);
	}
	
	override bool CanDisplayAttachmentSlot(int slot_id)
    {
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
            return (!FindAttachmentBySlotName("weaponOpticsHunting"));
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsHunting"))
		{
            return (FindAttachmentBySlotName("weaponOpticsHunting") != NULL);
		}
		
		if (HasIntegratedBipod() && slot_id == InventorySlots.GetSlotIdFromString("weaponBipod")) {
			return false;
		}
		
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponMagnifier")) {
            ItemOptics compatible_optic = ItemOptics.Cast(FindAttachmentBySlotName("weaponOptics"));
			if (!compatible_optic) {
				return false;
			}

			foreach (typename required_attachment_type: OpticMagnifier_Base.REQUIRED_ATTACHMENT_TYPES) {
				if (compatible_optic.IsInherited(required_attachment_type)) {
					return true;
				}
			}
			
			return false;
		}
		
		return super.CanDisplayAttachmentSlot(slot_id);
	}
	
	// vanilla fix for multiple optics
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
		if (ItemOptics.Cast(attachment) && (FindAttachmentBySlotName("weaponOptics") || FindAttachmentBySlotName("weaponOpticsAK") || FindAttachmentBySlotName("weaponOpticsHunting"))) {
		    return false;
		}

        return super.CanReceiveAttachment(attachment, slotId);
    }
	
	RA_Bipod_Base FindBipod()
	{
		array<EntityAI> items = {};
		if (!GetInventory().EnumerateInventory(InventoryTraversalType.INORDER, items)) {
			return null;
		}
		
		foreach (EntityAI item: items) {
			if (item.IsInherited(RA_Bipod_Base)) {
				return RA_Bipod_Base.Cast(item);
			}
		}
		
		return null;
	}
		
	RA_Switchable_Base FindSwitchable()
	{
		RA_Switchable_Base switchable_item = RA_Switchable_Base.Cast(GetAttachmentByType(RA_Switchable_Base));
		if (switchable_item) {
			return switchable_item;
		}
		
		RA_Hndgrd_Base handguard = RA_Hndgrd_Base.Cast(GetAttachmentByType(RA_Hndgrd_Base));
		if (handguard) {
			switchable_item = RA_Switchable_Base.Cast(handguard.GetAttachmentByType(RA_Switchable_Base));
			if (switchable_item) {
				return switchable_item;
			}
		}
		
		return null;
	}

	void ToggleSwitchables()
	{
		array<EntityAI> items = {};
		if (!GetInventory().EnumerateInventory(InventoryTraversalType.INORDER, items)) {
			return;
		}
		
		foreach (EntityAI item: items) {
			RA_Switchable_Base switchable = RA_Switchable_Base.Cast(item);
			if (switchable) {
				if(!switchable.IsEnabled()) {
					switchable.SetEnabled(true);
				}
				else {
					switchable.SetEnabled(false);
				}
			}
		}
	}
	
	bool IsBipodDeployed()
	{
		RA_Bipod_Base bipod = FindBipod();
		if (!bipod) {
			return false;
		}
		
		return bipod.IsDeployed();
	}
	
	vector GetBarrelStart()
	{
		return GetSelectionPositionWS("konec hlavne");
	}
	
	vector GetBarrelEnd()
	{
		return GetSelectionPositionWS("usti hlavne");
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionToggleBipod);
		AddAction(ActionZoomInMagnifier);
		AddAction(ActionZoomOutMagnifier);
		AddAction(ActionInspectWeapon);
		AddAction(ActionToggleLight);

		RemoveAction(ActionTurnOnWeaponFlashlight);
		RemoveAction(ActionTurnOffWeaponFlashlight);
	}
	
	int GetFireRate()
	{		
		float fire_rate = g_Game.ConfigGetFloat(string.Format("CfgWeapons %1 FullAuto reloadTime", GetType()));
		if (fire_rate <= 0) {
			return 0;
		}
		
		return (int)(1 / fire_rate * 60);
	}
	
	bool HasIntegratedBipod()
	{
		return ConfigIsExisting("integratedBipod");
	}
	
	string GetIntegratedBipodType()
	{
		return ConfigGetString("integratedBipod");
	}
}