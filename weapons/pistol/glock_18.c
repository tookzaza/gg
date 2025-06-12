class RA_Glock18_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new GlockRecoil(this);
	}
};

class RA_P226_Base: Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new GlockRecoil(this);
	}
};

class RA_P320_Base: Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new GlockRecoil(this);
	}

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_P320_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_P320_Tan");

		return m_SprayPaintEntry;
	}
};

class RA_Fort12_Base: Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Cz75Recoil(this);
	}
};

class RA_TT_Base: Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Cz75Recoil(this);
	}
};

class RA_MK23_Base: Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new GlockRecoil(this);
	}
};