#ifndef FACILITYCONTROLLER_H
#define FACILITYCONTROLLER_H

#include "Facility.h"
#include <vector>

class FacilityController {
private:
	vector<Facility> facilities;
public:
	// Constructor
	FacilityController();
	// Destructor
	~FacilityController();
	
	void addFacility(Facility& facility);

	void removeFacility(Facility& facility);

	void updateFacility(Facility& facility);

	void listFacilities();

	void searchFacility(int operatorId);

	void searchFacility(string& name);

	void loadData();

	void saveData(string& newFileName);
};

#endif 
