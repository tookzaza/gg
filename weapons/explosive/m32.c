class M32_Base : RifleBoltLock_Base
{
	override bool ShootsExplosiveAmmo()
	{
		return true;
	}
	
	override RecoilBase SpawnRecoilObject()
	{
		return new M79Recoil(this);
	}
};

class M32 : M32_Base {};