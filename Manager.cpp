# include "Manager.h"

Manager::Manager() {
	size = 0;
}
	
void Manager::addEmployee(Employee e, int position) {
	list[position] = e;
}

void Manager::addEmployee(Employee e) {
	list[this->size] = e;
	size++;
}

void Manager::generateEmployee() {
	int i;
	for (i = 0; i < 3; i++) {
		addEmployee(Employee());
	}
}

void Manager::display() {
	int i;
	printf("Ma nhan vien\tHo\tTen\tChuc vu\tDon vi\tLuong\n");
	for (i = 0; i < size; i++) {
		printf("%s\t\t%s\t%s\t%s\t%s\t%.0f\n", list[i].maNv, list[i].ho, list[i].ten, list[i].chucvu, list[i].donvi, list[i].thuclinh);
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
//	FILE *fp;
//	fp = fopen("data.txt", "w");
//	int i;
//	for (i = 0; i < size; i++) {
//		
//	}
//	fclose(fp);
}

void Manager::loadData() {
//	int num;
//	int bufferLength = 255;
//	char buffer[bufferLength];
//	FILE *fptr;
//	char str[1000];
//	if ((fptr = fopen("data.txt", "r")) == NULL) {
//		printf("Loi! Doc du lieu khong thanh cong");
//	}
////	int line = 3;
////	while (line > 0) {
////		line--;
////		fscanf(fptr, "%[^\ ]", &str);
////		printf(str);
////	}
//	while (fgets(buffer, bufferLength, fptr)) {
//		printf("%s\n", buffer);
//	}
//	fclose(fptr);
}

