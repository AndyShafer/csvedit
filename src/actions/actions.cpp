#include "actions.h"

void Actions::show(const ShowParams& par) {
	CSVReader in(par.getFilepath());
	std::string line;
	while(in.readline(line)) {
		std::cout << line << std::endl;
	}
}
