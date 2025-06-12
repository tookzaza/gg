modded class FirearmActionLoadBullet
{
	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);
		if (action_data.m_MainItem && action_data.m_MainItem.IsInherited(RA_RPG7_Base))
			RA_RPG7_Base.Cast(action_data.m_MainItem).AssembleGun();
	}
	
	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);
		if (action_data.m_MainItem && action_data.m_MainItem.IsInherited(RA_RPG7_Base))
			RA_RPG7_Base.Cast(action_data.m_MainItem).AssembleGun();
	}
}

class RA_RPG7_Base: Archery_Base
{
	override RecoilBase SpawnRecoilObject()
	{
		return new MachineGunRecoil(this);
	}

	#ifndef SERVER
	override void EEInit()
	{
		super.EEInit();

		g_Game.GetCallQueue(CALL_CATEGORY_GAMEPLAY).Call(UpdateVisuals);
	}

	void UpdateVisuals()
	{
		AssembleGun();

		if (FindAttachmentBySlotName("weaponOptics")) { 
			SetObjectTexture(2,"");
		}
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);

		if (ItemOptics.Cast(item))
		{
			SetObjectTexture(2,"");
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		if (ItemOptics.Cast(item))
		{
			SetObjectTexture(2,"RearmedServer\\Firearms\\RPG\\model\\data\\rpg7_co.paa");
		}
	}
	#endif

    override bool CanReceiveAttachment( EntityAI attachment, int slotId )
    {
        if ( slotId == InventorySlots.GetSlotIdFromString("weaponOptics") )
		{
			if ( FindAttachmentBySlotName("Rail") != NULL && FindAttachmentBySlotName("weaponOpticsAK") == NULL)
			{
				return true;
			}
			return false;
		}
		if ( slotId == InventorySlots.GetSlotIdFromString("weaponOpticsAK") )
		{
			if ( FindAttachmentBySlotName("Rail") == NULL )
			{
				return true;
			}
			return false;
		}
        return true;
    }

	override bool CanDisplayAttachmentSlot(int slot_id)
    {
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOptics"))
		{
            return (FindAttachmentBySlotName("Rail") != NULL);
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("weaponOpticsAK"))
		{
            return (!FindAttachmentBySlotName("Rail"));
		}
		if (slot_id == InventorySlots.GetSlotIdFromString("Rail"))
		{
            return (!FindAttachmentBySlotName("weaponOpticsAK"));
		}
        return super.CanDisplayAttachmentSlot(slot_id);
    }

	override void AssembleGun()
	{
		if (IsChamberEmpty(0)) {
			HideBullet(0);
		}
	}

	override float GetChanceToJam()
	{
		return 0;
	}

	override bool ShootsExplosiveAmmo()
	{
		return true;
	}

