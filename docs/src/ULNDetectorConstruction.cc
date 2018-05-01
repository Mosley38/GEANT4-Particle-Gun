#include "ULNDetectorConstruction.hh"
#include "ULNDetectorMessenger.hh"
#include "G4RunManager.hh"
#include "TrackerSD.hh"

#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4ThreeVector.hh"

#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"

#include "G4SystemOfUnits.hh"



DetectorConstruction::DetectorConstruction()
:G4VUserDetectorConstruction(),
      fScoringVolume(0), fLogicTarget(NULL), fCheckOverLaps(true), 
	  fStepLimit(NULL),
	  fLogicCone(NULL), fTargetMaterial(NULL), fConeMaterial(NULL)
{
	DefineMaterials();
}

DetectorConstruction::~DetectorConstruction()
{ 
	delete [] fLogicChamber;
	delete fStepLimit;
	delete fMessenger;
}

G4PhysicalVolume* DetectorConstruction::Construct()
{
	DefineMaterials();
	
	return DefineVolumes();
}	


void DetectorConstruction::DefineMaterials()
{
	G4NistManager* nistManager = G4NistManager::Instance();
	//Air defined
	nistManager->FindOrBuildMaterial("G4_AIR");
	//water defined 
	nistManager->FindOrBuidMaterial("G4_WATER");
	//iron defined
	fConeMaterial = nistManager->FindOrBuildMaterial("G4_WATER");
	//crystal defined
	fTargetMaterial = nistManager->FindOrBuildMaterial("G4_ANTHRACENE");
	//List of materials on printed
	G4cout << *(G4Material::GetMaterialTable()) << G4endl;
	
}	

G4VPhysicalVolume* DetectorConstruction::DefineVolumes()
{
	G4Materials* air = G4Material::GetMaterial("G4_AIR");
	
	
	
//size of world simulation will take place 	
	
	G4double world_x = 5.0*m;
	G4double world_y = 5.0*m;
	G4double world_z = 5.0*m;
	//cylinder construction
	G4double innerRadius = 1.4*m;
	G4double outerRadius = 1.5*m;
	G4double hz = 	3.0*m;
	G4double startAngle = 0.*deg;
	G4double spanningAngle = 360.*deg;
	//target build
	G4double target_x = 7.0*cm;
	G4double target_y = 5.0*cm;
	G4double target_z = 7.0*cm;
	
	
		
	G4GeometryManager::GetInstance()->SetWorldMaximumExtent(worldLength);

	G4Box* World_box = new G4Box("Box", world_x,world_y,world_z);

	G4LogicalVolume* BoxLV
		= new G4LogicalVolume(
			BoxS,
			air,
			"Box");
			
	//placement of the physical world volume (0,0,0).		
	G4PhysicalVolume* BoxPV
		= new G4PVPlacement(
					0,
					G4ThreeVector(),
					"Box",
					0,
					false,
					0,
					fCheckOverlaps);		
	
	//placement of petroleum resevoir		
	G4Tubs* ConeTube
		= new G4Tubs("Cone",
					innerRadius,
					outerRadius,
					hz,
					startAngle,
					spanningAngle);
					
					
	//Material in the world
		G4LogicalVolume* ConeLog
			= new G4LogicalVolume(cneTube, fConeMaterial, "Cone");
		G4double pos_x = 0.0*m;
		G4double pos_y = 0.0*m;
		G4double pos_z = -5.0*m;
		
		G4PhysicalVolume* Conephys
		   = new G4PVPlacement(0,
						  G4ThreeVector(pos_x, pos_y, pos_z)
						  cneLog,
						  "Cone"
						  BoxLog,
						  false,
						  0);
		
		    		 
		G4Tubs* targetS
		= new G4Tubs("target",0.,targetRadius,targetLength,0.*deg,360.*deg);
	fLogicTarget
		= new G4LogicalVolume(targetS, fTargetMaterial,"target",0,0,0)
	new G4PVPlacement(0,
					  G4ThreeVector(0.,0.,5.0*m),
					  fLogicTarget,
					  "target"
					  BoxLV,
					  false,
					  0,
					  fCheckOverlaps);
					  
		
	
	 
	
	return BoxPV;
}	


	
	


