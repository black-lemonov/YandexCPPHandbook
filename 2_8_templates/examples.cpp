#include <iostream>
#include <vector>

template <typename T>
struct ComplexNumber
{
    T im, re;
};

template<typename T>
std::vector<T>& Multiply(std::vector<T>& vect, T number) {
    for (T& el : vect) {
        el *= number;
    }
    return vect;
}

template <typename T>
std::vector<std::vector<T>>& Multiply(std::vector<std::vector<T>>& matr, T number) {
    for (auto& row : matr) {
        for (T& el : row) {
            el *= number;
        }
    }
    return matr;
}

template <typename T>
std::vector<std::vector<T>> Multiply(const std::vector<std::vector<T>>& matr1, const std::vector<std::vector<T>>& matr2) {
    if (matr1.empty() || matr2.empty()) {
        std::cout << "Невозможно перемножить пустые матрицы" << '\n';
        return {};
    }

    size_t rows_2 = matr2.size();
    size_t cols_1 = matr1.front().size();

    if (cols_1 != matr2.size()) {
        std::cout << "Невозможно перемножить матрицы заданной размерности" << '\n';
        return {};
    }

    size_t rows_1 = matr1.size();
    size_t cols_2 = matr2.front().size();

    std::vector<std::vector<T>> answer(rows_1, std::vector<T>(cols_2));

    for (size_t i = 0; i != rows_1; ++i) {
        for (size_t k = 0; k != cols_2; ++k) {
            for (size_t j = 0; j != cols_1; ++j) {
                answer[i][k] += matr1[i][j] * matr2[j][k]; 
            }
        }
    }   
    return answer;
}

template <typename T>
void Print(const std::vector<T>& vect) {
    for (const auto& el : vect) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void Print(const std::vector<std::vector<T>>& matr) {
    for (const auto& row : matr) {
        for (const T& el : row) {
            std::cout << el << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    std::vector<std::vector<int>> matr1 = {
        {9, 3,  5},
        {2, 0,  3},
        {0, 1, -6}
    };
    std::vector<std::vector<int>> matr2 = {
        { 1, -1, -1},
        {-1,  4,  7},
        { 8,  1, -1}
    };
    Print(matr1);
    std::cout << '*' << '\n';
    Print(matr2);
    std::cout << '=' << '\n';
    Print(Multiply(matr1, matr2));
}