#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    Account();
    Account(double bal, float interestRate); 
    virtual ~Account();


    void setMonthlyServiceCharges(float monthlyServiceCharges);
    float getMonthlyServiceCharges() const;
    void setAnnualInterestRate(float annualInterestRate);
    float getAnnualInterestRate() const;
    void setNumWithdrawls(int numWithdrawls);
    int getNumWithdrawls() const;
    void setNumDeposits(int numDeposits);
    int getNumDeposits() const;
    void setBalance(double balance);
    double getBalance() const;

    virtual void deposite(double amount);
    virtual void withdraw(double amount);
    virtual void calcInt();
    virtual void monthlyProc();
    virtual void printAccount();


private:
    double balance;
    int numDeposits;
    int numWithdrawls;
    float annualInterestRate;
    float monthlyServiceCharges;

};

#endif /* ACCOUNT_H */

