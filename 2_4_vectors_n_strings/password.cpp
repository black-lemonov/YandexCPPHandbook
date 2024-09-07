#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string password;
    std::cin >> password;
    if (password.length() < 8 || password.length() > 14) {
        std::cout << "NO";
        return 0;
    }

    int has_upper = 0, has_lower = 0, has_digits = 0, has_others = 0;

    for (size_t i = 0; i != password.length(); ++i) {
        if (password[i] < 32 || password[i] > 126) {
            std::cout << "NO";
            return 0;
        }
        if (std::isupper(password[i])) {
            has_upper = 1;
        }
        else if (std::islower(password[i])) {
            has_lower = 1;
        }
        else if (std::isdigit(password[i])) {
            has_digits = 1;
        } else {
            has_others = 1;
        }
    }

    if (has_upper + has_lower + has_digits + has_others >= 3) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}