#include "account.h"

int main() 
{
	vector<Account*> accounts;
	string cmd;
	while (cmd != "quit") 
	{
		cin >> cmd;
		if (cmd == "add") 
		{
			string name, type;
			int amount;
			double interest_rate;
			cin >> name >> type >> amount >> interest_rate;
			Account* acc = CreateAccount(type, name, amount, interest_rate);
			if (acc == NULL) 
			{
				cout << "Error: " << type << ", " << name << endl;
			} 
			else 
			{
				//cout<<acc->name()<<' '<<endl;
				accounts.push_back(acc);
				//cout<<"HI"<<endl;
			//	string a = ->name();
				//cout<<"zaaa "<<endl;
				//cout<<accounts.at(0)->type() <<' '<<endl;

			}
		} 
		else if (cmd == "delete") 
		{
			string name;
			cin >> name;
			for (int i = 0; i < accounts.size(); ++i) 
			{
				if (accounts[i]->name() == name) 
				{
					accounts.erase(accounts.begin() + i);
					break;
				}
			}
		} 
		else if (cmd == "show") 
		{
			for (int i = 0; i < accounts.size(); ++i) 
			{
				cout << accounts.at(i)->name() << "\t"<< accounts.at(i)->type() << "\t"<< accounts.at(i)->balance() << "\t"<< accounts.at(i)->interest_rate() << endl;
				
			}
		} 
		else if (cmd == "after") 
		{
			int n_year = 0;
			cin >> n_year;
			for (int i = 0; i < accounts.size(); ++i) 
			{
				cout << accounts[i]->name() << "\t"<< accounts[i]->type() << "\t"<< accounts[i]->ComputeExpectedBalance(n_year) << "\t"<< accounts[i]->interest_rate() << endl;
			}
		}
	}
	return 0;
}