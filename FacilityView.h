// Course number and name: CST8002_050 Programming Language Research Project
// Your professor’s name: Todd Keuleman
// the due date: some time in the future
// and your name as the author of the file: Vitor Curado, 041090973

#ifndef FACILITYVIEW_H
#define FACILITYVIEW_H

#include "Facility.h"
#include <vector>

using namespace std;

class FacilityView {
public:
	// Constructor
	FacilityView();
	// Destructor
	~FacilityView();
	// Function to display the data
	void displayFacility(const Facility& facility);

	// Function to display ALL facilities
	void displayFacilities(const vector<Facility>& facilities);


};

#endif
