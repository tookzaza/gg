class RA_M24_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ527Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_M24_SWS");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_M24_Camo1");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M24_Camo2");
		m_SprayPaintEntry.Add(SprayPaintTypes.CAMO, "RA_M24_Camo3");

		return m_SprayPaintEntry;
	}	
};