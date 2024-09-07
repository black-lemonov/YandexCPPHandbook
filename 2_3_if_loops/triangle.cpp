#include <iostream>

int main() {
    int side1, side2, side3;
    std::cin >> side1 >> side2 >> side3;
    if (side1 + side2 <= side3) {
        std::cout << "UNDEFINED";
    } else if(side1 + side3 <= side2) {
        std::cout << "UNDEFINED";
    } else if(side2 + side3 <= side1) {
        std::cout << "UNDEFINED";
    } else if (side1 * side1 + side2 * side2 == side3 * side3) {
        std::cout << "YES";
    } else if (side1 * side1 + side3 * side3 == side2 * side2) {
        std::cout << "YES";
    } else if (side2 * side2 + side3 * side3 == side1 * side1) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}