
#include "CheckingAccount.h"
#include "Account.h"

CheckingAccount::CheckingAccount()
{
}

CheckingAccount::CheckingAccount(double bal, float interestRate):Account(bal,interestRate)
{
}
CheckingAccount::~CheckingAccount()
{
}

void CheckingAccount::withdraw(double amount)
{
    double bal = getBalance();

    if ((bal - amount) < 0)
    {
        setBalance(bal - 15);
    }
    else
    {
        Account::withdraw(amount);
    }
}

void CheckingAccount::monthlyProc()
{
    float msCharges = getMonthlyServiceCharges();

    msCharges = msCharges + 5 + getNumWithdrawls() * 0.10;

    setMonthlyServiceCharges(msCharges);
    Account::monthlyProc();
}



