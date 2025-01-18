// Course number and name: CST8002_050 Programming Language Research Project
// Your professor’s name: Todd Keuleman
// the due date: Jan 26th
// and your name as the author of the file: Vitor Curado, 041090973

#include <string>
#include <iostream>

using namespace std;

/**
* @class Facility
* @brief Represents a facility
* 
* This class represents a facility, which is a place where children can be taken care of.
*/
class Facility {
private:
	string region;
	string district;
	string licenseNumber;
	string facilityName;
	string facilityType;

	// This is the actual address of the facility
	string facilityAddress1;

	// This, we store the province
	string facilityAddress2;

	// And here, we store the postal code
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
	
	//-------------
	// Constructors
	//-------------

	/**
	* @brief Default constructor
	* 
	* Initializes the facility with default values.
	* @param region The region of the facility
	* @param district The district of the facility
	* @param licenseNumber The license number of the facility
	* @param facilityName The name of the facility
	* @param facilityType The type of the facility
	* @param facilityAddress1 The actual address of the facility
	* @param facilityAddress2 The province
	* @param facilityAddress3 The postal code
	* @param maxNumberOfChildren The maximum number of children the facility can take care of
	* @param maxNumberOfInfants The maximum number of infants the facility can take care of
	* @param maxNumberOfPreSchoolAgedChildren The maximum number of pre-school aged children the facility can take care of
	* @param maxNumberOfSchoolAgedChildren The maximum number of school aged children the facility can take care of
	* @param languageOfService The language of service of the facility
	* @param operatorId The ID of the operator of the facility
	* @param designatedFacility Whether the facility is designated or not
	*/
	Facility() : region(""), district(""), licenseNumber(""), facilityName(""), facilityType(""), facilityAddress1(""), facilityAddress2(""), facilityAddress3(""), maxNumberOfChildren(0), maxNumberOfInfants(0), maxNumberOfPreSchoolAgedChildren(0), maxNumberOfSchoolAgedChildren(0), languageOfService("English"), operatorId(0), designatedFacility(false) {}

	/**
	* @brief Constructor with arguments
	*
	* Initializes the facility with customised values.
	* @param region The region of the facility
	* @param district The district of the facility
	* @param licenseNumber The license number of the facility
	* @param facilityName The name of the facility
	* @param facilityType The type of the facility
	* @param facilityAddress1 The actual address of the facility
	* @param facilityAddress2 The province
	* @param facilityAddress3 The postal code
	* @param maxNumberOfChildren The maximum number of children the facility can take care of
	* @param maxNumberOfInfants The maximum number of infants the facility can take care of
	* @param maxNumberOfPreSchoolAgedChildren The maximum number of pre-school aged children the facility can take care of
	* @param maxNumberOfSchoolAgedChildren The maximum number of school aged children the facility can take care of
	* @param languageOfService The language of service of the facility
	* @param operatorId The ID of the operator of the facility
	* @param designatedFacility Whether the facility is designated or not
	*/
	Facility(string& region, string& district, string& licenseNumber, string& facilityName, string& facilityType, string& facilityAddress1, string& facilityAddress2, string& facilityAddress3, int maxNumberOfChildren, int maxNumberOfInfants, int maxNumberOfPreSchoolAgedChildren, int maxNumberOfSchoolAgedChildren, string& languageOfService, int operatorId, bool designatedFacility);

	//--------
	// Getters
	//--------

	/**
	* @brief Gets the region of the facility
	* @return The region of the facility
	*/
	string getRegion() const { return this->region; }

	/**
	* @brief Gets the district of the facility
	* @return The district of the facility
	*/
	string getDistrict() const { return this->district; }

	/**
	* @brief Gets the license number of the facility
	* @return The license number of the facility
	*/
	string getLicenseNumber() const { return this->licenseNumber; }

	/**
	* @brief Gets the name of the facility
	* @return The name of the facility
	*/
	string getFacilityName() const { return this->facilityName; }

	/**
	* @brief Gets the type of the facility
	* @return The type of the facility
	*/
	string getFacilityType() const { return this->facilityType; }

	/**
	* @brief Gets the address of the facility
	* @return The address of the facility
	*/
	string getFacilityAddress1() const { return this->facilityAddress1; }

	/**
	* @brief Gets the address of the facility
	* @return The address of the facility
	*/
	string getFacilityAddress2() const { return this->facilityAddress2; }

	/**
	* @brief Gets the address of the facility
	* @return The address of the facility
	*/
	string getFacilityAddress3() const { return this->facilityAddress3; }

	/**
	* @brief Gets the maximum number of children the facility can take care of
	* @return The maximum number of children the facility can take care of
	*/
	int getMaxNumberOfChildren() const { return this->maxNumberOfChildren; }

	/**
	* @brief Gets the maximum number of infants the facility can take care of
	* @return The maximum number of infants the facility can take care of
	*/
	int getMaxNumberOfInfants() const { return this->maxNumberOfInfants; }