	override void InitStateMachine()
	{
		// setup abilities
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_OPENED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_SPECIAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_CROSSBOW_OPENED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_CROSSBOW_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_UNCOCKED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_COCKED));

		// setup state machine
		// basic weapon states
		WeaponStableState U = new XBUncockedEmpty(this, NULL, XBAnimState.uncocked);
		WeaponStableState C = new XBCockedEmpty(this, NULL, XBAnimState.cocked);
		WeaponStableState L = new XBLoaded(this, NULL, XBAnimState.cocked);
		// unstable (intermediate) states
		WeaponChargingStretch Mech_U = new WeaponChargingStretch(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_OPENED);
		WeaponEjectBullet Mech_L = new WeaponEjectBullet(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_SPECIAL);
		
		WeaponChambering Chamber_U = new WeaponChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_CROSSBOW_OPENED);
		WeaponChambering Chamber_C = new WeaponChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_CROSSBOW_CLOSED);
		//CrossbowReChambering Chamber_L = new CrossbowReChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_ONEBULLET_CLOSED);
		
		WeaponStateBase Trigger_U = new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_UNCOCKED);
		WeaponStateBase Trigger_C = new WeaponDryFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_COCKED);
		WeaponStateBase Trigger_L = new WeaponFireLast(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL);
		
		WeaponStateBase Unjam_J = new WeaponUnjamming(this, NULL, WeaponActions.UNJAMMING, WeaponActionUnjammingTypes.UNJAMMING_START);

		// events
		WeaponEventBase __M__ = new WeaponEventMechanism;
		WeaponEventBase __T__ = new WeaponEventTrigger;
		WeaponEventBase __TJ_ = new WeaponEventTriggerToJam;
		WeaponEventBase __L__ = new WeaponEventLoad1Bullet;
		WeaponEventBase __U__ = new WeaponEventUnjam;
		WeaponEventBase _fin_ = new WeaponEventHumanCommandActionFinished;
		WeaponEventBase _abt_ = new WeaponEventHumanCommandActionAborted;
		WeaponEventBase _dto_ = new WeaponEventDryFireTimeout;

		m_fsm = new WeaponFSM();
		
		//Charging
		m_fsm.AddTransition(new WeaponTransition( C,			__M__,	C));
		
		m_fsm.AddTransition(new WeaponTransition( U,			__M__,	Mech_U));
		m_fsm.AddTransition(new WeaponTransition(  Mech_U,		_fin_,	U, null, new WeaponGuardWeaponDischarged(this)));		
		m_fsm.AddTransition(new WeaponTransition(  Mech_U,		_fin_,	C ));
		m_fsm.AddTransition(new WeaponTransition(  Mech_U,		_abt_,	U, null, new WeaponGuardWeaponDischarged(this)));		
		m_fsm.AddTransition(new WeaponTransition(  Mech_U,		_abt_,	C ));
		
		m_fsm.AddTransition(new WeaponTransition( L,			__M__,	Mech_L));
		m_fsm.AddTransition(new WeaponTransition(  Mech_L,		_fin_,	C, null, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition(  Mech_L,		_fin_,	L));	
		m_fsm.AddTransition(new WeaponTransition(  Mech_L,		_abt_,	C, null, new WeaponGuardChamberEmpty(this)));
		m_fsm.AddTransition(new WeaponTransition(  Mech_L,		_abt_,	L));
			
		
		//Chamber bolt
		m_fsm.AddTransition(new WeaponTransition( U,			__L__,	Chamber_U));
		m_fsm.AddTransition(new WeaponTransition(  Chamber_U,		_fin_,	L, null, new WeaponGuardChamberFull(this)));
		m_fsm.AddTransition(new WeaponTransition(  Chamber_U,		_fin_,	C, null, new WeaponGuardWeaponCharged(this)));
		m_fsm.AddTransition(new WeaponTransition(  Chamber_U,		_fin_,	U));	
		m_fsm.AddTransition(new WeaponTransition(  Chamber_U,		_abt_,	L, null, new WeaponGuardChamberFull(this)));
		m_fsm.AddTransition(new WeaponTransition(  Chamber_U,		_abt_,	C, null, new WeaponGuardWeaponCharged(this)));
		m_fsm.AddTransition(new WeaponTransition(  Chamber_U,		_abt_,	U));
		
		
		m_fsm.AddTransition(new WeaponTransition( C,			__L__,	Chamber_C));
		m_fsm.AddTransition(new WeaponTransition(  Chamber_C,		_fin_,	L, null, new WeaponGuardChamberFull(this)));		
		m_fsm.AddTransition(new WeaponTransition(  Chamber_C,		_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Chamber_C,		_abt_,	L, null, new WeaponGuardChamberFull(this)));		
		m_fsm.AddTransition(new WeaponTransition(  Chamber_C,		_abt_,	C));
		
		m_fsm.AddTransition(new WeaponTransition( C,			__T__,	Trigger_C));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_C,	_fin_,	U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_C,	_abt_,	U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_C,	_dto_,	U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_C,	_abt_,	U));
		
		m_fsm.AddTransition(new WeaponTransition( U,			__T__,	Trigger_U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_U,	_fin_,	U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_U,	_abt_,	U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_U,	_dto_,	U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_U,	_abt_,	U));
		
		m_fsm.AddTransition(new WeaponTransition( L,			__T__,	Trigger_L));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_L,	_fin_,	U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_L,	_abt_,	U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_L,	_dto_,	U));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_L,	_abt_,	U));

		SelectionBulletHide();
		EffectBulletHide(0);
		
		SetInitialState(U);
		m_fsm.Start();
	}
}

class RA_RPG7: RA_RPG7_Base{};

class RocketLight: PointLightBase
{
	void RocketLight()
	{
		SetFlareVisible(true);
		SetVisibleDuringDaylight(true);
		SetDiffuseColor(1.3, 0.35, 0.15);
		SetAmbientColor(1.3, 0.35, 0.15);
		SetBrightnessTo(100.0);
		SetRadiusTo(50.0);
		SetCastShadow(true);
		EnableHeatHaze(true);
		
		SetFlickerAmplitude(0.2);
		SetFlickerSpeed(1);
		SetDancingShadowsMovementSpeed(0.5);
		SetDancingShadowsAmplitude(0.03);
		
		SetHeatHazePower(0.1);
		SetHeatHazeRadius(3);
	}
}

class RocketSimulation: Managed
{
	protected Particle m_Particle;
	protected EffectSound m_Sound;
	protected ScriptedLightBase m_Light;
	
	void OnFire(Entity entity)
	{		
		if (!GetGame().IsDedicatedServer()) {
			m_Light = ScriptedLightBase.CreateLight(RocketLight, Vector(0, 0, 0));
			m_Light.AttachOnObject(entity);
			
			entity.PlaySoundSetLoop(m_Sound, "roadflareLoop_SoundSet", 0, 0);
			//m_Sound.GetWaveObject().SetVolume(2.0);
			m_Particle = ParticleManager.GetInstance().PlayOnObject(ParticleList.JDRPG_SmokeTail, entity);
			
		}
	}
	
	void ~RocketSimulation()
	{
		if (m_Particle) {
			
			m_Particle.Stop();
			m_Particle.Delete();
			m_Particle = null;
		}
		
		if (m_Sound) {
			m_Sound.SoundStop();
		}
		
		if (m_Light) {
			m_Light.Delete();
		}
	}
}

modded class WeaponManager
{
    override void Fire(Weapon_Base wpn)
    {
        super.Fire(wpn);
        if(wpn.ClassName().Contains("RA_RPG7"))
        {
            for( int i = 0; i < wpn.GetMuzzleCount(); i++ )
            {
                    if(wpn.IsChamberEmpty(i))
                    {
                        wpn.EjectCasing(i);
                        wpn.EffectBulletHide(i);
                        wpn.HideBullet(i);
                    }
            }
        }
    }
}