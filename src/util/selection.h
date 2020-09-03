#pragma once

#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <climits>

typedef std::pair<long long,long long> range;

class Selection {
public:
	Selection();
	static Selection parseSelection(std::string selectStr);
	void complement();
	bool inSelection(long long n) const;
	bool isEmpty() const;
private:
	static range parseRange(const std::string& str);
	std::vector<range> ranges;
};
