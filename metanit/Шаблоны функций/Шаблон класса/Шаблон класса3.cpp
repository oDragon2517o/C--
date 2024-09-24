#include <iostream>

template <typename T, typename V>
class Transaction
{
public:
    Transaction(T fromAcc, T toAcc, V code, unsigned sum) : fromAccount{fromAcc}, toAccount{toAcc}, code{code}, sum{sum}
    {
    }
    void print() const
    {
        std::cout << "From: " << fromAccount << "\tTo: " << toAccount
                  << "\tSum: " << sum << "\tCode: " << code << std::endl;
    }

private:
    T fromAccount; // с какого счета
    T toAccount;   // на какой счет
    V code;        // код операции
    unsigned sum;  // сумма перевода
};

int main()
{
    // явная типизация
    Transaction<std::string, int> transaction1{"id1234", "id5678", 2804, 5000};
    transaction1.print(); // From: id1234    To: id5678      Sum: 5000       Code: 2804
    // неявная типизация
    Transaction transaction2{"id6789", "id9018", 3000, 6000};
    transaction2.print(); // From: id6789    To: id9018      Sum: 6000       Code: 3000
}