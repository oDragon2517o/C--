#include <iostream>

class Person
{
public:
    std::string name;
    unsigned age;
    void print()
    {
        std::cout << "Name: " << name << "\tAge: " << age << std::endl;
    }
};
int main()
{
    Person person;
    Person *ptr = &person;
    // обращаемся к полям и функции объекта через указатель
    ptr->name = "Tom";
    ptr->age = 22;
    ptr->print();
    // переобледелим переменные
    ptr->name = "Tom2";
    ptr->age = 40;
    // обращаемся к полям объекта
    std::cout << "Name: " << person.name << "\tAge: " << person.age << std::endl;
}
