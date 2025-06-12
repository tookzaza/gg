class RA_Hndgrd_Base: Inventory_Base
{
	bool IsLong()
	{
		return false;
	}

	override bool CanDetachAttachment(EntityAI parent)
	{
		if (ConfigGetBool("hasOpticFunctionality") && Weapon_Base.Cast(parent) && parent.FindAttachmentBySlotName("weaponOpticsHandguard"))
		{
			return false;
		}
		return true;
	}
};
class RA_PKM_ZenitB50Hndgrd_RIS: RA_Hndgrd_Base{};
class RA_Hndgrd_L85_RIS_Base: RA_Hndgrd_Base{};
class RA_Hndgrd_FAL_RIS: RA_Hndgrd_Base{};
class RA_Hndgrd_FAL_VLTOR: RA_Hndgrd_Base{};
class RA_AKS74U_ZenitB11PlasticHndgrd_RIS: RA_Hndgrd_Base{};
class Zenit_Hndgrd_Base: RA_Hndgrd_Base{};
class RA_AKS74U_CAAHndgrd_RIS: RA_Hndgrd_Base{};
class RA_AK12_Hndgrd: RA_Hndgrd_Base{};
class RA_AK_ZenitB30B31Hndgrd_RIS: Zenit_Hndgrd_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AK_ZenitB30B31Hndgrd_RIS");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AK_ZenitB30B31Hndgrd_RIS_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_AK_ZenitB10MB19Hndgrd_RIS: Zenit_Hndgrd_Base{};
class RA_AK_B10_B19_Hndgrd_Black: Zenit_Hndgrd_Base{};
class RA_AK_Sport4_Handguard: Zenit_Hndgrd_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AK_Sport4_Handguard");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AK_Sport4_Handguard_Tan");

		return m_SprayPaintEntry;
	}
	#ifndef SERVER
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);
		
		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail11_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(2,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
		if (slot_name == "weaponBipod")
		{
			SetObjectTexture(4,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,"");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(2,"");
			return;
		}
		if (slot_name == "weaponBipod")
		{
			SetObjectTexture(4,"");
			return;
		}
	}
	#endif
};
class RA_Hndgrd_AK_Polymer: RA_Hndgrd_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_AK_Polymer_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_AK_Polymer_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_Hndgrd_AK_Romanian: RA_Hndgrd_Base{};
class RA_6P29Mount: RA_Hndgrd_Base{};
class RA_6P29M: RA_Hndgrd_Base{};
class RA_CockRing: RA_Hndgrd_Base
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        if (slotId == InventorySlots.GetSlotIdFromString("weaponForegrip"))
		{
			InventoryLocation inventory_location = new InventoryLocation;
			GetInventory().GetCurrentInventoryLocation(inventory_location);	
			if (FindAttachmentBySlotName("weaponFlashlight") || inventory_location.GetSlot() == InventorySlots.GetSlotIdFromString("weaponValSuppressor"))
			{
				return false;
			}
		}
		if (slotId == InventorySlots.GetSlotIdFromString("weaponFlashlight") && FindAttachmentBySlotName("weaponForegrip"))
		{
			return false;
		}
        return super.CanReceiveAttachment(attachment, slotId);
    }
	override bool CanDisplayAttachmentSlot(int slot_id)
    {
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponForegrip"))
		{
			if (FindAttachmentBySlotName("weaponFlashlight"))
			{
				return false;
			}
			InventoryLocation inventory_location = new InventoryLocation;
			GetInventory().GetCurrentInventoryLocation(inventory_location);	
			if (inventory_location.GetSlot() == InventorySlots.GetSlotIdFromString("weaponValSuppressor"))
			{
				return false;
			}
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponFlashlight"))
		{
            return (FindAttachmentBySlotName("weaponForegrip") == NULL);
		}
        return super.CanDisplayAttachmentSlot(slot_id);
    }
	override bool CanPutAsAttachment(EntityAI parent)
	{
        if ((RA_9A91_Suppressor).Cast(parent) && FindAttachmentBySlotName("weaponForegrip"))
        {
            return false;
        }
        return super.CanPutAsAttachment(parent);
	}
};
class RA_M4_Handguard_Base: RA_Hndgrd_Base{};
class RA_Hndgrd_LWRCI_MKII_7_Base: RA_M4_Handguard_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_LWRCI_MKII_7_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Hndgrd_LWRCI_MKII_7_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_LWRCI_MKII_7_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_Hndgrd_LWRCI_MKII_7_Snow");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_Hndgrd_LWRCI_MKII_7_Camo");

		return m_SprayPaintEntry;
	}
};
class RA_M4_RISHndgrd_Base: RA_M4_Handguard_Base{};

