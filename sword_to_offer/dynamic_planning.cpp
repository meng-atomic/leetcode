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
*   Date: Sep 2, 2020
*  Brief: A brief introduction to this file.
*          
*/

#include <iostream>

int maxProductAfterCutting(int length) {
	if (length < 2) {
		return 0;
	}
	if (length < 3) {
		return 1;
	}
	if (length < 4) {
		return 2;
	}
	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;
	for (int i = 4; i <= length; ++i) {
		int max = 0;
		for (int j = 1; j <= i / 2; ++j) {
			int product = products[j] * products[i - j];
			max = product > max ? product : max;
		}
		products[i] = max;
	}
	int max = products[length];
	delete[] products;
	return max;
}

int main(int argc, char** argv) {
	std::cout << maxProductAfterCutting(8) << std::endl;
}
