#include <vector>
#include <iostream>

void bubble_sort(std::vector<int>& datas) {
    for (int i = 0; i < datas.size() - 1; ++i) {
        for (int j = 0; j < datas.size() - i - 1; ++j) {
            if (datas[j] > datas[j + 1]) {
                std::swap(datas[j], datas[j + 1]);
            }
        }
    }
}

int main(int argc, char** argv) {
    std::vector<int> datas = {5,4, 9, 7, 2, 6, 1};
    bubble_sort(datas);
    for (auto data : datas) {
        std::cout << data << ",";
    }
    std::cout << std::endl;
    return 0;
}