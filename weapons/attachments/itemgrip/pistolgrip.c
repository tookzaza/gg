class RA_AK_Pistol_Grip_Base : ItemBase{};
class RA_RK3_Grip_Base : RA_AK_Pistol_Grip_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AK_ZenitRK3PistolGrip");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AK_ZenitRK3PistolGrip_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_AK_CAAG47_Grip_Base : RA_AK_Pistol_Grip_Base{};
class RA_KGB_MG47_Grip_Base : RA_AK_Pistol_Grip_Base{};
class RA_AK_MOE_Base : RA_AK_Pistol_Grip_Base{};
class RA_AK12_Grip_Base : RA_AK_Pistol_Grip_Base{};

class RA_M4_Pistol_Grip_Base : ItemBase{};
class RA_TDHexagon_Grip_Base: RA_M4_Pistol_Grip_Base{};
class RA_GRAL_Grip_Base: RA_M4_Pistol_Grip_Base{};
class RA_MOE_Grip_Base : RA_M4_Pistol_Grip_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_M4_MOEPistolGrip_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M4_MOEPistolGrip_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M4_MOEPistolGrip_Green");

		return m_SprayPaintEntry;
	}
};
class RA_TDS_Grip_Base : RA_M4_Pistol_Grip_Base{};
class RA_OMRG_Grip_Base : RA_M4_Pistol_Grip_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_M4_OMRGPistolGrip_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M4_OMRGPistolGrip_FDE");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M4_OMRGPistolGrip_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_M4_OMRGPistolGrip_Camo");

		return m_SprayPaintEntry;
	}
};
class RA_DD_Grip_Base : RA_M4_Pistol_Grip_Base{};
class RA_Torque_Grip_Base : RA_M4_Pistol_Grip_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_Torque_Grip_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_Torque_Grip_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_PSG_ERGO_Grip_Base : RA_M4_Pistol_Grip_Base{};
class RA_HK_Grip_Base : RA_M4_Pistol_Grip_Base
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_M4_HKPistolGrip_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M4_HKPistolGrip_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_M4_HKPistolGrip_Green");

		return m_SprayPaintEntry;
	}
};

class RA_FAL_Pistol_Grip_Base: ItemBase{};
class RA_FAL_ParaGrip_Base: RA_FAL_Pistol_Grip_Base{};
class RA_FAL_FAB_Grip_Base: RA_FAL_Pistol_Grip_Base{};