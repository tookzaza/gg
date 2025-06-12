class RA_DDWave_Suppressor: ItemSuppressor
{
	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		RA_DDWave_Compensator comp = RA_DDWave_Compensator.Cast(parent);
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_DDWave_Compensator_Suppressed");
			lambda.Execute();
		}
	}

	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		
		RA_DDWave_Compensator_Suppressed comp = RA_DDWave_Compensator_Suppressed.Cast(parent);
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_DDWave_Compensator");
			lambda.Execute();
		}
	}

	override void OnItemAttachmentSlotChanged (notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.OnItemAttachmentSlotChanged(oldLoc, newLoc);

		RA_DDWave_Compensator comp = RA_DDWave_Compensator.Cast(newLoc.GetParent());
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_DDWave_Compensator_Suppressed");
			lambda.Execute();
		}
	}
};

class RA_DDWave_Compensator: ItemSuppressor
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
		return attachment.IsInherited(RA_DDWave_Suppressor);
    }
};

class RA_DDWave_Compensator_Suppressed: ItemSuppressor{};

//SDN

class RA_SDN_Suppressor: ItemSuppressor
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_SDN_Suppressor");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_SDN_Suppressor_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_SDN_Suppressor_Green");

		return m_SprayPaintEntry;
	}

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		RA_SDN_Compensator comp = RA_SDN_Compensator.Cast(parent);
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_SDN_Compensator_Suppressed");
			lambda.Execute();
		}
	}

	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		
		RA_SDN_Compensator_Suppressed comp = RA_SDN_Compensator_Suppressed.Cast(parent);
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_SDN_Compensator");
			lambda.Execute();
		}
	}

	override void OnItemAttachmentSlotChanged (notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.OnItemAttachmentSlotChanged(oldLoc, newLoc);

		RA_SDN_Compensator comp = RA_SDN_Compensator.Cast(newLoc.GetParent());
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_SDN_Compensator_Suppressed");
			lambda.Execute();
		}
	}
};

class RA_SDN_Compensator: ItemSuppressor
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
		return attachment.IsInherited(RA_SDN_Suppressor);
    }
};

class RA_SDN_Compensator_Suppressed: ItemSuppressor{};

//AAC

class RA_AAC2000_Suppressor: ItemSuppressor
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AAC2000_Suppressor");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AAC2000_Suppressor_Tan");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_AAC2000_Suppressor_Green");

		return m_SprayPaintEntry;
	}

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		RA_AAC2000_Compensator comp = RA_AAC2000_Compensator.Cast(parent);
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_AAC2000_Compensator_Suppressed");
			lambda.Execute();
		}
	}

	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		
		RA_AAC2000_Compensator_Suppressed comp = RA_AAC2000_Compensator_Suppressed.Cast(parent);
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_AAC2000_Compensator");
			lambda.Execute();
		}
	}

	override void OnItemAttachmentSlotChanged (notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.OnItemAttachmentSlotChanged(oldLoc, newLoc);

		RA_AAC2000_Compensator comp = RA_AAC2000_Compensator.Cast(newLoc.GetParent());
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_AAC2000_Compensator_Suppressed");
			lambda.Execute();
		}
	}
};

class RA_AAC2000_Compensator: ItemSuppressor
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        return attachment.IsInherited(RA_AAC2000_Suppressor);
    }
};

class RA_AAC2000_Compensator_Suppressed: ItemSuppressor{};

//AAC

class RA_SureFire_Suppressor: ItemSuppressor
{
	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_SureFire_Suppressor_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_SureFire_Suppressor_Tan");

		return m_SprayPaintEntry;
	}

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		super.OnWasAttached(parent, slot_id);
		
		RA_SureFire_Compensator comp = RA_SureFire_Compensator.Cast(parent);
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_SureFire_Compensator_Suppressed");
			lambda.Execute();
		}
	}

	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		
		RA_SureFire_Compensator_Suppressed comp = RA_SureFire_Compensator_Suppressed.Cast(parent);
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_SureFire_Compensator");
			lambda.Execute();
		}
	}

	override void OnItemAttachmentSlotChanged (notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		super.OnItemAttachmentSlotChanged(oldLoc, newLoc);

		RA_SureFire_Compensator comp = RA_SureFire_Compensator.Cast(newLoc.GetParent());
        if (!comp) {
			return;
		}
				
		if (g_Game.IsDedicatedServer()) {
			TurnItemIntoItemLambdaNoPlayer lambda = new TurnItemIntoItemLambdaNoPlayer(comp, "RA_SureFire_Compensator_Suppressed");
			lambda.Execute();
		}
	}
};

class RA_SureFire_Compensator: ItemSuppressor
{
	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        return attachment.IsInherited(RA_SureFire_Suppressor);
    }
};

class RA_SureFire_Compensator_Suppressed: ItemSuppressor{};