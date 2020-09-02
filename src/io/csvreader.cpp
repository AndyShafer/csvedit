#include "csvreader.h"

CSVReader::CSVReader(std::string filepath)
	: filepath(filepath) {
	file = std::ifstream(filepath);
}

bool CSVReader::readline(std::string& line) {
	if(!file.is_open()) {
		return false;
	}
	if(!getline(file, line)) {
		file.close();
		return false;
	}
	return true;
}

bool CSVReader::readline(std::vector<std::string>& fields) {
	return false;
}
