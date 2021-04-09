#include <iostream>
using namespace std;

#include <fstream>
#include <cstring>

const int NAME_SIZE = 20;
const int DEPT_NAME_SIZE = 5;

const int DYNAMIC_STUDENT_HEAP_SIZE = 5;

class student
{
    char *name;
    int age;
    char *department;
    int year_grad;

public:
    student();
    ~student();
    void readStudentData(ifstream &fin);
    void readStudentData();
    void printStudentData() const;
    void *operator new(size_t size);
    // void operator delete(void *p);

    static student *data;
    static bool data_occupied[DYNAMIC_STUDENT_HEAP_SIZE];
};

student *student::data = (student *)malloc(sizeof(student) * DYNAMIC_STUDENT_HEAP_SIZE);

bool student::data_occupied[DYNAMIC_STUDENT_HEAP_SIZE] = {false};

student::~student()
{
    free(name);
    free(department);
}

student::student() : age(-1), year_grad(-1)
{
    name = (char *)malloc(NAME_SIZE);
    department = (char *)malloc(DEPT_NAME_SIZE);
}

void *student::operator new(size_t size)
{
    void *s;
    for (int i = 0; i < DYNAMIC_STUDENT_HEAP_SIZE; i++)
    {
        if (data_occupied[i] == false)
        {
            data_occupied[i] = true;
            s = (void *)&data[i];
        }
    }
    return s;
}

// void student::operator delete(void *p)
// {
//     free(((student *)p));
// }

void student::readStudentData(ifstream &fin)
{
    fin.getline(name, NAME_SIZE);
    fin >> age >> department >> year_grad;
    fin.ignore(); //ignore newline
}

void student::readStudentData()
{
    cout << "Enter Student's Name: ";
    cin.getline(name, NAME_SIZE);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Department (Abbv.): ";
    cin >> department;
    cout << "Enter Year of Graduation: ";
    cin >> year_grad;
    cin.ignore(); //ignore newline
}

void student::printStudentData() const
{
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Department: " << department << endl;
    cout << "Year of Graduation: " << year_grad << endl;
}

int main()
{
    // cout << "Enter Number of Record to be added: ";
    // int n;
    // cin >> n;
    // cin.ignore(); //ignore newline
    // cout << endl;

    // student s[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Enter Detail of Student " << i + 1 << ":" << endl;
    //     s[i].readStudentData();
    //     cout << endl;
    // }

    // cout << "Output: " << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Data of Student " << i + 1 << ":" << endl;
    //     s[i].printStudentData();
    //     cout << endl;
    // }

    // char filename[] = "./data.txt";

    // ifstream fin;
    // fin.open(filename, ios::in);

    // cout << "Input through " << filename << endl;
    // student a[2];
    // int i = 0;

    // while (!fin.eof())
    // {
    //     a[i].readStudentData(fin);
    //     i++;
    // }

    // cout << "Data of Student"
    //      << ":" << endl;

    // for (int i = 0; i < 2; i++)
    // {
    //     a[i].printStudentData();
    // }

    // cout << endl;

    // fin.close();

    cout << endl
         << "Doing Pointers..." << endl;

    student *dynamic = new student;
    dynamic->readStudentData();
    dynamic->printStudentData();

    delete dynamic;

    return 0;
}