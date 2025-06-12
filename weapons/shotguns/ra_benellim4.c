class RA_BenelliM4_Base: ChamberFirst_InnerMagazine_SemiAutomatic_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new R12Recoil(this);
	}
};  
class RA_BenelliM4 : RA_BenelliM4_Base {};