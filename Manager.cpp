# include "Manager.h"

Manager::Manager() {
	size = 0;
}

void Manager::addEmployee(Employee e) {
	list[size] = e;
	size++;
}

void Manager::addEmployee(Employee e, int n) {
	// Kiem tra neu n co dat yeu cau
	if (n < 0 || n > size) {
		return;
	}
	for (int i = size; i > n; i--) {
		list[i] = list[i - 1];
	}
	list[n] = e;
	size++;
}

void Manager::display(Employee *listOfEmployee, int n) {
	int i;
	printf("MA\t|HO\t|TEN\t|DON VI\t|CHUC VU\t|HE SO LUONG\t|PHU CAP\t|THUC LINH\t|NGAY SINH\t|GT\n");
	for (i = 0; i < n; i++) {
		printf("%s\t|%s\t|%s\t|%s\t|%s\t\t|%.2f\t\t|%.1f\t\t|%.1f\t\t|", listOfEmployee[i].maNv,
			listOfEmployee[i].ho, listOfEmployee[i].ten, 
			listOfEmployee[i].donvi, listOfEmployee[i].chucvu, listOfEmployee[i].hesoLuong, listOfEmployee[i].phucap,
			listOfEmployee[i].thuclinh);
		listOfEmployee[i].ngaysinh.display();
		printf("\t|");
		if (listOfEmployee[i].gioitinh == 0) printf("Nu\n");
		else printf("Nam\n");
	}
}

void Manager::deleteEmployee(int position) {
	int i;
	// Sao chep gia tri tiep theo vao vi tri hien tai
	for (i = position; i < size - 1; i++) {
		list[i] = list[i + 1]; 
	}
	size--;
}

void Manager::deleteRetireEmployee(int retiredAge, int d, int m, int y) {
	int i = 0;
	while (i < size) {
		// find the employee age
		int employeeAge = list[i].calculateAge(d, m, y);
		// if it higher than retire age then delete it
		if (employeeAge > retiredAge) {
			deleteEmployee(i);
		}
		else {
			i++;
		}
	}
	
}

void Manager::saveData() {
	FILE *fp;
	fp = fopen("data.txt", "w");
	int i;
	for (i = 0; i < size; i++) {
		fprintf(fp, "%s %s %s %s %s %.3lf %.3lf %.3lf %.3lf %d,%d,%d,%d\n", list[i].maNv, 
			list[i].ho, list[i].ten, list[i].donvi, list[i].chucvu,
			list[i].hesoLuong, list[i].luong, list[i].phucap,
			list[i].thuclinh, list[i].ngaysinh.day, list[i].ngaysinh.month,
			list[i].ngaysinh.year, list[i].gioitinh);

	}
	fclose(fp);
}

void Manager::loadData() {
	FILE *fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("Loi! Doc du lieu khong thanh cong");
		return;
	}
	char maNv[30];
	char ho[10];
	char ten[10];
    char donvi[10];
    char chucvu[20];
    double hesoLuong, luong, phucap, thuclinh;
    int day, month, year;
    Date ngaysinh;
    bool gioitinh;
    Employee e = Employee();
	while (fscanf(fp, "%s %s %s %s %s %lf %lf %lf %lf %d,%d,%d,%d", e.maNv, e.ho, e.ten,
		e.donvi, e.chucvu, &e.hesoLuong, &e.luong, &e.phucap, &e.thuclinh, &day, 
		&month, &year, &e.gioitinh) == 13) {
		Date date = Date(day, month, year);	
		e.ngaysinh = date;
		this->addEmployee(e);	
		e = Employee();
	}
	fclose(fp);
}

void Manager::sort(int(*compare)(const Employee* e1, const Employee* e2), bool isAcsending) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size - 1; j++) {
			// so sanh 2 gia tri can kiem sap xep
			// 1 neu e1 > e2
			// 0 neu e1 = e2
			// -1 neu e1 < e2
			int result = compare(&list[j], &list[j + 1]);
			// neu muon sap xep theo chieu giam dan, ta dao nguoc gia tri cua result
			if (!isAcsending) {
				result = -result;
			}
			if (result > 0) {
				Employee temp = Employee(list[j + 1]);
				list[j + 1] = list[j];
				list[j] = temp;
			}
		}
	}
}

// tra ve 0 neu tim kiem khong thanh cong
// tra ve kich thuoc cua mang
int Manager::search(Employee e) {
	int n = 0, i;
	Employee tempList[size];
	for (i = 0; i < size; i++) {
		// kiem tra neu ma nhan vien khong rong va khong trung voi gia tri can tim thi bo qua nhan vien do
		if (strcmp(e.maNv, "empty") != 0 && strcmp(list[i].maNv, e.maNv) != 0) continue;
		if (strcmp(e.ho, "empty") != 0 && strcmp(list[i].ho, e.ho) != 0) continue;
		if (strcmp(e.ten, "empty") != 0 && strcmp(list[i].ten, e.ten) != 0) continue;
		if (strcmp(e.donvi, "empty") != 0 && strcmp(list[i].donvi, e.donvi) != 0) continue;
		if (strcmp(e.chucvu, "empty") != 0 && strcmp(list[i].chucvu, e.chucvu) != 0) continue;
		if (e.hesoLuong != -1 && !fequal(list[i].hesoLuong, e.hesoLuong)) continue;
		if (e.luong != -1 && fequal(list[i].luong, e.luong)) continue;
		if (e.phucap != -1 && fequal(list[i].phucap, e.phucap)) continue;
		if (e.thuclinh != -1 && fequal(list[i].thuclinh, e.thuclinh)) continue;
		if (e.ngaysinh.day != 0 && list[i].ngaysinh.compareTo(e.ngaysinh) != 0) continue;
		if (e.gioitinh != -1 && list[i].gioitinh != e.gioitinh) continue;
		
		tempList[n] = list[i];
		n++;
	}
	display(tempList, n);
	return n;
} 

int Manager::search(Employee e, int(*compare)(const Employee* e1, const Employee* e2), bool isAcsending) {
	int i;
	for (i = size - 1; i >= 0; i--) {
		// tang dan only
		int result = compare(&e, &list[i]);
		if (result < 0) {
			if (!isAcsending) {
				break;
			}
		}
		else if (result > 0) {
			if (isAcsending) {
				break;
			}
		}
		list[i + 1] = list[i];
	}
	list[i + 1] = e;
	size++;
	return (i + 1);
}

bool Manager::fequal(double a, double b) {
	return fabs(a-b) < 10E-6;
}


