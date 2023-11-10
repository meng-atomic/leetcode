#include <iostream>

int climb_stairs(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    return climb_stairs(n - 1) + climb_stairs(n - 2);
}

int main(int argc, char** argv) {
    std::cout << climb_stairs(3) << std::endl;
    std::cout << climb_stairs(4) << std::endl;
    return 0;
}