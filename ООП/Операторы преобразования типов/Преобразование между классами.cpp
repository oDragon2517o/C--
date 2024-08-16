#include <iostream>
class PrintBook;

// электронная книга
class Ebook
{
public:
    Ebook(std::string book_title)
    {
        title = book_title;
    }
    operator PrintBook() const;
    std::string getTitle() { return title; }

private:
    std::string title;
};
// печатная книга
class PrintBook
{
public:
    PrintBook(std::string book_title)
    {
        title = book_title;
    }
    operator Ebook() const;
    std::string getTitle() { return title; }

private:
    std::string title;
};

Ebook::operator PrintBook() const
{
    return PrintBook{title};
}
PrintBook::operator Ebook() const
{
    return Ebook{title};
}

int main()
{
    PrintBook book{"C++"};
    Ebook ebook{book};                               // оцифровываем книгу - из PrintBook в Ebook
    std::cout << ebook.getTitle() << std::endl;      // C++
    PrintBook print_book{ebook};                     // распечатываем книгу из Ebook в PrintBook
    std::cout << print_book.getTitle() << std::endl; // C++
}