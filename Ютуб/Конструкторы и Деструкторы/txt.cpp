В C++ порядок вызова конструкторов и деструкторов строго определён и зависит от структуры программы, иерархии классов и области видимости объектов.Давайте разберём это шаг за шагом.

                                                                                                     Порядок вызова конструкторов Для одиночного объекта :

    Конструктор вызывается,
    когда объект создаётся(например, при объявлении переменной или динамическом выделении памяти с new).Если объект — экземпляр класса, сначала вызываются конструкторы всех его базовых классов(если есть наследование), а затем конструктор самого класса.При наследовании :

    Конструкторы базовых классов вызываются сверху вниз по иерархии(от самого верхнего базового класса к производному)
        .После этого вызываются конструкторы членов класса(в порядке их объявления в классе)
        .Наконец,
    выполняется тело конструктора самого класса.Пример :

    cpp

    Свернуть

    Перенос

    Копировать
#include <iostream>
    class Base
{
public:
    Base() { std::cout << "Base constructor\n"; }
};

class Derived : public Base
{
public:
    Derived() { std::cout << "Derived constructor\n"; }
};

int main()
{
    Derived d;
    return 0;
}
Вывод :

    text

        Свернуть

            Перенос

                Копировать
                    Base constructor
                        Derived constructor
                            Для членов класса :

    Конструкторы членов класса вызываются в порядке их объявления в
    классе(не в порядке инициализации в списке инициализации конструктора !)
        .Пример :

    cpp

    Свернуть

    Перенос

    Копировать
#include <iostream>
    class Member
{
public:
    Member() { std::cout << "Member constructor\n"; }
};

class MyClass
{
    Member m1;
    Member m2;

public:
    MyClass() { std::cout << "MyClass constructor\n"; }
};

int main()
{
    MyClass obj;
    return 0;
}
Вывод :

    text

        Свернуть

            Перенос

                Копировать
                    Member constructor     // для m1
                        Member constructor // для m2
                            MyClass constructor
                                Порядок вызова деструкторов
                                    Для одиночного объекта :

    Деструктор вызывается,
    когда объект выходит из области видимости(для автоматических объектов) или когда вызывается delete(для динамических объектов).При наследовании :

    Деструкторы вызываются в обратном порядке относительно конструкторов : сначала деструктор производного класса,
    затем деструкторы базовых классов(снизу вверх).Важно : если базовый класс имеет виртуальный деструктор,
    это гарантирует правильный вызов деструкторов при работе через указатель на базовый класс.Пример :

    cpp

    Свернуть

    Перенос

    Копировать
#include <iostream>
    class Base
{
public:
    ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base
{
public:
    ~Derived() { std::cout << "Derived destructor\n"; }
};

int main()
{
    Derived d;
    return 0;
}
Вывод :

    text

        Свернуть

            Перенос

                Копировать
                    Derived destructor
                        Base destructor
                            Для членов класса :

    Деструкторы членов вызываются в обратном порядке их объявления в классе.Пример :

    cpp

        Свернуть

            Перенос

                Копировать
#include <iostream>
    class Member
{
public:
    ~Member() { std::cout << "Member destructor\n"; }
};

class MyClass
{
    Member m1;
    Member m2;

public:
    ~MyClass() { std::cout << "MyClass destructor\n"; }
};

int main()
{
    MyClass obj;
    return 0;
}
Вывод :

    text

        Свернуть

            Перенос

                Копировать
                    MyClass destructor
                        Member destructor     // для m2
                            Member destructor // для m1
                                Ключевые правила
                                    Конструкторы : Базовые классы → Члены(в порядке объявления) → Тело конструктора класса.Деструкторы : Тело деструктора класса → Члены(в обратном порядке объявления) → Базовые классы(снизу вверх)
                                                                                                                                             .Виртуальный деструктор : Если класс участвует в полиморфизме,
    деструктор базового класса должен быть виртуальным, чтобы гарантировать вызов деструктора производного класса.Пример с наследованием и членами cpp

                                                        Свернуть

                                                        Перенос

                                                        Копировать
#include <iostream>
                                                        class Base
{
public:
    Base() { std::cout << "Base constructor\n"; }
    virtual ~Base() { std::cout << "Base destructor\n"; }
};

class Member
{
public:
    Member() { std::cout << "Member constructor\n"; }
    ~Member() { std::cout << "Member destructor\n"; }
};

class Derived : public Base
{
    Member m1;
    Member m2;

public:
    Derived() { std::cout << "Derived constructor\n"; }
    ~Derived() { std::cout << "Derived destructor\n"; }
};

int main()
{
    Derived d;
    return 0;
}
Вывод :

    text

        Свернуть

            Перенос

                Копировать
                    Base constructor
                        Member constructor     // m1
                            Member constructor // m2
                                Derived constructor
                                    Derived destructor
                                        Member destructor     // m2
                                            Member destructor // m1
                                                Base destructor
                                                    Если что -
    то осталось непонятным,
    уточните — разберём конкретный случай !
