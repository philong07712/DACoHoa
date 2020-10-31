# include "Manager.cpp"
# include <string.h>
# include <stdio.h>

Manager manager = Manager();

void themNhanVien() {
	Employee e = Employee();
	printf("----------------------------------------\n");
	printf("Nhap ma nhan vien: ");
	scanf("%s", &e.maNv);
	printf("Nhap ho nhan vien: ");
	scanf("%s", &e.ho);
	printf("Nhap ten nhan vien: ");
	scanf("%s", &e.ten);
	printf("Nhap gioi tinh: \n");
	printf("0. Nu\n");
	printf("1. Nam\n");
	scanf("%d", &e.gioitinh);
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
	printf("----------------------------------------\n");
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

int compareByMaNv(const Employee *e1, const Employee *e2) {
	int result = strcmp(e1->maNv, e2->maNv);
	result = -result;
	return result;
}

int compareByHo(const Employee *e1, const Employee *e2) {
	int result = strcmp(e1->ho, e2->ho);
	result = -result;
	return result;
}

int compareByTen(const Employee *e1, const Employee *e2) {
	int result = strcmp(e1->ten, e2->ten);
	// thay chieu so sanh cua ten
	result = -result;
	return result;
}

int compareByDonVi(const Employee *e1, const Employee *e2) {
	int result = strcmp(e1->donvi, e2->donvi);
	// thay chieu so sanh cua ten
	result = -result;
	return result;
}

int compareByChucVu(const Employee *e1, const Employee *e2) {
	int result = strcmp(e1->chucvu, e2->chucvu);
	// thay chieu so sanh cua ten
	result = -result;
	return result;
}

int compareByHeSoLuong(const Employee *e1, const Employee *e2) {
	int result = e1->hesoLuong - e2->hesoLuong;
	if (result < 0) {
		return 1;
	}
	else if (result > 0) {
		return -1;
	}
	return 0;
}

int compareByLuong(const Employee *e1, const Employee *e2) {
	int result = e1->luong - e2->luong;
	if (result < 0) {
		return 1;
	}
	else if (result > 0) {
		return -1;
	}
	return 0;
}

int compareByPhuCap(const Employee *e1, const Employee *e2) {
	int result = e1->phucap - e2->phucap;
	if (result < 0) {
		return 1;
	}
	else if (result > 0) {
		return -1;
	}
	return 0;
}

int compareByThucLinh(const Employee *e1, const Employee *e2) {
	int result = e1->thuclinh - e2->thuclinh;
	if (result < 0) {
		return 1;
	}
	else if (result > 0) {
		return -1;
	}
	return 0;
}

int compareByNgaySinh(const Employee *e1, const Employee *e2) {
	int result = e1->ngaysinh.compareTo(e2->ngaysinh);
	return result;
}

int compareByGioiTinh(const Employee *e1, const Employee *e2) {
	int result = e1->gioitinh - e2->gioitinh;
	if (result < 0) {
		return 1;
	}
	else if (result > 0) {
		return -1;
	}
	return 0;
}


void sapxep() {
	int t, isAcsending;
	do {
		printf("----------------------------------------\n");
		printf("LUA CHON TIEU CHI DE SAP XEP\n");
		printf("1. MA NHAN VIEN\n");
		printf("2. HO\n");
		printf("3. TEN\n");
		printf("4. DON VI\n");
		printf("5. CHUC VU\n");
		printf("6. HE SO LUONG\n");
		printf("7. LUONG\n");
		printf("8. PHU CAP\n");
		printf("9. THUC LINH\n");
		printf("10. NGAY SINH\n");
		printf("11. GIOI TINH\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &t);
		printf("NHAP CHIEU SAP XEP\n");
		printf("0. GIAM DAN\n1.TANG DAN\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &isAcsending);

		switch(t) {
			case 1:
				manager.sort(compareByMaNv, isAcsending);
				break;
			case 2:
				manager.sort(compareByHo, isAcsending);
				break;
			case 3:
				manager.sort(compareByTen, isAcsending);
				break;
			case 4:
				manager.sort(compareByDonVi, isAcsending);
				break;
			case 5:
				manager.sort(compareByChucVu, isAcsending);
				break;
			case 6:
				manager.sort(compareByHeSoLuong, isAcsending);
				break;		
			case 7:
				manager.sort(compareByLuong, isAcsending);
				break;
			case 8:
				manager.sort(compareByPhuCap, isAcsending);
				break;
			case 9:
				manager.sort(compareByThucLinh, isAcsending);
				break;		
			case 10:
				manager.sort(compareByNgaySinh, isAcsending);
				break;
			case 11:
				manager.sort(compareByGioiTinh, isAcsending);
				break;																					
			default:	
				t = -1;
				printf("LUA CHON KHONG HOP LE\n");
		}
	} while (t == -1);
}

void timkiem() {
	// tao gia tri mac dinh cho 1 bien employee rong
	Employee e = Employee();
	strcpy(e.maNv, "empty");
	strcpy(e.ho, "empty");
	strcpy(e.ten, "empty");
	strcpy(e.donvi, "empty");
	strcpy(e.chucvu, "empty");
	e.hesoLuong = -1;
	e.luong = -1;
	e.phucap = -1;
	e.thuclinh = -1;
	e.ngaysinh = Date(0, 0, 0);
	e.gioitinh = -1;
	
	int d, m, y;
	int t;
	do {
		printf("NHAP TIEU CHI TIM KIEM: \n");
		printf("0. HOAN THANH\n");
		printf("1. MA NHAN VIEN\n");
		printf("2. HO\n");
		printf("3. TEN\n");
		printf("4. DON VI\n");
		printf("5. CHUC VU\n");
		printf("6. HE SO LUONG\n");
		printf("7. LUONG\n");
		printf("8. PHU CAP\n");
		printf("9. THUC LINH\n");
		printf("10. NGAY SINH\n");
		printf("11. GIOI TINH\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &t);
		switch (t) {
			case 0:
				break;
			case 1:
				printf("NHAP MA NHAN VIEN: ");
				scanf("%s", &e.maNv);
				break;
			case 2:
				printf("NHAP HO: ");
				scanf("%s", &e.ho);
				break;	
			case 3:
				printf("NHAP TEN: ");
				scanf("%s", &e.ten);
				break;
			case 4:
				printf("NHAP DON VI: ");
				scanf("%s", &e.donvi);
				break;
			case 5:
				printf("NHAP CHUC VU: ");
				scanf("%s", &e.chucvu);
				break;	
			case 6:
				printf("NHAP HE SO LUONG: ");
				scanf("%lf", &e.hesoLuong);
				break;
			case 7:
				printf("NHAP LUONG: ");
				scanf("%lf", &e.luong);
				break;
			case 8:
				printf("NHAP PHU CAP: ");
				scanf("%lf", &e.phucap);
				break;	
			case 9:
				printf("NHAP THUC LINH: ");
				scanf("%lf", &e.thuclinh);
				break;
			case 10:
				printf("NGAY: ");
				scanf("%d", &d);
				printf("THANG: ");
				scanf("%d", &m);
				printf("NAM: ");
				scanf("%d", &y);
				e.ngaysinh = Date(d, m, y);
				break;	
			case 11:
				printf("NHAP GIOI TINH: \n");
				printf("0. NU\n");
				printf("1. NAM\n");
				scanf("%d", &e.gioitinh);
				break;																						
			default:
				printf("LUA CHON KHONG HOP LE\n");
		}
	} while (t != 0);
	manager.search(e);
}

int main() {
	int t;
	manager.loadData();
	do {
		printf("----------------------------------------\n");
		printf("PHAN MEM QUAN LY NHAN VIEN\n");
		printf("BAN VUI LONG CHON CHUC NANG DE SU DUNG\n");
		printf("0. THOAT CHUONG TRINH\n");
		printf("1. THEM NHAN VIEN\n");
		printf("2. XOA NHAN VIEN\n");
		printf("3. XOA NHAN VIEN THEO DO TUOI\n");
		printf("4. IN RA DANH SACH NHAN VIEN\n");
		printf("5. IN RA BANG THONG KE THEO DON VI\n");
		printf("6. SAP XEP NHAN VIEN THEO MOT TIEU CHI\n");
		printf("7. TIM KIEM THEO NHIEU TIEU CHI\n");
		printf("----------------------------------------\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &t);
		
		switch (t) {
			case 1:
				themNhanVien();
				manager.saveData();
				break;
			case 2:
				int pos;
				printf("Nhap vi tri can xoa: ");
				scanf("%d", &pos);
				manager.deleteEmployee(pos - 1);
				manager.saveData();
				break;
			case 3:
				deleteRetiredEmployee();
				manager.saveData();
				break;	
			case 4:
				printf("----------------------------------------\n");
				manager.display(manager.list, manager.size);
				break; 	
			case 5:
				thongke();
				break;
			case 6:
				sapxep();
				manager.display(manager.list, manager.size);
				manager.saveData();
				break;
			case 7:
				timkiem();
				break;			
			default:
				printf("BAN VUI LONG NHAP LAI!!!\n"); 	
		}
	} while (t != 0);
	return 0;
}

