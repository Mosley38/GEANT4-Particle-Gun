#include "G4RunManager.hh"
#include "G4ULNPrimamryGeneratorAction.hh"

#include "QBBC.hh"
#include "G4DetectorConstruction.hh"
#include "G4PhysicsList.hh"
#include "G4ActionInitialization.hh"



int main()
{
	
	
	G4RunManager* runManager = new G4RunManger;
	
	runManger->SetUserInitialization(new G4DetectorConstruction);
	runManager->SetUserInitialization(new G4PhysicsList);
	runManager->SetUserInitialization(new G4ActionInitialization);
	runManager->SetUserInitialization(new G4ULNPrimaryGeneratorAction);
	
	runManager->Initialize();
	
	G4UImanager* UI = G4UImanager::GetUIpointer();
	UI->ApplyCommand("/run/verbose 1");
	UI->ApplyCommand("/event/verbose 1");
	UI-ApplyCommand("/tracking/verbose 1");
	
	int numberOfEvent = 20000;
	runManger->beamOn(numberOfEvent);
	
	
	
	
	
	delete runManger;
	return 0;
}


