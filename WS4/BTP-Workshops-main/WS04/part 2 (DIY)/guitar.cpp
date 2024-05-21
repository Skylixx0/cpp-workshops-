#include <iostream>
#include <cstring>
#include "guitar.h"

using namespace std;
namespace seneca{
    Guitar::Guitar(const char* model){
        if(model && model[0] != '\0'){
            strcpy(m_model, model);
        }
    }
    Guitar::Guitar(const GuitarString* strings, int cntStrings, const char* model){
        *this = Guitar(model);
        reString(strings, cntStrings);
    };
    Guitar::~Guitar(){
        delete[] m_strings;
        m_strings = nullptr;
    };
    Guitar& Guitar::reString(const GuitarString* strings, int cntStrings){
        delete[] m_strings;
        
        GuitarString* newStrings = new GuitarString[cntStrings];
        for(int i = 0; i < cntStrings; i++){
            newStrings[i] = strings[i];
        }
        m_cntStrings = cntStrings;

        m_strings = newStrings;
        newStrings = nullptr;

        return *this;
    };     
    Guitar& Guitar::reString(const GuitarString& aString, int idx){
        m_strings[idx] = aString;
        return *this;
    };   
    Guitar& Guitar::deString(){
        delete[] m_strings;
        m_strings = nullptr;
        m_cntStrings = 0;
        return *this;
    };
    bool Guitar::isStrung() const{
        if(m_cntStrings > 0){
            return true;
        }
            return false;
    };
    std::ostream& Guitar::display(std::ostream& out) const{
        if(!m_model || m_model[0] == '\0'){
            out << "Empty guitar object!\n";
            return out;
        }
        else {
            out << "Guitar Model: " << m_model << endl;
        }

        if(m_strings == nullptr || m_cntStrings <= 0){
            out << "Guitar cannot be used yet because it has no strings.\n";
        }
        else{
            out << "Strings:" << endl;
            for(int i = 0; i < m_cntStrings; i++){
                out << " #" << i + 1 << ". " << m_strings[i].getMaterial() << ' ' << '(' << m_strings[i].getGauge() << "mm" << ')' << endl; 
            }
        }
       
        return out;
    };


}