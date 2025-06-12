class RA_SV98_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new ScoutRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_SV98_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_SV98_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_SV98_Tan");

		return m_SprayPaintEntry;
	}
};