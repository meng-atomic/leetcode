#include <iostream>
#include <exception>
#include <cstdlib>

void myterminate() {
    std::cerr << "terminate handler called" << std::endl;
    abort();
}

int main(void) {
    std::set_terminate(myterminate);
    throw 0;
    return 0;
}