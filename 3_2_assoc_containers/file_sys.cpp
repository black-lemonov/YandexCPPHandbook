#include <iostream>
#include <string>
#include <set>

int main() {
    std::set<std::string> dirs;
    std::string filePath;
    while (true) {
        std::getline(std::cin, filePath);
        if (filePath.empty()) {
            break;
        }
        size_t pos = 0;
        while (true) {
            pos = filePath.find('/', pos);
            if (pos == std::string::npos) {
                break;
            }
            dirs.insert(filePath.substr(0, ++pos));
        }
    }
    for (std::string_view d : dirs) {
        std::cout << d << '\n';   
    }
}