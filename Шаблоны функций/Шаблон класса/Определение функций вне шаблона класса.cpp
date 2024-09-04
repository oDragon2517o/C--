#include <iostream>

template <typename T>
class Person
{
public:
    Person(T, std::string);            // обычный конструктор
    Person(const Person &);            // конструктор копирования
    ~Person();                         // деструктор
    Person &operator=(const Person &); // оператор присваивания
    void print() const;                // функция класса

private:
    T id;
    std::string name;
};
// определение конструктора вне шаблона класса
template <typename T>
Person<T>::Person(T id, std::string name) : id{id}, name{name} {}
// определение конструктора копирования вне шаблона класса
template <typename T>
Person<T>::Person(const Person &person) : id{person.id}, name{person.name} {}

// определение деструктора копирования вне шаблона класса
template <typename T>
Person<T>::~Person() { std::cout << "Person deleted" << std::endl; }

// определение оператора присвоения вне шаблона класса
template <typename T>
Person<T> &Person<T>::operator=(const Person &person)
{
    if (&person != this)
    {
        name = person.name;
        id = person.id;
    }
    return *this;
}

// определение функции вне шаблона класса
template <typename T>
void Person<T>::print() const
{
    std::cout << "Id: " << id << "\tName: " << name << std::endl;
}

int main()
{
    Person tom{123456, "Tom"};
    tom.print();

    Person tomas{tom}; // конструктор копирования
    tomas.print();

    Person tommy = tom; // оператор присваивания
    tommy.print();
}