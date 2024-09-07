#include <iostream>

int main() {
    int c1, r1, c2, r2;
    std::cin >> c1 >> r1 >> c2 >> r2;
    if (c1 == c2 || r1 == r2 || std::abs(c1-c2) == std::abs(r1-r2)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}