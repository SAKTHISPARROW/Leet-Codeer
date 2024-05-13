#include <iostream>
#include <string>

// Abstract class Shape
class Shape
{
public:
    virtual void draw() = 0; // Pure virtual function
};

// Class Circle inheriting from Shape
class Circle : public Shape
{
public:
    void draw() override
    {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Class Person
class Person
{
private:
    std::string name;

public:
    void setName(std::string name)
    {
        this->name = name;
    }

    std::string getName()
    {
        return this->name;
    }
};

// Class Vehicle
class Vehicle
{
public:
    virtual void drive() = 0; // Pure virtual function
};

// Class Car inheriting from Vehicle
class Car : public Vehicle
{
public:
    void drive() override
    {
        std::cout << "Driving a car" << std::endl;
    }
};

// Class SportsCar inheriting from Car
class SportsCar : public Car
{
public:
    void drive() override
    {
        std::cout << "Driving a sports car" << std::endl;
    }
};

// Abstract class Animal
class Animal
{
public:
    virtual void makeSound() = 0; // Pure virtual function
};

// Class Dog inheriting from Animal
class Dog : public Animal
{
public:
    void makeSound() override
    {
        std::cout << "Woof!" << std::endl;
    }
};

// Class Department
class Department
{
};

// Class Employee
class Employee
{
private:
    Department *department;

public:
    void setDepartment(Department *department)
    {
        this->department = department;
    }

    Department *getDepartment()
    {
        return this->department;
    }
};

// Class Roof
class Roof
{
};

// Class House
class House
{
private:
    Roof *roof;

public:
    void setRoof(Roof *roof)
    {
        this->roof = roof;
    }

    Roof *getRoof()
    {
        return this->roof;
    }
};

// Class Engine
class Engine
{
};

// Class Car2
class Car2
{
private:
    Engine *engine;

public:
    void setEngine(Engine *engine)
    {
        this->engine = engine;
    }

    Engine *getEngine()
    {
        return this->engine;
    }
};

int main()
{
    // Abstraction
    Shape *shape = new Circle();
    shape->draw();

    // Encapsulation
    Person person;
    person.setName("John Doe");
    std::cout << person.getName() << std::endl;

    // Inheritance
    Car *car = new SportsCar();
    car->drive();

    // Polymorphism
    Animal *animal = new Dog();
    animal->makeSound();

    // Association
    Employee employee;
    employee.setDepartment(new Department());

    // Aggregation
    House house;
    house.setRoof(new Roof());

    // Composition
    Car2 car2;
    car2.setEngine(new Engine());

    // Memory cleanup
    delete shape;
    delete car;
    delete animal;
    delete employee.getDepartment();
    delete house.getRoof();
    delete car2.getEngine();

    return 0;
}
