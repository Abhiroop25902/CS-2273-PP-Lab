#include <iostream>
using namespace std;
#include <string.h>

const int DEFAULT_STRING_SIZE = 10;

class Person
{
    char name[DEFAULT_STRING_SIZE];
    unsigned int age;
    char gender;

public:
    Person() : name("\n"), age(0), gender('-') {}
    Person(const char *given_name, unsigned int given_age, char given_gender) : age(given_age), gender(given_gender)
    {
        strcpy(name, given_name);
    }
    void read_data();
    void display_data();
};

void Person::read_data()
{
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender (single char only): ";
    cin >> gender;
}

void Person::display_data()
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
}

class Academic : public Person
{
    char department[DEFAULT_STRING_SIZE];

public:
    Academic() : department("\n") {}
    Academic(const char *given_name, unsigned int given_age, char given_gender, const char *given_dept) : Person(given_name, given_age, given_gender)
    {
        strcpy(department, given_dept);
    }
    void read_data();
    void display_data();
};

void Academic::read_data()
{
    Person::read_data();
    cout << "Enter Department: ";
    cin >> department;
}

void Academic::display_data()
{
    Person::display_data();
    cout << "Department: " << department << endl;
}

class Professional : public Person
{
    double salary;

public:
    Professional() : salary(0) {}
    Professional(const char *given_name, unsigned int given_age, char given_gender, const double given_salary) : Person(given_name, given_age, given_gender), salary(given_salary) {}
    void read_data();
    void display_data();
};

void Professional::read_data()
{
    Person::read_data();
    cout << "Enter Salary: ";
    cin >> salary;
}

void Professional::display_data()
{
    Person::display_data();
    cout << "Salary: " << salary << endl;
}

class Student : public Academic
{
    unsigned int year;

public:
    Student() : year(0) {}
    Student(const char *given_name, unsigned int given_age, char given_gender, const char *given_dept, const unsigned int given_year) : Academic(given_name, given_age, given_gender, given_dept), year(given_year) {}
    void read_data();
    void display_data();
};

void Student::read_data()
{
    Academic::read_data();
    cout << "Enter Year: ";
    cin >> year;
}

void Student::display_data()
{
    Academic::display_data();
    cout << "Year: " << year << endl;
}

class Clerk : public Professional
{
    char workLoad[DEFAULT_STRING_SIZE];

public:
    Clerk() : workLoad("\n") {}
    Clerk(const char *given_name, unsigned int given_age, char given_gender, const double given_salary, const char *given_work) : Professional(given_name, given_age, given_gender, given_salary)
    {
        strcpy(workLoad, given_work);
    }
    void read_data();
    void display_data();
};

void Clerk::read_data()
{
    Professional::read_data();
    cout << "Enter Work-Load: ";
    cin >> workLoad;
}

void Clerk::display_data()
{
    Professional::display_data();
    cout << "Work-Load: " << workLoad << endl;
}

int main()
{
    Clerk c("Abhiroop", 18, 'M', 2000, "Files");
    c.display_data();
}
