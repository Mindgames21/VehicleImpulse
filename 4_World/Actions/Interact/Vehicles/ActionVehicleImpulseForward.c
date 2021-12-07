class ActionVehicleImpulseForward: ActionVehicleImpulseBase
{
	override string GetText()
	{
		return "Apply Impulse [North]";
	}

	override void OnStart( ActionData action_data )
	{
		super.OnStart( action_data );
		
		Transport transportTarget = Transport.Cast(action_data.m_Target.GetObject());		
		if (transportTarget)
		{
			float mass = dBodyGetMass(transportTarget);
			vector impulse = vector.Forward;
			impulse[2] = 2.5 * mass;
			
			dBodyActive(transportTarget, ActiveState.ACTIVE);
			dBodyApplyImpulse(transportTarget, impulse);
		}
	}
};
