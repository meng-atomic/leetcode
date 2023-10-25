#include "../utils.hpp"

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());
  std::vector<std::vector<int>> res;
  for (int i = 0; i < nums.size() - 2; ++i) {
    if (nums[i] > 0) {
      break;
    }
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }
    int left = i + 1;
    int right = nums.size() - 1;
    while (left < right) {
      int sum = nums[i] + nums[left] + nums[right];
      if (sum == 0) {
        res.emplace_back(std::vector<int>({nums[i], nums[left], nums[right]}));
        while (left < right && nums[left] == nums[left + 1]) {
          ++left;
        }
        while (right > left && nums[right] == nums[right - 1]) {
          --right;
        }
        ++left;
        --right;
      } else if (sum > 0) {
        --right;
      } else {
        ++left;
      }
      // std::cout << i << ", " << left << ", " << right << ", " << sum << std::endl;
    }
  }
  return res;
}

int main(int argc, char** argv) {
  std::vector<int> nums = {-1,0,1,2,-1,-4};
  auto res = threeSum(nums);
  for (auto& v : res) {
    echo_container(v);
  }
  return 0;
}