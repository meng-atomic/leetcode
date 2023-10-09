#include "../utils.hpp"

void dfs(std::vector<std::vector<char>>& grid, std::unordered_set<int>& visited,
    const int i, const int j, const int row_size) {
    if (visited.count(i * row_size + j) > 0) {
        return;
    }
    if (grid[i][j] == '1') {
        visited.insert(i * row_size +j);
        // explore right
        if (j < (row_size - 1)) {
            dfs(grid, visited, i, j + 1, row_size);
        }
        // explore down
        if (i < (grid.size() - 1)) {
            dfs(grid, visited, i + 1, j, row_size);
        }
        // explore left
        if (j > 0) {
            dfs(grid, visited, i, j - 1, row_size);
        }
    }
}

int island_number(std::vector<std::vector<char>>& grid) {
    std::unordered_set<int> visited;
    int island_num = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            int pos = grid[i].size() * i + j;
            if (visited.count(pos) > 0) {
                continue;
            }
            if (grid[i][j] == '1') {
                ++island_num;
                dfs(grid, visited, i, j, grid[i].size());
            }
        }
    }
    return island_num;
}

int main(int argc, char** argv) {
    std::vector<std::vector<char>> grid = {
        {'0','1','0','0','0'},
        {'1','1','0','1','1'},
        {'0','0','1','0','0'},
        {'1','1','0','0','1'}  
    };
    std::cout << island_number(grid) << std::endl;
    return 0;
}