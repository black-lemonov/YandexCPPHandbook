#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x, y;
};

bool operator < (const Point& p1, const Point& p2) {
    return p1.x * p1.x + p1.y * p1.y < p2.x * p2.x + p2.y * p2.y;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<Point> points;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        Point p = {x, y};
        points.push_back(p);
    }
    std::sort(points.begin(), points.end());
    for (auto [x, y] : points) {
        std::cout << x << ' ' << y << '\n';
    }
}