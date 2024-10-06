// Задание 3
// Дано: 
// кол-во строк 
// строки вида: номер страницы слово
// Необходимо:
// сгруппировать слова по страницам
// вот так: номер страницы слово1 слово2 ...
#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    size_t wordsTotal;
    std::cin >> wordsTotal;
    std::map<int, std::set<std::string>> pagesMap;
    std::string word;
    int page;
    for (size_t i = 0; i != wordsTotal; ++i) {
        std::cin >> word >> page;
        pagesMap[page].insert(word);
    }
    for (const auto& [page, words] : pagesMap) {
        std::cout << page << ' ';
        for (const auto& w : words) {
            std::cout << w << ' ';
        }
        std::cout << '\n';
    }
}