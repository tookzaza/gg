class M300_Base : BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ527Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "M300_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "M300_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "M300_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "M300_Camo");

		return m_SprayPaintEntry;
	}
}