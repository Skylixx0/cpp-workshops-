#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
namespace seneca{
    class BankAccount{
        char m_userName[100 + 1];
        double m_balance;
        bool m_checking;
        int m_transactions;

        public:
        BankAccount(const char* name = nullptr, bool checking = false);
        void display() const;
        operator bool() const;
        operator double() const;
        operator const char*() const;
        operator int() const;
        BankAccount& operator+=(double amount);
        BankAccount& operator-=(double amount);
        BankAccount operator+(double amount) const;
        BankAccount& operator++();
        BankAccount operator++(int);
        bool operator>(double amount) const;
        
    };
        bool operator>(double amount, const BankAccount& account);
}
#endif

