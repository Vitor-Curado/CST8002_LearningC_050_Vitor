#include "View.h"

appStatus View::run()
{
	string newFileName;
	int operatorId = 0;
	appStatus result = appStatus::SUCCESS;
	int choice = 999;
	
	while (choice != 0) {
		choice = menu();
		switch (choice) {
		case 0:
			// Exit
			result = appStatus::SUCCESS;
			View::signature();
			choice = 0;
			// Saves automatically, persisting the data
			file.save();
			break;
		case 1:
			// Reload facility data
			file.load();
			View::signature();
			break;
		case 2:
			// Save current memory onto file, appending
			file.save();
			View::signature();
			break;
		case 3:
			// Display three last facilities
			file.displayLastThreeFacilities();
			break;
		case 4:
			// Display facility by operator ID
			cout << "Please enter operator ID:> ";
			cin >> operatorId;
			file.displayFacility(operatorId);
			View::signature();
			break;
		case 5:
			// Create a new facility
			file.createFacility();
			View::signature();
			break;
		case 6:
			// Modify facility
			// Assume only operatorID.
			cout << "Please enter operator ID:> ";
			cin >> operatorId;
			file.modifyFacility(operatorId);
			View::signature();
			break;
		case 7:
			// Delete facility
			// Ask for operator ID
			cout << "Please provide operator ID:> " << endl;
			cin >> operatorId;
			file.deleteFacility(operatorId);
			View::signature();
			break;
		case 8:
			// Sort facilities by region
			file.sortByRegion();
			file.displayAllFacilities();
			View::signature();
			break;
		case 9:
			// Sort facilities by district
			file.sortByDistrict();
			file.displayAllFacilities();
			View::signature();
			break;
		case 10:
			// Sort facilities by language
			file.sortByLanguage();
			file.displayAllFacilities();
			View::signature();
			break;
		case 11:
			// Sort facilities by type
			file.sortByType();
			file.displayAllFacilities();
			View::signature();
			break;
		default:
			cerr << "Invalid choice" << endl;
			result = appStatus::CRITICAL_ERROR_EMERGENCY_EXIT;
			break;
		}
	}

	return result;
}

int View::menu()
{
	int result = 0;
	int choice = 0;

	while (true) {
		cout << "=============================" << endl;
		cout << "          Main Menu          " << endl;
		cout << "=============================" << endl;
		cout << " 1 - Reload facility data" << endl;
		cout << " 2 - Save file" << endl;
		cout << " 3 - Display last three facilities" << endl;
		cout << " 4 - Display a facility" << endl;
		cout << " 5 - Create a new facility" << endl;
		cout << " 6 - Modify a facility" << endl;
		cout << " 7 - Delete a facility" << endl;
		cout << "-----------------------------" << endl;
		cout << "     New Functionalities!    " << endl;
		cout << "-----------------------------" << endl;
		cout << " 8 - Sort facilities by region" << endl;
		cout << " 9 - Sort facilities by district" << endl;
		cout << "10 - Sort facilities by language" << endl;
		cout << "11 - Sort facilities by type" << endl;
		cout << "-----------------------------" << endl;
		cout << " 0 - Exit" << endl;
		cout << "=============================" << endl;
		cout << "Please enter your choice:> ";
		cin >> choice;

		// Validate input: check if the input is an integer
		if (!cin.fail() && choice >= 0 && choice <= 11) {
			cout << endl << "You entered: " << choice << endl;
			result = choice;
			break;
		}
		else {
			cout << endl << "Wrong input" << endl;
			cout << "You entered: " << choice << endl;
			cout << "´Please, enter a valid integer" << endl;
		}
	}

	return result;
}
