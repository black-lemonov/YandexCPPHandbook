#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> words;
    std::string x;
    while (getline(std::cin, x)) {
        words.push_back(x);
    }

    std::sort(words.rbegin(), words.rend());

    for (size_t i = 0; i < words.size(); ++i) {
        std::cout << words[i] << '\n';
    }
}