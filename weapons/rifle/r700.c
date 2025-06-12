class RA_C14_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ550Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_C14TimberWolf");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_C14TimberWolf_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_C14TimberWolf_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_C14TimberWolf_Camo");

		return m_SprayPaintEntry;
	}
};