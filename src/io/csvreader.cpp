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
	if(!file.is_open()) {
		return false;
	}

	std::string line;
	if(!getline(file, line)) {
		file.close();
		return false;
	}

	std::vector<int> delimeters;
	bool quoted = false;
	for(int i = 0; i < line.size(); i++) {
		if(line[i] == '"' && (i == 0 || line[i-1] != '\\')) {
			quoted = !quoted;
		}
		if(line[i] == ',' && !quoted) {
			delimeters.push_back(i);
		}
	}

	if(delimeters.size() == 0) {
		fields.push_back(line);
		return true;
	}

	fields.push_back(line.substr(0, delimeters[0]));
	for(int i = 0; i < delimeters.size()-1; i++) {
		fields.push_back(line.substr(delimeters[i] + 1, delimeters[i+1] - delimeters[i] - 1));
	}
	fields.push_back(line.substr(delimeters[delimeters.size()-1]));
	return true;
}
