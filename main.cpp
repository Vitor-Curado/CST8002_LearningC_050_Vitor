#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Facility.h"
#include <sstream>


using namespace std;

int main() {

	fstream file("Licensed_Early_Learning_and_Childcare_Facilities.csv");
	string line;
	vector<Facility> data;

	if (!file) {
		cout << "Error opening file" << endl;
		return 1;
	}

	else {
		// reads the inital row, which is the header
		getline(file, line);

		// Reading the data
		while (getline(file, line)) {
			stringstream ss(line);

			// object we have to fill has properties as follows:
			// string& region, string& district, string& licenseNumber, string& facilityName, string& facilityType, string& facilityAddress1, string& facilityAddress2, string& facilityAddress3, int maxNumberOfChildren, int maxNumberOfInfants, int maxNumberOfPreSchoolAgedChildren, int maxNumberOfSchoolAgedChildren, string& languageOfService, int operatorId, bool designatedFacility
			// sample row:
			// Region 2 - Saint John,Anglophone South School District,215034,ORIGINS NLC 215,Full-time Centre,"567 Millidge Avenue, Saint John",NB,E2K 2N5,40,9,31,0,English,236706,1
			// variables defined as per the properties of the object
			string region, district, licenseNumber, facilityName, facilityType, facilityAddress1, facilityAddress2, facilityAddress3, languageOfService;
			int maxNumberOfChildren, maxNumberOfInfants, maxNumberOfPreSchoolAgedChildren, maxNumberOfSchoolAgedChildren, operatorId;
			bool designatedFacility;

			// Parsing the line
			getline(ss, region, ',');
			getline(ss, district, ',');
			getline(ss, licenseNumber, ',');
			getline(ss, facilityName, ',');
			getline(ss, facilityType, ',');
			getline(ss, facilityAddress1, ',');
			getline(ss, facilityAddress2, ',');
			getline(ss, facilityAddress3, ',');
			ss >> maxNumberOfChildren;

			// Note to self: .ignore() is used to ignore the comma after the integer
			// it is different than in the case of getline() where the delimiter is the comma
			ss.ignore();
			ss >> maxNumberOfInfants;
			ss.ignore();
			ss >> maxNumberOfPreSchoolAgedChildren;
			ss.ignore();
			ss >> maxNumberOfSchoolAgedChildren;
			ss.ignore();
			getline(ss, languageOfService, ',');
			ss >> operatorId;
			ss.ignore();
			ss >> designatedFacility;

			// Creating the object and pushing it to the vector
			Facility f(region, district, licenseNumber, facilityName, facilityType, facilityAddress1, facilityAddress2, facilityAddress3, maxNumberOfChildren, maxNumberOfInfants, maxNumberOfPreSchoolAgedChildren, maxNumberOfSchoolAgedChildren, languageOfService, operatorId, designatedFacility);
			data.push_back(f);
		}

		// Printing the size of the vector
		cout << "Size of the vector: " << data.size() << endl;
	}

	

	return 0;
}