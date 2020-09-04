#include <iostream>
#include <vector>
#include <map>
#include <string>

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
	std::vector<std::string> scheduals = {"JFK"};

	return scheduals;
}

int main(int argc, char** argv) {
	std::vector<std::vector<std::string>> tickets = {
			{"JFK","SFO"},
			{"JFK","ATL"},
			{"SFO","ATL"},
			{"ATL","JFK"},
			{"ATL","SFO"}
	};

	std::vector<std::vector<std::string>> tickets2 = {
			{"JFK","KUL"},
			{"JFK","NRT"},
			{"NRT","JFK"}
	};

	std::vector<std::string> schedual = findItinerary(tickets2);
	for (auto iter = schedual.begin(); iter != schedual.end();  ++iter) {
		std::cout << *iter << " --> ";
	}
	std::cout << std::endl;
}

