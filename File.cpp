#include "File.h"

using namespace std;

/**
* @brief Default constructor
* Initializes the file with default values.
* @throws exception if the file could not be opened
*/
File::File()
{
	file.open("Licensed_Early_Learning_and_Childcare_Facilities.csv");
	if (!file.is_open()) {
		throw exception("Error inside the constructor: could not open file");
	}

	// read the file
	load();
}

/**
* @brief Constructor
* Initializes the file with customised values.
* @param fileName The name of the file
* @throws exception if the file could not be opened
*/
File::File(string& fileName)
{
	this->file.open(fileName);
	if (!file.is_open()) {
		throw exception("Error inside the constructor: could not open file");
	}

	// read the file
	load();
}

/**
* @brief Destructor
* Closes the file
*/
File::~File()
{
}

/**
* @brief Loads the file
* Reads the file and loads the data into the vector
* @return The number of rows loaded
*/
int File::load()
{
	// empties the data vector before loading the file
	data.clear();

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

/**
* @brief Saves the file
* Saves the data from the vector to the file
* @return The number of rows affected
*/
int File::save() {
	// Open the file in read mode
	file.open("Licensed_Early_Learning_and_Childcare_Facilities.csv", ios::in);

	// count the number of rows
	int rows = 0;
	while (getline(file, line)) {
		rows++;
	}

	// Close the file
	file.close();

	// Save current file, overwriting the existing file
	file.open("Licensed_Early_Learning_and_Childcare_Facilities.csv", ios::out);

	if (!file.is_open()) {
		return false;
	}

	// write the header
	file << "Region,District,License Number,Facility Name,Facility Type,Facility Address 1,Facility Address 2,Facility Address 3,Max Number of Children,Max Number of Infants,Max Number of Pre-School Aged Children,Max Number of School Aged Children,Language of Service,Operator ID,Designated Facility" << endl;

	// write the data
	for (int i = 0; i < data.size(); i++) {
		file << data[i].getRegion() << ","
			<< data[i].getDistrict() << ","
			<< data[i].getLicenseNumber() << ","
			<< data[i].getFacilityName() << ","
			<< data[i].getFacilityType() << ","
			<< data[i].getFacilityAddress1() << ","
			<< data[i].getFacilityAddress2() << ","
			<< data[i].getFacilityAddress3() << ","
			<< data[i].getMaxNumberOfChildren() << ","
			<< data[i].getMaxNumberOfInfants() << ","
			<< data[i].getMaxNumberOfPreSchoolAgedChildren() << ","
			<< data[i].getMaxNumberOfSchoolAgedChildren() << ","
			<< data[i].getLanguageOfService() << ","
			<< data[i].getOperatorId() << ","
			<< data[i].getDesignatedFacility() << endl;
	}

	// return number of rows affected
	return data.size() - rows;
}

/**
* @brief Saves the file as a new file
* Saves the data from the vector to a new file
* @param newFileName The name of the new file
* @return Whether the file was saved or not
*/
bool File::save(string& newFileName)
{
	fstream file = fstream(newFileName, ios::out);

	if (!file.is_open()) {
		return false;
	}
	else {
		// write the header
		file << "Region,District,License Number,Facility Name,Facility Type,Facility Address 1,Facility Address 2,Facility Address 3,Max Number of Children,Max Number of Infants,Max Number of Pre-School Aged Children,Max Number of School Aged Children,Language of Service,Operator ID,Designated Facility" << endl;

		// write the data
		for (int i = 0; i < data.size(); i++) {
			file << data[i].getRegion() << ","
				<< data[i].getDistrict() << ","
				<< data[i].getLicenseNumber() << ","
				<< data[i].getFacilityName() << ","
				<< data[i].getFacilityType() << ","
				<< data[i].getFacilityAddress1() << ","
				<< data[i].getFacilityAddress2() << ","
				<< data[i].getFacilityAddress3() << ","
				<< data[i].getMaxNumberOfChildren() << ","
				<< data[i].getMaxNumberOfInfants() << ","
				<< data[i].getMaxNumberOfPreSchoolAgedChildren() << ","
				<< data[i].getMaxNumberOfSchoolAgedChildren() << ","
				<< data[i].getLanguageOfService() << ","
				<< data[i].getOperatorId() << ","
				<< data[i].getDesignatedFacility() << endl;
		}
	}

	return false;
}

/**
* @brief Deletes a facility by license number
* Deletes a facility by license number
* @param licenseNumber The license number of the facility
* @return Whether the facility was deleted or not
*/
bool File::deleteFacility(string& licenseNumber)
{
	int index = searchFacility(licenseNumber);
	if (index == -1) {
		return false;
	}
	else {
		data.erase(data.begin() + index);
		return true;
	}
}

/**
* @brief Deletes a facility by operator ID
* Deletes a facility by operator ID
* @param operatorId The operator ID of the facility
* @return Whether the facility was deleted or not
*/
bool File::deleteFacility(int operatorId)
{
	int index = searchFacility(operatorId);
	if (index == -1) {
		return false;
	}
	else {
		data.erase(data.begin() + index);
		return true;
	}
}

/**
* @brief Modifies a facility by operator ID
* Modifies a facility by operator ID
* @param operatorId The operator ID of the facility
* @return Whether the facility was modified or not
*/
bool File::modifyFacility(int operatorId)
{
	int index = searchFacility(operatorId);
	
	// if the facility is not found
	if (index < 0) {
		throw exception("Facility not found");
	}
	else {
		char choice{};
		// Display the facility
		data[index].display(cout);

		// Ask if user wants to modify each field, if yes, then modify
		cout << "Would you like to modify the region? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string region;
				cout << "Enter the new region: ";
				cin >> region;
				data[index].setRegion(region);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the district? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string district;
				cout << "Enter the new district: ";
				cin >> district;
				data[index].setDistrict(district);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the license number? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string licenseNumber;
				cout << "Enter the new license number: ";
				cin >> licenseNumber;
				data[index].setLicenseNumber(licenseNumber);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the facility name? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string facilityName;
				cout << "Enter the new facility name: ";
				cin >> facilityName;
				data[index].setFacilityName(facilityName);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the facility type? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string facilityType;
				cout << "Enter the new facility type: ";
				cin >> facilityType;
				data[index].setFacilityType(facilityType);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the facility address 1? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string facilityAddress1;
				cout << "Enter the new facility address 1: ";
				cin >> facilityAddress1;
				data[index].setFacilityAddress1(facilityAddress1);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the facility address 2? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string facilityAddress2;
				cout << "Enter the new facility address 2: ";
				cin >> facilityAddress2;
				data[index].setFacilityAddress2(facilityAddress2);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the facility address 3? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string facilityAddress3;
				cout << "Enter the new facility address 3: ";
				cin >> facilityAddress3;
				data[index].setFacilityAddress3(facilityAddress3);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the maximum number of children? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				int maxNumberOfChildren;
				cout << "Enter the new maximum number of children: ";
				cin >> maxNumberOfChildren;
				data[index].setMaxNumberOfChildren(maxNumberOfChildren);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the maximum number of infants? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				int maxNumberOfInfants;
				cout << "Enter the new maximum number of infants: ";
				cin >> maxNumberOfInfants;
				data[index].setMaxNumberOfInfants(maxNumberOfInfants);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the maximum number of pre-school aged children? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				int maxNumberOfPreSchoolAgedChildren;
				cout << "Enter the new maximum number of pre-school aged children: ";
				cin >> maxNumberOfPreSchoolAgedChildren;
				data[index].setMaxNumberOfPreSchoolAgedChildren(maxNumberOfPreSchoolAgedChildren);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the maximum number of school aged children? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				int maxNumberOfSchoolAgedChildren;
				cout << "Enter the new maximum number of school aged children: ";
				cin >> maxNumberOfSchoolAgedChildren;
				data[index].setMaxNumberOfSchoolAgedChildren(maxNumberOfSchoolAgedChildren);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the language of service? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string languageOfService;
				cout << "Enter the new language of service: ";
				cin >> languageOfService;
				data[index].setLanguageOfService(languageOfService);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the operator ID? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				int operatorId;
				cout << "Enter the new operator ID: ";
				cin >> operatorId;
				data[index].setOperatorId(operatorId);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		cout << "Would you like to modify the designated facility? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				bool designatedFacility;
				cout << "Enter the new designated facility: ";
				cin >> designatedFacility;
				data[index].setDesignatedFacility(designatedFacility);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}

		return true;
	}
}

