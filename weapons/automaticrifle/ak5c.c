class RA_AK5C_Base : RifleBoltFree_Base
{	
	override RecoilBase SpawnRecoilObject()
	{		
		return new M4a1Recoil(this);
	}
};
class RA_AK5C: RA_AK5C_Base{};