class RA_Long_M4_Handguard_Base: RA_M4_Handguard_Base
{
	void RA_Long_M4_Handguard_Base()
	{
		SetAnimationPhase("rotate", 0);
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (parent.FindAttachmentBySlotName("weaponOptics")) {
			SetAnimationPhase("rotate", 1);
		}
		else {
			SetAnimationPhase("rotate", 0);
		}
	}

	override bool IsLong()
	{
		return true;
	}
};
class RA_G28_Patrol_Hndgrd_Base: RA_Long_M4_Handguard_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_G28_Patrol_Hndgrd_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_G28_Patrol_Hndgrd_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_G28_DMR_Hndgrd_Base: RA_Long_M4_Handguard_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_G28_DMR_Hndgrd_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_G28_DMR_Hndgrd_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_Hndgrd_SR25_RIS_Base: RA_Long_M4_Handguard_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_SR25_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Hndgrd_SR25_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_SR25_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_Hndgrd_SR25_Snow");

		return m_SprayPaintEntry;
	}
};
class RA_Hndgrd_LWRCI_MKII_9_Base: RA_Long_M4_Handguard_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_LWRCI_MKII_9_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Hndgrd_LWRCI_MKII_9_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_LWRCI_MKII_9_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_Hndgrd_LWRCI_MKII_9_Snow");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_Hndgrd_LWRCI_MKII_9_Camo");

		return m_SprayPaintEntry;
	}
};
class RA_Hndgrd_DDRIS3_Base: RA_Long_M4_Handguard_Base
{
	#ifndef SERVER
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail11_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(2,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,"");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(2,"");
			return;
		}
	}
	#endif
	
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_DDRIS3_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Hndgrd_DDRIS3_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_DDRIS3_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_Hndgrd_DDMK18_RIS_Base: RA_Long_M4_Handguard_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_DDMK18_RIS_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Hndgrd_DDMK18_RIS_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_DDMK18_RIS_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_Hndgrd_DDMK18_RIS_Snow");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_Hndgrd_DDMK18_RIS_Camo");

		return m_SprayPaintEntry;
	}
};
class RA_Hndgrd_RIS416_Base: RA_Long_M4_Handguard_Base{};
class RA_Hndgrd_SR15_RIS_Base: RA_Long_M4_Handguard_Base{};
class RA_Hndgrd_MK12_MOD0_Base: RA_Long_M4_Handguard_Base
{
	#ifndef SERVER
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);
		
		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail11_co.paa");
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"");
			return;
		}
	}
	#endif
};

class RA_MOE_Hndgrd_Base: RA_Hndgrd_Base
{
	#ifndef SERVER
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);
		
		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail11_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(2,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
		if (slot_name == "weaponBipod")
		{
			SetObjectTexture(4,"RearmedServer\\Attachments\\Support\\M4\\MK16\\data\\Rail7_co.paa");
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,"");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(2,"");
			return;
		}
		if (slot_name == "weaponBipod")
		{
			SetObjectTexture(4,"");
			return;
		}
	}
	#endif
};

class RA_Hndgrd_Compact_Base: RA_Hndgrd_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_Compact_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_Compact_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Hndgrd_Compact_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_Hndgrd_Compact_Snow");

		return m_SprayPaintEntry;
	}
};

class RA_AK_MOE_Hndgrd_Base: RA_MOE_Hndgrd_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AK_MOE_Hndgrd_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AK_MOE_Hndgrd_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_AK_Hexagon_Hndgrd_Base: RA_MOE_Hndgrd_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AK_Hexagon_Hndgrd_Black");

		return m_SprayPaintEntry;
	}
};
class RA_Hndgrd_ChassisMK1_Base: RA_Hndgrd_Base
{
	override bool CanDetachAttachment (EntityAI parent)
    {
        if (Weapon_Base.Cast(parent) && parent.FindAttachmentBySlotName("weaponOptics"))
        {
            return false;
        }
        return super.CanDetachAttachment(parent);
    }

