class RA_PB_Base: Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MakarovRecoil(this);
	}
};