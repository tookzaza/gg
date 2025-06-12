modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);

		actions.Insert(ActionToggleBipod);
		actions.Insert(ActionZoomInMagnifier);
		actions.Insert(ActionZoomOutMagnifier);
		actions.Insert(ActionInspectWeapon);
		actions.Insert(ActionToggleLight);

		actions.Insert(ActionSprayPaintGreen);
		actions.Insert(ActionSprayPaintCamo);
		actions.Insert(ActionSprayPaintBlack);
		actions.Insert(ActionSprayPaintTan);
		actions.Insert(ActionSprayPaintSnow);
	}
}