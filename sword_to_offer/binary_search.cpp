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
*   Date: Aug 31, 2020
*  Brief: A brief introduction to this file.
*          
*/

#include <iostream>
#include <vector>

void printVec(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end) {
	if (begin < end) {
		for (auto iter = begin; iter != end; ++iter) {
			std::cout << *iter << ", ";
		}
		std::cout << std::endl;
	}
}

void printVec(const std::vector<int>::const_iterator& begin, const std::vector<int>::const_iterator& end) {
	if (begin < end) {
		for (auto iter = begin; iter != end; ++iter) {
			std::cout << *iter << ", ";
		}
		std::cout << std::endl;
	}
}

bool binary_search(const std::vector<int>::const_iterator& left, const std::vector<int>::const_iterator& right, int value) {
	if (left >= right) {
		return false;
	}
	auto mid = left + (right - left) / 2;
	if (*mid == value) {
		return true;
	} else if (*mid > value) {
		return binary_search(left, mid, value);
	} else {
		return binary_search(mid + 1, right, value);
	}
}

bool binary_search(const std::vector<int> datas, int value) {
	return binary_search(datas.begin(), datas.end(), value);
}

int findMinInSpinArray(const std::vector<int>& datas) {
	int value = datas.front();
	int left = 0, right = datas.size() - 1;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (mid == left || mid == right) {
			break;
		}
		if (datas[mid] >= value) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return datas[left] < datas[right] ? datas[left] : datas[right];
}

void binary_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (begin == end) {
		return;
	}
	int value = *begin;
	auto left = begin, right = end - 1;
	while (left < right) {
		if (*left > *right) {
			std::swap(*left, *right);
		}
		if (*left == value) {
			right--;
		} else {
			left++;
		}
	}

	binary_sort(begin, left);
	binary_sort(left + 1, end);
}

void merge_sort_recursive(std::vector<int>& datas, std::vector<int>& buffer, int start, int end) {
	if (start >= end) {
		return;
	}
	int len = end - start;
	int start1 = start, end1 = start + len / 2;
	int start2 = end1 + 1, end2 = end;
	merge_sort_recursive(datas, buffer, start1, end1);
	merge_sort_recursive(datas, buffer, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2) {
		buffer[k++] = datas[start1] < datas[start2] ? datas[start1++] : datas[start2++];
	}
	while (start1 <= end1) {
		buffer[k++] = datas[start1++];
	}
	while (start2 <= end2) {
		buffer[k++] = datas[start2++];
	}
	for (int k = start; k <= end; ++k) {
		datas[k] = buffer[k];
	}
}

void merge_sort(std::vector<int>& datas) {
	std::vector<int> buffer = datas;
	merge_sort_recursive(datas, buffer, 0, datas.size() - 1);
}

int main(int argc, char** argv) {
	std::vector<int> datas = {};
	std::cout << findMinInSpinArray(datas) << std::endl;
}

