#include <iostream>
#include <vector>
#include <algorithm>
#include "../utils.hpp"

void move_zero(std::vector<int>& nums) {
    for (int i = 0; i < (nums.size() - 1); ++i) {
        if (nums[i] == 0) {
            int j = i + 1;
            while ((j < (nums.size() - 1)) && (nums[j] == 0)) {
                ++j;
            }
            std::swap(nums[i], nums[j]);
            if (j >= (nums.size() - 1)) {
                break;
            }
        }
    }
}

int main(int argc, char** argv) {
    int count = 0;
    while (count < 10) {
        std::vector<int> nums = random_generator(20, -1, 10);
        auto iter = std::find(nums.begin(), nums.end(), 0);
        if (iter != nums.end()) {
            echo_container(nums);
            move_zero(nums);
            echo_container(nums);
            ++count;
        }
    }

    return 0;
}