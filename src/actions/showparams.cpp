#include "showparams.h"

ShowParams ShowParams::parseArgs(int argc, char **argv) {
	if(argc < 3) {
		throw std::invalid_argument("Not enough arguments");
	}
	if((std::string)argv[1] != "show") {
		throw std::invalid_argument("Not a show command");
	}

	ShowParams res;
	int argPos = 2;
	while(argPos < argc) {
		if(res.filepath != "") {
			throw std::invalid_argument("Unexpected argument: " + (std::string)argv[argPos]);
		} else {
			res.filepath = argv[argPos];
			argPos++;
		}
	}
	return res;
}

ShowParams::ShowParams() {}

std::string ShowParams::getFilepath() const {
	return filepath;
}
