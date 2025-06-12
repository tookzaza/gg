class RA_AWM_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ550Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AWM_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_AWM_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AWM_Tan");

		return m_SprayPaintEntry;
	}
}