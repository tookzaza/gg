enum SprayPaintTypes
{
	GREEN,
    BLACK,
    TAN,
    SNOW,
	CAMO
}

modded class ItemBase
{
    string GetColoredItem(int color)
    {
        return string.Empty;
    }

	SprayPaintItemEntry GetSprayPaintTypes()
	{
		return NULL;
	}
}

class ActionSprayPaintCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(8);
	}
}

class ActionSprayPaintBase: ActionContinuousBase
{
    int m_SprayPaintType;

	void ActionSprayPaintBase()
	{
		m_CallbackClass = ActionSprayPaintCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_LOW;
	}
	
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return true;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
        ItemBase targetitem = ItemBase.Cast(target.GetObject());
		if (!targetitem) {
			return false;
		}

		SprayPaintItemEntry sprayPaintTypes = SprayPaintItemEntry.Cast(targetitem.GetSprayPaintTypes());
		if (!sprayPaintTypes || !sprayPaintTypes.GetClassName(m_SprayPaintType) || sprayPaintTypes.GetClassName(m_SprayPaintType) == targetitem.GetType()) {
            return false;
        }

		RA_WoodenCrate_Base woodcrate = RA_WoodenCrate_Base.Cast(targetitem);
		if (woodcrate && (woodcrate.HasAnyCargo() || woodcrate.HasVS())) {
			return false;
		}

		return true;
	}

	override void OnStartClient(ActionData action_data)
	{
		#ifndef SERVER
		EffectSound effect = SEffectManager.PlaySound("SprayPaint_SoundSet", action_data.m_Target.GetObject().GetPosition());
		effect.SetAutodestroy(true);
		#endif
	}
}

class ActionSprayPaintGreen: ActionSprayPaintBase
{
    void ActionSprayPaintGreen()
	{
        m_SprayPaintType = SprayPaintTypes.GREEN;
	}

	override string GetText()
	{
		return "Spraypaint Green";
	}
}

class ActionSprayPaintTan: ActionSprayPaintBase
{
    void ActionSprayPaintTan()
	{
        m_SprayPaintType = SprayPaintTypes.TAN;
	}

	override string GetText()
	{
		return "Spraypaint Tan";
	}
}

class ActionSprayPaintSnow: ActionSprayPaintBase
{
    void ActionSprayPaintSnow()
	{
        m_SprayPaintType = SprayPaintTypes.SNOW;
	}

	override string GetText()
	{
		return "Spraypaint White";
	}
}

class ActionSprayPaintBlack: ActionSprayPaintBase
{
    void ActionSprayPaintBlack()
	{
        m_SprayPaintType = SprayPaintTypes.BLACK;
	}

	override string GetText()
	{
		return "Spraypaint Black";
	}
}

class ActionSprayPaintCamo: ActionSprayPaintBase
{
    void ActionSprayPaintCamo()
	{
        m_SprayPaintType = SprayPaintTypes.CAMO;
	}

	override string GetText()
	{
		return "Spraypaint Camo";
	}

	#ifndef SERVER
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
        ItemBase targetitem = ItemBase.Cast(target.GetObject());
		if (!targetitem) {
			return false;
		}

		SprayPaintItemEntry sprayPaintTypes = SprayPaintItemEntry.Cast(targetitem.GetSprayPaintTypes());
		if (!sprayPaintTypes || !sprayPaintTypes.GetClassName(m_SprayPaintType) || sprayPaintTypes.GetClassName(m_SprayPaintType) == targetitem.GetType()) {
            return false;
        }

		if (sprayPaintTypes.GetSprayPaintType(targetitem.GetType()) == SprayPaintTypes.TAN && item.IsInherited(RA_SprayPaint_Green)) {
			return true;
		}

		if (sprayPaintTypes.GetSprayPaintType(targetitem.GetType()) == SprayPaintTypes.GREEN && item.IsInherited(RA_SprayPaint_Tan)) {
			return true;
		}
		
		return false;
	}
	#endif
}

class RA_SprayPaint_Green: ItemBase
{
	override bool CanBeCombinedOverriden()
	{
		return true;
	}

    override void SetActions()
    {
        super.SetActions();

		AddAction(ActionSprayPaintCamo);
        AddAction(ActionSprayPaintGreen);
    }
}

class RA_SprayPaint_Black: ItemBase
{
	override bool CanBeCombinedOverriden()
	{
		return true;
	}

    override void SetActions()
    {
        super.SetActions();

        AddAction(ActionSprayPaintBlack);
    }
}

class RA_SprayPaint_Tan: ItemBase
{
	override bool CanBeCombinedOverriden()
	{
		return true;
	}

    override void SetActions()
    {
        super.SetActions();

		AddAction(ActionSprayPaintCamo);
        AddAction(ActionSprayPaintTan);
    }
}

class RA_SprayPaint_Snow: ItemBase
{
	override bool CanBeCombinedOverriden()
	{
		return true;
	}
	
    override void SetActions()
    {
        super.SetActions();

        AddAction(ActionSprayPaintSnow);
    }
}

class SprayPaintItemEntry: Managed
{
	//bidirectional access
	private ref map<int, string> keyToValue;
    private ref map<string, int> valueToKey;

    void SprayPaintItemEntry() {
        keyToValue = new map<int, string>();
        valueToKey = new map<string, int>();
    }

    void Add(int key, string value) {
        keyToValue.Set(key, value);
        valueToKey.Set(value, key);
    }

	//Gets the class name of the item based on a certain color
    string GetClassName(int key) {
        return keyToValue.Get(key);
    }

	//Gets the color of the item based on the class name
    int GetSprayPaintType(string value) {
        return valueToKey.Get(value);
    }
}