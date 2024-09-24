#include <iostream>
#include <string>

int main()
{
    std::string text{"Hello world!"};
    std::string word{"world"};
    for (unsigned i{}; i < text.length() - word.length() + 1; i++)
    {
        if (text.compare(i, word.length(), word) == 0)
        {
            std::cout << "text contains " << word << " at index " << i << std::endl;
        }
    }
}