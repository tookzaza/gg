class RA_M1A_Base: RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new SvdRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_M1A_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_M1A_OD");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_M1A_Tan");

		return m_SprayPaintEntry;
	}
}