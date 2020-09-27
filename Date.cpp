# include "Date.h"
# include <stdio.h>
# include <Math.h>

Date::Date() : day(1), month(1), year(2000) {
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
}

void Date::display() {
    printf("%d/%d/%d", this->day, this->month, this->year);
}
