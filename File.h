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
	bool save();
	bool deleteFacility();
	bool modifyFacility();
	bool createFacility();
	int searchFacility(string& licenseNumber);
};

#endif // !FILE_H