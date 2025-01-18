// Course number and name: CST8002_050 Programming Language Research Project
// Your professor’s name: Todd Keuleman
// the due date: Jan 26th
// and your name as the author of the file: Vitor Curado, 041090973

#include "Facility.h"

/**
* @brief Constructor with arguments
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
* @return Facility
*/
Facility::Facility(string& region, string& district, string& licenseNumber, string& facilityName, string& facilityType, string& facilityAddress1, string& facilityAddress2, string& facilityAddress3, int maxNumberOfChildren, int maxNumberOfInfants, int maxNumberOfPreSchoolAgedChildren, int maxNumberOfSchoolAgedChildren, string& languageOfService, int operatorId, bool designatedFacility)
{
	// nothing fancy was done here, just plain and simple variable assigning
	this->region = region;
	this->district = district;
	this->licenseNumber = licenseNumber;
	this->facilityName = facilityName;
	this->facilityType = facilityType;
	this->facilityAddress1 = facilityAddress1;
	this->facilityAddress2 = facilityAddress2;
	this->facilityAddress3 = facilityAddress3;
	this->maxNumberOfChildren = maxNumberOfChildren;
	this->maxNumberOfInfants = maxNumberOfInfants;
	this->maxNumberOfPreSchoolAgedChildren = maxNumberOfPreSchoolAgedChildren;
	this->maxNumberOfSchoolAgedChildren = maxNumberOfSchoolAgedChildren;
	this->languageOfService = languageOfService;
	this->operatorId = operatorId;
	this->designatedFacility = designatedFacility;
}

/**
* @brief Prints the facility in a smooth way
* @param region The region of the facility
* @return The region of the facility
*/
ostream& operator<<(ostream& os, const Facility& f)
{
    os << "Region: " << f.region << "\n";
    os << "District: " << f.district << "\n";
    os << "License Number: " << f.licenseNumber << "\n";
    os << "Facility Name: " << f.facilityName << "\n";
    os << "Facility Type: " << f.facilityType << "\n";
    os << "Facility Address 1: " << f.facilityAddress1 << "\n";
    os << "Facility Address 2: " << f.facilityAddress2 << "\n";
    os << "Facility Address 3: " << f.facilityAddress3 << "\n";
    os << "Max Number of Children: " << f.maxNumberOfChildren << "\n";
    os << "Max Number of Infants: " << f.maxNumberOfInfants << "\n";
    os << "Max Number of Pre-School Aged Children: " << f.maxNumberOfPreSchoolAgedChildren << "\n";
    os << "Max Number of School Aged Children: " << f.maxNumberOfSchoolAgedChildren << "\n";
    os << "Language of Service: " << f.languageOfService << "\n";
    os << "Operator ID: " << f.operatorId << "\n";
    os << "Designated Facility: " << (f.designatedFacility ? "Yes" : "No") << "\n";
    os << "\n";

    return os;
}
