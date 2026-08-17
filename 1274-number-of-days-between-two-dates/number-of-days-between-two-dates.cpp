#include <string>
#include <cmath>
#include <vector>
#include <sstream>

class Solution {
private:
    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysFrom1900(const std::string& dateStr) {
        int year, month, day;
        char dash1, dash2;
        std::stringstream ss(dateStr);
        ss >> year >> dash1 >> month >> dash2 >> day;

        int days = 0;

        // Add days for full years from 1900 to year - 1
        for (int y = 1900; y < year; ++y) {
            days += isLeap(y) ? 366 : 365;
        }

        // Add days for full months in the current year
        std::vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int m = 1; m < month; ++m) {
            if (m == 2 && isLeap(year)) {
                days += 29;
            } else {
                days += daysInMonths[m - 1];
            }
        }

        // Add remaining days of the current month
        days += day;
        return days;
    }

public:
    int daysBetweenDates(std::string date1, std::string date2) {
        return std::abs(daysFrom1900(date1) - daysFrom1900(date2));
    }
};