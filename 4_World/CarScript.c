modded class CarScript
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionVehicleImpulseBackward);
		AddAction(ActionVehicleImpulseForward);
		AddAction(ActionVehicleImpulseLeft);
		AddAction(ActionVehicleImpulseRight);
	}
};