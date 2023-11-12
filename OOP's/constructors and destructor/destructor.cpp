#include <iostream>
using namespace std;
/*
    Destructor ;
        - A destructor in C++ is a special member function of a class that is
          called when an object of the class goes out of scope or is explicitly
          deleted. The destructor is responsible for releasing resources or
          performing cleanup tasks associated with the object before it is
          destroyed.
*/
class student
{
    int rollno;
    string name;

public:
    student(string name_a, int rollno_a)
    {
        rollno = rollno_a;
        name = name_a;
        cout << "Default constructor called" << name << endl;
    }
    ~student()
    {
        cout << "Destructor called" << endl;
    }
    void disp()
    {
        cout << "Name: " << name << endl;
        cout << "Rollno: " << rollno << endl;
    }
};
int main()
{
    student s1("Sakthi", 119);
    s1.disp();
    return 0; // Destructor is called when the object goes out of scope
}