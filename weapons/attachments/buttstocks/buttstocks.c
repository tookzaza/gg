class Foldable_Buttstock: ButtstockBase
{
	/*override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		PlayerBase player;
		Class.CastTo(player, parent.GetHierarchyRootPlayer());
		Weapon_Base weapon = Weapon_Base.Cast(parent);
		if (!player) {
			Print("No Player");
			return;
		}
		if (!weapon) {
			Print("No Weapon");
			return;
		}
		
		if (weapon.ConfigGetBool("Unfolded") == 1) {
			Print("Wrong Gun Folded State");
			return;
		}
		Print("Attached Code Executed");
		MiscGameplayFunctions.TurnItemIntoItemEx(player, new TurnItemIntoItemLambda(parent, weapon.SwitchButtstock(), player));
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);

		if (GetAnimationPhase("fold") == 1) {
			SetAnimationPhase("fold", 0);
		}

		PlayerBase player;
		Class.CastTo(player, parent.GetHierarchyRootPlayer());
		Weapon_Base weapon = Weapon_Base.Cast(parent);
		if (!player) {
			Print("No Player");
			return;
		}
		if (!weapon) {
			Print("No Weapon");
			return;
		}
		
		if (weapon.ConfigGetBool("Unfolded") == 0) {
			return;
		}
		Print("Detached Code Executed");
		MiscGameplayFunctions.TurnItemIntoItemEx(player, new TurnItemIntoItemLambda(parent, weapon.SwitchButtstock(), player));
	}*/
};
class PRS_Bttstck_Base: ButtstockBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "PRS_Bttstck_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "PRS_Bttstck_OD");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "PRS_Bttstck_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "PRS_Bttstck_Snow");

		return m_SprayPaintEntry;
	}
};
class UBR_Bttstck_Base: ButtstockBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "UBR_Bttstck_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "UBR_Bttstck_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "UBR_Bttstck_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "UBR_Bttstck_Snow");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "UBR_Bttstck_Camo");

		return m_SprayPaintEntry;
	}
};
class M16A2_Bttstck_Base: ButtstockBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "M16A2_Bttstck_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "M16A2_Bttstck_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "M16A2_Bttstck_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "M16A2_Bttstck_Snow");

		return m_SprayPaintEntry;
	}
};
class RA_CQB7_Bttstck_Base: ButtstockBase{};
class RA_Viper_Bttstck_Base: ButtstockBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Viper_Bttstck_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Viper_Bttstck_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_HKE1_Bttstck: ButtstockBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_HKE1_Bttstck_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_HKE1_Bttstck_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_HKE1_Bttstck_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_HKE1_Bttstck_Snow");

		return m_SprayPaintEntry;
	}
};
class RA_ACS_Bttstck_Base: ButtstockBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_ACS_Bttstck_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_ACS_Bttstck_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_SOPMOD_Bttstck: ButtstockBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_SOPMOD_Bttstck_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_SOPMOD_Bttstck_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_SOPMOD_Bttstck_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_SOPMOD_Bttstck_Snow");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_SOPMOD_Bttstck_Camo");

		return m_SprayPaintEntry;
	}
};
class RA_RipStock_Bttstck_Base: ButtstockBase{};

//ak
class RA_Bttstck_AK_ZENIT_PT1: Foldable_Buttstock
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Bttstck_AK_ZENIT_PT1_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Bttstck_AK_ZENIT_PT1_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_Bttstck_AK_UAS : Foldable_Buttstock {};
class RA_Bttstck_AK_ZHUKOV_Base : Foldable_Buttstock
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Bttstck_AK_ZHUKOV");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Bttstck_AK_ZHUKOV_Tan");

		return m_SprayPaintEntry;
	}
};


class MP5A2_Bttstck: ButtstockBase{};

class RA_MP5_Buttstock: ButtstockBase{};
class MP5_Fixed_Bttstck: RA_MP5_Buttstock{};
class MP5_Foldable_Bttstck: RA_MP5_Buttstock{};
class MP5_Retractable_Bttstck: RA_MP5_Buttstock{};

class RA_AK_FoldingBttstck: Foldable_Buttstock{};
class RA_Plastic_AK74M_Bttstck: Foldable_Buttstock{};

class RA_Bttstck_SPAS12: ButtstockBase{};
class RA_Bttstck_SPAS12_Winter: ButtstockBase{};

class Rotor_43: ItemBase
{
	override bool CanDetachAttachment (EntityAI parent)
	{
		if (Weapon_Base.Cast(parent) && parent.FindAttachmentBySlotName("weaponButtstockM4"))
		{
			return false;
		}
		return true;
	}
};

class ASVAL_Bttstck : ButtstockBase {};
class VSSM_Bttstck : ButtstockBase {};

class RA_CQR_Bttstck: ButtstockBase
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!parent.IsInherited(RA_M4A1_Base) && !parent.IsInherited(RA_HK416_Base) && !parent.IsInherited(RA_MK18_Base) && !parent.IsInherited(RA_MK12_Base)) 	
		{
			return false;
		}		
		return super.CanPutAsAttachment(parent);
	}
};

class AK_M4Adapter: ItemBase{};
class SVD_M4Adapter: ItemBase
{
	#ifndef SERVER
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(2,"");
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (slot_name == "weaponPistolGrip")
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\M4A1\\data\\Grip_co.paa"); //grip
		}
	}
	#endif
};

class Scar_Bttstck_Base: ButtstockBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "Scar_Bttstck_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "Scar_Bttstck_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "Scar_Bttstck_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "Scar_Bttstck_Snow");

		return m_SprayPaintEntry;
	}
};

class RA_SCAR_Mk20Bttstck_Base: ButtstockBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_SCAR_Mk20Bttstck_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_SCAR_Mk20Bttstck_Tan");

		return m_SprayPaintEntry;
	}
};

modded class M4_MPBttstck
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "M4_MPBttstck");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "M4_MPBttstck_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "M4_MPBttstck_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "M4_MPBttstck_Snow");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "M4_MPBttstck_Camo");

		return m_SprayPaintEntry;
	}
}