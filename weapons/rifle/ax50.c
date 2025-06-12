class AX50_Base : BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ527Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "AX50_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "AX50_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "AX50_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "AX50_Snow");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "AX50_Camo");

		return m_SprayPaintEntry;
	}
}