// Course number and name: CST8002_050 Programming Language Research Project
// Your professor’s name: Todd Keuleman
// the due date: Jan 26th
// and your name as the author of the file: Vitor Curado, 041090973

#include "Facility.h"

Facility::Facility(string& region, string& district, string& licenseNumber, string& facilityName, string& facilityType, string& facilityAddress1, string& facilityAddress2, string& facilityAddress3, int maxNumberOfChildren, int maxNumberOfInfants, int maxNumberOfPreSchoolAgedChildren, int maxNumberOfSchoolAgedChildren, string& languageOfService, int operatorId, bool designatedFacility)
{
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
