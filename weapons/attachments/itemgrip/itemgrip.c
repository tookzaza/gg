class RA_RIS_Grip_Base: ItemBase{};
class RA_TangoDown_Grip: RA_RIS_Grip_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_TangoDown_Grip_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_TangoDown_Grip_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_TangoDown_Grip_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_TangoDown_Grip_Snow");

		return m_SprayPaintEntry;
	}
};
class RA_FortisShift_Grip: RA_RIS_Grip_Base{};
class RA_RK5_Grip: RA_RIS_Grip_Base{};
class RA_RK6_Grip: RA_RIS_Grip_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_RK6_Grip");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_RK6_Grip_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_SAW_RIS_Grip_Base: RA_RIS_Grip_Base{};
class RA_AFG_RIS_Grip_Base: RA_RIS_Grip_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AFG_RIS_Grip_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_AFG_RIS_Grip_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AFG_RIS_Grip_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_AFG_RIS_Grip_Camo");

		return m_SprayPaintEntry;
	}
};
class RA_RVG_Grip_Base: RA_RIS_Grip_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_RVG_RIS_Grip_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_RVG_RIS_Grip_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_RVG_RIS_Grip_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_RVG_RIS_Grip_Camo");

		return m_SprayPaintEntry;
	}
};
class RA_ZenitRK1B25U_RIS_Grip: RA_RIS_Grip_Base{};
class RA_RK0_Grip: RA_RIS_Grip_Base{};
class RA_KAC_Forward_Grip: RA_RIS_Grip_Base{};

class RA_CQR_Grip: RA_RIS_Grip_Base
{
    override bool CanPutAsAttachment( EntityAI parent )
	{
		if(!parent.IsInherited(RA_M4_Handguard_Base)) 	
		{
			return false;
		}		
		return super.CanPutAsAttachment(parent);
	}
};