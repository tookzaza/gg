class RA_Model1887_Base: Repeater_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Izh18Recoil(this);
	}
};