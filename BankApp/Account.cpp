#include<iostream>
#include "Account.h"
using namespace std ;
Account::Account() {
    balance = 0;
    numDeposits = 0;
    numWithdrawls = 0;
    annualInterestRate = 12; // 12% annual interest 
    monthlyServiceCharges = 1; // 1$ monthly maintainance 
}

Account::~Account() {
}

Account::Account(double bal,
        float interestRate) {
    balance = bal;
    numDeposits = 0;
    numWithdrawls = 0;
    annualInterestRate = interestRate;
    monthlyServiceCharges = 1; // 1$ per month
}

void Account::setMonthlyServiceCharges(float monthlyServiceCharges) {
    this->monthlyServiceCharges = monthlyServiceCharges;
}

float Account::getMonthlyServiceCharges() const {
    return monthlyServiceCharges;
}

void Account::setAnnualInterestRate(float annualInterestRate) {
    this->annualInterestRate = annualInterestRate;
}

float Account::getAnnualInterestRate() const {
    return annualInterestRate;
}

void Account::setNumWithdrawls(int numWithdrawls) {
    this->numWithdrawls = numWithdrawls;
}

int Account::getNumWithdrawls() const {
    return numWithdrawls;
}

void Account::setNumDeposits(int numDeposits) {
    this->numDeposits = numDeposits;
}

int Account::getNumDeposits() const {
    return numDeposits;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposite(double amount) {
    balance = balance + amount;
    numDeposits = numDeposits + 1;
}

void Account::withdraw(double amount) {
    balance = balance - amount;
    numWithdrawls = numWithdrawls + 1;
}

void Account::calcInt() {
    float MonthlyInterestRate = annualInterestRate / 12;
    float MonthlyInterest = balance * MonthlyInterestRate;

    balance = balance + MonthlyInterest;
}

void Account::monthlyProc() {
    balance = balance - monthlyServiceCharges;

    calcInt();

    numDeposits = 0;
    numWithdrawls = 0;
    monthlyServiceCharges = 0; // 1$
}

void Account::printAccount()
{
   cout<<"Balance :" <<getBalance()<<endl;
   cout<<"Number Of Deposites :" <<getNumDeposits()<<endl;
   cout<<"Number Of Withdrawals :" <<getNumWithdrawls()<<endl;
   cout<<"Annual Interest Rate :" <<getAnnualInterestRate()<<endl;
   cout<<"Monthly Service Charges :" <<getMonthlyServiceCharges()<<endl;
}