	/**
	* @brief Gets the maximum number of pre-school aged children the facility can take care of
	* @return The maximum number of pre-school aged children the facility can take care of
	*/
	int getMaxNumberOfPreSchoolAgedChildren() const { return this->maxNumberOfPreSchoolAgedChildren; }

	/**
	* @brief Gets the maximum number of school aged children the facility can take care of
	* @return The maximum number of school aged children the facility can take care of
	*/
	int getMaxNumberOfSchoolAgedChildren() const { return this->maxNumberOfSchoolAgedChildren; }

	/**
	* @brief Gets the language of service of the facility
	* @return The language of service of the facility
	*/
	string getLanguageOfService() const { return this->languageOfService; }

	/**
	* @brief Gets the ID of the operator of the facility
	* @return The ID of the operator of the facility
	*/
	int getOperatorId() const { return this->operatorId; }

	/**
	* @brief Gets whether the facility is designated or not
	* @return Whether the facility is designated or not
	*/
	bool getDesignatedFacility() const { return this->designatedFacility; }

	//--------
	// Setters
	//--------

	/**
	* @brief Sets the region of the facility
	* @param region The region of the facility
	*/
	void setRegion(string& region) { this->region = region; }

	/**
	* @brief Sets the district of the facility
	* @param district The district of the facility
	*/
	void setDistrict(string& district) { this->district = district; }

	/**
	* @brief Sets the license number of the facility
	* @param licenseNumber The license number of the facility
	*/
	void setLicenseNumber(string& licenseNumber) { this->licenseNumber = licenseNumber; }

	/**
	* @brief Sets the name of the facility
	* @param facilityName The name of the facility
	*/
	void setFacilityName(string& facilityName) { this->facilityName = facilityName; }

	/**
	* @brief Sets the type of the facility
	* @param facilityType The type of the facility
	*/
	void setFacilityType(string& facilityType) { this->facilityType = facilityType; }

	/**
	* @brief Sets the address of the facility
	* @param facilityAddress1 The address of the facility
	*/
	void setFacilityAddress1(string& facilityAddress1) { this->facilityAddress1 = facilityAddress1; }

	/**
	* @brief Sets the address of the facility
	* @param facilityAddress2 The address of the facility
	*/
	void setFacilityAddress2(string& facilityAddress2) { this->facilityAddress2 = facilityAddress2; }

	/**
	* @brief Sets the address of the facility
	* @param facilityAddress3 The address of the facility
	*/
	void setFacilityAddress3(string& facilityAddress3) { this->facilityAddress3 = facilityAddress3; }

	/**
	* @brief Sets the maximum number of children the facility can take care of
	* @param maxNumberOfChildren The maximum number of children the facility can take care of
	*/
	void setMaxNumberOfChildren(int maxNumberOfChildren) { this->maxNumberOfChildren = maxNumberOfChildren; }

	/**
	* @brief Sets the maximum number of infants the facility can take care of
	* @param maxNumberOfInfants The maximum number of infants the facility can take care of
	*/
	void setMaxNumberOfInfants(int maxNumberOfInfants) { this->maxNumberOfInfants = maxNumberOfInfants; }

	/**
	* @brief Sets the maximum number of pre-school aged children the facility can take care of
	* @param maxNumberOfPreSchoolAgedChildren The maximum number of pre-school aged children the facility can take care of
	*/
	void setMaxNumberOfPreSchoolAgedChildren(int maxNumberOfPreSchoolAgedChildren) { this->maxNumberOfPreSchoolAgedChildren = maxNumberOfPreSchoolAgedChildren; }

	/**
	* @brief Sets the maximum number of school aged children the facility can take care of
	* @param maxNumberOfSchoolAgedChildren The maximum number of school aged children the facility can take care of
	*/
	void setMaxNumberOfSchoolAgedChildren(int maxNumberOfSchoolAgedChildren) { this->maxNumberOfSchoolAgedChildren = maxNumberOfSchoolAgedChildren; }

	/**
	* @brief Sets the language of service of the facility
	* @param languageOfService The language of service of the facility
	*/
	void setLanguageOfService(string& languageOfService) { this->languageOfService = languageOfService; }

	/**
	* @brief Sets the ID of the operator of the facility
	* @param operatorId The ID of the operator of the facility
	*/
	void setOperatorId(int operatorId) { this->operatorId = operatorId; }

	/**
	* @brief Sets whether the facility is designated or not
	* @param designatedFacility Whether the facility is designated or not
	*/
	void setDesignatedFacility(bool designatedFacility) { this->designatedFacility = designatedFacility; }

	/**
	* @brief Overloaded operator<<
	* @param os The output stream
	* @param f The facility
	* @return The output stream
	*/
	friend ostream& operator<<(ostream& os, const Facility& f);

	/**
	* @brief Display the facility
	* @param os The output stream
	* @return The output stream
	*/
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
