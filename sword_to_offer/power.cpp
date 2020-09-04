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
#include <exception>
#include <stdlib.h>

const double ZERO = 1e-10;

bool equal(double value1, double value2) {
	return (value1 - value2) < ZERO && (value1 - value2) > -ZERO;
}

double powerWithUnsignedExp(double base, int exp) {
	if (exp == 0) {
		return 1.0;
	}
	if (exp == 1) {
		return base;
	}
	double res = powerWithUnsignedExp(base, exp >> 1);
	res *= res;
	if (exp & 0x01) {
		res *= base;
	}
	return res;
}

double power(double base, int exp) {
	if (equal(base, 0.0)) {
		if (exp < 0) {
			throw std::runtime_error("error rrr");
		} else {
			return 0.0;
		}
	}
	if (exp == 0) {
		return 1.0;
	} else if (exp > 0) {
		return powerWithUnsignedExp(base, exp);
	} else {
		return 1.0 / powerWithUnsignedExp(base, -exp);
	}
}

int main(int argc, char** argv) {
	std::cout << power(2, -2) << std::endl;
}

