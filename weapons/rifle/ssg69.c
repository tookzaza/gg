class RA_SSG69_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ527Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_SSG69_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_SSG69_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_SSG69_Tan");

		return m_SprayPaintEntry;
	}
};