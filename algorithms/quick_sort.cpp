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

void quick_sort(std::vector<int>& nums, int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = partition(nums, left, right);
  quick_sort(nums, left, mid - 1);
  quick_sort(nums, mid + 1, right);
}

int main(int argc, char** argv) {
  std::vector<int> nums = {7,3,3,6,8,1,5,2,4};
  echo_container(nums);
  quick_sort(nums, 0, nums.size() - 1);
  echo_container(nums);
  return 0;
}