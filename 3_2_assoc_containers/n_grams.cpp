#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <vector>
#include <algorithm>

int main() {
    size_t n, gramLength;
    std::cin >> n >> gramLength;
    std::string word;
    std::map<std::string, int> gramsFreqs;
    for (size_t i = 0; i != n; ++i) {
        std::cin >> word;
        if (word.length() < gramLength) {
            continue;
        }
        for (size_t j = 0; j + gramLength != word.length() + 1; ++j) {
            ++gramsFreqs[word.substr(j, gramLength)];
        }        
    }
    std::vector<std::pair<std::string, int>> sortedFreqs(gramsFreqs.begin(), gramsFreqs.end());
    std::sort(
        sortedFreqs.begin(), sortedFreqs.end(),
        [](const auto& a, const auto& b){
            return std::tie(b.second, a.first) < std::tie(a.second, b.first);
        }
    );
    for (const auto& [gram, freq] : sortedFreqs) {
        std::cout << gram << " - " << freq << '\n';
    }
}