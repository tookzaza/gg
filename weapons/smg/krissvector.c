class RA_Kriss_Vector_Base: RifleBoltLock_Base
{	
	override RecoilBase SpawnRecoilObject()
	{
		return new Cz61Recoil(this);
	}
};