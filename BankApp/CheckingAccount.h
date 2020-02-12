#include "Account.h"

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

class CheckingAccount : public Account {
public:
    CheckingAccount();
    CheckingAccount(double bal, float interestRate);
    virtual ~CheckingAccount();
    void withdraw(double amount);
    void monthlyProc();

private:

};

#endif /* CHECKINGACCOUNT_H */

