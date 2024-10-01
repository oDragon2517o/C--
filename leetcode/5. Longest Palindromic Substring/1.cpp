#include <iostream>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string palindrome;
        string halfPalindrome;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    halfPalindrome = memmove();
                }
            }
        }
        return {};
    }
    bool Palindrome(string Palindrome)
    {
        int len = Palindrome.length();
        for (int i = 0; i < len / 2; ++i)
        {
            if (Palindrome[i] != Palindrome[len - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string s = "babadttaweqda";

    Solution Cat;
    Cat.longestPalindrome(s);
}