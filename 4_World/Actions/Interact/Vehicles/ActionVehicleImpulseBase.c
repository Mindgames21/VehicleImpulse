class ActionVehicleImpulseBase: ActionInteractBase
{
	private string ItemInHand = "Wrench";
	

	void ActionVehicleImpulseBase()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

	override string GetText()
	{
		return "Apply Impulse";
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}
	
	override bool HasProgress()
	{
		return false;
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Transport targetCar = Transport.Cast(target.GetObject());
		if (!IsTransport(target) || !IsInReach(player, target, UAMaxDistances.DEFAULT))
			return false;

		//Car must be empty
		for (int i = 0; i < targetCar.CrewSize(); ++i)
		{
			if (targetCar.CrewMember(i))
			{
				return false;
			}
		}
		
		if (player.GetItemInHands().GetType() != ItemInHand)
		{
			return false;
		}

		//Car must be off
		Car car;
		if (Class.CastTo(car, targetCar) && car.EngineIsOn())
		{
			return false;
		}

		CarScript carScript;
        if (Class.CastTo(carScript, target.GetObject()))
        {
            if (carScript.m_Trader_Locked)
                return false;
        }
		 
		return true;

		
	}

	override bool IsInstant()
	{
		return true;
	}
};
