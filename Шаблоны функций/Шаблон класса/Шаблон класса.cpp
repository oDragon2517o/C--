#include <iostream>

// класс Person, где id - целое число
class UintPerson
{
public:
    UintPerson(unsigned id, std::string name) : id{id}, name{name}
    {
    }
    void print() const
    {
        std::cout << "Id: " << id << "\tName: " << name << std::endl;
    }

private:
    unsigned id;
    std::string name;
};

// класс Person, где id - строка
class StringPerson
{
public:
    StringPerson(std::string id, std::string name) : id{id}, name{name}
    {
    }
    void print() const
    {
        std::cout << "Id: " << id << "\tName: " << name << std::endl;
    }

private:
    std::string id;
    std::string name;
};

int main()
{
    UintPerson tom{123456, "Tom"};
    tom.print(); // Id: 123456      Name: Tom
    StringPerson bob{"tvi4xhcfhr", "Bob"};
    bob.print(); // Id: tvi4xhcfhr  Name: Bob
}