/**
* @brief Modifies a facility by license number
* Modifies a facility by license number
* @param licenseNumber The license number of the facility
* @return Whether the facility was modified or not
*/
bool File::modifyFacility(string& licenseNumber)
{
	int index = searchFacility(licenseNumber);
	// if the facility is not found
	if (index < 0) {
		throw exception("Facility not found");
	}
	else {
		char choice{};
		// Display the facility
		data[index].display(cout);
		// Ask if user wants to modify each field, if yes, then modify
		cout << "Would you like to modify the region? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string region;
				cout << "Enter the new region: ";
				cin >> region;
				data[index].setRegion(region);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}
		cout << "Would you like to modify the district? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string district;
				cout << "Enter the new district: ";
				cin >> district;
				data[index].setDistrict(district);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}
		cout << "Would you like to modify the license number? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string licenseNumber;
				cout << "Enter the new license number: ";
				cin >> licenseNumber;
				data[index].setLicenseNumber(licenseNumber);
				break;
			}
			else if (choice == 'n') {
				break;
			}
			else {
				cout << "Invalid choice" << endl;
				cout << "Please try again" << endl;
			}
		}
		cout << "Would you like to modify the facility name? (y/n)" << endl;
		while (true) {
			if (choice == 'y') {
				string facilityName;
				cout << "Enter the new facility name: ";
				cin >> facilityName;
				data[index].setFacilityName(facilityName);
				break;
			}
		}
	}
}

/**
* @brief Creates a facility
* Creates a facility
* @return Whether the facility was created or not
*/
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
			cout << "tell me a random string then press enter" << endl;
			string randomString;
			cin >> randomString;
			data.push_back(Facility(randomString, randomString, randomString, randomString, randomString, randomString, randomString, randomString, 0, 0, 0, 0, randomString, 0, false));
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

/**
* @brief Searches for a facility by license number
* Searches for a facility by license number
* @param licenseNumber The license number of the facility
* @return The index of the facility
*/
int File::searchFacility(string& licenseNumber)
{
	int index = -1;

	for (int i = 0; i < data.size(); i++) {
		if (data[i].getLicenseNumber() == licenseNumber) {
			index = i;
		}
	}
	return index;
}

/**
* @brief Searches for a facility by operator ID
* Searches for a facility by operator ID
* @param operatorId The operator ID of the facility
* @return The index of the facility
*/
int File::searchFacility(int operatorId)
{
	int index = -1;
	for (int i = 0; i < data.size(); i++) {
		if (data[i].getOperatorId() == operatorId) {
			index = i;
		}
	}
	return index;
}

/**
* @brief Displays all facilities
* Displays all facilities
*/
void File::displayAllFacilities()
{
	for (int i = 0; i < data.size(); i++) {
		data[i].display(cout);
	}
}


