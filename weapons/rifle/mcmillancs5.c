class RA_McMillan_CS5_Base: BoltActionRifle_ExternalMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new CZ527Recoil(this);
	}	
	
};
class RA_McMillan_CS5 extends RA_McMillan_CS5_Base {};