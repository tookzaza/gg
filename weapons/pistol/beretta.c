class RA_Beretta_Base : Pistol_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new P1Recoil(this);
	}
};
class RA_Beretta : RA_Beretta_Base {};