#include <iostream>

class Auto; // объявление класса Auto, чтобы Person видел этот класс

class Person
{
public:
    Person(std::string p_name)
    {
        name = p_name;
    }
    void drive(const Auto &);
    void setPrice(Auto &, unsigned);

private:
    std::string name;
};

class Auto
{
    // объявление дружественных функций
    friend void Person::drive(const Auto &);
    friend void Person::setPrice(Auto &, unsigned);

public:
    Auto(std::string a_name, unsigned a_price)
    {
        name = a_name;
        price = a_price;
    }
    void print()
    {
        std::cout << name << " : " << price << std::endl;
    }

private:
    std::string name; // название автомобиля
    unsigned price;   // цена автомобиля
};

void Person::drive(const Auto &car)
{
    std::cout << name << " drives " << car.name << std::endl;
}
void Person::setPrice(Auto &car, unsigned price)
{
    car.price = price;
}

int main()
{
    Auto tesla{"Tesla", 5000};
    Person tom{"Tom"};
    tom.drive(tesla);
    tom.setPrice(tesla, 8000);
    tesla.print();
}