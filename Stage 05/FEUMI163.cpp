// Final Try.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount
{
private:
	int AccountNumber = 0, AccountBalance = 0;
public:
	const double InterestRate = 1.03;
	void dataPersistency();
	void displayAccount();
	void enterAccountData();
	void computeInterest(int year);
};

BankAccount Customers[10];

string Again;
int year;
static int counter;s

void BankAccount::enterAccountData()
{
	bool loop;
	for (int count = 0; count < 10; count++)
	{
		do
		{
			cout << "\nAccount number: ";
			cin >> Customers[count].AccountNumber;
			if (Customers[count].AccountNumber >= 1000 && Customers[count].AccountNumber <= 9999)
			{
				do
				{
					cout << "Account Balance :";
					cin >> Customers[count].AccountBalance;

					if (Customers[count].AccountBalance <= 0 || Customers[count].AccountBalance >= 100000)
					{
						cout << "Invalid Amount..!Please Re-try...!"<<endl;
						loop = false;
					}
					else
						loop = true;
				} while (loop == false);
				counter++;
			}
			else
			{
				cout << "Invalid Details..! Please Re-try...!";
				loop = false;
			}
		} while (loop == false);
		cout << "would you like to countinue? (Y OR N)"<<endl;
		cin >> Again;
		if (Again == "N" || Again == "n")
			break;
	}
}

void BankAccount::computeInterest(int year)
{
	double balance = BankAccount::AccountBalance;
	cout << "\nAccount Number : " << BankAccount::AccountNumber << endl;
	for (int count = 0; count < year; count++)
	{
		balance = (BankAccount::InterestRate*balance);
	}
	cout << "Ending Balance: " << balance << endl;
}

void BankAccount::displayAccount()
{
	cout << "\nAccount Number  : " << BankAccount::AccountNumber << endl;
	cout << "Account Balance : " << BankAccount::AccountBalance << endl;
}

void BankAccount::dataPersistency()
{

	ofstream writeFile("BankAccount.txt", ios::app);

	if (writeFile.is_open())
	{
		writeFile << "\nAccount Number        :" << BankAccount::AccountNumber<<endl;
		writeFile << "Account Number        :" << BankAccount::AccountBalance<<endl;
		writeFile << "Account Interest Rate :" << BankAccount::InterestRate << endl;
		cout << "\n----Account Created----";
	}
	else
	{
		cout << "\nCannot Open File";

	}
	writeFile.close();
}

int main()
{
	int option, numyear;
	Customers[10];
	bool validation = false;
	string username, password;


		do
		{
			cout << "\n\n\t InterBanking Pty \t" << endl << endl;
			cout << "(1) Create Account \n(2) Calculate Interest \n(3) View Account \n(4) Exit" << endl;
			cin >> option;

			if (option == 1)
			{
				cout << "\n****Log In****" << endl;
				cout << "Username: ";
				cin >> username;
				cout << "Password: ";
				cin >> password;
				if (username == "Admin" && password == "1234")
				{
					cout << "\n----Create Account----" << endl;
					Customers[10].enterAccountData();
					for (int count = 0; count < counter; count++)
					{
						Customers[count].dataPersistency();
						Customers[count].displayAccount();
					}
					validation = false;
				}
				else
				{
					cout << "\n Incorrect Username or Password...! Please Re-try...!"<<endl;
					validation = false;
				}
			}
			else if (option == 2)
			{
				cout << "\n----Calculate Interest----" << endl;
				cout << "Enter the Number of Years: ";
				cin >> numyear;

				for (int count = 0; count < counter; count++)
				{
					Customers[count].computeInterest(numyear);
				}
				validation = false;
			}
			else if (option == 3)
			{
				cout << "\n----View Account----" << endl;
				for (int count = 0; count < counter; count++)
				{
					Customers[count].displayAccount();
				}
				validation = false;
			}
			else if (option == 4)
			{
				validation = true;
				break;
			}
			else
			{
				cout << "Thank You..! See you again..!" << endl;
				validation = false;
			}
		} while (validation == false);
	return 0;
}

