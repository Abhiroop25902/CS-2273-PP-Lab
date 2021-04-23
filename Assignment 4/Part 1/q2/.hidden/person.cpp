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
    Person(const char *, unsigned int, char);
    Person(const Person &);
    Person &operator=(const Person &);
    void read_data();
    void display_data();
    //using default destructor
};

Person::Person(const char *given_name, unsigned int given_age, char given_gender) : age(given_age), gender(given_gender)
{
    strcpy(name, given_name);
}

Person::Person(const Person &obj) : age(obj.age), gender(obj.gender)
{
    strcpy(name, obj.name);
}

Person &Person::operator=(const Person &rhs)
{
    strcpy(name, rhs.name);
    age = rhs.age;
    gender = rhs.gender;

    return *this;
}

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
