class RA_Switchable_Base: ItemBase
{
	protected bool m_IsEnabled;

	void RA_Switchable_Base()
	{
		RegisterNetSyncVariableBool("m_IsEnabled");
	}

	bool IsEnabled()
	{
		return m_IsEnabled;
	}

	void SetEnabled(bool enable)
	{
		if (!g_Game.IsServer()) {
			return;
		}

		m_IsEnabled = enable;
		SetSynchDirty();
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if (m_IsEnabled)
		{
			OnEnabled();
		}
		else
		{
			OnDisabled();
		}
	}

	void OnEnabled()
	{
		//Polymorphism
	}

	void OnDisabled()
	{
		//Polymorphism
	}

	override vector GetModifierValue(string modifier_name, vector default = "1 1 1")
	{
		if (!IsEnabled()) {
			return default;
		}
		
		return super.GetModifierValue(modifier_name, default);
	}
}

class RA_Laser_Base: RA_Switchable_Base
{
	#ifndef SERVER
	static const float BEAM_LENGTH = 100;

	protected RA_Laser_Beam m_Laser;
	protected ref Timer m_LaserTimer = new Timer(CALL_CATEGORY_GAMEPLAY);
	
	void ~RA_Laser_Base()
	{
		if (g_Game) {
			g_Game.ObjectDelete(m_Laser);
		}
		
		delete m_LaserTimer;
	}

	override bool CanPutAsAttachment(EntityAI parent)
	{
		if(!super.CanPutAsAttachment(parent)) {
			return false;
		}

		RA_Switchable_Base switchable_item = RA_Switchable_Base.Cast(parent.GetAttachmentByType(RA_Switchable_Base));
		if (switchable_item) {
			return false;
		}

		return true;
	}

	override void EEItemLocationChanged(notnull InventoryLocation oldLoc, notnull InventoryLocation newLoc)
	{
		OnDisabled();

		super.EEItemLocationChanged(oldLoc, newLoc);
	}
	
	void OnLaserTimer()
	{
		if (!m_Laser) {
			return;
		}
		
		if (!IsVisibleWithoutNVG() && !CheckNVGState()) {
			m_Laser.SetObjectTexture(0, "");
		} else {
			m_Laser.SetObjectTexture(0, LaserColor());
		}

		vector fd = -vector.Direction(GetMemoryPointPos("laser_start"), GetMemoryPointPos("laser_end")).Normalized();
		
		vector transform[4] = { 
			Vector(fd[2], fd[1], fd[0]),
			Vector(0, 1, 0),
			Vector(fd[0], fd[1], fd[2]) * GetDistance(),
			GetMemoryPointPos("laser_start")
		};
		
		m_Laser.SetTransform(transform);
	}

	override void OnEnabled()
	{
		m_Laser = RA_Laser_Beam.Cast(g_Game.CreateObjectEx("RA_Laser_Beam", GetMemoryPointPos("laser_start"), ECE_LOCAL));
		if (!m_Laser) {
			return;
		}

		AddChild(m_Laser, -1);
		
		m_LaserTimer.Run(0.1, this, "OnLaserTimer", null, true);
	}

	override void OnDisabled()
	{
		if (!m_Laser) {
			return;
		}

		RemoveChild(m_Laser);
		g_Game.ObjectDelete(m_Laser);
		m_LaserTimer.Stop();
	}
	
