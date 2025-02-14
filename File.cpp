#include "File.h"

File::File()
{
	file.open("Licensed_Early_Learning_and_Childcare_Facilities.csv");
	if (!file.is_open()) {
		throw exception("Error inside the constructor: could not open file");
	}

	// read the file
	load();
}

File::File(string& fileName)
{
	this->file.open(fileName);
	if (!file.is_open()) {
		throw exception("Error inside the constructor: could not open file");
	}

	// read the file
	load();
}

File::~File()
{
}

int File::load()
{
	// reads the inital row, which is the header
	getline(file, line);

	// Reading the data
	while (getline(file, line)) {
		stringstream ss(line);

		// object we have to fill has properties as follows:
		// string& region, string& district, string& licenseNumber, string& facilityName, string& facilityType, string& facilityAddress1, string& facilityAddress2, string& facilityAddress3, int maxNumberOfChildren, int maxNumberOfInfants, int maxNumberOfPreSchoolAgedChildren, int maxNumberOfSchoolAgedChildren, string& languageOfService, int operatorId, bool designatedFacility
		// sample row:
		// Region 2 - Saint John,Anglophone South School District,215034,ORIGINS NLC 215,Full-time Centre,"567 Millidge Avenue,x Saint John",NB,E2K 2N5,40,9,31,0,English,236706,1
		// variables defined as per the properties of the object
		string region, district, licenseNumber, facilityName, facilityType, facilityAddress1, facilityAddress2, facilityAddress3, languageOfService;
		int maxNumberOfChildren, maxNumberOfInfants, maxNumberOfPreSchoolAgedChildren, maxNumberOfSchoolAgedChildren, operatorId;
		bool designatedFacility;

		// Tweaks I did to make the parsing work. 
		string rest;
		// Parsing the line
		getline(ss, region, ',');
		getline(ss, district, ',');
		getline(ss, licenseNumber, ',');
		getline(ss, facilityName, ',');
		getline(ss, facilityType, ',');
		getline(ss, facilityAddress1, ',');
		getline(ss, rest, ',');
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

		// Fine tuning, erasing the annoying quotes
		facilityAddress1 = facilityAddress1 + rest;
		facilityAddress1.erase(0, 1);
		facilityAddress1.erase(facilityAddress1.size() - 1);

		// Creating the object and pushing it to the vector
		Facility f(region, district, licenseNumber, facilityName, facilityType, facilityAddress1, facilityAddress2, facilityAddress3, maxNumberOfChildren, maxNumberOfInfants, maxNumberOfPreSchoolAgedChildren, maxNumberOfSchoolAgedChildren, languageOfService, operatorId, designatedFacility);
		data.push_back(f);
	}

	// return the number of rows loaded
	return data.size();
}

bool File::save()
{
	return false;
}

bool File::deleteFacility()
{
	return false;
}

bool File::createFacility()
{
	// ask user if one would like to create from scratch, or default values
	cout << "Would you like to create a facility from scratch or use default values?" << endl;
	cout << "1 - From scratch - enter all fields" << endl;
	cout << "2 - Default values - everything zeroed" << endl;
	cout << "3 - Quick create - enter only the license number and operator ID" << endl;

	while (true)
	{
		int choice;
		cin >> choice;

		if (choice == 1) {
			cout << "Enter the region: ";
			string region;
			cin >> region;
			cout << "Enter the district: ";
			string district;
			cin >> district;
			cout << "Enter the license number: ";
			string licenseNumber;
			cin >> licenseNumber;
			cout << "Enter the facility name: ";
			string facilityName;
			cin >> facilityName;
			cout << "Enter the facility type: ";
			string facilityType;
			cin >> facilityType;
			cout << "Enter the facility address 1: ";
			string facilityAddress1;
			cin >> facilityAddress1;
			cout << "Enter the facility address 2: ";
			string facilityAddress2;
			cin >> facilityAddress2;
			cout << "Enter the facility address 3: ";
			string facilityAddress3;
			cin >> facilityAddress3;
			cout << "Enter the maximum number of children: ";
			int maxNumberOfChildren;
			cin >> maxNumberOfChildren;
			cout << "Enter the maximum number of infants: ";
			int maxNumberOfInfants;
			cin >> maxNumberOfInfants;
			cout << "Enter the maximum number of pre-school aged children: ";
			int maxNumberOfPreSchoolAgedChildren;
			cin >> maxNumberOfPreSchoolAgedChildren;
			cout << "Enter the maximum number of school aged children: ";
			int maxNumberOfSchoolAgedChildren;
			cin >> maxNumberOfSchoolAgedChildren;
			cout << "Enter the language of service: ";
			string languageOfService;
			cin >> languageOfService;
			cout << "Enter the operator ID: ";
			int operatorId;
			cin >> operatorId;
			cout << "Enter the designated facility: ";
			bool designatedFacility;
			cin >> designatedFacility;
			data.push_back(Facility(region, district, licenseNumber, facilityName, facilityType, facilityAddress1, facilityAddress2, facilityAddress3, maxNumberOfChildren, maxNumberOfInfants, maxNumberOfPreSchoolAgedChildren, maxNumberOfSchoolAgedChildren, languageOfService, operatorId, designatedFacility));
			return true;
		}

		else if (choice == 2) {
			string empty = "";
			data.push_back(Facility(empty, empty, empty, empty, empty, empty, empty, empty, 0, 0, 0, 0, empty, 0, false));
			return true;
		}
		else if (choice == 3) {
			string empty = "";
			cout << "Enter the license number: ";
			string licenseNumber;
			cin >> licenseNumber;
			cout << "Enter the operator ID: ";
			int operatorId;
			cin >> operatorId;

			data.push_back(Facility(empty, empty, licenseNumber, empty, empty, empty, empty, empty, 0, 0, 0, 0, empty, operatorId, false));
			return true;
		}

		else {
			cout << "Invalid choice" << endl;
			cout << "Please try again" << endl;
		}
	}
}

int File::searchFacility(string& licenseNumber)
{
	int index = 0;

	for (int i = 0; i < data.size(); i++) {
		if (data[i].getLicenseNumber() == licenseNumber) {
			index = i;
		}
	}
	return index;
}


