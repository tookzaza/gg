class RA_MP7A2_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new RAMP7Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_MP7A2");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_MP7A2_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_MP7A2_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_MP7A2_Snow");

		return m_SprayPaintEntry;
	}
};

class RA_MP7A2 : RA_MP7A2_Base {};