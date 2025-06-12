class RA_PPSH_Base: RifleBoltFree_Base
{
    override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
	}
};