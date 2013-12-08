#include "AreaConverterApp.h"
#include <iostream>

int main(int argc, char** argv) {
	AreaConverterApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}
	

