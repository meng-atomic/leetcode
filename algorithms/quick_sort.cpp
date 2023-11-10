#include <iostream>
#include "../utils.hpp"

int partition(std::vector<int>& nums, int left, int right) {
  if (left < 0 || left >= nums.size()) {
    return left;
  }
  
  int start = left;
  int base = nums[left];
  while (left < right) {
    while (left < right && nums[right] >= base) {
      --right;
    }
    while (left < right && nums[left] <= base) {
      ++left;
    }
    std::cout << left << ", " << right << std::endl;
    if (left < right) {
      std::swap(nums[left], nums[right]);
    }
  }
  
  std::swap(nums[start], nums[left]);
  return left;
}


int partition1(std::vector<int>& nums, int left, int right) {
  if (left >= right) {
    return left;
  }
  if (left < 0) {
    return -1;
  }
  if (left > nums.size()) {
    return -1;
  }

  int base = left;
  while (left < right) {
    while (left < right && nums[right] >= nums[base]) {
      --right;
    }
    while (left < right && nums[left] <= nums[base]) {
      ++left;
    }
    if (left < right) {
      std::swap(nums[left], nums[right]);
    }
    std::cout << left << "<->" << right << std::endl;
    echo_container(nums);
  }
  std::swap(nums[base], nums[left]);
  echo_container(nums);
  return left;
}


void quick_sort(std::vector<int>& nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = partition1(nums, left, right);
  quick_sort(nums, left, mid - 1);
  quick_sort(nums, mid + 1, right);
}

int main(int argc, char** argv) {
  std::vector<int> nums = {2,9,4,5,8,3,6,2,3,7,1};
  echo_container(nums);
  quick_sort(nums, 0, nums.size() - 1);
  echo_container(nums);
  return 0;
}