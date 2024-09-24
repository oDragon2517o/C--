#include <iostream>

class Person
{
private:
    std::string name;

    class Account // вложенный класс
    {
    public:
        Account(const std::string &p_email, const std::string &p_password)
        {
            email = p_email;
            password = p_password;
        }
        std::string email;
        std::string password;
    };
    Account account{"", ""}; // переменная вложенного класса Account
public:
    Person(const std::string &p_name, const std::string &p_email, const std::string &p_password)
    {
        name = p_name;
        account = Account(p_email, p_password);
    }
    void print()
    {
        std::cout << "Name: " << name << "\n"
                  << "Email: " << account.email << "\n"
                  << "Password: " << account.password << std::endl;
    }
};

int main()
{
    Person tom{"Tom", "tom@localhost.com", "qwerty"};
    tom.print();
}