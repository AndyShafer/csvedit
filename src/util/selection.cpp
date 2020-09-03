#include "selection.h"

Selection::Selection() {
	ranges.push_back(range(0, LLONG_MAX));
}

Selection Selection::parseSelection(std::string selectStr) {
	Selection selection;
	selection.ranges.clear();
	
	std::vector<range> ranges;
	size_t pos = 0;
	while((pos = selectStr.find(",")) != std::string::npos) {
		ranges.push_back(parseRange(selectStr.substr(0, pos)));
		selectStr.erase(0, pos+1);
	}
	ranges.push_back(parseRange(selectStr));

	std::sort(ranges.begin(), ranges.end());
	int s = -1, e = -1;
	for(int i = 0; i < ranges.size(); i++) {
		if(ranges[i].first > e + 1) {
			if(s != -1) {
				selection.ranges.push_back(range(s, e));
			}
			s = ranges[i].first;
			e = ranges[i].second;
		} else if(ranges[i].second > e) {
			e = ranges[i].second;
		}
	}
	selection.ranges.push_back(range(s, e));

	return selection;
}

void Selection::complement() {
	if(isEmpty()) {
		ranges.push_back(range(0, LLONG_MAX));
		return;
	}

	std::vector<range> newRanges;
	if(ranges[0].first > 0) {
		newRanges.push_back(range(0, ranges[0].first));
	}
	for(int i = 0; i < ranges.size()-1; i++) {
		newRanges.push_back(range(ranges[i].second+1, ranges[i+1].first-1));
	}
	if(ranges[ranges.size()-1].second != LLONG_MAX) {
		newRanges.push_back(range(ranges[ranges.size()-1].second+1, LLONG_MAX));
	}

	ranges = newRanges;
}

bool Selection::inSelection(long long n) const {
	if(isEmpty()) {
		return false;
	}

	auto possibleRange = std::lower_bound(ranges.begin(), ranges.end(), range(n, n));
	return possibleRange->second >= n;
}
bool Selection::isEmpty() const {
	return ranges.size() == 0;
}

range Selection::parseRange(const std::string& str) {
	size_t pos = str.find("-");
	if(pos == std::string::npos) {
		long long val = std::stoll(str);
		return range(val, val);
	} else {
		long long rangeStart = std::stoll(str.substr(0, pos));
		long long rangeEnd = std::stoll(str.substr(pos+1));
		if(rangeEnd < rangeStart) {
			throw std::invalid_argument("Invalid range");
		}
		return range(rangeStart, rangeEnd);
	}
}
