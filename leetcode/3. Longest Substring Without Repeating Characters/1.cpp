#include <iostream>
using namespace std;

// Given a string s, find the length of the longest substring without repeating characters.
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        for (int i = 1; s[i] == '\0'; i++)
        {
            cout << i << "\n";
            cout << s[i] << "\n";
        }
        cout << s[4];
        return {};
    }
};
// s = "abcabcbb"

int main()
{
    string s = "abcabcbb";

    Solution Cat;
    Cat.lengthOfLongestSubstring(s);
}