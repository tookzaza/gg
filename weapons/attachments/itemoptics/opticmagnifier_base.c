class OpticMagnifier_Base: ItemBase
{
	static ref array<typename> REQUIRED_ATTACHMENT_TYPES = {
		RA_AimpointT2,
		RA_XPS3_Holosight,
		RA_Vortex_UH1,
		RA_Pilad
	};

	protected bool m_State;
	
	void OpticMagnifier_Base()
	{
		RegisterNetSyncVariableBool("m_State");
	}
	
	void SetMagnifierState(bool state)
	{
		if (!g_Game.IsServer()) {
			return;
		}
		
		m_State = state;
		SetSynchDirty();
		
		SetAnimationPhase("flip", !m_State);
	}
	
	bool GetMagnifierState()
	{
		return m_State;
	}
		
	float GetSightMultiplier()
	{
		return Ternary<float>.If(m_State, ConfigGetFloat("magnifierMultiplier"), 1);
	}

	override bool CanPutAsAttachment(EntityAI parent)
	{
		ItemOptics compatible_optic;
		Class.CastTo(compatible_optic, parent.FindAttachmentBySlotName("weaponOptics"));
		if (!compatible_optic) {
			return false;
		}

		foreach (typename required_attachment_type: REQUIRED_ATTACHMENT_TYPES) {
			if (compatible_optic.IsInherited(required_attachment_type)) {
				return true;
			}
		}

		return false;
	}
	
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		
		ctx.Write(m_State);
	}
	
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version)) {
			return false;
		}
		
		return ctx.Read(m_State);
	}
	
	override void AfterStoreLoad()
	{
		super.AfterStoreLoad();
		
		SetMagnifierState(m_State);
	}
}

class RA_G33_Magnifier: OpticMagnifier_Base{};