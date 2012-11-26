#include "account.h"

Account::Account(const string& name, unsigned int balance, double interest_rate)
{
	name_=name;
	balance_=balance;
	interest_rate_=interest_rate;
}
Account::~Account()
{}
void Account::Deposit(unsigned int amount)
{
}
unsigned int Account::ComputeExpectedBalance(unsigned int n_years_later) const
{
	int balanceMoney = balance_;
	double balanceMoney2 = static_cast<double>(balance_);
	for(int i=0;i<n_years_later;i++)
	{
		balanceMoney2+=static_cast<double>(balance_)*interest_rate_;
	}
	balanceMoney = static_cast<int>(balanceMoney2);
	return balanceMoney;
}
unsigned int SavingAccount::ComputeExpectedBalance(unsigned int n_years_later) const
{
	int balanceMoney = balance_;
	double balanceMoney2 = static_cast<double>(balance_);
	for(int i=0;i<n_years_later;i++)
	{
		balanceMoney2=balanceMoney2*(1.0 + interest_rate_);
	}
	balanceMoney = static_cast<int>(balanceMoney2);
	return balanceMoney;
}
Account* CreateAccount(const string& type, const string& name, unsigned int balance, double interest_rate)
{
	Account* Q;
	if(type=="saving")
	{
		Q = new SavingAccount(name,balance,interest_rate);


	}
	else if(type=="normal")
	{
		//P = new Account(name,balance,interest_rate);

		Q=new Account(name,balance,interest_rate);
		//cout<<"HI"<<endl;
		//cout<<P.name()<<' '<<P.balance()<<' '<<P.interest_rate()<<endl;
		//cout<<Q->name()<<' '<<Q->balance()<<' '<<Q->interest_rate()<<endl;
	}
	else
	{
		Q = NULL;
	}
	return  Q;
}
SavingAccount::~SavingAccount()
{}