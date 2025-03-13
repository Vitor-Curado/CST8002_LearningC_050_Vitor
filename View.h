#include <string>
#include "File.h"

enum class appStatus {
    SUCCESS,
    CRITICAL_ERROR_EMERGENCY_EXIT
};

class View {
private:
    File& file;

public:
    appStatus run();
    int menu();

    View(File& file) : file(file) {}
    
    /**
	* @brief Signature
	* @return ostream&
	* @note This function is used to print the signature of the developer.
    */
    ostream& signature() const { return cout << "Developed by Vitor Curado" << endl; }
};