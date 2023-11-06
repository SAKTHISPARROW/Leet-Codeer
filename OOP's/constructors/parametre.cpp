#include <iostream>
using namespace std;
class person
{
private:
    string name;
    int age;

public:
    person(string s, int n)
    {
        name = s;
        age = n;
    }
    void intro()
    {
        cout << "My name is " << name << " and I am " << age << " years old." << endl;
    }
};
int main()
{
    person john("John", 25); // object of derived class
    john.intro();
    person alex("Alex", 30); // object of derived class
    alex.intro();
}