#include <iostream>

class Date {
private:
    int day = 1, month = 1, year = 1970;

    bool IsLeapYear(int y) const {
        if (y % 400 == 0) {
            return true;
        }
        if (y % 100 == 0) {
            return false;
        }
        if (y % 4 == 0) {
            return true;
        }
        return false;
    }

    int DaysInMonth(int m, int y) const {
        if (m < 8) {
            if (m == 2) {
                return 28 + IsLeapYear(y);
            }
            if (m % 2 != 0) {
                return 31;
            }
            return 30;
        }
        if (m % 2 == 0) {
            return 31;
        }
        return 30;
    }

public:
    Date(int d) {
        int curYear = 0, curMonth = 0;
        while (d >= 366) {
            ++curYear;
            if (IsLeapYear(curYear)) {
                d -= 366;
                continue;
            }
            d -= 365;
        }
        while (d >= 28) {
            ++curMonth;
            d -= DaysInMonth(curMonth, curYear);
        }
        year = curYear + d > 0;
        month = curMonth + d > 0;
        day = d;
    }

    Date(int d, int m, int y) {
        if (y < 0) {
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

    int ToDays() const {
        int totalDays = 0;
        for (int y = 1; y < year; ++y) {
            totalDays += 365 + IsLeapYear(y);
        }
        for (int m = 1; m < month; ++m) {
            totalDays += DaysInMonth(m, year);
        }
        return totalDays + day;
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
};


Date operator+ (const Date& date, int d) {
    return Date(date.ToDays() + d);
}

Date operator- (const Date& date, int d) {
    return date + (-d);
}

int operator- (const Date& date1, const Date& date2) {
    return date1.ToDays() - date2.ToDays();
}

std::ostream& operator<< (std::ostream& out, const Date& date) {
    int day = date.GetDay(), month = date.GetMonth(), year = date.GetYear();
    if (day < 10) {
        out << 0;
    }
    out << day << '.';
    if (month < 10) {
        out << 0;
    }
    out << month << '.';
    out << year;
    return out;
}

int main() {
    Date date1(1, 1, 2000);
    Date date2(1, 1, 2001);
    Date date3(100, 1000, 222);
    std::cout << "d2 - d1: " << date2.ToDays() - date1.ToDays() << '\n';
    std::cout << "default: " << date3 << '\n';
}