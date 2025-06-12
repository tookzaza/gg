class RA_UMP45_Base : RifleBoltLock_Base
{ 
	override RecoilBase SpawnRecoilObject()
	{
		return new Ump45Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_UMP45_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.SNOW, "RA_UMP45_Snow");

		return m_SprayPaintEntry;
	}
};