//
//action initialization

#ifndef ULNActionInitialization_h
#define ULNActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class ULNActionInitialization : public G4VUserActionInitialization
{
public:
	ULNActionInitialization();
	virtual ~ULNActionInitialization();
	virtual void BuildForMaster() const;
	virtual void Build() const;

};

#endif

