modded class MagazineStorage
{
    override bool DescriptionOverride(out string output)
    {
        int ammoCount = GetAmmoCount();
        set<string> ammoTypes = new set<string>;

        for (int i = 0; i < ammoCount; i++)
        {
            float dmg;
            string cartTypeName;
            if (GetCartridgeAtIndex(i, dmg, cartTypeName))
            {
                ammoTypes.Insert(cartTypeName);
            }
        }

	// probably an easier way to merge the array into a string but yolo
        string allTypes = "";
        for (int j = 0; j < ammoTypes.Count(); j++)
        {
            if (j > 0)
                allTypes += ", ";
            allTypes += ammoTypes.Get(j);
        }

        output = string.Format("%1\n\r\n Ammo Count [%2]\n\r\n Ammo Types [%3]", ConfigGetString("descriptionShort"), ammoCount, allTypes);

        return true;
    }
}
class RA_Mag_AKM_PMAG_30Rnd: MagazineStorage
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Mag_AKM_PMAG_30Rnd_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Mag_AKM_PMAG_30Rnd_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_Mag_AK74_PMAG_30Rnd: MagazineStorage
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Mag_AK74_PMAG_30Rnd_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Mag_AK74_PMAG_30Rnd_Tan");

		return m_SprayPaintEntry;
	}
};
class Mag_PPSH_30Rnd: MagazineStorage {};
class Mag_PPSH_Drum_71Rnd: MagazineStorage {};
class Mag_9A91_20Rnd: MagazineStorage {};
class Mag_SVT40_10Rnd: MagazineStorage {};
class RA_APS_Mag_20Rnd: MagazineStorage {};
class Mag_M82A1_10Rnd: MagazineStorage {};
class Mag_OPSKS_20Rnd: MagazineStorage {};
class Mag_M32_6Rnd: MagazineStorage {};
//class Mag_SV98_10Rnd: MagazineStorage {};
class RA_Mag_M200_7rnd: MagazineStorage {};
class Mag_308_PMAG_20Rnd: MagazineStorage
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "Mag_308_PMAG_20Rnd");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "Mag_308_PMAG_20Rnd_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "Mag_308_PMAG_20Rnd_Tan");

		return m_SprayPaintEntry;
	}
};
class Mag_M110_20Rnd: MagazineStorage {};
class RA_Mag_VSSK_10Rnd: MagazineStorage {};
class Mag_FiveSeven_20Rnd: MagazineStorage {};
class Mag_FiveSeven_30Rnd: MagazineStorage {};
class RA_Beretta_Mag_15Rnd: MagazineStorage {};
class Mag_R700_8Rnd: MagazineStorage {};
class Mag_R700_5Rnd: MagazineStorage {};
class Mag_PP19_30Rnd: MagazineStorage {};
class Mag_Glock_33Rnd: MagazineStorage {};
class Mag_Glock18_50Rnd: MagazineStorage {};
class RA_Mag_AK12_30Rnd : MagazineStorage {};
class Mag_ASH12_10Rnd: MagazineStorage {};
class Mag_ASH12_20Rnd: MagazineStorage {};
class Mag_Vector_Drum_50Rnd: MagazineStorage {};
class Mag_Vector_30Rnd: MagazineStorage {};
class Mag_Vector_13Rnd: MagazineStorage {};
class Mag_M300_7rnd: MagazineStorage {};
class Mag_SR3M130_30Rnd: MagazineStorage {};
class RA_Mag_SRS_5Rnd: MagazineStorage {};
class RA_Mag_SRS_7Rnd: MagazineStorage {};
class RA_Mag_SRS_HTI_5Rnd: MagazineStorage {};
class RA_Mag_DVL_10Rnd: MagazineStorage {};
class RA_Mag_M24_5Rnd: MagazineStorage {};
class RA_Mag_McMillan_CS5_10Rnd: MagazineStorage {};
class RA_Mag_Kivaari_10Rnd: MagazineStorage {};
class RA_M249_Magazine: MagazineStorage {};
class RA_Mag_M14_10Rnd: MagazineStorage {};
class RA_Mag_M14_20Rnd: MagazineStorage {};
class RA_Mag_Scar_H_20Rnd_Base: MagazineStorage
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Mag_Scar_H_20Rnd_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Mag_Scar_H_20Rnd_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_Mag_Scar_H_10Rnd_Base: MagazineStorage
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Mag_Scar_H_10Rnd_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Mag_Scar_H_10Rnd_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_Mag_Mini14_20Rnd: MagazineStorage {};
class RA_Mag_FAL_10Rnd: MagazineStorage {};
class RA_Mag_SA58_20Rnd: MagazineStorage{};
class RA_Mag_FAL_30Rnd: MagazineStorage {};
class RA_Mag_Galil_35Rnd: MagazineStorage {};
class RA_Mag_AA12_Drum32Rnd: MagazineStorage {};
class RA_Mag_P90_50Rnd: MagazineStorage {};
class RPK16_DrumMagazine: MagazineStorage {};
class AX50_Magazine: MagazineStorage {};
class M300_Magazine: MagazineStorage {};
class Mag_60Rnd_545x39: MagazineStorage {};
class RA_Mag_VIRTUS_30Rnd: MagazineStorage {};
class Mag_SVD_20Rnd: MagazineStorage {};
class RA_PMAG_Drum_60Rnd: MagazineStorage {};
class RA_Mag_MP7_40rnd: MagazineStorage {};
class RA_Mag_AXMK3_10rnd: MagazineStorage {};
class RA_Mag_MP7_20rnd: MagazineStorage {};
class Mag_Waffle_MP5_30Rnd: MagazineStorage {};
class RA_Mag_Vepr12_10Rnd: MagazineStorage{};
class RA_Mag_Vepr12_5Rnd: MagazineStorage{};
class RA_Mag_G36_30Rnd: MagazineStorage{};
class RA_Mag_Spear_20Rnd: MagazineStorage{};
class RA_Mag_Spear_20Rnd_Tan: MagazineStorage{};
class RA_Mag_G28_20Rnd_Base: TransparentMagazineBase
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Mag_G28_20Rnd_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Mag_G28_20Rnd_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_Mag_PKM_100Rnd: MagazineStorage{};
class RA_Mag_Dracarys_10Rnd: MagazineStorage{};
class Mag_AWM_5Rnd: MagazineStorage{};
class Mag_P226_15Rnd: MagazineStorage{};
class Mag_P320_15Rnd: MagazineStorage{};
class RA_Mag_Fort12_12Rnd: MagazineStorage{};
class RA_Mag_MK23_10Rnd: MagazineStorage{};
class RA_Mag_TT_8Rnd: MagazineStorage{};
class RA_Mag_PM_8Rnd: MagazineStorage{};
class Mag_SSG69_5rnd: MagazineStorage{};
class RA_Mag_AK5C_30Rnd: MagazineStorage{};

