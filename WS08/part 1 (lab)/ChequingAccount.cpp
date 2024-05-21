// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03.18.2024

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include "ChequingAccount.h"
using namespace std;

namespace seneca{
    ChequingAccount::ChequingAccount(double balance, double transFee, double monthEndFee) : Account(balance){
        if(!transFee || transFee < 0) transactionFee = 0.0;
        else transactionFee = transFee;

        if(!monthEndFee || monthEndFee < 0) monthlyFee = 0.0;
        else monthlyFee = monthEndFee;
    };
    
    bool ChequingAccount::credit(double amount){
        if(Account::debit(transactionFee)){
            Account::credit(amount);
            return true;
        }
        return false;
    };

    bool ChequingAccount::debit(double amount){
        if(Account::debit(transactionFee)){
            Account::debit(amount);
            return true;
        }
        return false;
    };
    
    void ChequingAccount::monthEnd(){
        if(monthlyFee) Account::debit(monthlyFee);
    };

    void ChequingAccount::display(std::ostream& out) const{
        out << "Account type: Chequing\n";
        out.setf(ios::fixed);
        out.precision(2);
        out << "Balance: $" << balance() << '\n';
        out << "Per Transaction Fee: " << transactionFee << '\n';
        out << "Monthly Fee: " << monthlyFee << '\n';
        out.unsetf(ios::fixed);
        out.precision(6);
    };
}