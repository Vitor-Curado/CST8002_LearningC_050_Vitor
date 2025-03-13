// Course number and name: CST8002_050 Programming Language Research Project
// Your professor’s name: Todd Keuleman
// the due date: Feb 16th
// and your name as the author of the file: Vitor Curado, 041090973

#include "Facility.h"
#include "File.h"

using namespace std;

/*
* @brief Main function
* 
* Here is where the fun happens, usually.
* 
* @return 0
*/
int main() {

	string data = "data.txt";
	string correctFileName = "Licensed_Early_Learning_and_Childcare_Facilities.csv";
	string wrongFileName = "Licensed_Early_Learning_and_Childcare_Facilities.txt";
	string newFileName;
	File file(data);
	int choice = 0;
	int input;

	//cout << file.isGood();
	//cout << file.isOpen();
	//cout << file.getFileName();
	

	//file.displayFacility(215034);
	file.displayFacility(236706);


	/*
	while (true) {
		// Display menu

		cout << "Menu: " << endl;
		cout << "1 - Reload facility data" << endl;
		cout << "2 - Save current file" << endl;
		cout << "3 - Save as new file" << endl;
		cout << "4 - Display facility" << endl;
		cout << "5 - Create a new facility" << endl;
		cout << "6 - Modify facility" << endl;
		cout << "7 - Delete facility" << endl;
		cout << "8 - Exit" << endl;
		cin >> input;
		switch (input) {
		case 1:
			// Reload facility data
			file.load();
			cout << "memory successfully loaded by Vitor Curado" << endl;
			break;

		case 2:
			// Save current memory onto file, appending
			file.save();
			cout << "successfully persisted by Vitor Curado" << endl;
			break;

		case 3:
			// Save as new file
			cout << "Enter new file name: ";
			cin >> newFileName;
			file.save(newFileName);
			cout << "successfully persisted by Vitor Curado" << endl;
			break;

		case 4:
			// Display facility
			file.displayAllFacilities();
			cout << "displayed by Vitor Curado" << endl;
			break;

		case 5:
			// Create a new facility
			file.createFacility();
			cout << "created by Vitor Curado" << endl;
			break;

		case 6:
			// Modify facility
			// Ask if user wants to look up license number, or operator ID
			cout << "Would you like to look up the facility by license number or operator ID?" << endl;
			cout << "1 - License number" << endl;
			cout << "2 - Operator ID" << endl;
			while (true) {
				cin >> choice;
				if (choice == 1) {
					string licenseNumber;
					cout << "Enter the license number: ";
					cin >> licenseNumber;
					file.modifyFacility(licenseNumber);
					cout << "modified by Vitor Curado" << endl;
					break;
				}
				else if (choice == 2) {
					int operatorId;
					cout << "Enter the operator ID: ";
					cin >> operatorId;
					file.modifyFacility(operatorId);
					cout << "modified by Vitor Curado" << endl;
					break;
				}
				else {
					cout << "Invalid choice" << endl;
					cout << "Please try again" << endl;
					cout << "this was done by victor" << endl;
				}
			}
			break;

		case 7:
			// Delete facility
			// Ask for license number or operator ID
			cout << "Victor was here" << endl;
			cout << "Would you like to delete the facility by license number or operator ID?" << endl;
			cout << "1 - License number" << endl;
			cout << "2 - Operator ID" << endl;
			while (true) {
				cin >> choice;
				if (choice == 1) {
					string licenseNumber;
					cout << "Enter the license number: ";
					cin >> licenseNumber;
					file.deleteFacility(licenseNumber);
					break;
				}
				else if (choice == 2) {
					int operatorId;
					cout << "Enter the operator ID: ";
					cin >> operatorId;
					file.deleteFacility(operatorId);
					break;
				}
				else {
					cout << "Invalid choice" << endl;
					cout << "Please try again" << endl;
				}
			}
			break;

		case 8:
			// Exit
			cout << "Goodbye" << endl;
			cout << "This program was done by Mr. Vitor Braga Marques Curado, El Grande fromage suisse" << endl;
			return 0;
			break;
		}
	}
	*/
	return 0;
}

// Post learning notes:
// According to my boy, chatGPT, when documenting code in C++, usually both the header file, and the cpp file are documented.
// but... the header file is usually documented with less details, since it's probably going to be included in multiple files, while
// the cpp file is documented with more details, since it's the file that contains the implementation of the class.
// --------------------
// Remember to manually click on the files to add to be committed on GitHub.
// --------------------
