#ifndef FILE_H
#define FILE_H

#include "Facility.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>

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
	int searchFacility(int operatorId);
	bool deleteFacility(int operatorId);
	bool modifyFacility(int operatorId);
	ostream& displayFacility(int operatorId);
	bool createFacility();
	bool createFacility(Facility& f);
	ostream& displayAllFacilities() const;
	ostream& displayLastThreeFacilities() const;

	// Sorting algorithms
	void sortByRegion();
	void sortByDistrict();
	void sortByLanguage();
	void sortByType();

	// Get unique
	set<string> getUniqueRegions();
	set<string> getUniqueDistricts();
	set<string> getUniqueLanguages();
	set<string> getUniqueTypes();
};

#endif // !FILE_H