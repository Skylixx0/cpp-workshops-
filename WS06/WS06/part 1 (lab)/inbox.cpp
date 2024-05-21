// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03/04/2024

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include "inbox.h"
#include "email.h"
using namespace std;
namespace seneca{
    Inbox::Inbox(){
        m_emails = nullptr;
        m_cntEmails = 0;
    };

    Inbox& Inbox::operator=(const Inbox& inbox){
        if(this != &inbox){
            delete[] this->m_emails;
            this->m_cntEmails = inbox.m_cntEmails;

            // this->m_emails = new Email[m_cntEmails];
            Email* newArrEmails = new Email[m_cntEmails];
            for (int i = 0; i < m_cntEmails; i++)
            {
                newArrEmails[i] = inbox.m_emails[i];
                // this->m_emails[i] = inbox.m_emails[i];
            }
            this->m_emails = newArrEmails;
            newArrEmails = nullptr;
        }
        return *this;
    };

    Inbox::Inbox(const Inbox& inbox) : Inbox(){
        if(this != &inbox){
            *this = inbox;
        }
    };

    Inbox::~Inbox(){
        delete[] this->m_emails;
        this->m_cntEmails = 0;
    };

    Inbox& Inbox::operator+=(const Email& email){
        if(email){
            Email* newInbox = new Email[m_cntEmails + 1];
            for (int i = 0; i < m_cntEmails; i++)   
            {
                newInbox[i] = this->m_emails[i];            
            }
            newInbox[m_cntEmails] = email;
            delete[] this->m_emails;
            this->m_emails = newInbox;
            m_cntEmails++;
        }
        return *this;
    };

    Inbox Inbox::operator+(const Email& email) const{
        Inbox inboxcpy(*this); // (const Inbox& nbox)
        inboxcpy += email;
        return inboxcpy;
    };

    void Inbox::load(const char* filename){
        if(filename){
            ifstream file(filename);
            if(file.is_open()){
                while (file)
                    {
                    Email email;
                    if(email.load(file)){
                        *this += email; 
                    }
                    else{
                        break;
                    }
                }
            file.close();
            }

        }
    };

    void Inbox::save(const char* filename) const{
        if(filename){
            ofstream file(filename);
            if(file.is_open()){
                for (int i = 0; i < m_cntEmails; ++i)
                {
                    file << m_emails[i];
                }
                file.close();
            }
        }
    }   

    ostream& operator<<(ostream& out, const Inbox& inbox){
        if(inbox.m_emails != nullptr){
            for(int i = 0; i < inbox.m_cntEmails; ++i){
                out << inbox.m_emails[i];   
            }
        };
        return out;
    };
}