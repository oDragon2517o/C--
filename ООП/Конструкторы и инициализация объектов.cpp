#include <iostream>

class Person
{
    std::string name{};
    unsigned age{};

public:
    void print()
    {
        std::cout << "Name: " << name << "\tAge: " << age << std::endl;
    }
    Person(std::string p_name, unsigned p_age)
    {
        name = p_name;
        age = p_age;
        std::cout << "First constructor" << std::endl;
    }
    Person(std::string p_name) : Person(p_name, 18) // вызов первого конструктора
    {
        std::cout << "Second constructor" << std::endl;
    }
    Person() : Person(std::string("Undefined")) // вызов второго конструктора
    {
        std::cout << "Third constructor" << std::endl;
    }
};
int main()
{
    Person sam; // вызываем конструктор Person()
    sam.print();
}