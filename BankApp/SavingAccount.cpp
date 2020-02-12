
#include<iostream>
#include "SavingAccount.h"

SavingAccount::SavingAccount() {
    status = 'A';
}

SavingAccount::SavingAccount(double bal, float interestRate):Account(bal,interestRate) 
{
    status = 'A'; 
}

SavingAccount::~SavingAccount() {
}

void SavingAccount::deposite(double amount) {

    if (status == 'I' && getBalance() + amount > 25) {
        status = 'A';     
    }

  Account::deposite(amount);
}

void SavingAccount::withdraw(double amount) {
    if (status == 'A') {
        Account::withdraw(amount);
    }

}

void SavingAccount::monthlyProc() {
    int numWithdrawals = getNumWithdrawls() ;
    float msCharge = getMonthlyServiceCharges() ;
    if (numWithdrawals > 4 )
    {
        msCharge = msCharge + numWithdrawals * 1 ;
        setMonthlyServiceCharges(msCharge) ;
    }
    
    Account::monthlyProc() ;
    if (getBalance() < 25)
        setStatus('I') ;
         
}

void SavingAccount::setStatus(char status) {
    this->status = status;
}

char SavingAccount::getStatus() const {
    return status;
}

void SavingAccount::printAccount()
{
   Account::printAccount() ;
   std::cout<<"Status :"<<(status == 'A' ? "Active":"Inactive")<<std::endl;
}
