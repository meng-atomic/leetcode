#include <vector>
#include <iostream>

int partition(std::vector<int>& datas, int left, int right) {
    int base = left;
    int ref = datas[left];
    std::cout << left << "-" << right << std::endl;
    while (left < right) {
        while (left < right && datas[right] >= ref) {
            --right;
        }
        while (left < right && datas[left] <= ref) {
            ++left;
        }
        if (left < right) {
            std::swap(datas[left], datas[right]);
        }
    }
    std::swap(datas[base], datas[left]);
    return left;
}

void quick_sort(std::vector<int>& datas, int left, int right) {
    if (left < 0) {
        return; 
    }

    if (left > datas.size() - 1) {
        return;
    }

    if (left >= right) {
        return;
    }

    int mid = partition(datas, left, right);
    std::cout << mid << std::endl;
    quick_sort(datas, left, mid - 1);
    quick_sort(datas, mid + 1, right);
}

int main(int argc, char** argv) {
    std::vector<int> datas = {7,7,3,8,5,1,6};
    quick_sort(datas, 0, datas.size() - 1);
    for (auto d : datas) {
        std::cout << d << ",";
    }
    std::cout << std::endl;
    return 0;
}