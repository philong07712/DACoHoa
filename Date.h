struct Date {
    int day;
    int month;
    int year;
    Date();
    Date(const Date&);
    Date(int, int, int);
    void display();
    int compareTo(const Date) const;
    bool isValid();
    bool isLeap();
};
