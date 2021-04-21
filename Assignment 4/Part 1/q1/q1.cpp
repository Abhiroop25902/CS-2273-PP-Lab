#include <iostream>
using namespace std;
#include <string.h>

const int DEFAULT_STRING_SIZE = 10;

class Vehicle
{
    float price;
    char *manufacturer;

public:
    Vehicle() : price(0), manufacturer(NULL) {}
    Vehicle(const float p, const char *man);
    Vehicle(const Vehicle &obj);
    Vehicle &operator=(const Vehicle &rhs);
    void read_data();
    void display_data();
    ~Vehicle();
};

Vehicle::Vehicle(const float p, const char *man) : price(p)
{
    manufacturer = new char[strlen(man) + 1]; //+1 for \n
    strcpy(manufacturer, man);
}

Vehicle::Vehicle(const Vehicle &obj) : price(obj.price)
{
    manufacturer = new char[strlen(obj.manufacturer) + 1]; //+1 for \n
    strcpy(manufacturer, obj.manufacturer);
}

Vehicle &Vehicle::operator=(const Vehicle &rhs)
{
    if (this == &rhs)
        return *this;

    delete[] manufacturer;

    price = rhs.price;

    manufacturer = new char[strlen(rhs.manufacturer) + 1]; //+1 for \n
    strcpy(manufacturer, rhs.manufacturer);

    return *this;
}

void Vehicle::read_data()
{
    if (manufacturer != NULL)
        delete[] manufacturer;

    manufacturer = new char[DEFAULT_STRING_SIZE + 1]; //+1 for \n

    cout << "Enter Price of Vehicle: ";
    cin >> price;

    cout << "Enter Manufacturer of Vehicle: ";
    cin >> manufacturer;
}

void Vehicle::display_data()
{
    cout << "Price of Vehicle: " << price << endl;

    if (manufacturer != NULL)
        cout << "Manufacturer of Vehicle: " << manufacturer << endl;
    else
        cout << "Manufacturer of Vehicle: NULL" << endl;

    cout << endl;
}

Vehicle::~Vehicle()
{
    if (manufacturer != NULL)
        delete[] manufacturer;
}

int main()
{
    // Vehicle v1;
    // v1.read_data();
    // v1.display_data();

    // Vehicle v2(20000, "Nissan");
    // v2.display_data();

    // Vehicle v3 = v1; //copy constructor
    // v3.display_data();

    // Vehicle v4;
    // v4 = v2; //assignment operator
    // v4.display_data();

    return 0;
}