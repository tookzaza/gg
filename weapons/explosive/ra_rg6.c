const float RG6_ROTATION_POSITION_M1 = -0.167;
const float RG6_ROTATION_POSITION_0 = 0.0;
const float RG6_ROTATION_POSITION_1 = 0.167;
const float RG6_ROTATION_POSITION_2 = 0.334;
const float RG6_ROTATION_POSITION_3 = 0.500;
const float RG6_ROTATION_POSITION_4 = 0.668;
const float RG6_ROTATION_POSITION_5 = 0.835;
const float RG6_ROTATION_POSITION_6 = 1.0;


enum RG6AnimState
{
	DEFAULT 			= 0, 	///< default weapon state
};

enum RG6StableStateID
{
	UNKNOWN				=  0,
	DEFAULT				=  1,
}

class RG6_Static_State extends WeaponStableState
{
	bool init = false;
	override void OnEntry(WeaponEventBase e) 
	{		
		if (LogManager.IsWeaponLogEnable()) { wpnPrint("[wpnstate] { RG6 stable state"); } 
		super.OnEntry(e);
		if (init)
		{
			RA_RG6_Base RG6;
			if (CastTo(RG6, m_weapon))
			{
				RG6.SyncCylinderRotation();
			}
		}
		init = true;
	}

	override void OnExit (WeaponEventBase e) { super.OnExit(e); if (LogManager.IsWeaponLogEnable()) { wpnPrint("[wpnstate] }  RG6 stable state"); } }
	override int GetCurrentStateID () { return RG6StableStateID.DEFAULT; }
	override bool HasBullet() { return m_weapon.IsChamberFull(m_weapon.GetCurrentMuzzle()); }
	override bool HasMagazine() { return false; }
	override bool IsJammed() { return m_weapon.IsJammed(); }
	override bool IsSingleState() { return true; }
};

class RA_RG6_Base: Weapon_Base
{
	ref WeaponStateBase C;
	int m_LastMuzzleloaded;
	int m_ActiveMuzzle;
	const string ATT_SLOT_CYLINDER = "RA_RG6_Cylinder";
	
	override void SetActions()
	{
		AddAction(FirearmActionLoadMultiBulletQuick);
		super.SetActions();
		AddAction(FirearmActionLoadMultiBullet);
	}
	
	override RecoilBase SpawnRecoilObject()
	{
		return new M79Recoil(this);
	}
	
	void RA_RG6_Base ()
	{
		m_LastMuzzleloaded = 0;
		m_ActiveMuzzle = 0;
	}
	
