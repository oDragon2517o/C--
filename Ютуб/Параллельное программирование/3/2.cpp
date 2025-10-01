#include <iostream>
#include <thread>

using namespace std;

// передача параметра по значению
void ByVal(string str)
{
    cout << "ByVal: " << str << endl;
}
// передача параметра по ссылке
void ByRef(const string &str)
{
    cout << "ByRef: &str" << &str << ": " << str << endl;
}

int main()
{
    // передача параметра по значению
    string param = "Hello";
    thread t{ByVal, param};

    // передача параметра по ссылке.
    cout << "&param: " << &param << endl;
    thread t{ByRef, cref(param)};
}
