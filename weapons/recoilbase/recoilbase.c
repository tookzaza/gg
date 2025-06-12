modded class RecoilBase
{
	override vector GetRecoilModifier(Weapon_Base weapon)
	{
		vector modifier_value = "1 1 1";
		weapon.ApplyTotalRecoilModifier(modifier_value);
		return modifier_value;
	}
}