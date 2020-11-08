# include "Date.h"
# include <stdio.h>
# include <Math.h>

// ham khoi tao mac dinh
Date::Date() : day(1), month(1), year(2000) {
}

// ham sao chep
Date::Date(const Date &d) {
	this->day = d.day;
	this->month = d.month;
	this->year = d.year;
}

// ham khoi tao voi 3 gia tri
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
}

// in ngay ra 
void Date::display() {
    printf("%d/%d/%d", this->day, this->month, this->year);
}

// so sanh 2 ngay voi nhau (sap xep)
int Date::compareTo(const Date d) const {
	// kiem tra theo thu tu nam, thang, ngay
	// kiem tra nam
	// -1 neu d1 < d2
	// 1 neu d1 > d2
	// 0 neu d1 = d2
	int result = this->year - d.year;
	if (result < 0) {
		return -1;
	}
	else if (result > 0) {
		return 1;
	}	
	// kiem tra thang
	result = this->month - d.month;
	if (result < 0) {
		return -1;
	}
	else if (result > 0) {
		return 1;
	}	
	// kiem tra ngay
	result = this->day - d.day;
	if (result < 0) {
		return -1;
	}
	else if (result > 0) {
		return 1;
	}	
	return 0;
} 

// tra ve xem thu ngay co phu hop
bool Date::isValid() {
	// nam hop le toi thieu va toi da
	int MIN_YEAR = 200;
	int MAX_YEAR = 9999;
	
	// neu so ngay khong hop le
	if (day < 1 || day > 31) {
		return false;
	}
	// neu so thang khong hop le
	if (month < 1 || month > 12) {
		return false;
	}
	// neu so nam khong hop le
	if (year < MIN_YEAR || year > MAX_YEAR) {
		return false;
	}
	// truong hop la thang 2, neu nam nhuan thi ngay toi da la 29
	// nguoc lai toi da la 28
	if (month == 2) {
		if (isLeap()) {
			return day <= 29;
		}
		else return day <= 28;
	}
	
	// kiem tra cac thang co 30 ngay
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		// so ngay toi da la 30
		return day < 31;
	}
	
	// nhung truong hop con lai la hop le
	return true;
}

// kiem tra xem co phai nam nhuan khong
bool Date::isLeap() {
	// la nam nhuan neu chia het cho 4(khong chia het cho 100) va 400
	if (year % 4 == 0) {
		if (year != 100) {
			return true;
		}
		else if (year % 400 == 0) {
			return true;
		}
	}
	return false;
}
