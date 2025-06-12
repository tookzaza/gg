class Railgun_Base: RifleSingleShot_Base
{	
	override RecoilBase SpawnRecoilObject()
	{
		return new Izh18Recoil(this);
	}
};

class Railgun: Railgun_Base
{	
	override void AssembleGun()
	{
		if (!FindAttachmentBySlotName("weaponOpticsAug"))
		{
			GetInventory().CreateAttachment("RailgunOptic");
		}
	}
};