#include<iostream>
#include<vector>
#include<cmath>

int main() {
    int rows, columns, mines;
    std::cin >> rows >> columns >> mines;
    std::vector<std::vector<int>> gamefield(rows, std::vector<int>(columns, 0));
    
    for (int i = 0; i != mines; ++i) {
        int r, c;
        std::cin >> r >> c;
        gamefield[r-1][c-1] = -1;
        for (size_t r_ = 0; r_ != gamefield.size(); ++r_) {
            for (size_t c_ = 0; c_ != gamefield[r_].size(); ++c_) {
                if (gamefield[r_][c_] == -1) {
                    continue;
                }

                if (
                    std::abs(r - static_cast<int>(r_ + 1)) <= 1
                    && std::abs(c - static_cast<int>(c_ + 1)) <= 1
                ) {
                    gamefield[r_][c_] += 1;
                }
            }
        }
    }

    for (size_t r = 0; ; ) {
        for (size_t c = 0; ; ) {
            if (gamefield[r][c] == -1) {
                std::cout << '*';
            } else {
                std::cout << gamefield[r][c];
            }
            
            ++c;
            if (c == gamefield[r].size()) {
                break;
            }
            std::cout << ' ';
        }
        ++r;
        if (r == gamefield.size()) {
            break;
        }
        std::cout << '\n';
    }
}