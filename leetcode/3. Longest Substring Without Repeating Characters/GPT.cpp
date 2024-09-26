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
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (charIndex.find(s[i]) != charIndex.end() && charIndex[s[i]] >= start)
            {
                start = charIndex[s[i]] + 1;
            }
            charIndex[s[i]] = i;
            maxLength = max(maxLength, i - start + 1);
        }
        cout << maxLength << "\n";
        return maxLength;
    }
};
// s = "abcabcbb"

int main()
{
    string s = "pwwkew";

    Solution Cat;
    Cat.lengthOfLongestSubstring(s);
}