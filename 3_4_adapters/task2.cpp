#include <iostream>
#include <set>
#include <queue>

int main() {
    size_t n, k;
    int x;
    std::cin >> n >> k;
    std::queue<int> numbers;
    std::multiset<int> window;
    for (size_t i = 1; i != n + 1; ++i) {
        std::cin >> x;
        numbers.push(x);
        window.insert(x);
        if (i >= k) {
            auto it = window.begin();
            std::cout << *it << '\n';
            window.erase(
                window.find(numbers.front())
            );
            numbers.pop();
        }
    }
}