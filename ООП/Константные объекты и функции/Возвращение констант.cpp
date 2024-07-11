#include <iostream>

class Person
{
private:
    std::string name;
    unsigned age;

public:
    Person(std::string p_name, unsigned p_age)
    {
        name = p_name;
        age = p_age;
    }
    // возвращаем константную ссылку
    const std::string &getName() const
    {
        return name;
    }
    // возвращаем указатель на константу
    const unsigned *getAge() const
    {
        return &age;
    }
    void print() const
    {
        std::cout << "Name: " << name << "\tAge: " << age << std::endl;
    }
};
int main()
{
    const Person tom{"Tom", 38};

    std::string tom_name = tom.getName();
    const unsigned *tom_age = tom.getAge();

    std::cout << "Name: " << tom_name << "\tAge: " << *tom_age << std::endl;
}