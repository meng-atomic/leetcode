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
#include <vector>
#include <map>

void maxGridCore(int rows, int cols, int& max, std::vector<std::pair<int, int>>& path, std::vector<std::vector<bool>> visited) {
	bool tail_reached = false;

}

int maxGrids(int rows, int cols) {
	int max = 0;
	std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
	std::vector<std::pair<int, int>> path = {{0, 0}};
	maxGridCore(rows, cols, max, path, visited);
	return max;
}

int main(int argc, char** argv) {
	std::cout << __FILE__ << std::endl;
}

