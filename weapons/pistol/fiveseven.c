class FiveSeven_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new GlockRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_FiveSeven_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_FiveSeven_Tan");

		return m_SprayPaintEntry;
	}
};