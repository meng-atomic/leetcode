#include <iostream>
#include <vector>
#include "../utils.hpp"

int most_water(const std::vector<int>& nums) {
    int most = 0;
    for (int left = 0; left < nums.size() - 1; ++left) {
        for (int right = nums.size() - 1; right > left; --right) {
            int tmp = (right - left) * std::min(nums[left], nums[right]);
            most = std::max(tmp, most);
        }
    }
    return most;
}

int most_water_1(const std::vector<int>& nums) {
  int most = 0;
  for (int left = 0, right = nums.size() - 1; left < right;) {
    int tmp = std::abs(right - left) * std::min(nums[left], nums[right]);
    most = std::max(tmp, most);
    if (nums[left] > nums[right]) {
      --right;
    } else {
      ++left;
    }
  }
  return most;
}

int main(int argc, char** argv) {
    std::vector<int> nums = {1,8,6,2,5,4,8,3,7};
    std::cout << most_water(nums) << std::endl;
    std::cout << most_water_1(nums) << std::endl;
    return 0;
}