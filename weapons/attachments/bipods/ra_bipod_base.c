class RA_Bipod_Base: ItemBase
{	
	protected bool m_IsDeployed;
	
	void RA_Bipod_Base()
	{
		RegisterNetSyncVariableBool("m_IsDeployed");
	}
	
	bool IsDeployed()
	{
		return m_IsDeployed;
	}
	
	// Returns success, not new state
	void SetDeployed(bool state)
	{
		if (!g_Game.IsServer()) {
			return;
		}
		
		
		if (!FindParentWeapon()) {
			return;
		}
		
		
		m_IsDeployed = state;
		SetAnimationPhase("bipod", m_IsDeployed);
		SetSynchDirty();
	}
	
	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		super.OnWasDetached(parent, slot_id);
		
		// Fold the bipod on detach always
		if (g_Game.IsServer() && IsDeployed()) {
			SetDeployed(false);
		}
	}
	
	// Recursively search up for a weapon
	Weapon_Base FindParentWeapon()
	{
		EntityAI parent = GetHierarchyParent();
		while (parent) {
			Weapon_Base weapon_parent = Weapon_Base.Cast(parent);
			if (weapon_parent) {
				return weapon_parent;
			}
			
			parent = parent.GetHierarchyParent();
		}
		
		return null;
	}
	
	override void ApplyRecoilModifier(inout vector modifier_value)
	{
		DayZPlayerImplement player = DayZPlayerImplement.Cast(GetHierarchyRootPlayer());
		if (!player) {
			return;
		}
		
		HumanMovementState movement_state = new HumanMovementState();
		player.GetMovementState(movement_state);
		if (!movement_state.IsRaisedInProne()) {
			return;
		}
		
		if (!IsDeployed()) {
			return;
		}
		
		vector value = GetModifierValue("recoilModifier");
		modifier_value[0] = value[0] * modifier_value[0];
		modifier_value[1] = value[1] * modifier_value[1];
		modifier_value[2] = value[2] * modifier_value[2];
	}		
	
	override void ApplySwayModifier(inout vector modifier_value)
	{
		DayZPlayerImplement player = DayZPlayerImplement.Cast(GetHierarchyRootPlayer());
		if (!player) {
			return;
		}
		
		HumanMovementState movement_state = new HumanMovementState();
		player.GetMovementState(movement_state);
		if (!movement_state.IsRaisedInProne()) {
			return;
		}
		
		if (!IsDeployed()) {
			return;
		}
		
		vector value = GetModifierValue("swayModifier");
		modifier_value[0] = value[0] * modifier_value[0];
		modifier_value[1] = value[1] * modifier_value[1];
		modifier_value[2] = value[2] * modifier_value[2];
	}
}

class RA_Atlas_Bipod: RA_Bipod_Base
{
}

class RA_Harris_Bipod: RA_Bipod_Base
{
}

class RA_Magpul_Bipod: RA_Bipod_Base
{
}

class RA_M249_Bipod: RA_Bipod_Base
{
}

class RA_M200_Bipod: RA_Bipod_Base
{
}

class RA_PKM_Bipod: RA_Bipod_Base
{
}