#include <iostream>

template <typename T>
class Person
{
public:
    Person(T id, std::string name) : id{id}, name{name}
    {
    }
    void print() const
    {
        std::cout << "Id: " << id << "\tName: " << name << std::endl;
    }

private:
    T id;
    std::string name;
};
int main()
{
    Person tom{123456, "Tom"};       // T - число
    tom.print();                     // Id: 123456      Name: Tom
    Person bob{"tvi4xhcfhr", "Bob"}; // T - строка
    bob.print();                     // Id: tvi4xhcfhr  Name: Bob
}