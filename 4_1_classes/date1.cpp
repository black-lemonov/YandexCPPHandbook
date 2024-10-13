// Вам надо написать класс Date для хранения даты григорианского календаря.
// Используйте три переменных типа int для хранения дня, месяца и года.
// В вашем классе должен быть следующий публичный интерфейс:
// Конструктор, принимающий на вход три числа: день, месяц и год.
// В случае некорректной даты должна создаваться дата 1 января 1970 года.

// Константные функции GetDay, GetMonth и GetYear.

// Бинарные операторы + и -, где вторым аргументом является целое число — количество дней.
// Эти операторы должны вернуть новую дату, отстоящую от заданной на указанное число дней.

// Бинарный оператор -, вычисляющий разность между двумя датами и возвращающий int – количество дней.

#include <iostream>
#include <unordered_map>

class Date {
private:
    int day = 1;
    int month = 1;
    int year = 1970;
    
    bool IsLeap(int y) const {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    }

    int DaysInMonth(int m, int y) const {
        std::unordered_map<int, int> monthDays = {
            {1,31}, {2,28}, {3,31}, {4,30}, {5,31}, {6,30},
            {7,31}, {8,31}, {9,30}, {10,31}, {11,30}, {12,31}
        };
        int extraDays = 0;
        if (IsLeap(y) && m == 2) {
            extraDays = 1;
        }
        return monthDays[m] + extraDays;
    }

public:
    Date(int d, int m, int y) {
        if (y < 1970 || y > 2099) {
            return;
        }
        if (m < 0 || m > 12) {
            return;
        }
        if (d < 0 || d > DaysInMonth(m, y)) {
            return;
        }
        day = d;
        month = m;
        year = y;
    }

    int GetDay() const {
        return day;
    }

    int GetMonth() const {
        return month;
    }

    int GetYear() const {
        return year;
    }

    Date operator+ (int days) const {
        int d = day;
        int m = month;
        int y = year;
        while (days--) {
            ++d;
            if (d > DaysInMonth(m, y)) {
                ++m;
                if (m > 12) {
                    ++y;
                    m = 1;
                }
                d = 1;
            }
        }
        return Date(d, m, y);
    }

    Date operator- (int days) const {
        int d = day;
        int m = month;
        int y = year;
        while (days--) {
            --d;
            if (d < 1) {
                --m;
                if (m < 1) {
                    --y;
                    m = 12;
                }
                d = DaysInMonth(m, y);
            }
        }
        return Date(d, m, y);
    }

    int operator- (const Date& date2) const {
        int d = date2.GetDay();
        int m = date2.GetMonth();
        int y = date2.GetYear();
        if (y > year || (y == year && m > month) || (y == year && m == month && d > day)) {
            return -(date2 - *this);
        }
        int daysCount = 0;
        while (y != year || m != month || d != day) {
            ++d;
            ++daysCount;
            if (d > DaysInMonth(m, y)) {
                ++m;
                if (m > 12) {
                    ++y;
                    m = 1;
                }
                d = 1;
            }
        }
        return daysCount;
    }
};

std::ostream& operator<< (std::ostream& out, const Date& date) {
    if (date.GetDay() < 10) {
        out << '0';
    }
    out << date.GetDay() << '.';
    if (date.GetMonth() < 10) {
        out << '0';
    }
    out << date.GetMonth() << '.';
    out << date.GetYear();
    return out;
}

int main() {
    Date d1(13, 10, 2024);
    Date d2(5, 7, 2024);
    std::cout << d1 - d2 << '\n';
    std::cout << d2 - d1 << '\n';
}