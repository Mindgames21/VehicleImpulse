modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(ActionVehicleImpulseBase);
		actions.Insert(ActionVehicleImpulseBackward);
		actions.Insert(ActionVehicleImpulseForward);
		actions.Insert(ActionVehicleImpulseLeft);
		actions.Insert(ActionVehicleImpulseRight);
	}
};