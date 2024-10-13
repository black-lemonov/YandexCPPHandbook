#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    size_t n, k;
    std::cin >> n >> k;
    std::vector<int> sorted(n);
    int x;
    for (size_t i = 0; i != n; ++i) {
        std::cin >> x;
        sorted[i] = x;
    }
    while (std::cin >> x) {
        auto it = std::min_element(
            sorted.begin(), sorted.end(),
            [=](const int a, const int b){
                return std::abs(a-x) < std::abs(b-x);
            }
        );
        std::cout << *it << '\n';
    }
}