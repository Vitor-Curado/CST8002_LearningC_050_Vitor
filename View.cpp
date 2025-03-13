#include "View.h"

enum class appStatus {
	SUCCESS,
	CRITICAL_ERROR_EMERGENCY_EXIT
};

int View::run()
{

	return 0;
}

int View::menu()
{
	int result = 0;
	int choice = 0;

	while (true) {
		cout << "Menu: " << endl;
		cout << "1 - Reload facility data" << endl;
		cout << "2 - Save current file" << endl;
		cout << "3 - Save as new file" << endl;
		cout << "4 - Display facility" << endl;
		cout << "5 - Create a new facility" << endl;
		cout << "6 - Modify facility" << endl;
		cout << "7 - Delete facility" << endl;
		cout << "8 - Exit" << endl;

		cin >> choice;

		// Validate input: check if the input is an integer
		if (!cin.fail() && choice >= 1 && choice <= 8) {
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
