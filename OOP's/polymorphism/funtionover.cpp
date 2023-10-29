#include <iostream>
using namespace std;
/*
    Polymorphism
        Polymorphism is a fundamental concept in C++ and object-oriented programming
        (OOP) that allows objects of different classes to be treated as objects of a
        common base class. It enables you to write more flexible and generic code by
        abstracting away the specific implementation details of classes. There are two
        main types of polymorphism in C++: compile-time (or static) polymorphism and
        runtime (or dynamic) polymorphism. Here's an explanation and example code for
        both types:

        (i) Compile-time (Static or Overloading or Early binding) Polymorphism:
            This type of polymorphism is resolved at compile time.
            It is achieved through function overloading and operator overloading.


            (a) Function Overloading:
                Function overloading allows you to define multiple functions with
                the same name but different parameter lists. The appropriate function
                to be called is determined by the number and types of arguments at
                compile time.

            (b) Operator Overloading:
                Operator overloading allows you to define the behavior of operators
                for user-defined types. It enables you to use operators like
                +, -, *, etc., with objects of custom classes.

        (ii) Runtime (Dynamic or Late binding or Overriding) Polymorphism:
            Runtime polymorphism is achieved through virtual functions and is
            resolved at runtime. It allows you to call the appropriate method of
            an object based on its actual type, even when accessed through a
            pointer or reference to a base class.

            (a) Runtime Polymorphism with Data Members

            (b) Virtual Function
*/
class arith
{
public:
    int add(int a, int b)
    {
        cout << "int=";
        return a + b;
    }
    double add(double a, double b)
    {
        cout << "double=";
        return a + b;
    }
    float add(float a, float b)
    {
        cout << "float=";
        return a + b;
    }
};
int main()
{
    arith a;
    cout << a.add(1, 2) << endl;
    cout << a.add(1.2, 2.3) << endl;
    cout << a.add(1.2f, 2.3f) << endl;
    return 0;
}