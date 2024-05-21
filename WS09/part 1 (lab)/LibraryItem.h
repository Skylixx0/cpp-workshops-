#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H
#include <iostream>

namespace seneca{
    class LibraryItem{
        char* m_title;
        int m_year;
        public:
        LibraryItem();
        LibraryItem(const LibraryItem& obj);
        LibraryItem(const char* title, int year);
        LibraryItem& operator=(const LibraryItem& obj);
        virtual ~LibraryItem();
        virtual std::ostream& display(std::ostream& ostr = std::cout) const;
    };
}
#endif