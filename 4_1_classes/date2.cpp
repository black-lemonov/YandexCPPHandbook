// Вам надо переделать реализацию класса Date из предыдущей задачи,
// сохранив публичный интерфейс неизменным.
// Теперь для хранения даты используйте одну переменную типа int — количество дней,
// прошедших с некоторого начала отсчёта.

// Считайте, что все обрабатываемые даты будут лежать в пределах от 1 января 1970 года до 31 декабря 2099 года.
#include <unordered_map>
#include <iostream>

class Date {
private:
    // дней с 1 января 1970 года
    int days = 0;

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

    Date(int d) {
        if (d < 0 || d > 47481) {
            return;
        }
        days = d;
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
        while (y != 1970 || m != 1 || d != 1) {
            ++days;
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
    }

    int GetDay() const {
        int d = 1;
        int m = 1;
        int y = 1970;
        int totalDays = days;
        while (totalDays--) {
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
        return d;
    }

    int GetMonth() const {
        int m = 1;
        int y = 1970;
        int totalDays = days;
        while (true) {
            totalDays -= DaysInMonth(m, y);
            if (totalDays < 0) {
                return m;
            }
            ++m;
            y += m/13;
            m %= 13;
        }
    }

    int GetYear() const {
        int y = 1970;
        int totalDays = days;
        while (true) {
            totalDays -= 365 + IsLeap(y);
            if (totalDays < 0) {
                return y;
            }
            ++y;
        }
    }

    Date operator+ (int d) const {
        return Date(days + d);
    }

    Date operator- (int d) const {
        return Date(days - d);
    }

    int operator- (const Date& date2) const {
        return days - date2.days;
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
    Date d1(31, 12, 2002);
    std::cout << d1 << '\n';
}