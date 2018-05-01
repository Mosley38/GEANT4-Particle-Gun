#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"

ActuibInitialization::ActionInitialization()
	: G4VUserActionInitialization()
{}
	
ActionInitialization::~ActionInitialization()
{}		

void ActionInitialization::BuildForMaster() const
	{
		SetUserAction(new RunAction);
	}		
	
void ActionInitialization::Build() const
	{
		SetUserAction(new PrimaryGeneratioAction);
		SetUserAction(new RunAction);
		SetUserAction(new EventAction);
	}	