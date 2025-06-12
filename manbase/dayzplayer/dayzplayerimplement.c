class AimSoundsConstants
{
	static const string SOUNDSET_IN = "_aim_in_SoundSet";
	static const string SOUNDSET_OUT = "_aim_out_SoundSet";
	static const string CONFIG_ENTRY = "aimSoundSet";
	static const string DEFAULT_SOUNDSET = "AK";

	static const float MAX_RANGE = 20;
}

modded class DayZPlayerImplement
{		
	override void HandleWeapons(float pDt, Entity pInHands, HumanInputController pInputs, out bool pExitIronSights)
	{
		super.HandleWeapons(pDt, pInHands, pInputs, pExitIronSights);

		if (g_Game.IsDedicatedServer()) {
			return;
		}
		
		Weapon_Base weapon = Weapon_Base.Cast(pInHands);
		if (!weapon) { 
			return;
		}
		
		if (m_IsFireWeaponRaised && !m_RaiseStarted) {
			PlayAimSound(weapon, false);
			return;
		}
		
		if (!m_IsFireWeaponRaised && m_RaiseStarted) {
			PlayAimSound(weapon, true);
			return;
		}
	}

	override void HandleOptic(notnull ItemOptics optic, bool inHands, HumanInputController pInputs, out bool pExitOptics)
	{		
		UAInterface input = GetInputInterface();
		if (!input)
		{
			return;
		}
		
		Weapon_Base weapon;
		int FOVcount;
		
		if (input.SyncedPress_ID(UAZoomInOptics))
		{
			weapon = Weapon_Base.Cast(optic.GetHierarchyParent());
			FOVcount = optic.GetStepFOVCount();
		
			if (weapon && m_CameraIronsight && !m_CameraOptics)
			{
				SetIronsights(false);
				SwitchOptics(optic,true);
				optic.SetStepFOVIndex(0);
			}
			else if (m_CameraOptics)
			{
				if (optic.StepFOVUp()) {
					PlayOpticZoomSound();
				}
			}
		}

		if (input.SyncedPress_ID(UAZoomOutOptics))
		{
			if (!m_CameraOptics)
			{
				return;
			}

			weapon = Weapon_Base.Cast(optic.GetHierarchyParent());
			FOVcount = optic.GetStepFOVCount();

			if (optic.StepFOVDown())
			{
				PlayOpticZoomSound();
			}
			else
			{
				if (weapon && weapon.CanEnterIronsights())
				{
					SwitchOptics(optic,false);
					pInputs.ResetFreeLookToggle();
					SetIronsights(true);
				}
			}
		}
	}

	void PlayOpticZoomSound(float volume = 1)
	{
		if (g_Game.IsDedicatedServer()) {
			return;
		}
		
		EffectSound sound;
		PlaySoundSet(sound, "combinationlock_changedial_SoundSet", 0, 0);
		sound.SetSoundAutodestroy(true);
		sound.SetSoundVolume(volume);
	}

	void PlayAimSound(Weapon_Base weapon, bool exit, float volume = 1)
	{
		if (g_Game.IsDedicatedServer()) {
			return;
		}
		
		EffectSound sound;
		PlaySoundSet(sound, GetAimSoundSet(weapon, exit), 0, 0);
		sound.SetSoundAutodestroy(true);
		sound.SetSoundVolume(volume);
	}

	static string GetAimSoundSet(Weapon_Base weapon, bool exit)
	{
		string sound_set;

		if (!weapon) {
			if (exit) {
				return AimSoundsConstants.DEFAULT_SOUNDSET + AimSoundsConstants.SOUNDSET_OUT;
			} else {
				return AimSoundsConstants.DEFAULT_SOUNDSET + AimSoundsConstants.SOUNDSET_IN;
			}
		}

		sound_set = weapon.ConfigGetString(AimSoundsConstants.CONFIG_ENTRY);

		// Fallback - predict sound set
		if (sound_set.Length() == 0) {
			sound_set = PredictAimSoundSet(weapon);
		}

		if (exit) {
			return sound_set + AimSoundsConstants.SOUNDSET_OUT;
		} else {
			return sound_set + AimSoundsConstants.SOUNDSET_IN;
		}
	}

	static string PredictAimSoundSet(Weapon_Base weapon)
	{
		if (!weapon) {
			return AimSoundsConstants.DEFAULT_SOUNDSET;
		}

		if (weapon.IsInherited(Pistol_Base) || weapon.IsInherited(Magnum_Base)) {
			return "FNX45";
		}

		if (weapon.IsInherited(BoltActionRifle_InnerMagazine_Base)) {
			return "Mosin";
		}
		
		if (weapon.IsInherited(BoltActionRifle_Base) || weapon.IsInherited(DoubleBarrel_Base)) {
			return "CR527";
		}

		string cartridge_type = weapon.GetChamberAmmoTypeName(weapon.GetCurrentMuzzle());

		if (cartridge_type.Contains("12ga")) {
			return "Saiga";
		}

		if (cartridge_type.Contains("762x54") || cartridge_type.Contains("308Win")) {
			return "SVD";
		}
		
		if (cartridge_type.Contains("Ammo_380")) {
			return "CZ61";
		}
		
		if (cartridge_type.Contains("9x39")) {
			return "VSS";
		}

		return AimSoundsConstants.DEFAULT_SOUNDSET;
	}
}