modded class Mag_STANAG_30Rnd
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "Mag_STANAG_30Rnd_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "Mag_STANAG_30Rnd_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "Mag_STANAG_30Rnd");

		return m_SprayPaintEntry;
	}
};

modded class Mag_VAL_20Rnd
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "Mag_VAL_20Rnd_Black");

		return m_SprayPaintEntry;
	}
};







class TransparentMagazineBase: MagazineStorage
{
	override void EEInit()
	{
		super.EEInit();
		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateTotalAmmoVisibility);
	}

	void UpdateAmmoVisibility()
    {
		if (!g_Game.IsServer()) {
			return;
		}

		int ammoCount = GetAmmoCount();
		SetAnimationPhase((ammoCount).ToString(), 0);
		SetAnimationPhase((ammoCount + 1).ToString(), 1);
    }

	void UpdateTotalAmmoVisibility()
    {
		if (!g_Game.IsServer()) {
			return;
		}

		int ammoCount = GetAmmoCount();
		for (int i = 1; i <= GetAmmoMax(); ++i)
		{
			SetAnimationPhase(i.ToString(), i > ammoCount);
		}
    }
}

modded class ActionLoadMagazineQuick
{
    override void OnFinishProgress( ActionData action_data )
    {
        super.OnFinishProgress(action_data);

        TransparentMagazineBase transmag = TransparentMagazineBase.Cast(action_data.m_MainItem);
		if (transmag) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(transmag.UpdateTotalAmmoVisibility, 1000);
		}
    }
}
modded class ActionLoadMagazine
{
    override void OnFinishProgress( ActionData action_data )
    {
        super.OnFinishProgress(action_data);

        TransparentMagazineBase transmag = TransparentMagazineBase.Cast(action_data.m_MainItem);
		if (transmag) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(transmag.UpdateTotalAmmoVisibility, 1000);
		}
    }
}
modded class ActionEmptyMagazine
{
    override void OnFinishProgress( ActionData action_data )
    {
        super.OnFinishProgress(action_data);

        TransparentMagazineBase transmag = TransparentMagazineBase.Cast(action_data.m_MainItem);
		if (transmag) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(transmag.UpdateTotalAmmoVisibility, 1000);
		}
    }
}
modded class Weapon_Base
{
	override void EEFired(int muzzleType, int mode, string ammoType)
	{
		super.EEFired(muzzleType, mode, ammoType);
		
		TransparentMagazineBase transmag = TransparentMagazineBase.Cast(FindAttachmentBySlotName("magazine"));
		if (transmag) {
			g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(transmag.UpdateAmmoVisibility, 100);
		}
	}
}
