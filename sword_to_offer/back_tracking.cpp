/*************************************************************************
*
* FORWARDX ROBOT LLC CONFIDENTIAL
* __________________
*
*  [2018] RENAISSANCE ROBOT LLC
*  All Rights Reserved.
*
* NOTICE:  All information contained herein is, and remains the property of
* Renaissance Robot LLC and its suppliers, if any. The intellectual and
* technical concepts contained herein are proprietary to Renaissance Robot LLC
* and its suppliers and may be covered by U.S. and Foreign Patents, patents in
* process, and are protected by trade secret or copyright law.
*
* Dissemination of this information or reproduction of this material is strictly
* forbidden unless prior written permission is obtained from Renaissance Robot LLC.
*
* Author: zhangmeng
*  Email: zhangmeng@forwardx.com
*   Date: Sep 1, 2020
*  Brief: A brief introduction to this file.
*          
*/

#include <iostream>
#include <string>
#include <map>
#include <string.h>
#include <vector>

void printVector(std::vector<std::pair<int, int>> vec) {
	for (auto data : vec) {
		std::cout << data.first << ", " << data.second << " -->  ";
	}
	std::cout << std::endl;
}

bool hasPathCore(const char* matrix, int rows, int cols, const char* str, int index, bool* visited, std::vector<std::pair<int, int>>& path) {
	if (str[index] == '\0') {
		return true;
	}
	auto last_step = path.back();
	int last_row = last_step.first, last_col = last_step.second;
	std::vector<std::pair<int, int>> next_steps = {
			{last_row - 1, last_col}, {last_row + 1, last_col},
			{last_row, last_col - 1}, {last_row, last_col + 1}
	};
	for (auto step : next_steps) {
		if (step.first < 0 || step.first > rows - 1
				|| step.second < 0 || step.second > cols - 1) {
			continue;
		}
		int i = step.first, j = step.second;
		if (matrix[i * cols + j] == str[index] && !visited[i * cols + j]) {
			visited[i * cols + j] = true;
			path.push_back({i, j});
			if (hasPathCore(matrix, rows, cols, str, index + 1, visited, path)) {
				return true;
			}
			path.pop_back();
			visited[i * cols + j] = false;
		}
	}
	return false;
}

bool hasPath(const char* matrix, int rows, int cols, const char* str, std::vector<std::pair<int, int>>& path) {
	bool* visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (matrix[i * cols + j] == str[0]) {
				path.push_back({i, j});
				visited[i * cols + j] = true;
				if (hasPathCore(matrix, rows, cols, str, 1, visited, path)) {
					return true;
				}
				path.pop_back();
				visited[i * cols + j] = false;
			}
		}
	}
	return false;
}

int main(int argc, char** argv) {
	std::string str = "bfcb";
	std::string matrix = "abtgcfcsjded";
	std::vector<std::pair<int, int>> path;
	if (hasPath(matrix.c_str(), 3, 4, str.c_str(), path)) {
		printVector(path);
	} else {
		std::cout << "no path" << std::endl;
	}
}

