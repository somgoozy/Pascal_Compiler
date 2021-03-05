#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "src/parser.h"


int  main(int argc, char** argv) {
	parser p;
	std::string fileName, errMsg;

	// get file name from command line, or ask user
	if (argc > 1)
		fileName = argv[1];
	else {
		std::cout << "Enter file name: ";
		getline(std::cin, fileName);
	}

	// open file in scanner
	p.compile(fileName);
	return 0;
}
