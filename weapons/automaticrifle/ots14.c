class RA_OTS14_Base : RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new VSSRecoil(this);
	}

	override bool CanEnterIronsights()
	{
		return true;
	}	
};