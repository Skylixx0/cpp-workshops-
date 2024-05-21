// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03.18.2024

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca{
    double Account::balance() const{
        return m_balance;
    };

    Account::Account(double amount){
        if(!amount || amount < 0) m_balance = 0.0;
        else m_balance = amount;
    };

    bool Account::credit(double amount){
        if(amount && amount > 0) {
            m_balance += amount;
            return true;
        }
        return false;
    };
    
    bool Account::debit(double amount){
        if(amount && amount > 0){
            m_balance -= amount;
            return true;
        }
        return false;
    };
}