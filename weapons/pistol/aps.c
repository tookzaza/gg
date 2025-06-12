class RA_APS_Base: Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MakarovRecoil(this);
	}
};