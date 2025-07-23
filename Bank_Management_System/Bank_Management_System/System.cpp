#include "System.h"

void write_account();
void display_deatils(int);
void delete_account(int);

void System::write_account()
{
	//data being written in to be called out
	outFile.open("Account.dat", ios::binary | ios::app);
	ac.create_Account(); //take input from user convert to binary form then call out function
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(Bank_Account)); // cast charaters and write size of
	outFile.close();
}

void System::delete_account(int n)
{
	inFile.open("account.dat", ios::binary);
	if (!inFile) //if inFile could not be opened 
	{
		cout << "File cpuld not be opened !! Press any key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(Bank_Account))) // cast into characters
	{
		if (ac.retacno() != n)
		{
			outFile.write(reinterpret_cast<char*> (&ac), sizeof(Bank_Account));
		}
	}
	inFile.close();
	outFile.close();
	remove("Bank_Account.dat");
	rename("Temp.dat", "Bank_Account.dat");
	cout << "\t Record Deleted..." << endl;

}

void System::display_deatils(int n)
{
	inFile.open("account.dat", ios::binary);
	if (inFile)
	{
		cout << "File could not be open !! Press any key...";
		return;
	}
	cout << "\t Bank Account Detail" << endl;
	while (inFile.read(reinterpret_cast <char*> (&ac), sizeof(Bank_Account)));
	{	if (ac.retacno() == n) //if account number is present in file
	{
		ac.display_Account();
		flag = true;
	}
	}
	inFile.close();
	if (flag == false)
	{
		cout << "\t Account number does'nt exist" << endl;
	}
}

void System::display_all()
{
	system("cls");
	Bank_Account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be opened! || Press any key...";
		return;
	}
	cout << "\t Bank Account Holder List" << endl;
	cout << "===========================================================" << endl;
	cout << "A/C no.           NAME           TYPE           BALAENCE" << endl;
	cout << "===========================================================" << endl;
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(Bank_Account)))
	{
		ac.report();
	}
	inFile.close();
}

void System::deposit_money_withdraw(int n, int opt)
{
	int amt;
	bool found = false;
	Bank_Account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be opened! || Press any key!...";
		return;
	}
	while (!File.eof() && found == false) //if the file that is being found is false
	{  
		File.read(reinterpret_cast<char*> (&ac), sizeof(Bank_Account));
		if (ac.retacno() == n) // if acount number is entered by user
		{
			ac.display_Account(); 
			if (opt == 1)
			{
				cout << "\t Enter the amount to be deposited:  ";
				cin >> amt;
				ac.depo(amt);
			}
			if (opt == 2)
			{
				cout << "\t Enter the amount to be withdrawn: ";
				cin >> amt; //insert amount
				int balance = ac.retdepo() - amt; // balance can is what is taken from amount 
				if (balance < 0) // if less than 0
				{
					cout << "\t Insufficient balance" << endl;
				}
				else
				{
					ac.draw(amt); //withdraw from amount
				}
			}
			int pos = (-1) * static_cast<int>(sizeof(Bank_Account)); // static cast to integer
			File.seekp(pos, ios::cur); //move the pointer to the position if the file
			File.write(reinterpret_cast<char*> (&ac), sizeof(Bank_Account)); //write record in file
			cout << "\t Record updated!!" << endl;
			found = true;
		}
	}
	File.close();
	if (found == false)
	{
		cout << "\t record not found" << endl;
	}
}

void System::update_BA(int n)
{
	bool found = false; //run check on found
	Bank_Account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::out);//open file in binary mode
	if (!File)
	{
		cout << "File could not be found !! Press any key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(Bank_Account));	//read record from file
		if (ac.retacno() == n)
		{
			ac.display_Account();
			cout << endl;
			cout << "\t Enter the new details of the account" << endl;
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(Bank_Account));	//move the pointer to the position of the file
			File.seekp(pos, ios::cur);	//move the pointer to position of the file
			File.write(reinterpret_cast<char*>(&ac), sizeof(Bank_Account));
			cout << "\t Record Updated!! " << endl;
			found = true;
		}
	}
	File.close();
	if (found == false)
	{
		cout << "\t Record Not Found!! " << endl;
	}
}
