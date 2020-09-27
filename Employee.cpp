# include "Employee.h"
# include <string.h>
Employee::Employee() {
	strcpy(ho, "Doan");
	strcpy(ten, "Hung");
	hesoLuong = 3.4;
	strcpy(donvi, "IT");
	strcpy(chucvu, "GD");
	strcpy(maNv, "IT4");
	gioitinh = true;
	calculateSalary();
}

void Employee::display() {
}    

void Employee::calculateSalary() {
	int LUONG_CO_BAN = 850;
    luong = hesoLuong * LUONG_CO_BAN;
    if (strcmp(this->chucvu, "GD") == 0 || strcmp(this->chucvu, "PGD") == 0) {
        phucap = 0.4 * luong;
    }
    else if ((strcmp(this->chucvu, "TP") == 0) || (strcmp(this->chucvu, "PP") == 0)) {
        phucap = 0.25 * luong;
    }
    else {
        phucap = 0;
    }
    this->thuclinh = luong + phucap;
}

int Employee::calculateAge(int d, int m, int y) {
	// neu ngay sinh lon hon ngay hien tai, thi thang hien tai giam di 1
	if (ngaysinh.day > d) {
		m--;
	}
	// neu thang sinh lon hon thang hien tai, thi nam hien tai giam di 1
	if (ngaysinh.month > m) {
		y--;
	}
	return y - ngaysinh.year;
}
