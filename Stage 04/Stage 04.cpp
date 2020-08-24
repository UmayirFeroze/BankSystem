// Testing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct BankAccount
{

	int AccountNumber;
	double AccountBalance;
	string AccountHolder;
};

BankAccount enterAccountData()
{
	BankAccount NewBankAccount;
	do
	{
		cout << "\n----Create Account----" << endl;
		cout << "Enter Account Number: ";
		cin >> NewBankAccount.AccountNumber;
		
		if (NewBankAccount.AccountNumber != 0)
		{
			cout << "Enter Account Holder Name: ";
			cin >> NewBankAccount.AccountHolder;
			cout << "Enter Account Balance: ";
			cin >> NewBankAccount.AccountBalance;
			cout << "\n----Created Account----" << endl;
			cout << "Account Holder: " << NewBankAccount.AccountHolder << endl;
			cout << "Account Number: " << NewBankAccount.AccountNumber << endl;
			cout << "Account Balance: " << NewBankAccount.AccountBalance << endl;
		}
		
	} while (NewBankAccount.AccountNumber != 0000);
	return NewBankAccount;

}

void displayAccount(BankAccount Customer)
{
	cout << "\n****Account Details****" << endl;
	cout << "Account Holder: " << Customer.AccountHolder << endl;
	cout << "Account Number: " << Customer.AccountNumber << endl;
	cout << "Account Balance: " << Customer.AccountBalance << endl;
}

double calculateInterest(double balance)
{
	const double interest = 1.05;
	balance = balance*interest;
	return balance;
}

int main()
{
	int option,year, numyear,accoutType;
	string username, password;
	double accBalance;//calculatedBalance
	BankAccount Customer;
	do
	{
		cout << "\n\n\t InterBanking Pty \t" << endl << endl;
		cout << "(1) Create Account \n(2) Calculate Interest \n(3) View Account \n(4) Exit" << endl;
		cin >> option;
		if (option == 1)
		{
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			if (username == "Admin"&&password == "1234")//Validate User
			{
				Customer = enterAccountData();
			}
			else
				cout << "Incorrect Username or Password...!";
		}
		else if (option == 2)
		{
			cout << "Enter the Number of Years: ";
			cin >> numyear;
			accBalance = Customer.AccountBalance;
			for (year =1;year <= numyear;++year)
			{
				accBalance = calculateInterest(accBalance);
			}
			cout << "Account Balance: " << accBalance<<endl;
;			Customer.AccountBalance = accBalance;
		}
		else if (option == 3)
		{
			displayAccount(Customer);
		};
	} while (option != 4);
}
