class RA_Mosin9130_Base: BoltActionRifle_InnerMagazine_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MosinRecoil(this);
	}
};