	float GetDistance()
	{
		vector beam_start = ModelToWorld(GetMemoryPointPos("laser_start"));
		vector beam_end = ModelToWorld(GetMemoryPointPos("laser_end"));
		vector direction = vector.Direction(beam_start, beam_end).Normalized();

		vector contact_pos, contact_dir;
		int contact_comp;

		//EntityFlags.PASSTRANSLUCENT > IsFlagSet(EntityFlags.PASSTRANSLUCENT)
		set<Object> results = new set<Object>();
		if (DayZPhysics.RaycastRV(beam_start, beam_start + (direction *  BEAM_LENGTH), contact_pos, contact_dir, contact_comp, results, NULL, GetHierarchyRootPlayer(), false, false, ObjIntersectFire))
		{
			EntityAI entity = EntityAI.Cast(results[0]);
			if (entity && entity.IsFlagSet(EntityFlags.TRANSLUCENT)) {
				DayZPhysics.RaycastRV(contact_pos, beam_start + (direction *  BEAM_LENGTH), contact_pos, contact_dir, contact_comp, results, NULL, GetHierarchyRootPlayer(), false, false, ObjIntersectFire);
			}
			return vector.Distance(beam_start, contact_pos);
		}
		
		return BEAM_LENGTH;
	}

	bool CheckNVGState()
	{
		PlayerBase player = PlayerBase.Cast(g_Game.GetPlayer());

		if (!player || !player.GetCurrentCamera())
		{
			return false;
		}

		DayZPlayerCameraBase camera = DayZPlayerCameraBase.Cast(g_Game.GetPlayer().GetCurrentCamera());
		if (!camera || !camera.IsCameraNV()) 
		{
			return false;
		}

		return true;
	}

	bool IsVisibleWithoutNVG()
	{
		return true;
	}

	#endif

	string LaserColor()
	{
		return "#(argb,8,8,3)color(0,1,0,0.3,co)";
	}

	//TODO GET WORKING
	/*override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}*/
}

class RA_Laser_Beam: ItemBase{};

class NcSTAR_Laser_Base: RA_Laser_Base{};

class NcSTAR_White_Laser: NcSTAR_Laser_Base
{
	override string LaserColor()
	{
		return "#(argb,8,8,3)color(1,1,1,0.3,co)";
	}
}
class NcSTAR_Red_Laser: NcSTAR_Laser_Base
{
	override string LaserColor()
	{
		return "#(argb,8,8,3)color(1,0,0,0.3,co)";
	}
}

class NcSTAR_Green_Laser: NcSTAR_Laser_Base{}

class NcSTAR_Blue_Laser: NcSTAR_Laser_Base
{
	override string LaserColor()
	{
		return "#(argb,8,8,3)color(0,0,1,0.3,co)";
	}
}

class RA_PEQ2A_Base: RA_Laser_Base
{
	override string LaserColor()
	{
		return "#(argb,8,8,3)color(1,0,0,0.3,co)";
	}
}

class RA_ANPEQ_Base: RA_Laser_Base
{
	#ifndef SERVER
	override bool IsVisibleWithoutNVG()
	{
		return false;
	}
	#endif

	override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_ANPEQ_Black");
		m_SprayPaintEntry.Add(SprayPaintTypes.GREEN, "RA_ANPEQ_Green");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_ANPEQ_Tan");

		return m_SprayPaintEntry;
	}
}

class RA_Perst_Base: RA_Laser_Base
{
	#ifndef SERVER
	override bool IsVisibleWithoutNVG()
	{
		return false;
	}
	#endif
}

class RA_Flashlight: RA_Switchable_Base
{
	#ifndef SERVER
	UniversallightLight 	m_Light;

	override ScriptedLightBase GetLight()
	{
		return m_Light;
	}

	override void OnEnabled()
	{
		m_Light = UniversallightLight.Cast(  ScriptedLightBase.CreateLight(UniversallightLight, "0 0 0", 0.08)  ); // Position is zero because light is attached on parent immediately.
		m_Light.AttachOnMemoryPoint(this, "beamStart", "beamEnd");
	}

	override void OnDisabled()
	{
		if (m_Light)
			m_Light.FadeOut();
		
		m_Light = NULL;
	}
	#endif

	override bool IsLightSource()
	{
		return true;
	}
}

class RA_X300_Base: RA_Flashlight{}

class RA_ScoutLight_Base: RA_Flashlight{}