class RA_Ammo_127x55: Ammunition_Base{}
class RA_Ammo_127x99: Ammunition_Base{}
class RA_Ammo_338lm: Ammunition_Base{}
class RA_Ammo_408: Ammunition_Base{}
class Ammo_46x30: Ammunition_Base{}
class Ammo_57x28: Ammunition_Base{}
class RA_Ammo_300AAC: Ammunition_Base{}
class RA_Ammo_Railgun: Ammunition_Base{}


class RA_Ammo_RPG7: Ammunition_Base{}

class Ammo_ExplosiveBolt: Bolt_Base 
{
	static const int RPC_START_EFFECT = 235238;
	
	static const int EFFECT_LENGTH_TOTAL = 8000;
	static const int EFFECT_BLIP_LENGTH = 100;
	
	protected PointLightBase m_Light;
	
	void ~Ammo_ExplosiveBolt()
	{
		if (m_Light) {
			m_Light.Destroy();
		}
	}
	
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		
		switch (rpc_type) {
			case RPC_START_EFFECT: {
				if (g_Game.IsDedicatedServer()) {
					break;
				}
				
				m_Light = PointLightBase.Cast(ScriptedLightBase.CreateLight(PointLightBase));
				m_Light.AttachOnObject(this, "0 0 0.5");
				m_Light.SetAmbientColor(255, 255, 0);
				m_Light.SetDiffuseColor(255, 35, 35);
				RunEffect(EFFECT_LENGTH_TOTAL, true);
				break;
			}
		}
	}
	
	override void SetFromProjectile(ProjectileStoppedInfo info)
	{
		super.SetFromProjectile(info);
		
		TerrainCollisionInfo terrain_info = TerrainCollisionInfo.Cast(info);
		if (terrain_info && terrain_info.GetIsWater()) {
			return;
		}
				
		ScriptRPC().Send(this, RPC_START_EFFECT, true);
		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(DoExplosion, EFFECT_LENGTH_TOTAL);
	}
	
	protected void DoExplosion()
	{
		Explosive_Bolt explosive_bolt = Explosive_Bolt.Cast(g_Game.CreateObject("Explosive_Bolt", GetWorldPosition()));
		if (explosive_bolt) {
			explosive_bolt.Explode(this);
			Explode(DamageType.EXPLOSION, explosive_bolt.GetExplosiveType());
		}
	}

	override void OnExplodeClient()
	{
		super.OnExplodeClient();
		
		ParticleManager.GetInstance().PlayInWorld(ParticleList.GRENADE_M84, GetPosition());
	}
	
	protected void RunEffect(int time_remaining, bool state)
	{
		if (time_remaining <= 1) {
			m_Light.SetRadiusTo(0);
			m_Light.SetBrightnessTo(0);
			return;
		}
				
		m_Light.SetVisibleDuringDaylight(state);
		m_Light.SetBrightnessTo(0.4 * state);
		m_Light.SetFlareVisible(state);
		m_Light.SetRadiusTo(3.0 * state);
		
		// using normal distribution because its fucking cool
		int delta_time = Math.Poisson(time_remaining / EFFECT_LENGTH_TOTAL, 2) * time_remaining;
		if (state) {
			SEffectManager.PlaySound("Beep2_SoundSet", GetWorldPosition());
			delta_time = EFFECT_BLIP_LENGTH;
		}

		g_Game.GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RunEffect, delta_time, false, time_remaining - delta_time, !state);
	}
}