// Course number and name: CST8002_050 Programming Language Research Project
// Your professor’s name: Todd Keuleman
// the due date: Jan 26th
// and your name as the author of the file: Vitor Curado, 041090973

#include "Facility.h"

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
