#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account 
{
public:
	Account(){}
	Account(const string& name, unsigned int balance, double interest_rate);
	virtual ~Account();
	void Deposit(unsigned int amount);
	bool Withdraw(unsigned int amount);
	virtual unsigned int ComputeExpectedBalance(unsigned int n_years_later) const;
	virtual const char* type() const { return "normal"; }
	const unsigned int& balance() const { return balance_; }
	const string& name() const { return name_; }
	const double& interest_rate() const { return interest_rate_; }
protected:
	string name_;
	unsigned int balance_;
	double interest_rate_; // �⺻ ���´� �ܸ��� ���.
};
class SavingAccount : public Account 
{
public:
	virtual ~SavingAccount();
	SavingAccount(const string& name, int balance, double interest_rate) : Account(name, balance, interest_rate){}
	virtual const char* type() const { return "saving"; }
	// �� Ÿ���� ���´� ������ ���.
	virtual unsigned int ComputeExpectedBalance(unsigned int n_years_later) const;
};
Account* CreateAccount(const string& type,const string& name, unsigned int balance, double interest_rate);