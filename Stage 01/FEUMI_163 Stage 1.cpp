// Assignment stage 1.cpp : Defines the entry point for the console application.
//

//Creating a bank account would simultaneously create a customer account
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Creating BankAccount Structure
struct BankAccount
{
	int AccountNumber;
	double AccountBalance;
	string AccountHolder, Password;
};

//Main Function
int main()
{
	string username, password, accountHolder, choice; //Declaring variables
	int user, accountNumber;
	BankAccount NewBankAccount; //Creating NewBankAccount Object
	do
	{
		//Display Menu
		cout << "\n\n\t InterBanking Pty \t" << endl << endl;
		cout << "\nWelcome to InterBanking Pty" << endl << "Select User: " << endl << "(1) Administrator" << endl << "(2) Customer" << endl << "(3) Quit " << endl;
		cin >> user;
		if (user == 1) //If user is Administrator
		{
			cout << "----Log In----" << endl; //Administrator Menu
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			cout << "" << endl;

			if (username == "Admin" && password == "1234") //Validating User
			{

				cout << "\n----Enter Customer Details----" << endl << endl; //Creating or Updating Customer Account
				cout << "Account Holder Name: ";
				cin >> NewBankAccount.AccountHolder;
				cout << "Account Password: ";
				cin >> NewBankAccount.Password;
				cout << "Account Number: ";
				cin >> NewBankAccount.AccountNumber;
				cout << "Account Balance: ";
				cin >> NewBankAccount.AccountBalance;

				cout << "\n----Created Customer Account----" << endl; //Echoing the input
				cout << "Account Holder Name: " << NewBankAccount.AccountHolder << endl;
				cout << "Account Password: " << NewBankAccount.Password << endl;
				cout << "Account Number: " << NewBankAccount.AccountNumber << endl;
				cout << "Account Balance: " << NewBankAccount.AccountBalance;

			}
			else
				cout << "\nEither Username or Password is Incorrect..! Please Retry..!\n"<<endl; //Error Message
		}
		else if (user == 2) //If user is Customer 
		{
			cout << "\n----Log In----" << endl; // Customer Menu
			cout << "Acccount Holder: ";
			cin >> accountHolder;
			cout << "Account Number: ";
			cin >> accountNumber;
			
			if (accountNumber == NewBankAccount.AccountNumber && accountHolder == NewBankAccount.AccountHolder) //Validate Customer 
			{
				cout << "\n Welcome Mr. " << NewBankAccount.AccountHolder << endl; //Display Customer Account Details
				cout << "\n----Bank Account Details----" << endl;
				cout << "Account Number: " << NewBankAccount.AccountNumber<<endl;
				cout << "Account Balance: " << NewBankAccount.AccountBalance<<endl;
			}
			else
				cout << "\nIncorrect Account Name or Number..!\n" << endl; //Error message 
		}
		else if (user == 3) //Exit the Menu
		{
			cout << "Thank You..! See you again...!\n" << endl << endl;
			break;
		}
	} while (user != 3);
	system("pause");
}