	override void InitStateMachine ()
	{
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED_KEEP));
		m_abilities.Insert(new AbilityRecord(WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE));
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED));
		m_abilities.Insert(new AbilityRecord(WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_SPECIAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL));
		m_abilities.Insert(new AbilityRecord(WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY));


		// setup state machine
		// basic weapon state
		C = new RG6_Static_State(this, NULL, RG6AnimState.DEFAULT);


		RG6WeaponChambering Chamber = new RG6WeaponChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED_KEEP,WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);
		RG6WeaponChambering Chamber_E = new RG6WeaponChambering(this, NULL, WeaponActions.CHAMBERING, WeaponActionChamberingTypes.CHAMBERING_STARTLOOPABLE_CLOSED,WeaponActionChamberingTypes.CHAMBERING_ENDLOOPABLE);

		WeaponCharging Mech = new WeaponCharging(this, NULL, WeaponActions.MECHANISM, WeaponActionMechanismTypes.MECHANISM_CLOSED);
		
		WeaponStateBase	Trigger_normal = new RG6WeaponFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_NORMAL);
		WeaponStateBase	Trigger_dry = new RG6WeaponFire(this, NULL, WeaponActions.FIRE, WeaponActionFireTypes.FIRE_DRY);
		
		// events

		WeaponEventBase __L__ = new WeaponEventLoad1Bullet;
		WeaponEventBase _fin_ = new WeaponEventHumanCommandActionFinished;
		WeaponEventBase _abt_ = new WeaponEventHumanCommandActionAborted;
		WeaponEventBase __M__ = new WeaponEventMechanism;
		WeaponEventBase __T__ = new WeaponEventTrigger;
		

		WeaponEventBase _rto_ = new WeaponEventReloadTimeout;
		WeaponEventBase _dto_ = new WeaponEventDryFireTimeout;

	
		m_fsm = new WeaponFSM();



		m_fsm.AddTransition(new WeaponTransition( C,				__L__,	Chamber, null, new WeaponGuardAnyChamberFiredOut(this))); // chamber from closed charged
		m_fsm.AddTransition(new WeaponTransition(  Chamber,	_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Chamber,	_abt_,	C));

		
		m_fsm.AddTransition(new WeaponTransition( C,				__L__,	Chamber_E)); // chamber from closed charged
		m_fsm.AddTransition(new WeaponTransition(  Chamber_E,	_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Chamber_E,	_abt_,	C));

		
		m_fsm.AddTransition(new WeaponTransition( C,				__M__,	Mech)); // charge from closed
		m_fsm.AddTransition(new WeaponTransition(  Mech,		_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Mech,		_abt_,	C));

		
		
		m_fsm.AddTransition(new WeaponTransition( C,				__T__,	Trigger_normal, null, new GuardAnd (new WeaponGuardCurrentChamberFull(this), new GuardNot(new WeaponGuardCurrentChamberFiredOut(this))) )); // fire.cocked
		m_fsm.AddTransition(new WeaponTransition(  Trigger_normal,	_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_normal, 	_dto_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_normal, 	_abt_,	C));
		
		m_fsm.AddTransition(new WeaponTransition( C,				__T__,	Trigger_dry)); // fire.cocked
		m_fsm.AddTransition(new WeaponTransition(  Trigger_dry,	_fin_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_dry, 	_dto_,	C));
		m_fsm.AddTransition(new WeaponTransition(  Trigger_dry, 	_abt_,	C));


		m_fsm.SetInitialState(C);
		SelectionBulletHide();
		SetCurrentMuzzle(0);
		//HideMagazine();
		m_fsm.Start();
	}
	
	override bool CanChamberBullet(int muzzleIndex, Magazine mag)
	{
		for (int i = 0; i < GetMuzzleCount(); i++)
		{
			if ( CanChamberFromMag(i, mag) )
			{
				if (IsChamberEmpty(i))
					return true;
				
				if (IsChamberFiredOut(i))
					return true;
			} 
		}
		return false;
	}
	
	override void AssembleGun()
	{
		super.AssembleGun();
		
		if ( !FindAttachmentBySlotName(ATT_SLOT_CYLINDER) )
		{
			GetInventory().CreateAttachment("RA_RG6_Cylinder");
		}

		ForceSyncSelectionState();
		SyncCylinderRotation();
	}
	
	static float GetCylinderRotation(int muzzleIndex)
	{
		switch (muzzleIndex)
		{
			case 0:
				return RG6_ROTATION_POSITION_0;
			case 1:
				return RG6_ROTATION_POSITION_5;
			case 2:
				return RG6_ROTATION_POSITION_4;
			case 3:
				return RG6_ROTATION_POSITION_3;
			case 4:
				return RG6_ROTATION_POSITION_2;
			case 5:
				return RG6_ROTATION_POSITION_1;
		}
		
		ErrorEx(string.Format("Invalid muzzle index: %1", muzzleIndex));
		
		return RG6_ROTATION_POSITION_0;
	}
	
	void SetCylinderRotationAnimationPhase(float rot, bool reset = false)
	{
		RA_RG6_Cylinder cylinder = RA_RG6_Cylinder.Cast(GetAttachmentByType(RA_RG6_Cylinder));
		if (cylinder)
		{
			float anim_phase = cylinder.GetAnimationPhase("Rotate_Cylinder");
			if ( Math.AbsFloat(anim_phase - rot) > 0.1 )
			{
				if (reset)
				{
					cylinder.ResetAnimationPhase("Rotate_Cylinder", rot );
				}				
				else if (rot == RG6_ROTATION_POSITION_0)
				{
					cylinder.ResetAnimationPhase("Rotate_Cylinder", RG6_ROTATION_POSITION_M1 );
				}
				
				cylinder.SetAnimationPhase("Rotate_Cylinder", rot );
			}
		}
	}
	
	void SyncCylinderRotation(bool reset = true)
	{
		SetCylinderRotationAnimationPhase(GetCylinderRotation(GetCurrentMuzzle()), reset);
	}
	
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		
		if (g_Game.IsClient())
			return;
		
		SetAttachmentsHealth();
	}
	
	void SetAttachmentsHealth()
	{
		EntityAI entity;
		ItemBase attachment;
		for (int i = 0; i < GetInventory().AttachmentCount(); i++)
		{
			entity = GetInventory().GetAttachmentFromIndex(i);
			if ( Class.CastTo(attachment,entity) )
			{
				attachment.SetHealth01("","Health",GetHealth01());
			}
		}
	}
	
	override void OnFire(int muzzle_index)
	{
		super.OnFire(muzzle_index);
		RA_RG6_Cylinder cylinder = RA_RG6_Cylinder.Cast(GetAttachmentByType(RA_RG6_Cylinder));
		if (cylinder)
		{
			string bullet_nose = "bullet_nose";
			if (muzzle_index > 0)
				bullet_nose = string.Format("bullet_nose_" + (muzzle_index + 1));
			cylinder.HideSelection(bullet_nose);
		}
	}
	
	override bool IsShowingChamberedBullet()
	{
		return false;
	}
	
	override bool CanEjectBullet() 
	{
		for (int i = 0; i < GetMuzzleCount(); i++)
		{
			if (IsChamberFull(i))
				return true;
		}
		return false;
	}
	
	override void ShowBullet(int muzzleIndex)
	{
		super.ShowBullet(muzzleIndex);
		
		RA_RG6_Cylinder cylinder = RA_RG6_Cylinder.Cast(GetAttachmentByType(RA_RG6_Cylinder));
		if (cylinder)
		{		
			string bullet = "bullet";
			if (muzzleIndex > 0)
				bullet = string.Format("bullet_" + (muzzleIndex + 1));
			
			cylinder.ShowSelection(bullet);
			
			if (!IsChamberFiredOut(muzzleIndex))
			{
				string bullet_nose = "bullet_nose";
				if (muzzleIndex > 0)
					bullet_nose = string.Format("bullet_nose_" + (muzzleIndex + 1));
				cylinder.ShowSelection(bullet_nose);
			}
		}
	}
	
	override void HideBullet(int muzzleIndex)
	{
		super.HideBullet(muzzleIndex);
		
		RA_RG6_Cylinder cylinder = RA_RG6_Cylinder.Cast(GetAttachmentByType(RA_RG6_Cylinder));
		if (cylinder)
		{		
			string bullet = "bullet";
			if (muzzleIndex > 0)
				bullet = string.Format("bullet_" + (muzzleIndex + 1));
			
			cylinder.HideSelection(bullet);
			
			string bullet_nose = "bullet_nose";
			if (muzzleIndex > 0)
				bullet_nose = string.Format("bullet_nose_" + (muzzleIndex + 1));
			cylinder.HideSelection(bullet_nose);
		}
	}
};

