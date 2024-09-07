#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> guests(n);

    for (int i = 0; i != n; ++i) {
        int x;
        std::cin >> x;
        guests[i] = x;
    }

    std::vector<int> seats(n);

    for (int i = 0; i != n; ++i) {
        seats[guests[i]-1] = i + 1;
    }

    for (int i = 0; i != n; ++i) {
        std::cout << seats[i] << ' ';
    }
}