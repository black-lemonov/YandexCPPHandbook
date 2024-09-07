#include <iostream>

int main() {
    int n;
    std::cin >> n;
    double ln2_sum = 0;
    int sign = 1;
    for (int i = 1; i <= n; ++i) {
        ln2_sum += 1.0 / i * sign;
        sign = -sign;
    }
    std::cout << ln2_sum;
}