#include <iostream>
using namespace std;

const int DEFAULT_SIZE = 10;
const int INCREMENT_SIZE = 10;
const int MAX_SIZE = 20;
const int MAX_RSA = 5;

class rsa
{
    int loc;
    unsigned int arr_size; //never gonna be -ve
    unsigned int max_size; //never gonna be -ve
    int *arr;

public:
    rsa(int arr_s = DEFAULT_SIZE, int max_s = MAX_SIZE);
    rsa(const rsa &rhs);
    rsa &operator=(const rsa &rhs);
    const rsa operator+(const rsa &) const;
    bool addElement(int data);
    bool inflate(int extra_space);
    bool resetElements(int given_index, int n);
    bool printAll() const;
    ~rsa();

    int fetchElement(int loc) const
    {
        return arr[loc];
    }

    int getMaxSize() const
    {
        return max_size;
    }

    int getCount() const
    {
        return loc;
    }

    static unsigned int no_of_rsa;

    static unsigned int return_no_of_rsa()
    {
        return no_of_rsa;
    }
};

unsigned int rsa::no_of_rsa = 0;

const rsa rsa::operator+(const rsa &r) const
{
    rsa c(*this);
    c.no_of_rsa--;//c is temporary so one decrement
    c.no_of_rsa--; // this is to nullify the assignment increment

    for (int i = 0; i <= r.arr_size; i++)
        c.addElement(r.arr[i]);

    return c;
}

rsa::rsa(int arr_s, int max_s)
{

    if(no_of_rsa > MAX_RSA)
    {
        cout<<"Error: Max RSA Limit Reached"<<endl;
        exit(0);
    }
    no_of_rsa++;

    loc = -1;
    arr_size = arr_s - 1; //cause 0 indexed array
    arr = new int[arr_s];
    max_size = max_s - 1;

    if (arr == NULL)
    {
        cout << "Error: Memory Allotment Error, Exiting" << endl;
        exit(11);
    }
}

rsa::rsa(const rsa &rhs)
{

    if(no_of_rsa > MAX_RSA)
    {
        cout<<"Error: Max RSA Limit Reached"<<endl;
        exit(0);
    }

    no_of_rsa++;

    loc = rhs.loc;
    arr_size = rhs.arr_size;
    max_size = rhs.max_size;
    arr = new int[arr_size];

    for (int i = 0; i <= arr_size; i++)
        arr[i] = rhs.arr[i];
}

rsa &rsa::operator=(const rsa &rhs)
{
    no_of_rsa++;

    if (this == &rhs)
        return *this;

    delete arr;

    loc = rhs.loc;
    arr_size = rhs.arr_size;
    max_size = rhs.max_size;
    arr = new int[arr_size];

    for (int i = 0; i <= arr_size; i++)
        arr[i] = rhs.arr[i];

    return *this;
}

rsa::~rsa()
{
    no_of_rsa--;

    cout << "Deleting following RSA..." << endl;
    printAll();
    cout << endl;

    delete arr;
}

bool rsa::inflate(int extra_space)
{
    int *temp = new int[arr_size + extra_space];
    arr_size += extra_space;
    if (temp == nullptr)
        return false;

    for (int i = 0; i <= arr_size; i++)
    {
        temp[i] = arr[i];
    }

    delete arr;
    arr = temp;
    return true;
}

bool rsa::addElement(int data)
{
    if (loc == arr_size)
    {
        if (arr_size == max_size)
        {
            return false;
        }
        else if (arr_size + INCREMENT_SIZE <= max_size)
            if (!inflate(INCREMENT_SIZE))
            {
                cout << "Error: Fail to inflate, exiting";
                exit(-1);
            }
            else if (!inflate(max_size - arr_size))
            {
                cout << "Error: Fail to inflate, exiting";
                exit(-1);
            }
    }

    loc++;
    arr[loc] = data;

    return true;
}

//location should be based on a zero indexed array
bool rsa::resetElements(int given_index, int n)
{
    if (arr_size < given_index + n)
        return false;

    int initial = given_index - 1;
    int final = given_index + n - 1;

    while (final <= arr_size)
    {
        arr[initial] = arr[final];
        initial++;
        final++;
    }

    loc = initial - 1;

    while (initial <= arr_size)
    {
        arr[initial] = 0;
        initial++;
    }

    return true;
}

bool rsa::printAll() const
{
    for (int i = 0; i < arr_size + 1; i++)
        cout << fetchElement(i) << " ";
    cout << endl;

    return true;
}

int main()
{
    rsa a;

    cout << "Initializing RSA with initial size " << DEFAULT_SIZE << " and  max size " << MAX_SIZE << endl;
    cout << endl;

    cout << "Adding 10 elements (no inflating takes place)" << endl;
    for (int i = 0; i < 10; i++)
        if (!a.addElement(i))
        {
            cout << "Error: Overflowing Max Size" << endl;
            exit(1);
        }
    a.printAll();
    cout << endl;

    cout << "Adding 10 more elements (inflation will take place)" << endl;
    for (int i = 0; i < 10; i++)
        if (!a.addElement(i + 10))
        {
            cout << "Error: Overflowing Max Size" << endl;
            exit(1);
        }
    a.printAll();
    cout << endl;

    cout << "No. Of RSA = " << rsa::return_no_of_rsa() << endl;

    cout << "Max Size: " << a.getMaxSize() + 1 << endl;
    cout << "No. of elements: " << a.getCount() + 1 << endl;
    cout << endl;

    {
        cout << "Making another RSA(b) having value 20-39:" << endl;
        rsa b;
        for (int i = 0; i < 20; i++)
            if (!b.addElement(i + 20))
            {
                cout << "Error: Overflowing Max Size" << endl;
                exit(1);
            }
        b.printAll();
        cout << endl;
    }

    cout << "Making another RSA(c) using copy constructor of a..." << endl;

    rsa c(a);
    c.printAll();
    cout << endl;

    cout << "Resetting Elements(c)(make their value 0) with given pos 1, and n as 15" << endl;
    if (!c.resetElements(1, 15))
    {
        cout << "Error: provided out of bound parameters" << endl;
    }
    c.printAll();
    cout << endl;

    cout << "No. Of RSA = " << rsa::return_no_of_rsa() << endl;

    cout << "Making another RSA(d) using \'=\' operator of a..." << endl;

    rsa d;
    d = a;
    d.printAll();
    cout << endl;

    cout << "Resetting Elements(d)(make their value 0) with given pos 1, and n as 10" << endl;
    if (!d.resetElements(1, 10))
    {
        cout << "Error: provided out of bound parameters" << endl;
    }
    d.printAll();
    cout << endl;

    cout << "No. Of RSA = " << rsa::return_no_of_rsa() << endl;

    cout << "Making rsa e \'=\' c \'+\' d operator..." << endl;
    rsa e;
    e = c + d;
    cout << "e..." << endl;
    e.printAll();
    cout << endl;

    cout << endl
         << endl
         << endl;

    cout << "a..." << endl;
    a.printAll();
    cout << endl;

    cout << "c..." << endl;
    c.printAll();
    cout << endl;

    cout << "d..." << endl;
    d.printAll();
    cout << endl;

    cout << "e..." << endl;
    e.printAll();
    cout << endl;

    cout << "No. Of RSA = " << rsa::return_no_of_rsa() << endl;

    return 0;
}