#pragma once

#include <string>
#include <stdexcept>

class ShowParams {
public:
	static ShowParams parseArgs(int argc, char **argv);
	std::string getFilepath() const;
private:
	ShowParams();
	std::string filepath = "";
};
