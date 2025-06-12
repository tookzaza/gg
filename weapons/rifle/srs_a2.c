class RA_DT_SRS_A2_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ550Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_DT_SRS_A2");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_DT_SRS_A2_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_DT_SRS_A2_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_DT_SRS_A2_Camo");

		return m_SprayPaintEntry;
	}

	override bool CanBeInspected()
	{
		return true;
	}
};

class RA_DT_SRS_HTI_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ550Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_DT_SRS_HTI_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_DT_SRS_HTI_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_DT_SRS_HTI_Tan");
		//m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_DT_SRS_HTI_Rattlecan");

		return m_SprayPaintEntry;
	}

	override bool CanBeInspected()
	{
		return true;
	}
};