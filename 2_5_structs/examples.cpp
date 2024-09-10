#include <iostream>
#include <utility>

// Так выглядит enum в C++
enum class Screen {
    mobile,
    desktop,
    laptop,
    tablet
};

struct Point {
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};


int main() {
    Screen my_device = Screen::laptop;
    std::cout << static_cast<int>(my_device) << '\n';
    Point p1 = {.x=1.0, .y = 1.0, .z = 1.0};
    std::cout << '(' <<  p1.x << ' ' << p1.y << ' ' << p1.z << ')' << '\n';
    std::cout << sizeof(p1) << '\n';
    std::pair<char, unsigned> cell = {'A', 12};
    std::cout << cell.first << ' ' << cell.second << '\n';
    std::tuple<double, double, double> point = {0.0, 0.0, 0.0};
    std::cout << std::get<0>(point) << '\n'; 
    std::cout << sizeof(point) << '\n';
    auto [x, y, z] = point;
    std::cout << '(' <<  x << ' ' << y << ' ' << z << ')' << '\n';
}