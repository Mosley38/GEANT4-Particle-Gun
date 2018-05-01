//
//
#ifndef ULNDetectorConstruction_h
#define ULNDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "globals.hh"

class G4Box;
class G4PhysicalVolume;
class G4Material;
class G4GenericMessenger;

class ULNDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	ULNDetectorConstruction();
	virtual ~ULNDetectorConstruction();
	virtual G4VPhysicalVolume* Construct();
	
private:
	G4GenericMessenger* fMessenger;
};

#endif
