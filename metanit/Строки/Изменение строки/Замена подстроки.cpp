#include <iostream>
#include <string>

int main()
{
    std::string text{"Hello, Tom!"};
    const std::string separators{" ,;:.\"!\n"};            // разделители слова
    size_t start{text.find("Tom")};                        // находим позицию подстроки
    size_t end{text.find_first_of(separators, start + 1)}; // Находим конец подстроки
    if (end == std::string::npos)                          // если разделители слова не найдены
    {
        end = text.length();
    }
    text.replace(start, end - start, "Alice"); // заменяем подстроку

    std::cout << text << std::endl; // Hello, Alice!
}