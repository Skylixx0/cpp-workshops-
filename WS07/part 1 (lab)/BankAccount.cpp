// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03.13.2024

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.    

#include <iostream>
#include <cstring>
#include "BankAccount.h"

using namespace std;
namespace seneca{
double BankAccount::getBalance() const{
    return this->m_balance;
};

void BankAccount::setBalance(double newBalance){
    this->m_balance = newBalance;
};

ostream& BankAccount::writeCurrency(ostream& out, double amount) const{
    out.precision(2);
    out.setf(ios::fixed);
    out << '$' << amount;
    out.unsetf(ios::fixed);
    out.precision(6);
    return out;
};

BankAccount::BankAccount(const char* name, const Date& openDate, const DepositInfo& depInfo, double balance){
    strcpy(this->m_name, name);
    m_openDate = openDate;
    m_depInfo = depInfo;
    m_balance = balance;
};

std::ostream& BankAccount::write(std::ostream& out) const{
    out << ">> " << m_name << " | ";
    writeCurrency(out, this->m_balance);
    out << " | " << m_openDate << " | " << m_depInfo;
    return out;
};

std::istream& BankAccount::read(std::istream& in){
    cout << "Name: ";
    in.getline(m_name, 100, '\n');
    cout << "Opening Balance: ";
    in >> m_balance;
    cout << "Date Opened ";
    in >> m_openDate;
    in >> m_depInfo;
    return in;
}; 

std::istream& operator>>(std::istream& in, BankAccount& account){
    account.read(in);
    return in;
};

std::ostream& operator<<(std::ostream& out, const BankAccount& account){
    account.write(out);
    return out;
};


}