class RA_RG6 extends RA_RG6_Base
{
	override bool ShootsExplosiveAmmo()
	{
		return true;
	}
	
	override bool OnAction(int action_id, Man player, ParamsReadContext ctx)
	{
		if (g_Game.IsServer())
		{
			if (action_id == EActions.SPIN)
			{
				const float animPhaseOffset = 0.167;
	
				RA_RG6_Cylinder cylinder = RA_RG6_Cylinder.Cast(GetAttachmentByType(RA_RG6_Cylinder));
		
				if (cylinder)
				{
					float animPhase = cylinder.GetAnimationPhase("Rotate_Cylinder");
					if (animPhase + animPhaseOffset > 1.0)
					{
						animPhase -= 1.0;
						cylinder.ResetAnimationPhase("Rotate_Cylinder", animPhase);
					}
	
					cylinder.SetAnimationPhase("Rotate_Cylinder", animPhase);
				}
			}
		}
		
		return super.OnAction(action_id, player, ctx);
	}
}

class RA_RG6_Cylinder extends DummyItem {};

class RG6WeaponChambering extends WeaponStateBase
{
	WeaponActions m_action;
	int m_startActionType;
	int m_endActionType;
	Magazine m_srcMagazine; /// source of the cartridge
	ref InventoryLocation m_srcMagazinePrevLocation;

