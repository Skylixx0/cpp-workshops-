#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H
#include <iostream>
#include "guitarString.h"

namespace seneca {
    class Guitar {
        char m_model[65] = {'\0'}; 
        GuitarString* m_strings = nullptr;
        int m_cntStrings = 0;

    public:
        Guitar(const char* model = "Stratocaster");
        Guitar(const GuitarString* strings, int cntStrings, const char* model);
        ~Guitar();

        Guitar& reString(const GuitarString* strings, int cntStrings);  
        Guitar& reString(const GuitarString& aString, int idx);   
        Guitar& deString();
        bool isStrung() const;
        std::ostream& display(std::ostream& out = std::cout) const;
    };
};
#endif