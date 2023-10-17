#include "../utils.hpp"

bool is_valid(const std::string& s) {
    std::unordered_map<char, char> bracket_map = {
        {'(', ')'},
        {'{', '}'},
        {'[', ']'}
    };
    std::stack<char> stack;
    for (auto& c : s) {
        if (bracket_map.count(c) != 0) {
            stack.push(c);
            std::cout << "push " << c << std::endl;
        } else {
            if (stack.empty()) {
                return false;
            } else {
                if (bracket_map[stack.top()] == c) {
                    std::cout << "pop " << stack.top() << std::endl;
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return stack.empty();
}

int main(int argc, char** argv) {
    std::string s = "{[()]}[(]";

    if (is_valid(s)) {
        std::cout << s << " is valid" << std::endl;
    } else {
        std::cout << s << " is not valid" << std::endl;
    }
    return 0;
}