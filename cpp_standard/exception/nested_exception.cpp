#include <iostream>
#include <exception>
#include <stdexcept>

void print_what(const std::exception& e) {
    std::cerr << e.what() << std::endl;
    try {
        std::rethrow_if_nested(e);
    } catch (const std::exception& nested) {
        std::cerr << "nested: ";
        print_what(nested);
    }
}

void throw_nested() {
    try {
        throw std::logic_error("first");
    } catch (const std::exception& e) {
        std::throw_with_nested(std::logic_error("second"));
    }
}

int main() {
    try {
        throw_nested();
    } catch (std::exception& e) {
        print_what(e);
    }
}