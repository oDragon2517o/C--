#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    string str1 = "qwerty";
    string str2;
    str2 = str1.substr(2, 4);
    cout << str2 << "\n";
}