	#ifndef SERVER
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"RearmedServer\\Attachments\\Support\\SVD\\ChassisMK1\\data\\mounts_magpul_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,"RearmedServer\\Attachments\\Support\\SVD\\ChassisMK1\\data\\mounts_magpul_co.paa");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(2,"RearmedServer\\Attachments\\Support\\SVD\\ChassisMK1\\data\\mounts_magpul_co.paa");
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponForegrip")
		{
			SetObjectTexture(1,"");
			return;
		}
		if (slot_name == "weaponFlashlight")
		{
			SetObjectTexture(3,"");
			return;
		}
		if (slot_name == "weaponFlashlight2")
		{
			SetObjectTexture(2,"");
			return;
		}
	}
	#endif
};
class RA_Hndgrd_FAL_MLOK: RA_MOE_Hndgrd_Base{};
class RA_Hndgrd_RSASS_Base: RA_MOE_Hndgrd_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_RSASS_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Hndgrd_RSASS_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_RSASS_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_Hndgrd_RSASS_Snow");

		return m_SprayPaintEntry;
	}
};
class RA_Hndgrd_Keymod_AR10_Base: RA_MOE_Hndgrd_Base{};
class RA_Hndgrd_MK47_AR10_Base: RA_MOE_Hndgrd_Base
{
	void RA_Hndgrd_MK47_AR10_Base()
	{
		SetAnimationPhase("rotate", 0);
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (parent.FindAttachmentBySlotName("weaponOptics")) {
			SetAnimationPhase("rotate", 1);
		}
		else {
			SetAnimationPhase("rotate", 0);
		}
	}
};

class RA_Hndgrd_KAC_MLOK_Base: RA_MOE_Hndgrd_Base
{
	void RA_Hndgrd_KAC_MLOK_Base()
	{
		SetAnimationPhase("rotate", 0);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_KAC_MLOK_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Hndgrd_KAC_MLOK_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_KAC_MLOK_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_Hndgrd_KAC_MLOK_Snow");

		return m_SprayPaintEntry;
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (parent.FindAttachmentBySlotName("weaponOptics")) {
			SetAnimationPhase("rotate", 1);
		}
		else {
			SetAnimationPhase("rotate", 0);
		}
	}
};

class RA_Hndgrd_Carbon416_Base: RA_MOE_Hndgrd_Base
{
	void RA_Hndgrd_Carbon416_Base()
	{
		SetAnimationPhase("rotate", 0);
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (parent.FindAttachmentBySlotName("weaponOptics")) {
			SetAnimationPhase("rotate", 1);
		}
		else {
			SetAnimationPhase("rotate", 0);
		}
	}
};

class RA_Hndgrd_MLOK416_Base: RA_MOE_Hndgrd_Base
{
	void RA_Hndgrd_MLOK416_Base()
	{
		SetAnimationPhase("rotate", 0);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_MLOK416_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_MLOK416_Tan");

		return m_SprayPaintEntry;
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (parent.FindAttachmentBySlotName("weaponOptics")) {
			SetAnimationPhase("rotate", 1);
		}
		else {
			SetAnimationPhase("rotate", 0);
		}
	}
};

class RA_Hndgrd_MK16_13_Base: RA_MOE_Hndgrd_Base
{
	void RA_Hndgrd_MK16_13_Base()
	{
		SetAnimationPhase("rotate", 0);
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (parent.FindAttachmentBySlotName("weaponOptics")) {
			SetAnimationPhase("rotate", 1);
		}
		else {
			SetAnimationPhase("rotate", 0);
		}
	}

	override bool IsLong()
	{
		return true;
	}
};

class RA_Hndgrd_MK16_10_Base: RA_MOE_Hndgrd_Base
{
	void RA_Hndgrd_MK16_10_Base()
	{
		SetAnimationPhase("rotate", 0);
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (parent.FindAttachmentBySlotName("weaponOptics")) {
			SetAnimationPhase("rotate", 1);
		}
		else {
			SetAnimationPhase("rotate", 0);
		}
	}

	override bool IsLong()
	{
		return true;
	}
};

class RA_Hndgrd_MagpulMOE_Carbine_Base: RA_MOE_Hndgrd_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Hndgrd_MagpulMOE_Carbine_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_Hndgrd_MagpulMOE_Carbine_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Hndgrd_MagpulMOE_Carbine_Tan");

		return m_SprayPaintEntry;
	}
};

class RA_Hndgrd_G36_Short_Base : RA_Hndgrd_Base{}
class RA_Hndgrd_G36_Long_Base : RA_Hndgrd_Base{}

class RA_Hndgrd_MCX_Base: RA_MOE_Hndgrd_Base
{
	void RA_Hndgrd_MCX_Base()
	{
		SetAnimationPhase("rotate", 0);
	}
	
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (parent.FindAttachmentBySlotName("weaponOptics")) {
			SetAnimationPhase("rotate", 1);
		}
		else {
			SetAnimationPhase("rotate", 0);
		}
	}

	override bool IsLong()
	{
		return true;
	}
};
class RA_Hndgrd_MCX_STD_Base: RA_Hndgrd_MCX_Base{}
class RA_Hndgrd_MCX_LVAW_Base: RA_Hndgrd_MCX_Base{}
class RA_Hndgrd_MCX_LT_Base: RA_Hndgrd_MCX_Base{}
class RA_Hndgrd_MCX_KM_Base: RA_Hndgrd_MCX_Base{}
