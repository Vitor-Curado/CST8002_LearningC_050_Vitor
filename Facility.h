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
	
	// Constructors
	Facility() : region(""), district(""), licenseNumber(""), facilityName(""), facilityType(""), facilityAddress1(""), facilityAddress2(""), facilityAddress3(""), maxNumberOfChildren(0), maxNumberOfInfants(0), maxNumberOfPreSchoolAgedChildren(0), maxNumberOfSchoolAgedChildren(0), languageOfService("English"), operatorId(0), designatedFacility(false) {}
	Facility(string& region, string& district, string& licenseNumber, string& facilityName, string& facilityType, string& facilityAddress1, string& facilityAddress2, string& facilityAddress3, int maxNumberOfChildren, int maxNumberOfInfants, int maxNumberOfPreSchoolAgedChildren, int maxNumberOfSchoolAgedChildren, string& languageOfService, int operatorId, bool designatedFacility);

	// Getters
	string getRegion() const { return this->region; }
	string getDistrict() const { return this->district; }
	string getLicenseNumber() const { return this->licenseNumber; }
	string getFacilityName() const { return this->facilityName; }
	string getFacilityType() const { return this->facilityType; }
	string getFacilityAddress1() const { return this->facilityAddress1; }
	string getFacilityAddress2() const { return this->facilityAddress2; }
	string getFacilityAddress3() const { return this->facilityAddress3; }
	int getMaxNumberOfChildren() const { return this->maxNumberOfChildren; }
	int getMaxNumberOfInfants() const { return this->maxNumberOfInfants; }
	int getMaxNumberOfPreSchoolAgedChildren() const { return this->maxNumberOfPreSchoolAgedChildren; }
	int getMaxNumberOfSchoolAgedChildren() const { return this->maxNumberOfSchoolAgedChildren; }
	string getLanguageOfService() const { return this->languageOfService; }
	int getOperatorId() const { return this->operatorId; }
	bool getDesignatedFacility() const { return this->designatedFacility; }

	// Setters
	void setRegion(string& region) { this->region = region; }
	void setDistrict(string& district) { this->district = district; }
	void setLicenseNumber(string& licenseNumber) { this->licenseNumber = licenseNumber; }
	void setFacilityName(string& facilityName) { this->facilityName = facilityName; }
	void setFacilityType(string& facilityType) { this->facilityType = facilityType; }
	void setFacilityAddress1(string& facilityAddress1) { this->facilityAddress1 = facilityAddress1; }
	void setFacilityAddress2(string& facilityAddress2) { this->facilityAddress2 = facilityAddress2; }
	void setFacilityAddress3(string& facilityAddress3) { this->facilityAddress3 = facilityAddress3; }
	void setMaxNumberOfChildren(int maxNumberOfChildren) { this->maxNumberOfChildren = maxNumberOfChildren; }
	void setMaxNumberOfInfants(int maxNumberOfInfants) { this->maxNumberOfInfants = maxNumberOfInfants; }
	void setMaxNumberOfPreSchoolAgedChildren(int maxNumberOfPreSchoolAgedChildren) { this->maxNumberOfPreSchoolAgedChildren = maxNumberOfPreSchoolAgedChildren; }
	void setMaxNumberOfSchoolAgedChildren(int maxNumberOfSchoolAgedChildren) { this->maxNumberOfSchoolAgedChildren = maxNumberOfSchoolAgedChildren; }
	void setLanguageOfService(string& languageOfService) { this->languageOfService = languageOfService; }
	void setOperatorId(int operatorId) { this->operatorId = operatorId; }
	void setDesignatedFacility(bool designatedFacility) { this->designatedFacility = designatedFacility; }

	// friend
	friend ostream& operator<<(ostream& os, const Facility& f);

	// display
    ostream& display(ostream& os) const {
		os << "Region: " << region << "\n"
		<< "District: " << district << "\n"
		<< "License Number: " << licenseNumber << "\n"
		<< "Facility Name: " << facilityName << "\n"
		<< "Facility Type: " << facilityType << "\n"
		<< "Facility Address1: " << facilityAddress1 << "\n"
		<< "Facility Address2: " << facilityAddress2 << "\n"
		<< "Facility Address3: " << facilityAddress3 << "\n"
		<< "Max Number Of Children: " << maxNumberOfChildren << "\n"
		<< "Max Number Of Infants: " << maxNumberOfInfants << "\n"
		<< "Max Number Of PreSchool Aged Children: " << maxNumberOfPreSchoolAgedChildren << "\n"
		<< "Max Number Of School Aged Children: " << maxNumberOfSchoolAgedChildren << "\n"
		<< "Language Of Service: " << languageOfService << "\n"
		<< "Operator Id: " << operatorId << "\n"
		<< "Designated Facility: " << (designatedFacility ? "Yes" : "No") << "\n"
		<< "\n";
		return os;
    }
};
