class RA_ItemOptics: ItemOptics
{
	override void OnOpticEnter()
    {
        if (g_Game && !g_Game.IsDedicatedServer())
        {
            PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());
			if (!player)
			{
				return;
			}

            Weapon_Base weapon = Weapon_Base.Cast(player.GetItemInHands());
            if (!weapon)
            {
                return;
            }
			// *1000 normally, but we want to make it so it hides slightly earlier
            g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(HideSelection, (weapon.GetADSModifierPercentage()*700), false, "hide");
        }
    }

	override void OnOpticExit()
	{
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Remove(HideSelection);
		super.OnOpticExit();
	}
}
class RA_MagnifierCompatibleOptic_Base: RA_ItemOptics
{
    override bool CanDetachAttachment (EntityAI parent)
    {
        if (Weapon_Base.Cast(parent) && parent.FindAttachmentBySlotName("weaponMagnifier"))
        {
            return false;
        }
        return super.CanDetachAttachment(parent);
    }

    override void OnOpticEnter()
	{
		super.OnOpticEnter();

        Weapon_Base parent = Weapon_Base.Cast(GetHierarchyParent());

        if (!parent) {
            return;
        }

        OpticMagnifier_Base magnifier = OpticMagnifier_Base.Cast(parent.FindAttachmentBySlotName("weaponMagnifier"));
        if (!magnifier || !magnifier.GetMagnifierState())
        {
            return;
        }
		#ifndef SERVER
        parent.SetSimpleHiddenSelectionState(0, 0);
		#endif
        HideSelection("magnifier");
		magnifier.HideSelection("hide");
	}

    override void OnOpticExit()
	{
		super.OnOpticExit();

        Weapon_Base parent = Weapon_Base.Cast(GetHierarchyParent());

        if (!parent) {
            return;
        }

        OpticMagnifier_Base magnifier = OpticMagnifier_Base.Cast(parent.FindAttachmentBySlotName("weaponMagnifier"));
        if (!magnifier || !magnifier.GetMagnifierState())
        {
            return;
        }
		#ifndef SERVER
        parent.SetSimpleHiddenSelectionState(0, 1);
		#endif
        ShowSelection("magnifier");
		magnifier.ShowSelection("hide");
	}
}
// 1x Optics  ----------------------------------------
class RA_AimpointT2: RA_MagnifierCompatibleOptic_Base{}
class RA_XPS3_Holosight: RA_MagnifierCompatibleOptic_Base
{
    override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_XPS3_Holosight");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_XPS3_Holosight_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_XPS3_Holosight_Tan");

		return m_SprayPaintEntry;
	}
}
class RA_Vortex_UH1: RA_MagnifierCompatibleOptic_Base{}
class RA_Pilad: RA_MagnifierCompatibleOptic_Base{}
class RA_PK06: RA_ItemOptics{}
class RA_Romeo4TOptic: RA_ItemOptics
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Romeo4TOptic");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Romeo4TOptic_Tan");

		return m_SprayPaintEntry;
	}
}
class RA_SRS: RA_ItemOptics{}
class RA_PKAS: RA_ItemOptics{}
class RA_Prism: RA_ItemOptics{} //need to improve Prism
class RA_RMR_Base: RA_ItemOptics{}
class RA_Romeo1_Base: RA_ItemOptics{}
class RA_Romeo3_Optic_Base: RA_ItemOptics{}
//todo Holosun

// LPVOs and 4x Optics ------------------------------
class RA_ACOG: RA_ItemOptics
{
    override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_ACOG");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_ACOG_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_ACOG_Tan");

		return m_SprayPaintEntry;
	}
}
class RA_Specter_Elcan: RA_ItemOptics
{
    override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Specter_Elcan");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Specter_Elcan_Tan");

		return m_SprayPaintEntry;
	}
}
class RA_ATACR: RA_ItemOptics{}
class RA_Tango6: RA_ItemOptics
{
    override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Tango6");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Tango6_Tan");

		return m_SprayPaintEntry;
	}
}
class RA_46x: RA_ItemOptics{}
class RA_VortexRazorOptic_Base: RA_ItemOptics
{
    override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_VortexRazorOptic_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_VortexRazorOptic_Brown");

		return m_SprayPaintEntry;
	}
}
class RA_Vudu_Optic: RA_ItemOptics{}
class RA_HAMR_Optic: RA_ItemOptics{}

// Sniper Optics ------------------------------------
class RA_LeupoldMk4Optic: RA_ItemOptics{}
class RA_PM2: RA_ItemOptics{}

//Others
class RA_G36_Optic: RA_ItemOptics{}