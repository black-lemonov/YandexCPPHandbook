#include <iostream>

int main() {
    int numb;
    std::cin >> numb;
    int digits_sum = 0;
    while (numb != 0) {
        digits_sum += numb % 10;
        numb /= 10;
    }
    std::cout << digits_sum;
}