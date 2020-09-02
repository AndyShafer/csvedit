#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class CSVReader {
public:
	CSVReader(std::string filepath);
	bool readline(std::string& line);
	bool readline(std::vector<std::string>& fields);
private:
	std::string filepath;
	std::ifstream file;
};
