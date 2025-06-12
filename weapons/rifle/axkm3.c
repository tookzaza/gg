class RA_AXMK3_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ527Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AXMK3_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AXMK3_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_AXMK3_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_AXMK3_Camo");

		return m_SprayPaintEntry;
	}
};