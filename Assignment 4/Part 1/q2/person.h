#ifndef PERSON
#define PERSON

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
#endif