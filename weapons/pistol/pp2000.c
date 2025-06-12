class RA_PP2000_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new P1Recoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_PP2000_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_PP2000_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_PP2000: RA_PP2000_Base{};