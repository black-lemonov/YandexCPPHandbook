#include <iostream>
#include <string>
#include <queue>

int main() {
    std::string command;
    int x;
    std::priority_queue<int> numbers;
    while (std::cin >> command) {
        if (command == "ADD") {
            std::cin >> x;
            numbers.push(x);
        } else if (command == "EXTRACT") {
            if (numbers.empty()) {
                std::cout << "CANNOT" << '\n';
                continue;
            }
            std::cout << numbers.top() << '\n';
            numbers.pop();
        } else if (command == "CLEAR") {
            while (!numbers.empty()) {
                numbers.pop();
            }
        }
    }
    
}