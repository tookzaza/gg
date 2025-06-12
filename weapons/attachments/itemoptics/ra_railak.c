class RA_OpticMount: ItemBase
{
    override bool CanDetachAttachment (EntityAI parent)
    {
        if (Weapon_Base.Cast(parent) && parent.FindAttachmentBySlotName("weaponOptics") || parent.FindAttachmentBySlotName("weaponOpticsHunting"))
        {
            return false;
        }
        return super.CanDetachAttachment(parent);
    }
}

class RA_RailAK: RA_OpticMount{}

class RA_AKS74u_RIS_Mount: RA_OpticMount{}

class RA_GalilOptic_Mount: RA_OpticMount{}

class RA_UTG4_M14_Mount: RA_OpticMount{}

class RA_RailSKS: RA_OpticMount{}