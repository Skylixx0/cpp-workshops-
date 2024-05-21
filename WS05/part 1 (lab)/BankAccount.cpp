// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 02.13.2024

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cmath>
#include "BankAccount.h"

using namespace std;
namespace seneca{
    BankAccount::BankAccount(const char* name, bool checking){
        m_balance = 0.0;
        m_transactions = 0;
        m_checking = checking;
        if(name != nullptr && name[0] != '\0'){
            strcpy(m_userName, name);
        }
        else{
            m_userName[0] = '\0';
        }
    };
    
    BankAccount::operator bool() const{
        return m_userName && m_userName[0] != '\0'; // bool returnValue
    };

    void BankAccount::display() const{
        bool returnValue = operator bool();
        if(returnValue == true){
            if(m_checking == true){
                cout << m_userName << " -> " << "$" << m_balance << " in " << "checking" << " account." << endl;
            }
            if(m_checking == false){
                cout << m_userName << " -> " << "$" << m_balance << " in " << "savings" << " account." << endl;
            }
        }
        // use ternary operator later
    };

    BankAccount::operator double() const{
        bool returnValue = operator bool();

        if(returnValue == true){
            return m_balance;
        }
        return nan("");
    };

    BankAccount::operator const char*() const{
        bool returnValue = operator bool();

        if(returnValue == true){
            return m_userName;
        }
        else{
            return "Not Open";
        }
    };

    BankAccount::operator int() const{
        bool returnValue = operator bool();

        if(returnValue == true){
            return m_transactions;
        }
        return -1;
    };

    BankAccount& BankAccount::operator+=(double amount){
        bool returnValue = operator bool();
        if(returnValue == true) {        
            m_balance += amount;
            m_transactions++;
        }
        return *this;
    };

    BankAccount& BankAccount::operator-=(double amount){
        operator+=(-1 * amount);
        return *this;
    };

    BankAccount BankAccount::operator+(double amount) const{
        BankAccount result;
        result = *this; 
        result = result.operator+=(amount); // might be a problem
        return result;
    }

    BankAccount& BankAccount::operator++(){
        bool returnValue = operator bool();
        if(returnValue && m_balance > 0.0){
            char account[] = "checnking";
            if (m_checking != true) { 
                strcpy(account, "saving");
            };

            if(m_checking == false) m_balance *= 1.025;
            else{
                m_balance *= 1.005;
            }
        }
        return *this;
    };
    
    BankAccount BankAccount::operator++(int){
        BankAccount result;
        result = *this;
        // result = result.operator++();
        //this->operator++();
        //(*this).operator++();
        ++(*this);
        return result;
    };

    bool BankAccount::operator>(double amount) const{
        bool returnValue = operator bool();
        if(returnValue){
            if(m_balance > amount) return returnValue;
            else{
                return false;
            }
        }
        return returnValue;
    }
    
    bool operator>(double amount, const BankAccount& account){
        if(amount > account.operator double()){
            return true;
        }
        return false;
    };



}