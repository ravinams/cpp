#include<string>

#include "Customer.h"

#ifndef BANK_H
#define BANK_H
using namespace std;

class Bank {
public:
    Bank();   
    virtual ~Bank();
    static int numberOfCustomers;
    void addCustomer(string firstName, string lastName);  
    static int getNumOfCustomers();
    Customer* getCustomer(size_t index);
    Customer* getCustomer(string firstName, string lastName);
    void printReport();

private:

    Customer** customers;

};

#endif /* BANK_H */

