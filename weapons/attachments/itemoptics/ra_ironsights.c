class RA_IronSights: ItemOptics
{
    void RA_IronSights()
    {
        SetAnimationPhase("rotate", 0);
    }

    override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		if (parent.FindAttachmentBySlotName("weaponOptics")) {
			SetAnimationPhase("rotate", 1);
		}
		else {
			SetAnimationPhase("rotate", 0);
		}
	}
};
class RA_KAC_IronSights: RA_IronSights{};