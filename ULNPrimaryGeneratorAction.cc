#include "ULNPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"



ULNPrimaryGeneratorAction::ULNPrimaryGeneratorAction()
	: G4VUserPrimaryGeneratorAction()
{
	G4int nofParticles = 1;
	fParticleGun = new G4ParticleGun(nofParticles);
	
	G4ParticleDefinition* particleDefinition
		= G4ParticleTable::GetParticleTable()->FindParticle("gamma");
	
	fParticleGun->SetParticleDefinition(gamma)
	fParticleGun->SetParticleEnergy(50.0*Mev)
	fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.))
}

ULNPrimaryGeneratorAction::~ULNPrimaryGeneratorAction()
{
	delete fParticleGun;
		
}

void ULNPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{	
	G4double worldZHalfLength = 0;
	G4LogicalVolume* BoxLv
		= G4LogicalVolumeStore::GetInstance()->GetVolume("Box");
	G4Box* worldBox = NULL; 
}