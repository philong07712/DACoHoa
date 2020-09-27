# include "Employee.cpp"
# include "Object.cpp"
struct Manager {
    Employee list[50];
    int size;
    Manager();
    void addEmployee(Employee);
    void addEmployee(Employee, int);
    void generateEmployee();
    void deleteRetireEmployee(int, int, int, int);
    void display();
    void loadData();
    void saveData();
    void deleteEmployee(int);
};

