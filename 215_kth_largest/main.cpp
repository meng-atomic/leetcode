#include "../utils.hpp"

int partition(std::vector<int>& nums, int left, int right) {
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
  }
  std::swap(nums[base], nums[left]);
  return left;
}

int findKthLargest(std::vector<int>& nums, int k) {
    if (nums.size() < k) {
      return NAN;
    }
    if (nums.size() == 0) {
      return NAN;
    }
    int left = 0;
    while (nums.size() - left > k) {
      auto nleft = partition(nums, left, nums.size() - 1);
      echo_container(nums);
      if (nleft == left) {
        return nums[nums.size() - k];
      }
      left = nleft + 1;
    }
  
    return nums[nums.size() - k];
}

int main(int argc, char** argv) {
    std::vector<int> nums = {2,9,4,5,8,3,6,2,3,7,1};
    int k = 4;
    std::cout << findKthLargest(nums, k) << std::endl;
    return 0;
}