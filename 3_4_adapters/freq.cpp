#include <iostream>
#include <utility>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
    size_t k;
    std::cin >> k;
    std::unordered_map<std::string, int> wordsFreq;
    std::string x;
    while (std::cin >> x) {
        ++wordsFreq[x];
    }

    // alias
    using TPair = std::pair<int, std::string>;

    std::priority_queue<TPair> kWords;

    for (const auto& [w, f] : wordsFreq) {
        kWords.push({-f, w});
        if (kWords.size() > k) {
            kWords.pop();
        }
    }

    std::vector<TPair> topWords;
    while (!kWords.empty()) {
        const auto& [f, w] = kWords.top();
        topWords.push_back({-f, w});
        kWords.pop();
    }
    std::reverse(topWords.begin(), topWords.end());
    for (const auto& [f, w] : topWords) {
        std::cout << w << '\t' << f << '\n';
    }
}