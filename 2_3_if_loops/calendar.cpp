#include <iostream>

int main() {
    int first_day, total_days;
    std::cin >> first_day >> total_days;

    int day = 1;

    do {
        for (int i = 1; i <= 7; ++i) {
            if (i < first_day) {
                std::cout << "  " << ' ';
                continue;
            }

            if (day < 10) {
                std::cout << ' ';
            }
            std::cout << day;
            ++day;
            
            if (day > total_days) {
                break;
            }

            if (i < 7) {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
        first_day = 1;
    } while (day <= total_days);
}