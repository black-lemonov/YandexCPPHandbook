#include <iostream>
#include <array>
#include <vector>

template <typename T, size_t N, size_t M>
void Print(const std::array<std::array<T, N>, M>& matr) {
    for (const auto& row : matr) {
        for (const auto& el : row) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<int> vect;
    for (size_t i = 0; i != 100; ++i) {
        vect.push_back(i);
    }
    std::array<int, 100> arr;
    std::cout << "arr: " << sizeof(arr) << '\n';
    std::cout << "vect: " << sizeof(vect) << '\n';
    std::array<std::array<int, 3>, 3> matr{{{0, 0, 1}, {0, 1, 0}, {1, 0, 0}}};
    Print(matr);
    
}