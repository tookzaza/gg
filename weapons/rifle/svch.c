class RA_SVCh_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new FALRecoil(this);
	}	
};
class RA_SVCh : RA_SVCh_Base {};