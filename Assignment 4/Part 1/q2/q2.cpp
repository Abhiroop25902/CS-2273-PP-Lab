#include <iostream>
using namespace std;

#include "person.h"

int main()
{
    Person p1;
    p1.read_data();
    p1.display_data();

    Person *p2 = new Person("Sanjana", 20, 'F');
    p2->display_data();

    Person p3 = p1;
    p3.display_data();

    Person p4;
    p4 = *p2;
    delete[] p2;
    p4.display_data();
}