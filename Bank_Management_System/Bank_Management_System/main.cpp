#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "Bank_Account.h"
#include "System.h"

using namespace std;


int main()
{
	char ch;
	int num;
do{
	cout << "\t\t -----------------------------------------" << endl;
	cout << "\t\t | Welcome to the Bank Management System |" << endl;
	cout << "\t\t -----------------------------------------" << endl;

	cout << endl;
	cout << "\t --Main Menu--" << endl;
	cout << "\t 1. Create Account: " << endl;	//Created
	cout << "\t 2. Deposit Money: " << endl;	//Created
	cout << "\t 3. Withdraw Money: " << endl;	//Created
	cout << "\t 4. Balence Enquiry: " << endl;	//Created
	cout << "\t 5. All Account Holder List: " << endl;	//Created
	cout << "\t 6. Close Account: " << endl;	//Created
	cout << "\t 7. Modify Account: " << endl;
	cout << "\t 8. Exit: " << endl;	//Created
	cout << endl;

	cout << "\t Enter your choice (1-8): ";
	cin >> ch;
	System sys;


	
		switch (ch)
		{
			case'1':
				sys.write_account();
				break;
			case'2':
				system("cls");
				cout << "\t Enter the account number: ";
				cin >> num;
				sys.deposit_money_withdraw(num, 1);	//DEPOSIT FUNCTION
				break;
			case'3':
				system("cls");
				cout << "\t Enter the account number: ";
				cin >> num;
				sys.deposit_money_withdraw(num, 2);	//WITHDRAW FUNCTION
				break;
			case'4':
				system("cls");
				cout << "\t Enter the account number: ";
				cin >> num;
				sys.display_deatils(num);	//BALAENCE EQUIRIES FUNCTION
				break;
			case'5':
				sys.display_all();				//DISPLAY ALL FUNCTION
				break;
			case'6':
				system("cls");
				cout << "\t Enter the account number: ";
				cin >> num;
				sys.delete_account(num);	//CLOSE ACCOUNT FUNCTION
				break;
			case'7':
				system("cls");
				cout << "\t Enter the account number: ";
				cin >> num;	//MODIFY ACCOUNT FUNCTION
				sys.update_BA(num);
				break;  
			case'8':
				cout << "\t Thanks for using the Bank Management System" << endl;
				break;
		}
	cin.ignore();
	cin.get();
} while (ch != '8');
return 0;
	/*Bank_Account BA;
	BA.create_Account();
	BA.display_Account();
	
	return 0;*/
}

