class RA_P90_Base: RifleBoltFree_Base
{	
	override RecoilBase SpawnRecoilObject()
	{
		return new Cz61Recoil(this);
	}
};  