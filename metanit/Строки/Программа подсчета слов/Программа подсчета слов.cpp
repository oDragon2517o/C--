#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string text; // Исходный текст
    std::cout << "Enter some text: ";
    std::getline(std::cin, text);
    const std::string separators{" ,;:.\"!?'*\n"};    // разделители слов
    std::vector<std::string> words;                   // вектор для хранения слов
    size_t start{text.find_first_not_of(separators)}; // начальный индекс первого слова
    while (start != std::string::npos)                // проходим, пока в строке не окажется других символов, кроме separators
    {
        size_t end = text.find_first_of(separators, start + 1); // находим, где кончается слово
        if (end == std::string::npos)                           // если НЕ найден ни один из символов-разделителей
            end = text.length();                                // устанавливаем переменную end на конец текста
        words.push_back(text.substr(start, end - start));       // добавляем в вектор слово
        start = text.find_first_not_of(separators, end + 1);    // находим начальный индекс следующего слова и переустанавливаем start
    }
    // выводим количество слов
    std::cout << "\nText contains " << words.size() << " words:" << std::endl;
    // выводим все слова на консоль
    for (const auto &word : words)
    {
        std::cout << word << std::endl;
    }
}