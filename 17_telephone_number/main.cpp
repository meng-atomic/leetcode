#include <iostream>
#include <vector>
#include <string>
#include <map>

void backtrack(std::vector<std::string>& combinations, std::string& combination, std::map<char, std::string> dig_map, const std::string& digits, int index) {
    if (index == digits.length()) {
        combinations.push_back(combination);
        return;
    }
    std::string chars = dig_map[digits[index]];
    for (auto iter = chars.begin(); iter != chars.end(); ++iter) {
        combination.push_back(*iter);
        backtrack(combinations, combination, dig_map, digits, index + 1);
        combination.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits) {
    std::vector<std::string> combinations;
    std::map<char, std::string> dig_map = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxzy"}
    };
    std::string combination ="";
    backtrack(combinations, combination, dig_map, digits, 0);
    return combinations;
}

int main(int argc, char** argv) {
	std::vector<std::string> res = letterCombinations("234");
	std::cout << "size: " << res.size();
	return 0;
}
