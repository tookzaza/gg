class Rifle_GL_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new M4a1Recoil(this);
	}

	string SwitchGL()
    {
        if (ConfigIsExisting("switchGLInto"))
            return ConfigGetString("switchGLInto");

        return string.Empty;
    }
}