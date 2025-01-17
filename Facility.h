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
	Facility();
	Facility(string& region, string& district, string& licenseNumber, string& facilityName, string& facilityType, string& facilityAddress1, string& facilityAddress2, string& facilityAddress3, int maxNumberOfChildren, int maxNumberOfInfants, int maxNumberOfPreSchoolAgedChildren, int maxNumberOfSchoolAgedChildren, string& languageOfService, int operatorId, bool designatedFacility);
};
