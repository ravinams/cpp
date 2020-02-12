#include <iostream>
#include <exception>
#include <stdexcept>
#include "Bank.h"
#include "Account.h"

using namespace std;

int Bank::numberOfCustomers = 0;

void searchCustomer(Bank& bank);

void searchAccount(Bank& bank);

void addCustomer(Bank& bank);

void openAccount(Bank& bank);

void depositAmount(Bank& bank);

void withdrawAmount(Bank& bank);

int main(int argc,
        char ** argv) {
    Bank b;
    int choice;
    
    do {
        cout << "**************************" << endl;
        cout << "1). Search for customer." << endl;
        cout << "2). Search for Account." << endl;
        cout << "3). Add customer." << endl;
        cout << "4). Open account." << endl;
        cout << "5). Deposit into account." << endl;
        cout << "6). Withdraw from account." << endl;
        cout << "7). Print Bank details." << endl;
        cout << "8). Exit." << endl;
        cout << "Please choose operation(1..8) :";
        cin >> choice;

        switch (choice) {
            case 1:
                searchCustomer(b);

                break;

            case 2:
                searchAccount(b);

                break;
            case 3:
                addCustomer(b);

                break;

            case 4:
                openAccount(b);

                break;

            case 5:
                depositAmount(b);

                break;

            case 6:
                withdrawAmount(b);

                break;

            case 7:
                b.printReport();

                break;

            case 8:
                cout << "Exiting the bank" << endl;

                break;

            default:
                cout << "Invalid choice , please reenter choice " << endl;
        }
    } while (choice != 8);

    return 0;
}

void searchCustomer(Bank& bank) {
    string firstName, lastName;
    cout << "Enter customer first name:" << endl;
    cin>>firstName;
    cout << "Enter customer last name:" << endl;
    cin>>lastName;
    try {
        Customer *c = bank.getCustomer(firstName, lastName);
        if (c != nullptr) {
            c->printCustomer();
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what();
    }
}

void addCustomer(Bank& bank) {
    string firstName, lastName;
    cout << "Enter customer first name:" << endl;
    cin>>firstName;
    cout << "Enter customer last name:" << endl;
    cin>>lastName;
    bank.addCustomer(firstName, lastName);

}

void openAccount(Bank& bank) {
    string firstName, lastName;
    cout << "Enter customer first name:" << endl;
    cin>>firstName;
    cout << "Enter customer last name:" << endl;
    cin>>lastName;
    try {
        Customer *c = bank.getCustomer(firstName, lastName);
        if (c != nullptr) {
            c->openAccount();
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what();
    }
}

void depositAmount(Bank& bank) {
    string firstName, lastName;
    cout << "Enter customer first name:" << endl;
    cin>>firstName;
    cout << "Enter customer last name:" << endl;
    cin>>lastName;
    try {
        Customer *c = bank.getCustomer(firstName, lastName);
        if (c != nullptr) {
            c->printCustomer();
            cout << "Please choose enter account#(starts with 1) to deposit :";
            int accNo;
            cin>>accNo;
            if (accNo < 1 || accNo > c->GetNumberOfAccounts())
                cout << "Invalid account number" << endl;
            else {
                Account *acc = c->GetAccount(accNo - 1);
                cout << "Enter the amount to be deposited:";
                double deposit;
                cin>>deposit;
                acc->deposite(deposit);
                cout << "Successfully deposited" << endl;

            }
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what();
    }
}

void withdrawAmount(Bank& bank) {
    string firstName, lastName;
    cout << "Enter customer first name:" << endl;
    cin>>firstName;
    cout << "Enter customer last name:" << endl;
    cin>>lastName;
    try {
        Customer *c = bank.getCustomer(firstName, lastName);
        if (c != nullptr) {
            c->printCustomer();
            cout << "Please choose enter account#(starts with 1) to deposit :";
            int accNo;
            cin>>accNo;
            if (accNo < 1 || accNo > c->GetNumberOfAccounts())
                cout << "Invalid account number" << endl;
            else {
                Account *acc = c->GetAccount(accNo - 1);
                cout << "Enter the amount to be withdrawn:";
                double amount;
                cin>>amount;
                acc->withdraw(amount);               
            }
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what();
    }
}

void searchAccount(Bank& bank)
{
      string firstName, lastName;
    cout << "Enter customer first name:" << endl;
    cin>>firstName;
    cout << "Enter customer last name:" << endl;
    cin>>lastName;
    try {
        Customer *c = bank.getCustomer(firstName, lastName);
        if (c != nullptr) {
            c->printCustomer();
            cout << "Please choose enter account#(starts with 1) :";
            int accNo;
            cin>>accNo;
            if (accNo < 1 || accNo > c->GetNumberOfAccounts())
                cout << "Invalid account number" << endl;
            else {
               c->GetAccount(accNo-1)->printAccount() ;
            }
        }
    } catch (const std::invalid_argument& e) {
        std::cout << e.what();
    }
    
}