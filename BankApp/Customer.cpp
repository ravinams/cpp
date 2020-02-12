
#include<iostream>
#include "Customer.h"
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
using namespace std;

Customer::Customer() {
    numberOfAccounts = 0;
    accounts = new Account*[5];
}

Customer::~Customer() {
    for (int i = 0; i != 5; ++i) {
        delete accounts[i];
    }

    delete[] accounts;
}

void Customer::SetPhone(std::string phone) {
    this -> phone = phone;
}

std::string Customer::GetPhone() const {
    return phone;
}

void Customer::SetZip(std::string zip) {
    this -> zip = zip;
}

std::string Customer::GetZip() const {
    return zip;
}

void Customer::SetState(std::string state) {
    this -> state = state;
}

std::string Customer::GetState() const {
    return state;
}

void Customer::SetCity(std::string city) {
    this -> city = city;
}

std::string Customer::GetCity() const {
    return city;
}

void Customer::SetAddress(std::string address) {
    this -> address = address;
}

std::string Customer::GetAddress() const {
    return address;
}

void Customer::SetFirstName(std::string firstName) {
    this -> firstName = firstName;
}

std::string Customer::GetFirstName() const {
    return firstName;
}

void Customer::SetLastName(std::string lastName) {
    this -> lastName = lastName;
}

std::string Customer::GetLastName() const {
    return lastName;
}

void Customer::SetAccount(Account* account) {
    accounts[numberOfAccounts++] = account;
}

Account* Customer::GetAccount(int accNum) const {
    return accounts[accNum];
}

int Customer::GetNumberOfAccounts() const {
    return numberOfAccounts;
}

void Customer::printCustomer() {

    cout << "************ CUSTOMER INFO *****************" << endl;
    cout << "Customer First Name  : " << GetFirstName() << "  |  Customer Last Name : " << GetLastName()<<"  | number of accounts = "<<GetNumberOfAccounts() << endl;
    cout << "*****************************" << endl;

    for (int i = 0; i < GetNumberOfAccounts(); i++) {
        cout << "Account# :" << i + 1 << endl;
        accounts[i]->printAccount();
        cout << "*****************************" << endl;
    }

}

void Customer::openAccount() {
    char accountType;
    Account *account;

    do {

        cout << "Enter a account type ('S'for savings and 'C' for Checking) : ";
        cin>>accountType;

        if (accountType == 'S' || accountType == 's')
            account = new SavingAccount();
        else if (accountType == 'C' || accountType == 'c')
            account = new CheckingAccount();

    }    while (!(accountType == 'S' || accountType == 's' || accountType == 'C' || accountType == 'c'));
    accounts[numberOfAccounts++] = account;
    cout << "Account#" << numberOfAccounts << " created successfully." << endl;
}