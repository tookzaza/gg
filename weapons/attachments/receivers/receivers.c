class RailDustCover_Base: Inventory_Base
{
    override bool CanDetachAttachment (EntityAI parent)
	{
        if ( Weapon_Base.Cast(parent) && parent.FindAttachmentBySlotName("weaponOpticsCover"))
        {
            return false;
        }
        return super.CanDetachAttachment(parent);
    }
}

class RA_AK_B33Receiver: RailDustCover_Base
{
    override SprayPaintItemEntry GetSprayPaintTypes()
	{
		SprayPaintItemEntry m_SprayPaintEntry = new SprayPaintItemEntry();
		m_SprayPaintEntry.Add(SprayPaintTypes.BLACK, "RA_AK_B33Receiver");
		m_SprayPaintEntry.Add(SprayPaintTypes.TAN, "RA_AK_B33Receiver_Tan");

		return m_SprayPaintEntry;
	}
};
class RA_AK_Hexagon_DustCover: RailDustCover_Base{};

class RA_AK_DustCover: Inventory_Base{};