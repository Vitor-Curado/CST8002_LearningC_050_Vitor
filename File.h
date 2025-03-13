#ifndef FILE_H
#define FILE_H

#include "Facility.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

/**
* @class File
* @brief Represents a file. Controller for the facilities
* 
* This class represents a file, which is a controller for the facilities.
*/
class File {
private:
	string line;
	vector<Facility> data;
	fstream file;
	string fileName; // Add a member to store the file name
public:
	File();
	File(string& fileName);
	~File();
	int load();
	int save();
	bool save(string& newFileName);
	bool deleteFacility(int operatorId);
	bool modifyFacility(int operatorId);
	bool createFacility();
	int searchFacility(int operatorId);
	ostream& displayAllFacilities();
	ostream& displayFacility(int operatorId);
	bool isOpen() { return file.is_open(); }
	bool isGood() { return file.good(); }
	string getFileName() { return file.is_open() ? fileName : ""; } // Use the new member to return the file name
};

#endif // !FILE_H