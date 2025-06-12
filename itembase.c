modded class ItemBase
{
    override void OnRightClick()
	{
		super.OnRightClick();
		if (CanBeSplit() && !g_Game.IsLeftCtrlDown() && !g_Game.GetPlayer().GetInventory().HasInventoryReservation(this,null)) {
			if (g_Game.IsClient()) {
				array<string> sounds = {};
				ConfigGetTextArray("ItemMoveSounds", sounds);					
				EffectSound sound = SEffectManager.CreateSound(sounds.GetRandomElement(), GetPosition());
				if (sound) {
					sound.SetSoundAutodestroy(true);
					sound.SoundPlay();
					sound.SetVolume(ConfigGetFloat("ItemMoveSoundVolume"));
				}
				
				EffectSound move_sound = SEffectManager.CreateSound("IMS_Item_Move_Regular", GetPosition());
				if (move_sound) {
					move_sound.SetSoundAutodestroy(true);
					move_sound.SoundPlay();
				}
			}
		}
	}
	
	// quick utility, idk the best way to do this but
	static float AverageValueOfVector(vector vec)
	{
		return (vec[0] + vec[1] + vec[2]) / 3.0;
	}
	
	void ApplyRecoilModifier(inout vector modifier_value)
	{
		vector value = GetModifierValue("recoilModifier");
		modifier_value[0] = value[0] * modifier_value[0];
		modifier_value[1] = value[1] * modifier_value[1];
		modifier_value[2] = value[2] * modifier_value[2];
	}	
	
	void ApplySwayModifier(inout vector modifier_value)
	{
		vector value = GetModifierValue("swayModifier");
		modifier_value[0] = value[0] * modifier_value[0];
		modifier_value[1] = value[1] * modifier_value[1];
		modifier_value[2] = value[2] * modifier_value[2];
	}
		
	void ApplyADSModifier(inout vector modifier_value)
	{
		vector value = GetModifierValue("adsModifier");
		modifier_value[0] = value[0] * modifier_value[0];
		modifier_value[1] = value[1] * modifier_value[1];
		modifier_value[2] = value[2] * modifier_value[2];
	}	
	
	void ApplySightMisalignmentModifier(inout vector modifier_value)
	{
		vector value = GetModifierValue("sightMisalignmentModifier");
		modifier_value[0] = value[0] * modifier_value[0];
		modifier_value[1] = value[1] * modifier_value[1];
		modifier_value[2] = value[2] * modifier_value[2];
	}
	
	vector GetModifierValue(string modifier_name, vector default = "1 1 1")
	{
		if (!ConfigIsExisting(modifier_name)) {
			return default;
		}

		return ConfigGetVector(modifier_name);
	}
		
	// gets all items inside this and finds their product, getting the full recoil modifier
	void ApplyTotalRecoilModifier(inout vector modifier_value)
	{		
		ApplyRecoilModifier(modifier_value);
		for (int i = 0; i < GetInventory().AttachmentCount(); ++i)
		{
			ItemBase item = ItemBase.Cast(GetInventory().GetAttachmentFromIndex(i));
			if (!item || item == this) {
				continue;
			}
			
			item.ApplyTotalRecoilModifier(modifier_value);
		}
	}	
	
	void ApplyTotalSwayModifier(inout vector modifier_value)
	{		
		ApplySwayModifier(modifier_value);
		for (int i = 0; i < GetInventory().AttachmentCount(); ++i)
		{
			ItemBase item = ItemBase.Cast(GetInventory().GetAttachmentFromIndex(i));
			if (!item || item == this) {
				continue;
			}
			
			item.ApplyTotalSwayModifier(modifier_value);
		}
	}	

	void ApplyTotalADSModifier(inout vector modifier_value)
	{
		ApplyADSModifier(modifier_value);
		
		for (int i = 0; i < GetInventory().AttachmentCount(); ++i)
		{
			ItemBase item = ItemBase.Cast(GetInventory().GetAttachmentFromIndex(i));
			if (!item || item == this) {
				continue;
			}
			
			item.ApplyTotalADSModifier(modifier_value);
		}
	}
		
	void ApplyTotalSightMisalignmentModifier(inout vector modifier_value)
	{		
		ApplySightMisalignmentModifier(modifier_value);
		
		for (int i = 0; i < GetInventory().AttachmentCount(); ++i)
		{
			ItemBase item = ItemBase.Cast(GetInventory().GetAttachmentFromIndex(i));
			if (!item || item == this) {
				continue;
			}
			
			item.ApplyTotalSightMisalignmentModifier(modifier_value);
		}
	}
	float GetDefaultRecoilModifierPercentage()
	{
		vector modifier_value = "1 1 1";
		ApplyRecoilModifier(modifier_value);
		return AverageValueOfVector(modifier_value);
	}
		
	float GetRecoilModifierPercentage()
	{
		vector modifier_value = "1 1 1";
		ApplyTotalRecoilModifier(modifier_value);
		return AverageValueOfVector(modifier_value);
	}
		
	float GetDefaultSwayModifierPercentage()
	{
		vector modifier_value = "1 1 1";
		ApplySwayModifier(modifier_value);
		return AverageValueOfVector(modifier_value);
	}
	
	float GetSwayModifierPercentage()
	{
		vector modifier_value = "1 1 1";
		ApplyTotalSwayModifier(modifier_value);
		return AverageValueOfVector(modifier_value);
	}
		
	float GetDefaultADSModifierPercentage()
	{
		
		vector modifier_value = "1 1 1";
		ApplyADSModifier(modifier_value);
		return AverageValueOfVector(modifier_value);
	}	
	float GetADSModifierPercentage()
	{
		vector modifier_value = "1 1 1";
		ApplyTotalADSModifier(modifier_value);
		return AverageValueOfVector(modifier_value);
	}
			
	float GetSightMisalignmentModifierPercentage()
	{
		vector modifier_value = "1 1 1";
		ApplyTotalSightMisalignmentModifier(modifier_value);
		return AverageValueOfVector(modifier_value);
	}
		
	// This is quite slow, but called on client soo i think were ookay?
	bool HasWeaponModifiers()
	{
		return (GetRecoilModifierPercentage() != 1.0 || GetSwayModifierPercentage() != 1.0 || GetADSModifierPercentage() != 1.0 || GetSightMisalignmentModifierPercentage() != 1.0);
	}
}