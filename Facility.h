#include <string>
#include <iostream>

using namespace std;

class Facility {
private:
	string region;
	string district;
	string licenseNumber;
	string facilityName;
	string facilityType;
	string facilityAddress1;
	string facilityAddress2;
	string facilityAddress3;

	int maxNumberOfChildren;
	int maxNumberOfInfants;
	int maxNumberOfPreSchoolAgedChildren;
	int maxNumberOfSchoolAgedChildren;

	string languageOfService;

	int operatorId;
	bool designatedFacility;

public:

	// Simple methods may be defined in the header file
	Facility() : region(""), district(""), licenseNumber(""), facilityName(""), facilityType(""), facilityAddress1(""), facilityAddress2(""), facilityAddress3(""), maxNumberOfChildren(0), maxNumberOfInfants(0), maxNumberOfPreSchoolAgedChildren(0), maxNumberOfSchoolAgedChildren(0), languageOfService("English"), operatorId(0), designatedFacility(false) {}
	Facility(string& region, string& district, string& licenseNumber, string& facilityName, string& facilityType, string& facilityAddress1, string& facilityAddress2, string& facilityAddress3, int maxNumberOfChildren, int maxNumberOfInfants, int maxNumberOfPreSchoolAgedChildren, int maxNumberOfSchoolAgedChildren, string& languageOfService, int operatorId, bool designatedFacility);
};
