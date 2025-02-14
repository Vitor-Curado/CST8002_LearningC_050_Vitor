#ifndef FILE_H
#define FILE_H

#include "Facility.h"
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class File {
private:
	string line;
	vector<Facility> data;
	fstream file;
public:
	File();
	File(string& fileName);
	~File();
	int load();
	int save();
	bool save(string& newFileName);
	bool deleteFacility(string& licenseNumber);
	bool deleteFacility(int operatorId);
	bool modifyFacility(int operatorId);
	bool modifyFacility(string& licenseNumber);
	bool createFacility();
	int searchFacility(string& licenseNumber);
	int searchFacility(int operatorId);
	void displayAllFacilities();
};

#endif // !FILE_H