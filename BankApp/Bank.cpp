#include <iostream>
#include <exception>
#include <stdexcept>

#include "Bank.h"

using namespace std ;

Bank::Bank()
{
    customers = new Customer *[10];
}

Bank::~Bank()
{
    for (int i = 0; i != 10; ++i)
    {
        delete customers[i];
    }

    delete[] customers;
}

int Bank::getNumOfCustomers()
{
    return numberOfCustomers;
}

void Bank::addCustomer(string firstName,
                       string lastName)
{
    Customer * c = new Customer();

    c -> SetFirstName(firstName);
    c -> SetLastName(lastName);

    customers[numberOfCustomers++] = c;
    cout<<"Customer successfully created."<<endl;
    cout<<"Each customer must have at least one account, please provide account information."<<endl;
    c->openAccount() ;
        
}

Customer * Bank::getCustomer(size_t index)
{
    if (index < getNumOfCustomers())
    {
        return customers[index];
    }
}

Customer * Bank::getCustomer(string firstName,
                             string lastName)
{
     for (int i = 0 ; i < getNumOfCustomers() ; i++)
    {
        Customer *c = customers[i] ;
        if (c->GetFirstName() == firstName && c->GetLastName() == lastName)
            return c ;        
    }
     throw std::invalid_argument("Customer does exists with given first name and last name \n");
}

void Bank::printReport()
{
    int custCnt = getNumOfCustomers() ;
    int accountCnt =0 ;
      double endBalance = 0;
      float serviceCharges = 0 ;
    int numDeposites = 0;
    int numWithdrawals = 0;
    cout<<"************ BANK *****************"<<endl;
    cout<<"Number Of Customers : "<<custCnt<<endl; ;
    cout<<"*****************************"<<endl;
    for (int i = 0 ; i < custCnt ; i++)
    {
        Customer *c = customers[i] ; 
        accountCnt = accountCnt + c->GetNumberOfAccounts() ;
        for (int i = 0 ; i < c->GetNumberOfAccounts() ; i++)
        {
            numDeposites = numDeposites + c->GetAccount(i+1)->getNumDeposits();
            numWithdrawals = numWithdrawals + c->GetAccount(i+1)->getNumWithdrawls();
            endBalance = endBalance + c->GetAccount(i+1)->getBalance() ;
            serviceCharges = serviceCharges +  c->GetAccount(i+1)->getMonthlyServiceCharges() ;
        }
       
    }
    
    cout<<"Number Of Accounts : "<<accountCnt<<endl; 
    cout<<"*****************************"<<endl;
    cout<<"Number Of Deposits : "<<numDeposites<<endl; 
    cout<<"*****************************"<<endl;
    cout<<"Number Of Withdrawals : "<<numWithdrawals<<endl; 
    cout<<"*****************************"<<endl;
    cout<<"Service Charges : "<<serviceCharges<<endl; 
    cout<<"*****************************"<<endl;
    cout<<"Total Balance : "<<endBalance<<endl; 
    cout<<"*****************************"<<endl;

}


