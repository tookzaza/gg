#ifndef SERVER
class AdminGhillieWrap: ItemBase
{	
    override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		for (int i = 0; i < 8; i++) {
			parent.SetObjectTexture(i, "");
		}
		
		//DeleteSafe();
	}
}
#endif