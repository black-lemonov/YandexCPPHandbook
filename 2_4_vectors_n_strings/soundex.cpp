#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string word, word_copy;
    std::cin >> word;
    auto first_letter = word[0];
    word_copy += first_letter;

    std::vector<char> to_delete = {
        'a', 'e', 'h', 'i', 'o', 'u', 'w', 'y'
    };

    for (size_t i = 1; i != word.length(); ++i) {
        bool yes = false;
        for (size_t j = 0; j != to_delete.size(); ++j) {
            if (word[i] == to_delete[j]) {
                yes = true;
                break;
            }
        }
        if (!yes) {
            word_copy += word[i];
        }
    }

    std::string word_copy2;
    word_copy2 += first_letter;

    for (size_t i = 1; i != word_copy.length(); ++i) {
        if (
            word_copy[i] == 'b'
            || word_copy[i] == 'f'
            || word_copy[i] == 'p'
            || word_copy[i] == 'v'
        ) {
            word_copy2 += '1';
            continue;
        }

        if (
            word_copy[i] == 'c'
            || word_copy[i] == 'g'
            || word_copy[i] == 'j'
            || word_copy[i] == 'k'
            || word_copy[i] == 'q'
            || word_copy[i] == 's'
            || word_copy[i] == 'x'
            || word_copy[i] == 'z'
        ) {
            word_copy2 += '2';
            continue;
        }

        if (word_copy[i] == 'd' || word_copy[i] == 't') {
            word_copy2 += '3';
            continue;
        }

        if (word_copy[i] == 'l') {
            word_copy2 += '4';
            continue;
        }

        if (word_copy[i] == 'm' || word_copy[i] == 'n') {
            word_copy2 += '5';
            continue;
        }

        if (word_copy[i] == 'r') {
            word_copy2 += '6';
            continue;
        }
    }

    std::string word_copy3;
    word_copy3 += first_letter;
    char prev = word_copy3[0];
    for (size_t i = 1; i < word_copy2.length(); ++i) {
        if (word_copy2[i] != prev) {
            word_copy3 += word_copy2[i];
        }
        prev = word_copy2[i];
    }

    word_copy3.resize(4, '0');
    std::cout << word_copy3;
}