#ifndef FACILITYCONTROLLER_H
#define FACILITYCONTROLLER_H

#include "Facility.h"

class FacilityController {
public:
	// Constructor
	FacilityController();
	// Destructor
	~FacilityController();
	
	void addFacility(Facility& facility);

	void removeFacility(Facility& facility);

	void updateFacility(Facility& facility);

	void listFacilities();
};

#endif 
