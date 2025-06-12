class ActionToggleBipod: ActionSingleUseBase
{
	void ActionToggleBipod()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_ATTACHBARREL;
		m_Text = "Toggle Bipod";
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCIPresent;
		m_ConditionTarget = new CCTNone;
	}
	
	override bool HasTarget()
	{
		return false;
	}
	
	override bool UseMainItem()
	{
		return true;
	}

	override typename GetInputType()
	{
		return ToggleBipodActionInput;
	}
			
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!super.ActionCondition(player, target, item)) {
			return false;
		}
				
		Weapon_Base weapon = Weapon_Base.Cast(item);
		if (!weapon) {
			return false;
		}
		
		return weapon.FindBipod() != null;
	}
	
	override void OnExecuteServer(ActionData action_data)
	{
		super.OnExecuteServer(action_data);
		
		Weapon_Base weapon = Weapon_Base.Cast(action_data.m_MainItem);
		if (!weapon) {
			return;
		}
		
		RA_Bipod_Base bipod = weapon.FindBipod();
		if (!bipod) {
			return;
		}
		
		bipod.SetDeployed(!bipod.IsDeployed());
	}
}

class ToggleBipodActionInput: DefaultActionInput
{
	void ToggleBipodActionInput(PlayerBase player)
	{
		SetInput("UAToggleBipod");
		m_InputType = ActionInputType.AIT_SINGLE;
	}

	override void OnActionStart()
	{
		super.OnActionStart();
		m_Active = false;
	}
	
	override bool WasEnded() return false;
}