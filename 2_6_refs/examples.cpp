#include <iostream>
#include <vector>
#include <string>

struct Point {
    double x;
    double y;
    double z;
};

int main() {
    int x = 10;
    int& ref = x;
    ref++;
    std::cout << x << '\n';
    Point p1 = {0, 0, 0};
    auto& p1_x = p1.x;
    p1_x = 3.14;
    std::cout << p1_x << '\n';

    int* ptr = nullptr;
    ptr = &x;

    std::cout << *ptr << '\n';
    (*ptr)++;
    std::cout << *ptr << '\n';

    Point* point_ptr = &p1;
    std::cout << point_ptr->x << ' ' << point_ptr->y << ' ' << point_ptr->z << '\n'; 

    int y = 20;
    // конст указатель
    int* const ptrc = &x; 
    ++*ptrc;
    std::cout << *ptrc << '\n';

    // указатель на конст
    const int* cptr = &x;

    std::vector<std::string> creep = {"I", "am", "a", "creep", "I", "am", "a", "weirdo"};
    for (const auto& s : creep) {
        std::cout << s << '\n';
    }
    int length_sum = 0;
    for (const auto& s : creep) {
        length_sum += s.length();
    }
    std::cout << length_sum << '\n';
}