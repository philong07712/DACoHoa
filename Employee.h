# include "Date.cpp"
struct Employee {
    char maNv[30];
    char ho[10];
    char ten[10];
    char donvi[10];
    char chucvu[20];
    double hesoLuong, luong, phucap, thuclinh;
    Date ngaysinh;
    bool gioitinh;
    public:
    Employee();
    void display();
    void calculateSalary();
    int calculateAge(int, int, int);
};
