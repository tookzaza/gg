class RA_SVT40_Base : RifleBoltLock_Base
{
    override RecoilBase SpawnRecoilObject()
	{		
		return new SvdRecoil(this);
	}

	override bool CanEnterIronsights()
	{
		ItemOptics optic = GetAttachedOptics();
		if (optic)
			return true;
		return super.CanEnterIronsights();
	}
}

class RA_SVT40 : RA_SVT40_Base{}
