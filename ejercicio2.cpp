#include <iostream>

class Date {
public:
    explicit Date(int d, int m, int y) : day{d}, year{y} {
        if (m >= 1 && m <= 12) {
            month = m;
        }
        if (y < 1900 || y > 2050) {
            year = 1900;
        }
        validateDay();
    }

    void setDay(int d) {
        day = d;
        validateDay();
    }

    void setMonth(int m) {
        if (m >= 1 && m <= 12) {
            month = m;
            validateDay();
        }
    }

    void setYear(int y) {
        year = y;
        if (y < 1900 || y > 2050) {
            year = 1900;
        }
        validateDay();
    }

    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    void displayDate() const {
        std::cout << day << " / " << month << " / " << year << std::endl;
    }

    bool isLeapYear() const {
        if (year % 4 == 0) {
            if (year % 100 != 0 || year % 400 == 0) {
                return true;
            }
        }
        return false;
    }

private:
    int day;
    int year;
    int month{1};

    void validateDay() {
        static int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear()) {
            daysInMonth[2] = 29;
        } else {
            daysInMonth[2] = 28;
        }

        if (day < 1 || day > daysInMonth[month]) {
            day = 1;
        }
    }
};

int main() {
    Date date1(3, 1, 2020); // Fecha válida
    Date date2(15, 14, 2019); // Año fuera de rango
    Date date3(20, 12, 1500); // Fecha válida, pero año fuera de rango

    std::cout << "Fecha 1: ";
    date1.displayDate();
    std::cout << "Fecha 2: ";
    date2.displayDate();
    std::cout << "Fecha 3: ";
    date3.displayDate();

    return 0;
}