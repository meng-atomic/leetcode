#include <iostream>
#include <exception>

void myunexpected() {
    std::cerr << "unexpected called\n";
    throw 0;
}

void myfunction () throw (int) {
    throw 1;
}

int main() {
    std::set_unexpected(myunexpected);
    try {
        myfunction();
    } catch (int) {
        std::cerr << "caught int \n";
    } catch (...) {
        std::cerr << "caught some other exception type\n";
    }
    return 0;
}