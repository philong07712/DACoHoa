# include "Date.cpp"
struct Employee {
    char maNv[30];
    char ho[10];
    char ten[10];
    char donvi[10];
    char chucvu[20];
    double hesoLuong, luong, phucap, thuclinh;
    Date ngaysinh;
    // 0 la nu, 1 la nam
    int gioitinh;
    public:
    Employee();
    Employee(const Employee&);
    void display();
    void calculateSalary();
    int calculateAge(int, int, int);
};