	ref WeaponStateBase m_start;
	ref RG6WeaponEjectAllMuzzles m_eject;
	ref RG6WeaponCylinderRotate m_rotate;
	ref WeaponChambering_Base m_chamber;
	ref LoopedChambering_Wait4ShowBullet2 m_w4sb2;
	ref WeaponStartAction m_endLoop;
	ref BulletHide_W4T m_hideB;

	void RG6WeaponChambering(Weapon_Base w = NULL, WeaponStateBase parent = NULL, WeaponActions action = WeaponActions.NONE, int startActionType = -1, int endActionType = -1)
	{
		m_action = action;
		m_startActionType = startActionType;
		m_endActionType = endActionType;

		// setup nested state machine
		m_start = new WeaponChambering_Start(m_weapon, this, m_action, m_startActionType);
		m_eject = new RG6WeaponEjectAllMuzzles(m_weapon, this);
		m_rotate = new RG6WeaponCylinderRotate(m_weapon, this);
		m_chamber = new RG6WeaponChambering_MultiMuzzle(m_weapon, this);
		m_w4sb2 = LoopedChambering_Wait4ShowBullet2(m_weapon, this);
		m_hideB = new BulletHide_W4T(m_weapon, this);
		m_endLoop = new LoopedChambering_EndLoop(m_weapon, this, m_action, m_endActionType); // @NOTE: termination playing action - dummy?
		// events
		WeaponEventBase							_fin_ = new WeaponEventHumanCommandActionFinished;
		WeaponEventContinuousLoadBulletStart	__lS_ = new WeaponEventContinuousLoadBulletStart;
		WeaponEventContinuousLoadBulletEnd		__lE_ = new WeaponEventContinuousLoadBulletEnd;
		WeaponEventCylinderRotate				__cr_ = new WeaponEventCylinderRotate;
		WeaponEventAnimBulletShow				__bs_ = new WeaponEventAnimBulletShow;
		WeaponEventAnimBulletHide				__bh_ = new WeaponEventAnimBulletHide;
		WeaponEventAnimBulletEject				__be_ = new WeaponEventAnimBulletEject;
		WeaponEventAnimBulletInMagazine			__bM_ = new WeaponEventAnimBulletInMagazine;
		WeaponEventAnimBulletShow2				_bs2_ = new WeaponEventAnimBulletShow2;

		m_fsm = new WeaponFSM(this); // @NOTE: set owner of the submachine fsm
		m_fsm.AddTransition(new WeaponTransition(m_start,	__be_, m_eject));
		m_fsm.AddTransition(new WeaponTransition(m_start,	__cr_, m_rotate));
		
		m_fsm.AddTransition(new WeaponTransition(m_eject,	__cr_, m_rotate));			
		m_fsm.AddTransition(new WeaponTransition(m_rotate,	__be_, m_eject));
		
		m_fsm.AddTransition(new WeaponTransition(m_eject, __bs_, m_chamber));
		m_fsm.AddTransition(new WeaponTransition(m_rotate, __bs_, m_chamber));		
		
		m_fsm.AddTransition(new WeaponTransition(m_chamber, __bM_, m_w4sb2, null, new GuardAnd(new GuardAnd(new WeaponGuardHasAmmoInLoopedState(m_chamber), new WeaponGuardChamberMultiHasRoomBulltetIgnoreLast(m_weapon)),new WeaponGuardWeaponManagerWantContinue())));
		m_fsm.AddTransition(new WeaponTransition(m_chamber, __bM_, m_endLoop));
		m_fsm.AddTransition(new WeaponTransition(m_w4sb2, 	__cr_, m_rotate));
		
		m_fsm.AddTransition(new WeaponTransition(m_endLoop, _fin_, null));
		
		// Safety exits
		m_fsm.AddTransition(new WeaponTransition(m_w4sb2, 	_fin_, null));
		m_fsm.AddTransition(new WeaponTransition(m_chamber, _fin_, null));
		m_fsm.AddTransition(new WeaponTransition(m_rotate,  _fin_, null));
		m_fsm.AddTransition(new WeaponTransition(m_eject  , _fin_, null));
		m_fsm.AddTransition(new WeaponTransition(m_start  , _fin_, null));		

		m_fsm.SetInitialState(m_start);
	}

