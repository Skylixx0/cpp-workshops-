#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LibraryItem.h"

using namespace std;
namespace seneca{
    LibraryItem::LibraryItem(){
        this->m_title = nullptr;
        this->m_year = 0;
    };

    LibraryItem::LibraryItem(const char* title, int year){
        this->m_title = new char[strlen(title) + 1];
        strcpy(this->m_title, title);
        this->m_year = year;
    };

    LibraryItem::LibraryItem(const LibraryItem& obj){
        m_title = nullptr;
        *this = obj;
    };

    LibraryItem& LibraryItem::operator=(const LibraryItem& obj){
        if(this != &obj){
            delete[] this->m_title;
            m_year = obj.m_year;
            if(obj.m_title != nullptr){
                m_title = new char[strlen(obj.m_title) + 1];
                strcpy(this->m_title, obj.m_title);
            }
            else{
                this->m_title = nullptr;
            }
        }
        return *this;
    };

    LibraryItem::~LibraryItem(){
        delete[] this->m_title;
    };

    std::ostream& LibraryItem::display(std::ostream& ostr) const{
        ostr << "Title: " << this->m_title << " (" << this->m_year << ')';
        return ostr;
    };
}