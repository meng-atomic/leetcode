#include <iostream>
#include <vector>
#include <unordered_set>

template<typename C>
void echo_container(const C& vec) {
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        std::cout << *iter << ",";
    }
    std::cout << std::endl;
}

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> num_set;
    for (auto& num : nums) {
        num_set.insert(num);
    }
    echo_container(num_set);
    int max_length = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (num_set.count(nums[i] - 1) == 0) {
            int length = 1;
            int num = nums[i];
            while (num_set.count(++num) > 0) {
                length += 1;
            }
            max_length = std::max(max_length, length);
        } 
    }
    return max_length;
}

int main(int argc, char** argv) {
    std::vector<int> nums = {100,4,200,1,3,2};
    auto res = longestConsecutive(nums);
    std::cout << res << std::endl;
    return 0;
}