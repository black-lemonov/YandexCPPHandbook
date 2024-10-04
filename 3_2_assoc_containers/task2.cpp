// На вход поступают строки
// необходимо вывести буквы встречающиеся
// во всех введенных строках в алфавитном порядке

#include <unordered_set>
#include <set>
#include <string>
#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> words;
    std::string word;
    while (true) {
        std::getline(std::cin, word);
        if (word.empty()) {
            break;
        }
        words.push_back(word);
    }
    std::set<char> letters;
    for (const auto& w : words) {
        for (char l : w) {
            bool foundLetter = true;
            for (const auto& w2 : words) {
                if (w2.find(l) == std::string::npos) {
                    foundLetter = false;
                    break;
                }
            }
            if (foundLetter) {
                letters.insert(l);
            }
        }
    }
    for (char c : letters) {
        std::cout << c << ' ';
    }
}