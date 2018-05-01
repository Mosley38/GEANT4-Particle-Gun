//
// ULNPrimaryGenerator class
//
#ifndef ULNPrimaryGeneratorAction_h
#define ULNPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;

class ULNPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
public:
	ULNPrimaryGeneratorAction();
	virtual ~ULNPrimaryGeneratorAction();
	virtual void GeneratePrimaries(G4Event*);
	
private:
	G4ParticleGun* fParticleGun;

};

#endif
