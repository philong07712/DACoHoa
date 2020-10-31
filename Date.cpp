# include "Date.h"
# include <stdio.h>
# include <Math.h>

Date::Date() : day(1), month(1), year(2000) {
}

Date::Date(const Date &d) {
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
}

void Date::display() {
    printf("%d/%d/%d", this->day, this->month, this->year);
}
int Date::compareTo(const Date d) const {
	int result = this->year - d.year;
	if (result != 0) {
		return result;
	}
	result = this->month - d.month;
	if (result != 0) {
		return result;
	}
	result = this->day - d.day;
	return result;
} 
