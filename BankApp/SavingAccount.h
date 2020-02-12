#include "Account.h"


#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

class SavingAccount : public Account {
public:
    SavingAccount();
    SavingAccount(double bal, float interestRate);
    
    virtual ~SavingAccount();
    void deposite(double amount);
    void withdraw(double amount);
    void monthlyProc();
    void setStatus(char status);
    char getStatus() const;
    void printAccount();
private:
    char status; // 'A' = ACTIVE , 'I' = INACTIVE 

};

#endif /* SAVINGACCOUNT_H */

