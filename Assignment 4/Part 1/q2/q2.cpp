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

int main()
{
    Student *s1 = new Student;
    s1->read_data();
    s1->display_data();

    Student s2("Sanjana", 21, 'F', "CST", 2023);
    s2.display_data();

    Student s3 = *s1;
    delete[] s1;
    s3.display_data();

    Student s4;
    s4 = s2;
    s4.display_data();
}