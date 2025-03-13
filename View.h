#ifndef VIEW_H
#define VIEW_H

#include "File.h"

class View {
private:
	File& file;

public:
	int run();
	int menu();
};

#endif // !VIEW_H