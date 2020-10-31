# include "Employee.cpp"
# include "Object.cpp"
struct Manager {
    Employee list[50];
    int size;
    Manager();
    void addEmployee(Employee);
    void addEmployee(Employee, int);
    void deleteRetireEmployee(int, int, int, int);
    void display(Employee *, int);
    void loadData();
    void saveData();
    void deleteEmployee(int);
    void sort(int (*)(const Employee*, const Employee*), bool);
    int search(Employee);
    bool fequal(double, double);
};

