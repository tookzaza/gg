class RA_SPAS12_Base : ChamberFirst_InnerMagazine_SemiAutomatic_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Mp133Recoil(this);
	}
};  
class RA_SPAS12 : RA_SPAS12_Base {};
class RA_SPAS12_Winter : RA_SPAS12 {};