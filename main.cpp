# include "Manager.cpp"
# include <string.h>
# include <stdio.h>

Manager manager = Manager();

void themNhanVien() {
	Employee e = Employee();
	printf("Nhap ma nhan vien: ");
	scanf("%s", &e.maNv);
	printf("Nhap ho nhan vien: ");
	scanf("%s", &e.ho);
	printf("Nhap ten nhan vien: ");
	scanf("%s", &e.ten);
	printf("Nhap gioi tinh: \n");
	printf("1. Nam\n");
	printf("2. Nu\n");
	int t;
	scanf("%d", &t);
	if (t == 1) {
		// true la nam
		e.gioitinh = true;
	}
	else {
		// false la nu
		e.gioitinh = false;
	}
	// nhap ngay thang nam sinh
	int d, m, y;
	printf("Nhap ngay sinh: \n");
	printf("Ngay: ");
	scanf("%d", &d);
	printf("Thang: ");
	scanf("%d", &m);
	printf("Nam: ");
	scanf("%d", &y);
	e.ngaysinh = Date(d, m, y);
	// Nhap don vi
	printf("Nhap don vi: ");
	scanf("%s", &e.donvi);
	printf("Nhap chuc vu: ");
	scanf("%s", &e.chucvu);
	printf("Nhap he so luong: ");
	scanf("%lf", &e.hesoLuong);

	e.calculateSalary();
	manager.addEmployee(e);
}

void deleteRetiredEmployee() {
	int age, d, m, y;
	printf("Nhap tuoi nghi huu: ");
	scanf("%d", &age);
	printf("Nhap ngay hien tai: ");
	scanf("%d", &d);
	printf("Nhap thang hien tai: ");
	scanf("%d", &m);
	printf("Nhap nam hien tai: ");
	scanf("%d", &y);
	manager.deleteRetireEmployee(age, d, m, y);
}

void thongke() {
	int i, j;
	// khoi tao mang object gom 20 gia tri
	Object objList[20] = {Object()};
	// khoi tao kich thuoc hien tai cua mang
	int listSize = 0;
	// chay qua toan bo nhan vien trong cong ty
 	for (i = 0; i < manager.size; i++) {
 		// chay qua toan bo don vi da co truoc
 		bool isAdded = false;
		for (j = 0; j < listSize; j++) {
			// neu don vi cua nhan vien va don vi da co trung` nhau
			if (strcmp(manager.list[i].donvi, objList[j].donvi) == 0) {
				// truong hop nu
				if (manager.list[i].gioitinh == false) {
					objList[j].numFemale += 1;
				}
				else {
					objList[j].numMale += 1;
				}
				objList[j].totalSalary += manager.list[i].thuclinh;
				isAdded = true;
				break;
			}
		}
		// neu khong co don vi nao, thi ta tao. don vi do'
		if (isAdded == false) {
			strcpy(objList[listSize].donvi, manager.list[i].donvi);
			// truong hop nu
			if (manager.list[i].gioitinh == false) {
				objList[listSize].numFemale += 1;
			}
			else {
				objList[listSize].numMale += 1;
			}
			objList[listSize].totalSalary += manager.list[i].thuclinh;
			listSize++;
		}
	}
	
	// in ra
	printf("Don vi\tSo nu\tSo nam\tTong thuc linh\n");
	for (i = 0; i < listSize; i++) {
		printf("%s\t%d\t%d\t%.0f\n", objList[i].donvi, objList[i].numFemale, objList[i].numMale, objList[i].totalSalary);
	}
}
int main() {
	int t;
	do {
		printf("PHAN MEM QUAN LY NHAN VIEN\n");
		printf("BAN VUI LONG CHON CHUC NANG DE SU DUNG\n");
		printf("0. THOAT CHUONG TRINH\n");
		printf("1. THEM NHAN VIEN\n");
		printf("2. XOA NHAN VIEN\n");
		printf("3. XOA NHAN VIEN THEO DO TUOI\n");
		printf("4. IN RA DANH SACH NHAN VIEN\n");
		printf("5. IN RA BANG THONG KE THEO DON VI\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &t);
		switch (t) {
			case 1:
				manager.generateEmployee();
				themNhanVien();
				break;
			case 2:
				int pos;
				printf("Nhap vi tri can xoa: ");
				scanf("%d", &pos);
				manager.deleteEmployee(pos - 1);
				break;
			case 3:
				deleteRetiredEmployee();
				break;	
			case 4:
				manager.display();
				break; 	
			case 5:
				thongke();
				break;	
			default:
				printf("BAN VUI LONG NHAP LAI!!!\n"); 	
		}
	} while (t != 0);
	return 0;
}


