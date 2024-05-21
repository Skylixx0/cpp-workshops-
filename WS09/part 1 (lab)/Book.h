#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include "LibraryItem.h"

namespace seneca{
    class Book : public LibraryItem{    
        char* m_author;
        public:
        Book(const char* title, int year, const char* author);
        Book& operator=(const Book& obj);
        Book(const Book& obj);
        ~Book();
        std::ostream& display(std::ostream& ostr = std::cout) const override;
        bool operator>(const Book& other)const;
    };
}
#endif