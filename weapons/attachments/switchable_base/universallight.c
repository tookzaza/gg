modded class UniversalLight
{
	static const int LIGHT_COUNT = 4;
	
	// we are doing multiple lights to increase the obstruction
	protected ref array<UniversallightLight> m_Lights = {};
	
	override void OnWorkStart()
	{
		if (g_Game.IsDedicatedServer()) {
			return;
		}
		
		for (int i = 0; i < LIGHT_COUNT; i++) {
			UniversallightLight light = UniversallightLight.Cast(ScriptedLightBase.CreateLight(UniversallightLight, "0 0 0", 0.08)); // Position is zero because light is attached on parent immediately.
			light.AttachOnMemoryPoint(this, "beamStart", "beamEnd");
			m_Lights.Insert(light);
			if (i != 0) {
				light.SetBrightnessTo(0.01);
			}
		}
		
		SetObjectMaterial(GLASS_ID, LIGHT_ON_GLASS);
		SetObjectMaterial(REFLECTOR_ID, LIGHT_ON_REFLECTOR);
	}
	
	override void OnWork( float consumed_energy )
	{
		if (g_Game.IsDedicatedServer()) {
			return;
		}
		
		Battery9V battery = Battery9V.Cast(GetCompEM().GetEnergySource());
		if (!battery) {
			return;
		}
		
		foreach (UniversallightLight light: m_Lights) {
			if (!light) {
				continue;
			}
			
			float efficiency = battery.GetEfficiency0To1();
			if (efficiency < 1) {
				light.SetIntensity(efficiency, GetCompEM().GetUpdateInterval());
			} else {
				light.SetIntensity(1, 0);
			}
		}
	}
	
		
	override void OnWorkStop()
	{	
		if (g_Game.IsDedicatedServer()) {
			return;
		}

		foreach (UniversallightLight light: m_Lights) { 
			if (light) {
				light.FadeOut();
			}
		}
		
		SetObjectMaterial(GLASS_ID, LIGHT_OFF_GLASS);
		SetObjectMaterial(REFLECTOR_ID, LIGHT_OFF_REFLECTOR);
	}
}