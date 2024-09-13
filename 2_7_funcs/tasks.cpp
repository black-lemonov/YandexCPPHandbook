#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>

/** 
 * Возвращает пару из индексов максимального элемента в матрице.
 * Если максимальных элементов несколько, то наименьшую такую пару.
 */
std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>>& matrix) {
    std::pair<size_t, size_t> max_indices(0, 0);
    int max_el = matrix[0][0];
    for (size_t i = 0; i != matrix.size(); ++i) {
        for (size_t j = 0; j != matrix[i].size(); ++j) {
            if (matrix[i][j] > max_el) {
                max_el = matrix[i][j];
                max_indices = {i, j};
            }
        }
    } 
    return max_indices;
}

/**
 * Вычисляет наибольший общий префикс строк
 */
std::string CommonPrefix(const std::vector<std::string>& words) {
    if (words.empty()) {
        return "";
    }

    const std::string& shortest = *std::min_element(words.begin(), words.end(), [](const std::string& s1, const std::string& s2)->bool{
        return s1.length() < s2.length();
    });

    std::string prefix;

    for (size_t i = 0; i != shortest.length(); ++i) {
        auto c = shortest[i];
        for (const auto& w : words) {
            if (w[i] != c) {
                return prefix;
            }
        }
        prefix += c;
    } 
    return prefix;
}

/**
 * Split как в питоне
 */
std::vector<std::string> Split(const std::string& str, char delimiter) {
    std::vector<std::string> splits;
    std::string cur_str;
    for (auto c : str) {
        if (c == delimiter) {
            splits.push_back(cur_str);
            cur_str.clear();
            continue;
        }        
        cur_str += c;
    }
    splits.push_back(cur_str);
    return splits;
}

std::string Join(const std::vector<std::string>& tokens, char delimiter) {
    if (tokens.empty()) {
        return "";
    }

    if (tokens.size() == 1) {
        return tokens.front();
    }

    std::string joined;
    for (size_t i = 0; i + 1 != tokens.size(); ++i) {
        joined += tokens[i];
        joined += delimiter;
    }
    joined += tokens.back();
    return joined;
}

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>>& matrix) {
    size_t rows = matrix.size(), columns = matrix[0].size();

    std::vector<std::vector<int>> t(columns, std::vector<int>(rows));

    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != columns; ++j) {
            t[j][i] = matrix[i][j];
        }
    }
    return t;
}

void PrintMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int c : row) {
            std::cout << c << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<std::vector<int>> matr = {{1,0,1}, {0,1,1}, {0,0,1}};
    PrintMatrix(matr);
    PrintMatrix(Transpose(matr));
    int* a = nullptr;
    std::cout << &a << '\n'; 
}