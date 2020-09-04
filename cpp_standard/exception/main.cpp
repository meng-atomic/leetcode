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

// exception example
#include <iostream>       // std::cerr
#include <exception>
#include <system_error>
#include <cmath>
#include <cerrno>
#include <string>

enum class CUSTOM_ERR_CATEGORY {
	SUCCESS = 0, 
	CLIENT_ERROR,
	SERVER_ERROR,
	OTHER,
};

namespace std {
template<> struct is_error_condition_enum<CUSTOM_ERR_CATEGORY> : public true_type {};
}

class CustomCategory_t : public std::error_category {
public:
	virtual const char* name() const noexcept { return "custom"; }
	virtual std::error_condition default_error_condition(int ev) const noexcept {
		if ((ev >= 200) && (ev < 300)) {
			return std::error_condition(CUSTOM_ERR_CATEGORY::SUCCESS);
		} else if ((ev >= 400) && (ev < 500)) {
			return std::error_condition(CUSTOM_ERR_CATEGORY::CLIENT_ERROR);
		} else if ((ev >= 500) && (ev < 600)) {
			return std::error_condition(CUSTOM_ERR_CATEGORY::SERVER_ERROR);
		} else {
			return std::error_condition(CUSTOM_ERR_CATEGORY::OTHER);
		}
	}

	virtual bool equivalent(const std::error_code& code, int condition) const noexcept {
		return *this == code.category() && static_cast<int>(default_error_condition(code.value()).value() == condition);
	}
	virtual std::string message(int ev) const noexcept {
		switch (ev) {
			case 200: return "OK";
			case 403: return "403 Forbidden";
			case 404: return "404 Not Found";
			case 500: return "500 Internal Server Error";
			case 503: return "503 Service Unavailable";
			default: return "Unknow error";
		}
	}
}CustomCategory;

std::error_condition make_error_condition(CUSTOM_ERR_CATEGORY e) {
	return std::error_condition(static_cast<int>(e), CustomCategory);
}

int main () {
	std::error_code e(404, CustomCategory);
	if (e == CUSTOM_ERR_CATEGORY::SUCCESS) {
		std::cout << "Success: " << e.message() << std::endl;
	} else if (e == CUSTOM_ERR_CATEGORY::CLIENT_ERROR) {
		std::cout << "Client Error: " << e.message() << std::endl;
	} else if (e == CUSTOM_ERR_CATEGORY::SERVER_ERROR) {
		std::cout << "Server Error: " << e.message() << std::endl;
	} else {
		std::cout << "Unknown" << std::endl;
	}
	return 0;
}
