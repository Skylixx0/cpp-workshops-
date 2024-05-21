// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03/04/2024

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_INBOX_H
#define SENECA_INBOX_H
#include "email.h"
namespace seneca{
    class Inbox{
        Email* m_emails;
        int m_cntEmails;
        public:
        Inbox();
        Inbox(const Inbox&);
        ~Inbox();
        Inbox& operator=(const Inbox&);
        Inbox& operator+=(const Email& email);
        Inbox operator+(const Email& email) const;
        void load(const char* filename);
        friend std::ostream& operator<<(std::ostream& out, const Inbox& inbox);
        void save(const char* filename) const;
    };
}
#endif