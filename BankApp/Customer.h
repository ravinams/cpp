#include<string>
#include "Account.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H

using namespace std  ;

class Customer {
public:
    Customer();
    Customer(const Customer& orig);
    virtual ~Customer();
    void SetPhone(std::string phone);
    std::string GetPhone() const;
    void SetZip(std::string zip);
    std::string GetZip() const;
    void SetState(std::string state);
    std::string GetState() const;
    void SetCity(std::string city);
    std::string GetCity() const;
    void SetAddress(std::string address);
    std::string GetAddress() const;
    void SetFirstName(std::string firstName);
    std::string GetFirstName() const;
    void SetLastName(std::string lastName);
    std::string GetLastName() const;
    void SetAccount(Account* account)  ;
    Account* GetAccount(int accNum) const;
    int GetNumberOfAccounts() const;
    void openAccount();
    void printCustomer();
    
    
private:
    std::string lastName;
    std::string firstName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone;
    int numberOfAccounts ;
    Account **accounts ;

};

#endif /* CUSTOMER_H */