	override void OnEntry(WeaponEventBase e)
	{
		if (e != NULL)
		{
			
			m_srcMagazine = e.m_magazine;
			if (m_srcMagazine != NULL)
			{
				InventoryLocation newSrc = new InventoryLocation;
				m_srcMagazine.GetInventory().GetCurrentInventoryLocation(newSrc);
				
				m_srcMagazinePrevLocation = newSrc;
		
				// move to LH
				InventoryLocation lhand = new InventoryLocation;
				lhand.SetAttachment(e.m_player, m_srcMagazine, InventorySlots.LEFTHAND);
				if (GameInventory.LocationSyncMoveEntity(newSrc, lhand))
				{
					if (LogManager.IsWeaponLogEnable()) { wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, ok - ammo pile removed from inv (inv->LHand)"); }
				}
				else
					Error("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, error - cannot remove ammo pile from inv");
				
				m_chamber.m_srcMagazine = m_srcMagazine;
			} 
			else
			{
				Print("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering m_srcMagazine = NULL");
			}
		}
		else
		{
			Print("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering (e=NULL), m_srcMagazine=" + m_srcMagazine.ToString());
		}

		super.OnEntry(e); // @NOTE: super at the end (prevent override from submachine start)
	}
	
	override void OnExit(WeaponEventBase e)
	{
		bool done = false;
		if (m_srcMagazine)
		{
			e.m_player.GetInventory().ClearInventoryReservationEx( m_srcMagazine , m_srcMagazinePrevLocation );
			
			InventoryLocation leftHandIl = new InventoryLocation;
			m_srcMagazine.GetInventory().GetCurrentInventoryLocation(leftHandIl);
			if (leftHandIl.IsValid())
			{
				if (m_srcMagazinePrevLocation && m_srcMagazinePrevLocation.IsValid())
				{
					if (vector.DistanceSq(m_srcMagazinePrevLocation.GetPos(), leftHandIl.GetPos()) < WeaponManager.MAX_DROP_MAGAZINE_DISTANCE_SQ )
					{
						if ( GameInventory.LocationCanMoveEntity(leftHandIl,m_srcMagazinePrevLocation) )
						{
							if ( GameInventory.LocationSyncMoveEntity(leftHandIl,m_srcMagazinePrevLocation) )
							{
								if (LogManager.IsWeaponLogEnable()) { wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, ok - ammo pile removed from left hand to previous location (LHand->inv) - exit"); }
								done = true;
							}
						}
					}
				}
				
				if ( !done)
				{
					InventoryLocation il = new InventoryLocation;
					e.m_player.GetInventory().FindFreeLocationFor( m_srcMagazine, FindInventoryLocationType.CARGO, il );
			
					if (!il || !il.IsValid())
					{
						if (DayZPlayerUtils.HandleDropMagazine(e.m_player, m_srcMagazine))
						{
							if (LogManager.IsWeaponLogEnable()) { wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, ok - no inventory space for ammo pile - dropped to ground - exit"); }
						}
						else
							Error("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, error - cannot drop ammo pile from left hand after not found inventory space for ammo pile - exit");
					
					}
					else
					{
						if (GameInventory.LocationSyncMoveEntity(leftHandIl, il))
						{
							if (LogManager.IsWeaponLogEnable()) { wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, ok - ammo pile removed from left hand (LHand->inv) - exit"); }
						}
						else
							Error("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, error - cannot remove ammo pile from wpn - exit");
					}
				}
			}
		}
		
		super.OnExit(e);
		m_srcMagazine = NULL;
		m_chamber.m_srcMagazine = NULL;
		m_srcMagazinePrevLocation = NULL;
	}
	
	override void OnAbort(WeaponEventBase e)
	{
		bool done = false;
		if (m_srcMagazine)
		{
			e.m_player.GetInventory().ClearInventoryReservationEx( m_srcMagazine , m_srcMagazinePrevLocation );
			
			InventoryLocation leftHandIl = new InventoryLocation;
			m_srcMagazine.GetInventory().GetCurrentInventoryLocation(leftHandIl);
			if (leftHandIl.IsValid())
			{
				if (m_srcMagazinePrevLocation && m_srcMagazinePrevLocation.IsValid())
				{
					if (vector.DistanceSq(m_srcMagazinePrevLocation.GetPos(), leftHandIl.GetPos()) < WeaponManager.MAX_DROP_MAGAZINE_DISTANCE_SQ )
					{
						if ( GameInventory.LocationCanMoveEntity(leftHandIl,m_srcMagazinePrevLocation) )
						{
							if ( GameInventory.LocationSyncMoveEntity(leftHandIl,m_srcMagazinePrevLocation) )
							{
								if (LogManager.IsWeaponLogEnable()) { wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, ok - ammo pile removed from left hand to previous location (LHand->inv) - abort"); }
								done = true;
							}
						}
					}
				}
				
				if ( !done)
				{
					InventoryLocation il = new InventoryLocation;
					e.m_player.GetInventory().FindFreeLocationFor( m_srcMagazine, FindInventoryLocationType.CARGO, il );
			
					if (!il || !il.IsValid())
					{
						if (DayZPlayerUtils.HandleDropMagazine(e.m_player, m_srcMagazine))
						{
							if (LogManager.IsWeaponLogEnable()) { wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, ok - no inventory space for ammo pile - dropped to ground - abort"); }
						}
						else
							Error("[wpnfsm] " + Object.GetDebugName(m_weapon) + " LoopedChambering, error - cannot drop ammo pile from left hand after not found inventory space for ammo pile - abort");
					
					}
					else
					{
						if (GameInventory.LocationSyncMoveEntity(leftHandIl, il))
						{
							if (LogManager.IsWeaponLogEnable()) { wpnDebugPrint("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering, ok - ammo pile removed from left hand (LHand->inv) - abort"); }
						}
						else
							Error("[wpnfsm] " + Object.GetDebugName(m_weapon) + " LoopedChambering, error - cannot remove ammo pile from wpn - abort");
					}
				}
			}
		}
		
		super.OnAbort(e);
		m_srcMagazine = NULL;
		m_chamber.m_srcMagazine = NULL;
		m_srcMagazinePrevLocation = NULL;
	}
	
	override bool SaveCurrentFSMState(ParamsWriteContext ctx)
	{
		if (!super.SaveCurrentFSMState(ctx))
			return false;

		if (!ctx.Write(m_srcMagazine))
		{
			Error("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering.SaveCurrentFSMState: cannot save m_srcMagazine for weapon=" + m_weapon);
			return false;
		}
		
		if (!OptionalLocationWriteToContext(m_srcMagazinePrevLocation, ctx))
		{
			Error("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering.SaveCurrentFSMState: cannot write m_srcMagazinePrevLocation for weapon=" + m_weapon);
			return false;
		}
		
		return true;
	}

	override bool LoadCurrentFSMState(ParamsReadContext ctx, int version)
	{
		if (!super.LoadCurrentFSMState(ctx, version))
			return false;

		if (!ctx.Read(m_srcMagazine))
		{
			Error("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering.LoadCurrentFSMState: cannot read m_srcMagazine for weapon=" + m_weapon);
			return false;
		}
		
		if (!OptionalLocationReadFromContext(m_srcMagazinePrevLocation, ctx))
		{
			Error("[wpnfsm] " + Object.GetDebugName(m_weapon) + " WeaponMagnumChambering.LoadCurrentFSMState: cannot read m_srcMagazinePrevLocation for weapon=" + m_weapon);
			return false;
		}
		return true;
	}
};

class RG6WeaponFire extends WeaponFireMultiMuzzle
{
	override void OnEntry (WeaponEventBase e)
	{
		super.OnEntry(e);
		if (e)
		{
			RA_RG6_Cylinder cylinder = RA_RG6_Cylinder.Cast(m_weapon.GetAttachmentByType(RA_RG6_Cylinder));
			if(cylinder)
			{
				float a;
				int mi = m_weapon.GetCurrentMuzzle();
				switch(mi)
				{
					case 0:
						a = RG6_ROTATION_POSITION_0;
						break;
					case 1:
						a = RG6_ROTATION_POSITION_5;
						cylinder.ResetAnimationPhase("Rotate_Cylinder", RG6_ROTATION_POSITION_6 );
						break;
					case 2:
						a = RG6_ROTATION_POSITION_4;
						break;
					case 3:
						a = RG6_ROTATION_POSITION_3;
						break;
					case 4:
						a = RG6_ROTATION_POSITION_2;
						break;
					case 5:
						a = RG6_ROTATION_POSITION_1;
						break;
				}
				cylinder.SetAnimationPhase("Rotate_Cylinder", a);
			}
		}
	}

	override void OnUpdate (float dt)
	{
		m_dtAccumulator += dt;

		DayZPlayer p;
		Class.CastTo(p, m_weapon.GetHierarchyParent());

		int muzzleIndex = m_weapon.GetCurrentMuzzle();
		float reloadTime = m_weapon.GetReloadTime(muzzleIndex);
		if (m_dtAccumulator >= reloadTime)
			if (m_weapon.CanProcessWeaponEvents())
				m_weapon.ProcessWeaponEvent(new WeaponEventReloadTimeout(p));
	}

	override void OnExit (WeaponEventBase e)
	{
		if (e)
			m_dtAccumulator = 0;
		super.OnExit(e);
	}
};

class RG6WeaponChambering_MultiMuzzle extends WeaponChambering_Cartridge
{
	override bool IsWaitingForActionFinish () { return false; }
	override void OnEntry(WeaponEventBase e)
	{
		super.OnEntry(e);
	}
	
	override void OnExit(WeaponEventBase e)
	{
		m_weapon.SelectionBulletHide();
		int muzzle = m_weapon.GetCurrentMuzzle();
		
		if (!m_weapon.IsChamberFull(muzzle))
		{
			if (m_weapon.PushCartridgeToChamber(muzzle, m_damage, m_type))
			{
				RA_RG6_Cylinder cylinder = RA_RG6_Cylinder.Cast(m_weapon.GetAttachmentByType(RA_RG6_Cylinder));

				if (cylinder)
				{
					string bullet = "bullet";
					string bullet_nose = "bullet_nose";
					
					if (muzzle > 0)
					{
						bullet = string.Format("bullet_" + ( muzzle + 1 ));
						bullet_nose = string.Format("bullet_nose_" + ( muzzle + 1 ));
					}
					cylinder.ShowSelection(bullet);
					cylinder.ShowSelection(bullet_nose);
				}
			}
			else
			m_type = string.Empty;
			return;
		}
	}
}

class RG6WeaponCylinderRotate extends WeaponStateBase
{	
	bool FindNextFreeMuzzle(int currentMuzzle, out int nextMuzzle)
	{
		nextMuzzle = currentMuzzle;
		int nMuzzles = m_weapon.GetMuzzleCount();
		
		for (int i = 0; i < nMuzzles; ++i)
		{
			--nextMuzzle;
			nextMuzzle = Math.WrapInt(nextMuzzle, 0, nMuzzles);
			if (m_weapon.IsChamberEmpty(nextMuzzle))
				return true;
		}
		
		return false;
	}
	
	override void OnEntry(WeaponEventBase e)
	{
		int nextMuzzle;
		if (FindNextFreeMuzzle(m_weapon.GetCurrentMuzzle(), nextMuzzle))
		{
			RA_RG6_Base RG6 = RA_RG6_Base.Cast(m_weapon);
			RG6.SetCylinderRotationAnimationPhase(RG6.GetCylinderRotation(nextMuzzle));
			m_weapon.SetCurrentMuzzle(nextMuzzle);
		}
		super.OnEntry(e); // @NOTE: super at the end (prevent override from submachine start)
	}

};

class RG6WeaponEjectAllMuzzles: WeaponStateBase
{
	Magazine m_dstMagazine;
	void RG6WeaponEjectAllMuzzles (Weapon_Base w = NULL, WeaponStateBase parent = NULL) { }

	override void OnEntry (WeaponEventBase e)
	{
		super.OnEntry(e);
		if (e)
		{
			RA_RG6_Cylinder cylinder = RA_RG6_Cylinder.Cast(m_weapon.GetAttachmentByType(RA_RG6_Cylinder));
			if(cylinder)
			{
				cylinder.HideSelection("bullet");
				cylinder.HideSelection("bullet_2");
				cylinder.HideSelection("bullet_3");
				cylinder.HideSelection("bullet_4");
				cylinder.HideSelection("bullet_5");
				cylinder.HideSelection("bullet_6");
				
				cylinder.HideSelection("bullet_nose");
				cylinder.HideSelection("bullet_nose_2");
				cylinder.HideSelection("bullet_nose_3");
				cylinder.HideSelection("bullet_nose_4");
				cylinder.HideSelection("bullet_nose_5");
				cylinder.HideSelection("bullet_nose_6");
			}
			
			Print("Muzzle Count: "+m_weapon.GetMuzzleCount());
			for( int i = 0; i < m_weapon.GetMuzzleCount(); i++ )
			{
				Print("IsChamberFiredOut: "+m_weapon.IsChamberFiredOut(i));
				if(m_weapon.IsChamberFiredOut(i))
				{
					m_weapon.EjectCasing(i);
					m_weapon.EffectBulletHide(i);
					m_weapon.HideBullet(i);
					continue;
				}
				
				Print("!IsChamberEmpty(i): "+!m_weapon.IsChamberEmpty(i));
				if(!m_weapon.IsChamberEmpty(i))
				{
					DayZPlayer p = e.m_player;
					if(m_dstMagazine && m_dstMagazine.GetAmmoCount() < m_dstMagazine.GetAmmoMax() )
					{
						m_weapon.CreateRound(i);
						ejectBulletAndStoreInMagazine(m_weapon,i,m_dstMagazine,p);
					}
					else
					{
						m_weapon.CreateRound(i);
						ejectBulletAndStoreInMagazine(m_weapon,i,null,p);
					}
					m_weapon.EffectBulletHide(i);
					m_weapon.HideBullet(i);
				}
			}
			m_weapon.SetWeaponOpen(false);
			m_weapon.SetCharged(true);
		}
		//m_weapon.SelectionBulletHide();
	}
	
	override bool IsWaitingForActionFinish () 
	{ 
		return false; 
	}
};

modded class FirearmActionMechanicManipulate
{	
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		if (!super.ActionCondition( player, target, item ))
			return false;
		
		bool result = false;
		Weapon_Base wpn = Weapon_Base.Cast(item);
		if ( player.GetWeaponManager().CanEjectBullet(wpn))
		{
			if( GetGame().IsServer() && GetGame().IsMultiplayer() )
			{
				result = true;
			}
			else
			{ 
				if( player.GetWeaponManager().CanEjectBulletVerified() )
				{
					result = true;
				}
				player.GetWeaponManager().SetEjectBulletTryTimestamp();
			}
		}
		return result;
	}
	
	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		
		action_data.m_Player.GetWeaponManager().EjectBulletVerified( this );
	}
};