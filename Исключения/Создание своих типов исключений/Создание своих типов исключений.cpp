#include <iostream>

class AgeException
{
public:
    AgeException(std::string message) : message{message} {}
    std::string getMessage() const { return message; }

private:
    std::string message;
};

class Person
{
public:
    Person(std::string name, unsigned age)
    {
        if (!age || age > 110) // если возраст равен 0 или больше 110
        {
            throw AgeException{"Invalid age"};
        }
        this->name = name;
        this->age = age;
    }
    void print() const
    {
        std::cout << "Name: " << name << "\tAge: " << age << std::endl;
    }

private:
    std::string name;
    unsigned age;
};

int main()
{
    try
    {
        Person tom{"Tom", 38}; // Корректные данные
        tom.print();

        Person bob{"Bob", 1500}; // Некорректные данные
        bob.print();
    }
    catch (const AgeException &ex)
    {
        std::cout << ex.getMessage() << std::endl;
    }
}