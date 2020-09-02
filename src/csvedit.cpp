#include <iostream>
#include <stdexcept>
#include "actions/showparams.h"
#include "actions/actions.h"

int main(int argc, char **argv) {
	if(argc < 2) {
		throw std::invalid_argument("Expected command");
	}

	if((std::string)argv[1] == "show") {
		Actions::show(ShowParams::parseArgs(argc, argv));
	}
	else {
		throw std::invalid_argument("Unknown command: " + (std::string)argv[1]);
	}

}
