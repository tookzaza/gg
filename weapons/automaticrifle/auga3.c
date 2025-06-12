class RA_Auga3_Base : RifleBoltFree_Base
{
	override RecoilBase SpawnRecoilObject()
	{		
		return new M4a1Recoil(this);
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
}

class RA_Auga3 : RA_Auga3_Base {};