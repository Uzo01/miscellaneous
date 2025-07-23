#pragma once
#include "Bank_Account.h"

class System
{
	Bank_Account ac;
	ofstream outFile;
	ifstream inFile; //input file stream
	bool flag = false;
public:
	void write_account();
	void delete_account(int n);
	void display_deatils(int n);
	void display_all();
	void deposit_money_withdraw(int n, int opt);
	void update_BA(int n);
};