class RA_Vector_Base : RifleBoltLock_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new Mp5kRecoil(this);
	}
	
	override void EEItemAttached(EntityAI item, string slot_name)
	{	
		super.EEItemAttached(item,slot_name);

		if (ItemOptics.Cast(item))
		{
			SetAnimationPhase("rotate", 1);
			return;
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{	
		super.EEItemDetached(item, slot_name);

		if (ItemOptics.Cast(item))
		{
			SetAnimationPhase("rotate", 0);
			return;
		}
	}		
};

class RA_Vector : RA_Vector_Base {};
