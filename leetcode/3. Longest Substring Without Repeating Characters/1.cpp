#include <iostream>
using namespace std;

#include <unordered_map>
#include <string>
using namespace std;
// Given a string s, find the length of the longest substring without repeating characters.
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 1; j < i; j++)
            {
                // cout << s[i - j] << "\n";
                if (s[i] == s[i - j])
                {
                    if (maxLength < j)
                    {
                        maxLength = j;
                    }
                    break;
                }
            }
            // cout << maxLength << "\n";
        }

        return (maxLength);
    }
};
// s = "abcabcbb"

int main()
{
    string s = "abcabcbb";

    Solution Cat;
    Cat.lengthOfLongestSubstring(s);
}