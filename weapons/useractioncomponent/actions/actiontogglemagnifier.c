class ActionZoomMagnifierBase: FirearmActionBase
{
	void ActionZoomMagnifierBase()
	{
		m_Text = "Flip Magnifier";
		m_StanceMask 	= DayZPlayerConstants.STANCEMASK_ALL;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined();
		m_ConditionTarget = new CCTSelf;
	}

	override int GetActionCategory()
	{
		return AC_SINGLE_USE;
	}

	override int GetStanceMask(PlayerBase player)
	{
		return DayZPlayerConstants.STANCEMASK_ALL;
	}
	
	override bool HasTarget()
	{
		return false;
	}
	
	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);
		
		OpticMagnifier_Base magnifier_base = OpticMagnifier_Base.Cast(action_data.m_MainItem.GetAttachmentByType(OpticMagnifier_Base));
		if (!magnifier_base) {
			return;
		}
		
		magnifier_base.SetMagnifierState(!magnifier_base.GetMagnifierState());
	}
}

class ActionZoomInMagnifier: ActionZoomMagnifierBase
{
	override typename GetInputType()
	{
		return ZoomInMagnifierActionInput;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{		
		OpticMagnifier_Base magnifier_base = OpticMagnifier_Base.Cast(item.GetAttachmentByType(OpticMagnifier_Base));
		if (!magnifier_base) {
			return false;
		}
		
		return !magnifier_base.GetMagnifierState();
	}

	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient(action_data);
		
		OpticMagnifier_Base magnifier_base = OpticMagnifier_Base.Cast(action_data.m_MainItem.FindAttachmentBySlotName("weaponMagnifier"));
		if (!magnifier_base) {
			return;
		}

		RA_MagnifierCompatibleOptic_Base optic = RA_MagnifierCompatibleOptic_Base.Cast(action_data.m_MainItem.FindAttachmentBySlotName("weaponOptics"));
		if (!optic) {
			return;
		}
		
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		//checking if raised to apply hide selections
		if(!player) {
			return;
		}

		HumanInputController hic = player.GetInputController();
		if(!hic.WeaponADS()) {
			return;
		}

		action_data.m_MainItem.SetSimpleHiddenSelectionState(0, 0);
        optic.HideSelection("magnifier");
	}

	override void OnStart(ActionData action_data)
	{
		super.OnStart(action_data);
		
		OpticMagnifier_Base magnifier_base = OpticMagnifier_Base.Cast(action_data.m_MainItem.FindAttachmentBySlotName("weaponMagnifier"));
		if (!magnifier_base) {
			return;
		}

		magnifier_base.HideSelection("hide");
	}
}

class ActionZoomOutMagnifier: ActionZoomMagnifierBase
{
	override typename GetInputType()
	{
		return ZoomOutMagnifierActionInput;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{		
		OpticMagnifier_Base magnifier_base = OpticMagnifier_Base.Cast(item.GetAttachmentByType(OpticMagnifier_Base));
		if (!magnifier_base) {
			return false;
		}
		
		return magnifier_base.GetMagnifierState();
	}

	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient(action_data);
		
		OpticMagnifier_Base magnifier_base = OpticMagnifier_Base.Cast(action_data.m_MainItem.FindAttachmentBySlotName("weaponMagnifier"));
		if (!magnifier_base) {
			return;
		}

		RA_MagnifierCompatibleOptic_Base optic = RA_MagnifierCompatibleOptic_Base.Cast(action_data.m_MainItem.FindAttachmentBySlotName("weaponOptics"));
		if (!optic) {
			return;
		}

		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		//checking if raised to apply hide selections
		if(!player) {
			return;
		}

		HumanInputController hic = player.GetInputController();
		if(!hic.WeaponADS()) {
			return;
		}

		action_data.m_MainItem.SetSimpleHiddenSelectionState(0, 1);
        optic.ShowSelection("magnifier");
	}

	override void OnStart(ActionData action_data)
	{
		super.OnStart(action_data);
		
		OpticMagnifier_Base magnifier_base = OpticMagnifier_Base.Cast(action_data.m_MainItem.FindAttachmentBySlotName("weaponMagnifier"));
		if (!magnifier_base) {
			return;
		}

		magnifier_base.ShowSelection("hide");
	}
}

class ZoomInMagnifierActionInput: DefaultActionInput
{
	void ZoomInMagnifierActionInput(PlayerBase player)
	{
		SetInput("UAZoomInOptics");
		m_InputType = ActionInputType.AIT_SINGLE;
	}

	override void OnActionStart()
	{
		super.OnActionStart();
		m_Active = false;
	}
	
	override bool WasEnded() return false;
}

class ZoomOutMagnifierActionInput: DefaultActionInput
{
	void ZoomOutMagnifierActionInput(PlayerBase player)
	{
		SetInput("UAZoomOutOptics");
		m_InputType = ActionInputType.AIT_SINGLE;
	}

	override void OnActionStart()
	{
		super.OnActionStart();
		m_Active = false;
	}
	
	override bool WasEnded() return false;
}