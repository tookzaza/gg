class RA_PBS1_Suppressor: ItemSuppressor{};
class RA_PBS4_Suppressor: ItemSuppressor{};
class RA_Putnik_Suppressor: ItemSuppressor{};
class RA_Salvo_Muzzle: ItemSuppressor{};
class RA_Salvo_Suppressor: ItemSuppressor{};
class RA_CMB_ShotgunMuzzle: ItemSuppressor{};
class RA_QDJK_ShotgunMuzzle: ItemSuppressor
{
    override bool CanPutAsAttachment(EntityAI parent)
    {
        if(!super.CanPutAsAttachment(parent)) {return false;}

        if (RA_MP153_Base.Cast(parent))
        {
            return false;
        }
        return true;
    }
};
class RA_DVL_Suppressor : SuppressorBase{};
class RA_9A91_Suppressor: SuppressorBase{};
class RA_Rotex_Suppressor: ItemSuppressor
{
    override bool CanPutAsAttachment(EntityAI parent)
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}

        if (RA_MP7A1.Cast(parent) || RA_MP7A2.Cast(parent))
        {
            return true;
        }
        return false;
	}
}

modded class PistolSuppressor: ItemSuppressor
{
    override bool CanPutAsAttachment(EntityAI parent)
	{
		if(!super.CanPutAsAttachment(parent)) {return false;}

        if (RA_MP7A1.Cast(parent) || RA_MP7A2.Cast(parent))
        {
            return false;
        }
        return true;
	}
}