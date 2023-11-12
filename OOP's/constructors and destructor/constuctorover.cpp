#include <iostream>
using namespace std;
/*
        Constructor Overloading means when we have two or more constructors but change in number of parameters,
        or change in order of parameters, or change in data types of parameters are present

        Overloaded Costructor :
            1.constructor  overloading is when we overload default constructor and
            parameterized constructor like this

        Default :
            A(){
                name = "";
            }

        Parameterized:
            A(string name_a){
                name = name_a;
            }

        Overloaded:
            A(string name_a = ""){
                name = name_a;
            }
*/
class student
{
    int rollno;
    string name;
    int age;

public:
    student() // Constructor with no arguments (default constructor)
    {
        rollno = 0;
        name = "unknown";
        age = 0;
    }
    student(const string &name_a, int age_a, int rollno_a) // Constructor with name and roll number
    {
        rollno = rollno_a;
        name = name_a;
        age = age_a;
    }
    student(int rollno_a, const string &name_a) // Constructor can also be overloaded by changing order of parameters of constructor
    {
        rollno = rollno_a;
        name = name_a;
    }
    void disp()
    {
        cout << "Name: " << name << endl;
        cout << "Rollno: " << rollno << endl;
        cout << "Age: " << age << endl;
    }
};
int main()
{
    student s1;
    student s2("Sakthi", 22, 119);
    student s3(120, "Jessi");
    s1.disp();
    s2.disp();
    s3.disp();
}