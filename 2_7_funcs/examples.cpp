#include <iostream>
#include <vector>
#include <string>

struct Student
{
    std::string first_name, middle_name, last_name, university;
    int course, age; 
};

int Fact(int n) {
    if (n == 1) {
        return 1;
    }
    return Fact(n-1) * n;
}

void Swap(int& a, int&b) {
    auto tmp = a;
    a = b;
    b = tmp;
}

/**
 *  Аргументы сложных типов (векторы, строки, любые контейнеры, большие структуры)
 *  всегда лучше передавать в функцию по константной ссылке,
 *  если функция использует их только для чтения
 */
int Sum(const std::vector<int>& vect) {
    int sum = 0;
    for (auto& n : vect) {
        sum += n;
    }
    return sum;
}

bool operator < (const Student& lhs, const Student& rhs) {
    return lhs.age < rhs.age;
}

/// @brief как же круто
/// @param group 
void PrintStudents(const std::vector<Student>& group) {
    for (const auto& [name, patronym, surname, uni, course, age] : group) {
        std::cout << name << ' ' << patronym << ' ' << surname << ' ' << uni << ' ';
        std::cout << course << " курс " << age << " лет" << '\n';
    }
    std::cout << '\n';
}

int main() {
    const int x = 10;
    std::cout << Fact(x) << '\n';
    int a = 2, b = 1;
    Swap(a, b);
    std::cout << a << ' ' << b << '\n';
    std::vector<int> abc = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << Sum(abc) << '\n';
    std::vector<Student> group_46 = {{"Иван", "Иванович","Иванов", "КубГУ", 1, 18}};
    PrintStudents(group_46);
    // это охуенно
    auto Transfer = [&group_46](int n)->void{ 
        for (auto& s : group_46) {
            s.course++;
            s.age++;
        }
    };
    Transfer(1);
    PrintStudents(group_46);
}
