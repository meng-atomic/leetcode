#include <iostream>
#include <exception>
#include <stdexcept>

int main() {
    std::exception_ptr p;
    try {
        throw std::logic_error("some logic_error exception");
    } catch(const std::exception& e) {
        p = std::current_exception();
        std::cout << "exception caught, but continuing..." << std::endl;
    }
    std::cout << "(after exception)" << std::endl;
    try {
        std::rethrow_exception(p);
    } catch (const std::exception& e) {
        std::cout << "exception caught: " << e.what() << std::endl;
    }
}