// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03/04/2024

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_EMAIL_H
#define SENECA_EMAIL_H

namespace seneca{
    class Email{
        char m_fromName[100];
        char m_fromAddress[100];
        char m_dateReceived[20];
        char* m_subject;
        public:
        Email();
        Email(const Email&); // 
        ~Email();
        Email& operator=(const Email&); // 
        bool load(std::istream& in);
        friend std::ostream& operator<<(std::ostream& out, const Email& email);
        operator bool() const;
    };
}
#endif