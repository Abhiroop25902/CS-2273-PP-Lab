#include <iostream>
using namespace std;

#include <ctime>
#include <cstdlib>

class Shape
{
public:
    virtual void read() = 0;
    virtual void calc_area() = 0;
};

class Triangle : public Shape
{
    double base;
    double height;

public:
    Triangle() : base(0), height(0) {}
    Triangle(const double given_base, const double given_height) : base(given_base), height(given_height) {}
    void calc_area()
    {
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << 0.5 * base * height << endl;
    }
    void read();
};

void Triangle::read()
{
    cout << "Enter Base: ";
    cin >> base;
    cout << "Enter Height: ";
    cin >> height;
}

class Rectangle : public Shape
{
    double length;
    double breadth;

public:
    Rectangle() : length(0), breadth(0) {}
    Rectangle(const double given_length, const double given_breadth) : length(given_length), breadth(given_breadth) {}
    void calc_area()
    {
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << length * breadth << endl;
    }

    void read();
};
void Rectangle::read()
{
    cout << "Enter Length: ";
    cin >> length;
    cout << "Enter Breadth: ";
    cin >> breadth;
}

const double pi = 3.14159;

class Circle : public Shape
{
    double radius;

public:
    Circle() : radius(0) {}
    Circle(const double given_radius) : radius(given_radius) {}
    void calc_area()
    {
        cout << "Radius: " << radius << endl;
        cout << "Area:" << pi * radius * radius << endl;
    }
    void read();
};

void Circle::read()
{
    cout << "Enter Radius: ";
    cin >> radius;
}

int main()
{
    srand(time(0));

    int counter = 0;
    int num_rand;

    Shape *shape_ptr[10];

    num_rand = rand() % 2 + 1;

    cout << "Triangles: " << endl;
    for (int i = counter; i < counter + num_rand; i++)
    {
        shape_ptr[i] = new Triangle(rand() % 10 + 1, rand() % 10 + 1);
        shape_ptr[i]->calc_area();
        cout << endl;
    }
    cout << endl
         << "Rectangles: " << endl;

    counter += num_rand;

    num_rand = rand() % 2 + 1;

    for (int i = counter; i < counter + num_rand; i++)
    {
        shape_ptr[i] = new Rectangle(rand() % 10 + 1, rand() % 10 + 1);
        shape_ptr[i]->calc_area();
        cout << endl;
    }

    cout << endl
         << "Circles: " << endl;

    counter += num_rand;

    for (int i = counter; i < 10; i++)
    {
        shape_ptr[i] = new Circle(rand() % 10 + 1);
        shape_ptr[i]->calc_area();
        cout << endl;
    }
    return 0;
}
