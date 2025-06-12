class RA_MP9_Base : RifleBoltLock_Base
{	
	
	override RecoilBase SpawnRecoilObject()
	{
		return new Cz61Recoil(this);
	}
	
	//some command is different for this weapon
	override int GetWeaponSpecificCommand(int weaponAction ,int subCommand)
	{
		if ( weaponAction == WeaponActions.CHAMBERING)
		{
			switch (subCommand)
			{
				case WeaponActionChamberingTypes.CHAMBERING_ONEBULLET_UNIQUE_CLOSED:
					return WeaponActionChamberingTypes.CHAMBERING_ONEBULLET_OPENED;
				
				default:
					return subCommand;
			}
		
		}
		return subCommand;
	}
};
class RA_MP9: RA_MP9_Base {};