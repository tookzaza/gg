class RA_HenrySS_Shotgun_Base: RifleSingleShot_Base
{
    override RecoilBase SpawnRecoilObject()
	{
		return new Izh18ShotgunRecoil(this);
	}
};  