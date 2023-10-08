#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void echo_vector(const std::vector<int>& vec) {
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << ",";
    }
    std::cout << std::endl;
}

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> res;
    for (auto i = 0; i < nums.size(); ++i) {
        for (auto j = i + 1; j < nums.size(); ++j) {
            if ((nums[i] + nums[j]) == target) {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    return res;
}

std::vector<int> twoSum_logN(std::vector<int>& nums, int target) {
    std::vector<int> res;
    std::unordered_map<int, int> nums_map;
    for (auto i = 0; i < nums.size(); ++i) {
        if (nums_map.count(target - nums[i]) > 0) {
            return std::vector<int>({i, nums_map[target - nums[i]]});
        }
        nums_map[nums[i]] = i;
    }
    return res;
}

int main(int argc, char** argv) {
    std::vector<int> nums = {15,2,7,11};
    auto res = twoSum_logN(nums, 17);
    echo_vector(res);
    return 0;
}