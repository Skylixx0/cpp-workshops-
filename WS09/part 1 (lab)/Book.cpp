#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;
namespace seneca{
    Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year){
            this->m_author = new char[strlen(author) + 1];
            strcpy(m_author, author);
    };

    Book& Book::operator=(const Book& obj){
        (LibraryItem&)*this = (const LibraryItem&)obj;
        if(this != &obj){
            delete[] this->m_author;
            if(obj.m_author != nullptr){
                m_author = new char[strlen(obj.m_author) + 1];
                strcpy(m_author, obj.m_author);
            }
        }
        else{
            m_author = nullptr;
        }
        return *this;
    };

    Book::Book(const Book& obj) : LibraryItem(obj){
        m_author = nullptr;
        *this = obj;
    };

    Book::~Book(){
        delete[] m_author;
    };

    std::ostream& Book::display(std::ostream& ostr) const{
        LibraryItem::display(ostr);
        cout << '\n' << "Author: " << m_author;
        return ostr;
    };
    
    bool Book::operator>(const Book& other)const{
        if(strcmp(m_author, other.m_author) > 0){
              return true;
        }
        return false;
    }
}