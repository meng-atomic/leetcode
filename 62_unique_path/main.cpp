#include "../utils.hpp"

void echo_grid(const std::vector<std::vector<int>>& grid) {
    for (auto& vec : grid) {
        for (auto& d : vec) {
            std::cout << d << " ";
        }
        std::cout << std::endl;
    }
}

int unique_path(int m, int n) {
    std::vector<std::vector<int>> f(m, std::vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        f[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        f[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    echo_grid(f);
    return f[m - 1][n - 1];
}

int main(int argc, char** argv) {
    std::cout << unique_path(3, 7) << std::endl;
    return 0;
}