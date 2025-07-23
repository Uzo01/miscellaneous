#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>

using namespace std;

class Bank_Account
{
	int account_num;
	char name[50];
	char type;
	int Money_deposite;
public:
	int retacno() const;
	void create_Account();
	void display_Account();
	void report() const;
	void depo(int x) { Money_deposite += x;	} //adding money into money deposit function
	void draw(int x) { Money_deposite -= x; } //withdraw money from money deposit function
	int retdepo()const { return Money_deposite; }
	void modify();
};