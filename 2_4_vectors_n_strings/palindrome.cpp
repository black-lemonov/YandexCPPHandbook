#include <iostream>
#include <string>

int main() {
    std::string x;
    getline(std::cin, x);
    std::string no_spaces;
    for (size_t i = 0; i != x.length(); ++i) {
        if (x[i] != ' ') {
            no_spaces += x[i];
        }
    }
    if (no_spaces.length() == 0) {
        std::cout << "YES";
        return 0;
    }
    for (size_t i = 0, j = no_spaces.length() - 1; i < j; ++i, --j) {
        if (no_spaces[i] != no_spaces[j]) {
            std::cout << "NO";
            return 0;
        }
    }
    
    std::cout << "YES";
}