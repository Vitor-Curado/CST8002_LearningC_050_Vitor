// Course number and name: CST8002_050 Programming Language Research Project
// Your professor’s name: Todd Keuleman
// the due date: Feb 16th
// and your name as the author of the file: Vitor Curado, 041090973

#include "Facility.h"
#include "File.h"
#include "View.h"

using namespace std;

/*
* @brief Main function
* 
* Here is where the fun happens, usually.
* 
* @return 0
*/
int main() {

	File file;
	string name = "rawData.txt";
	//file.save(name);
	/*
	set<string> districts = file.getUniqueDistricts();
	set<string> regions = file.getUniqueRegions();
	set<string> languages = file.getUniqueLanguages();
	set<string> types = file.getUniqueTypes();

	cout << "Districts: " << endl;
	for (auto district : districts) {
		cout << district << endl;
	}

	cout << "Regions: " << endl;
	for (auto region : regions) {
		cout << region << endl;
	}

	cout << "Languages: " << endl;
	for (auto language : languages) {
		cout << language << endl;
	}

	cout << "Types: " << endl;
	for (auto type : types) {
		cout << type << endl;
	}
	*/

	View view(file);
	appStatus status = view.run();

	if (status == appStatus::CRITICAL_ERROR_EMERGENCY_EXIT) {
		cerr << "An error occurred" << endl;
		return 1;
	} if (status == appStatus::SUCCESS) {
		cout << "Program exited successfully." << endl;
		return 0;
	}
}

// Post learning notes:
// According to my boy, chatGPT, when documenting code in C++, usually both the header file, and the cpp file are documented.
// but... the header file is usually documented with less details, since it's probably going to be included in multiple files, while
// the cpp file is documented with more details, since it's the file that contains the implementation of the class.
// --------------------
// Remember to manually click on the files to add to be committed on GitHub.
// --------------------
