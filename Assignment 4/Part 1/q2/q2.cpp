#include <iostream>
using namespace std;
#include <string.h>

#include "person.h"

class Student : public Person
{
    char department[DEFAULT_STRING_SIZE];
    unsigned int year;

public:
    Student() : department("\n"), year(0) {}
    Student(const char *name, unsigned int age, char gender, const char *department, unsigned int year);
    Student(const Student &rhs);
    Student &operator=(const Student &rhs);
    void read_data();
    void display_data();
};

Student::Student(const char *name, unsigned int age, char gender, const char *given_department, unsigned int given_year) : Person(name, age, gender), year(given_year)
{
    strcpy(department, given_department);
}

Student::Student(const Student &rhs) : Person(rhs), year(rhs.year)
{
    strcpy(department, rhs.department);
}

Student &Student::operator=(const Student &rhs)
{
    if (this == &rhs)
        return *this;

    (Person &)(*this) = rhs;

    strcpy(department, rhs.department);
    year = rhs.year;

    return *this;
}

void Student::read_data()
{
    Person::read_data();

    cout << "Enter Department: ";
    cin >> department;

    cout << "Enter Graduation Year: ";
    cin >> year;
}

void Student::display_data()
{
    Person::display_data();
    cout << "Department: " << department << endl;
    cout << "Graduation year: " << year << endl;
}

class Clerk : public Person
{
    char workload[DEFAULT_STRING_SIZE];
    float salary;

public:
    Clerk() : workload("\n"), salary(0) {}
    Clerk(const char *name, unsigned int age, char gender, const char *given_workload, float given_salary);
    Clerk(const Clerk &rhs);
    Clerk &operator=(const Clerk &rhs);
    void read_data();
    void display_data();
};

Clerk::Clerk(const char *name, unsigned int age, char gender, const char *given_workload, float given_salary) : Person(name, age, gender), salary(given_salary)
{
    strcpy(workload, given_workload);
}

Clerk::Clerk(const Clerk &rhs) : Person(rhs), salary(rhs.salary)
{
    strcpy(workload, rhs.workload);
}

Clerk &Clerk::operator=(const Clerk &rhs)
{
    if (this == &rhs)
        return *this;

    (Person &)(*this) = rhs; //using assignment operator of Person Class

    strcpy(workload, rhs.workload);
    salary = rhs.salary;

    return *this;
}

void Clerk::read_data()
{
    Person::read_data();
    cout << "Enter Workload: ";
    cin >> workload;
    cout << "Enter Salary: ";
    cin >> salary;
}

void Clerk::display_data()
{
    Person::display_data();
    cout << "Workload: " << workload << endl;
    cout << "Salary: " << salary << endl;
}

class Professor : public Person
{
    char department[DEFAULT_STRING_SIZE];
    char courseLoad[DEFAULT_STRING_SIZE];
    float salary;

public:
    Professor() : department("\n"), courseLoad("\n"), salary(0) {}
    Professor(const char *name, unsigned int age, char gender, const char *given_department, const char *given_courseLoad, float given_salary);
    Professor(const Professor &rhs);
    Professor &operator=(const Professor &rhs);
    void read_data();
    void display_data();
};

Professor::Professor(const char *name, unsigned int age, char gender, const char *given_department, const char *given_courseLoad, float given_salary) : Person(name, age, gender), salary(given_salary)
{
    strcpy(department, given_department);
    strcpy(courseLoad, given_courseLoad);
}

Professor::Professor(const Professor &rhs) : Person(rhs), salary(rhs.salary)
{
    strcpy(department, rhs.department);
    strcpy(courseLoad, rhs.courseLoad);
}

Professor &Professor::operator=(const Professor &rhs)
{
    if (this == &rhs)
        return *this;

    (Person &)(*this) = rhs; //invoking assignment operator of Person

    strcpy(department, rhs.department);
    strcpy(courseLoad, rhs.courseLoad);
    salary = rhs.salary;

    return *this;
}

void Professor::read_data()
{
    Person::read_data();
    cout << "Enter Department: ";
    cin >> department;
    cout << "Enter CourseLoad: ";
    cin >> courseLoad;
    cout << "Enter Salary: ";
    cin >> salary;
}

void Professor::display_data()
{
    Person::display_data();
    cout << "Department: " << department << endl;
    cout << "CourseLoad: " << courseLoad << endl;
    cout << "Salary: " << salary << endl;
}

int main()
{
    Professor *p1 = new Professor;
    p1->read_data();
    p1->display_data();

    Professor p2("Sanjana", 21, 'F', "CST", "CS-2201", 200000);
    p2.display_data();

    Professor p3 = *p1;
    delete[] p1;
    p3.display_data();

    Professor p4;
    p4 = p2;
    p4.display_data();
}