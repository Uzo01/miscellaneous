#include "Bank_Account.h"

int Bank_Account::retacno() const
{
	return account_num;
}

void Bank_Account::create_Account()
{
	system("cls");
	cout << "\t Enter the account number: ";
	cin >> account_num; //enter the account name
	cout << "\t Enter the name of the account holder: ";
	cin.ignore();
	cin.getline(name, 50); //whatever is writter is stored with elements up to 50
	cout << "\t Enter the type of account (Current C/S Saving): ";
	cin >> type;
	type = toupper(type); //turns type cast to upper case
	cout << "\t Enter the initial amount (>= 500 for saving and >= 1000 for current): ";
	cin >> Money_deposite; //Deposite the money 
	cout << "\t Account Created: )";
	cout << endl;
}

void Bank_Account::display_Account()
{
	cout << "\t Bank Account Number: " << account_num << endl;
	cout << "\t Account Holder Name: " << name << endl;
	cout << "\t Type of account: " << type << endl;
	cout << "\t Account Balance: " << Money_deposite << endl;
}

void Bank_Account::report() const
{
	cout << account_num << setw(10) << " " << name << setw(16) << type << setw(16) << Money_deposite << endl; //return values for function in account num name and money deposite
}

void Bank_Account::modify()
{
	cout << "\t Account Number: " << account_num << endl;
	cout << "\t Modify Holders Name: ";
	cin.ignore();
	cin.getline(name, 50);
	cin >> type;
	type = toupper(type);	//convert to upper
	cout << "\t Modify Balance amount: ";
	cin >> Money_deposite;
}



