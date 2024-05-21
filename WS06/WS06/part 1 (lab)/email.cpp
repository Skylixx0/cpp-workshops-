// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03/04/2024

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "email.h"
using namespace std;
namespace seneca{
    Email::Email(){
        m_fromName[0] = '\0';
        m_fromAddress[0] = '\0';
        m_dateReceived[0] = '\0';
        m_subject = nullptr;
    };

    Email& Email::operator=(const Email& email){
        if(this != &email){ // and if email is not null
            // strcpy(m_fromName, email.m_fromName);
            // strcpy(m_fromAddress, email.m_fromAddress);
            // strcpy(m_dateReceived, email.m_dateReceived);
            delete[] m_subject;
            strcpy(m_fromName, email.m_fromName);
            strcpy(m_fromAddress, email.m_fromAddress);
            strcpy(m_dateReceived, email.m_dateReceived);

            if (email.m_subject != nullptr) {
                m_subject = new char[strlen(email.m_subject) + 1];
                strcpy(m_subject, email.m_subject);
            }
            else{
                m_subject = nullptr;
            }

            //char* newArrSubj = new char[strlen(email.m_subject) + 1];
            //strncpy(newArrSubj, email.m_subject, strlen(email.m_subject) + 1); // 
            // strcpy(newArrSubj, email.m_subject);
            //delete[] m_subject;
            //m_subject = newArrSubj;
            //newArrSubj = nullptr; // might be wrong
        }
        // else if((email.operator bool()) == false){
        //     m_fromName[0] = '\0';
        //     m_fromAddress[0] = '\0';
        //     m_dateReceived[0] = '\0';
        //     m_subject = nullptr;
        // }
        return *this;
    };

    Email::Email(const Email& email) : Email(){ // Email()
        if(this != &email){ //&email != nullptr
            *this = email;
        }
    };

    Email::~Email(){
        delete[] m_subject;
        m_fromName[0] = '\0';
        m_fromAddress[0] = '\0';
        m_dateReceived[0] = '\0';
    };

    bool Email::load(std::istream& in){
        char buffer[1000];
        in.getline(m_fromAddress, 100, ',');
        in.getline(m_fromName, 100, ',');
        in.getline(buffer, 1000, ',');
        in.getline(m_dateReceived, 20);

        // cout << m_fromAddress << endl;
        if(in.good()){
            delete[] m_subject;
            m_subject = new char[strlen(buffer) + 1];
            strcpy(m_subject, buffer);
            return true;
        }
            *this = Email();
        
        return false;
    };

    std::ostream& operator<<(ostream& out, const Email& email){
        if(email.operator bool()){
            out.width(20);
            out << email.m_fromName << "  ";
            out.setf(ios::left);
            out.width(40);
            out << email.m_fromAddress << "  ";
            out.width(15);
            out << email.m_dateReceived + 11  << "  ";
            out.unsetf(ios::left);
            out << email.m_subject << endl;
        };
        return out;
    };

    Email::operator bool() const{
        return m_dateReceived != '\0' && m_fromAddress != '\0' && m_fromName != '\0' && m_subject != nullptr; // 1 if every data member is not in empty state, 0 otherwise / in everything except m_subject was '\0' (null terminator)
    };

}