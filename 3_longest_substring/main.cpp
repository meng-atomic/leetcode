#include "../utils.hpp"

int longest_substring(const std::string& str) {
    int max_size = 0;
    auto left = str.begin();
    auto right = str.begin() + 1;
    while (left != str.end()) {
        while (right != str.end()) {
            std::cout << "inspecting " << str.substr(left - str.begin(), right - left) << std::endl;
            auto iter = std::find(left, right, *right);
            std::cout << "left: " << left - str.begin()
              << ", right: " << right - str.begin()
              << ", iter: " << iter - str.begin() << std::endl;
            if (iter < right - 1) {
                max_size = std::max(max_size, int(right - left));
                left = iter + 1;
                ++right;
                break;
            }
            if (iter == right - 1) {
                max_size = std::max(max_size, int(right - left));
                left = right;
                ++right;
                break;
            }
            if (iter > right - 1) {
                ++right;
                continue;
            }
        }
        if (right == str.end()) {
            break;
        }
    }
    return max_size;
}

int main(int argc, char** argv) {
    std::string str = "pwawkew";
    std::cout << longest_substring(str) << std::endl;
    return 0;
}