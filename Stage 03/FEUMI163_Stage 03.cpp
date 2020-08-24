// Stage 03.cpp : Defines the entry point for the console application.
//

//Assumptions: 
/**/
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct BankAccount
{

	int AccountNumber;
	double AccountBalance,InterestRate;
	string AccountHolder, Password;
};

int main()s
{
	string username, password, accountHolder, choice;
	int user, accountNumber,accountType,accountChoice,back,transferOptions,currentMonth,month;
	double transferAmount, addInterest;
	const double charge = 20.00;
	BankAccount Savings; //Create Savings Account
	BankAccount Current; //Create Current Account
	do
	{
		//Choose user
		cout << "\n\n\t InterBanking Pty \t" << endl << endl;
		cout << "\nWelcome to InterBanking Pty" << endl << "Select User: " << endl << "(1) Administrator" << endl << "(2) Customer" << endl << "(3) Quit " << endl;
		cin >> user;
		if (user == 1) //Administrator User
		{
			cout<< "----Log In----" << endl;
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;
			cout << "" << endl;

			if (username == "Admin" && password == "1234") //Validating User
			{
				do
				{
					cout << "\n Select type of account you want to Create/ Update: " << endl;
					cout << "(1)Savings" << endl << "(2)Current" << endl << "(3) Back" << endl;
					cin >> accountType;
					if (accountType == 1)
					{
						cout << "\nSavings Account \n\n----Enter Customer Details----" << endl << endl; //Creating or Updating Savngs Account
						do
						{
							cout << "\nAccount Holder Name: ";
							cin >> Savings.AccountHolder;
							cout << "Account Number: ";
							cin >> Savings.AccountNumber;
							cout << "Account Balance: $";
							cin >> Savings.AccountBalance;
							cout << "Interest Rate: ";
							cin >> Savings.InterestRate;
							if (((Savings.AccountNumber < 1000) || (Savings.AccountNumber > 9999)) || ((Savings.AccountBalance < 0) || (Savings.AccountBalance > 1000000))
								|| ((Savings.InterestRate < 0.01) || (Savings.InterestRate > 15.0) || (Current.InterestRate > Savings.InterestRate)))
							{
								cout << "****Entered Values are Incorrect or Invalid****"<<endl;
							}

						} while (((Savings.AccountNumber < 1000) || (Savings.AccountNumber > 9999)) || ((Savings.AccountBalance < 0) || (Savings.AccountBalance > 1000000))
							|| ((Savings.InterestRate < 0.01) || (Savings.InterestRate > 15.0) || (Current.InterestRate > Savings.InterestRate)));
						cout << "\n----Created Customer Account----" << endl; //Echoing the input
						cout << "Account Holder Name: " << Savings.AccountHolder << endl;
						cout << "Account Number: " << Savings.AccountNumber << endl;
						cout << "Account Balance: $" << Savings.AccountBalance << endl;
						cout << "Interest Rate: " << Savings.InterestRate << "%" << endl;
					}
					else if (accountType == 2)
					{
						do
						{
							cout << "\nCurrent Account \n\n----Enter Customer Details----" << endl << endl; //Creating or Updating Current Account
							cout << "Account Holder Name: ";
							cin >> Current.AccountHolder;
							cout << "Account Number: ";
							cin >> Current.AccountNumber;
							cout << "Account Balance: $";
							cin >> Current.AccountBalance;
							cout << "Interest Rate: ";
							cin >> Current.InterestRate;
							if (((Current.AccountNumber < 1000) || (Current.AccountNumber > 9999)) || ((Current.AccountBalance < 0) || (Current.AccountBalance > 1000000))
								|| ((Current.InterestRate < 0.01) || (Current.InterestRate > 15.0) || (Current.InterestRate > Savings.InterestRate)))
							{
								cout << "****Entered Values are Incorrect or Invalid****" << endl;
							}
						} while (((Current.AccountNumber < 1000) || (Current.AccountNumber > 9999)) || ((Current.AccountBalance < 0) || (Current.AccountBalance > 1000000))
							|| ((Current.InterestRate < 0.01) || (Current.InterestRate > 15.0) || (Current.InterestRate > Savings.InterestRate)));
						cout << "\n----Created Customer Account----" << endl; //Echoing the input
						cout << "Account Holder Name: " << Current.AccountHolder << endl;
						cout << "Account Number: " << Current.AccountNumber << endl;
						cout << "Account Balance: $" << Current.AccountBalance << endl;
						cout << "Interest Rate: " << Current.InterestRate << "%" << endl;
					}

				} while (accountType < 3);
			}
			else
				cout << "Incorrect Username or Password... Please Retry..!";
		}
		else if (user == 2)
		{
			do
			{
				cout << "\nInter Banking Pty" << endl;
				cout << "Select Option: " << endl << "(1) View Savings Account" << endl << "(2) View Current Account" << endl << "(3) Transfer Funds" << endl << "(4) Exit" << endl;
				cin >> accountChoice;
				if (accountChoice == 1) //View Savings Account
				{
					cout << "\n----Log In----" << endl; // Customer Menu
					cout << "Acccount Holder: ";
					cin >> accountHolder;
					cout << "Account Number: ";
					cin >> accountNumber;
					cout << "In which month of the year are we? (Enter a number) : ";
					cin >> currentMonth;

					if ((accountHolder == Savings.AccountHolder && accountNumber == Savings.AccountNumber)&&(currentMonth>0 && currentMonth<13)) //Authorize Customer
						if (currentMonth == 1)
						{
							cout << "\n----Savings Account----" << endl;
							cout << "Account Holder: " << Savings.AccountHolder << endl;
							cout << "Account Number: " << Savings.AccountNumber << endl;
							cout << "Interest Rate: " << Savings.InterestRate << endl;

							cout << "Account Balance: $" << Savings.AccountBalance << endl;
							cout << "\nWould you like to go back? " << endl << "(1) Yes" << endl << "(2) No" << endl;
							cin >> back;
							if (back == 2)
								break;
						}
						else
						{
							cout << "\n----Savings Account----" << endl;
							cout << "Account Holder: " << Savings.AccountHolder << endl;
							cout << "Account Number: " << Savings.AccountNumber << endl;
							cout << "Interest Rate: " << Savings.InterestRate << endl;
							for (month = 1;month <= currentMonth;++month)
							{
								cout << "Month: " << month << endl;
								addInterest = Savings.AccountBalance*(Savings.InterestRate/100);
								cout << "Interest: " << addInterest << endl;
								cout << "Montly Charge: " << charge<<endl;
								Savings.AccountBalance = Savings.AccountBalance + addInterest - charge;
								cout << "Account Balance: " << Savings.AccountBalance << endl;
							}
							
						}
				}
				else  if (accountChoice == 2) //View Current Account
				{
					cout << "\n----Log In----" << endl;
					cout << "Account Holder: ";
					cin >> accountHolder;
					cout << "Account Number: ";
					cin >> accountNumber;
					cout << "In which month of the year are we? (Enter a number) : ";
					cin >> currentMonth;

					if ((accountHolder == Current.AccountHolder && accountNumber == Current.AccountNumber) && (currentMonth>0 && currentMonth<13)) //Authorize Customer
						if (currentMonth == 1)
						{
							cout << "\n----Savings Account----" << endl;
							cout << "Account Holder: " << Current.AccountHolder << endl;
							cout << "Account Number: " << Current.AccountNumber << endl;
							cout << "Interest Rate: " << Current.InterestRate << endl;

							cout << "Account Balance: $" << Current.AccountBalance << endl;
							cout << "\nWould you like to go back? " << endl << "(1) Yes" << endl << "(2) No" << endl;
							cin >> back;
							if (back == 2)
								break;
						}
						else
						{
							cout << "\n----Savings Account----" << endl;
							cout << "Account Holder: " << Current.AccountHolder << endl;
							cout << "Account Number: " << Current.AccountNumber << endl;
							cout << "Interest Rate: " << Current.InterestRate << endl;
							for (month = 1;month <= currentMonth;++month)
							{
								cout << "Month: " << month << endl;
								addInterest = Current.AccountBalance*(Savings.InterestRate / 100);
								cout << "Interest: " << addInterest << endl;
								cout << "Montly Charge: " << charge << endl;
								Current.AccountBalance = Current.AccountBalance + addInterest - charge;
								cout << "Account Balance: " << Current.AccountBalance << endl;
							}

						}
				
				}
				else if (accountChoice == 3) //Transfer Funds
				{

				}
			} while (accountChoice != 4 || back != 2);
		}
		else if (user == 3) //Exit Menu
		{
			cout << "\nThank you...! See you again...!" << endl;
			break;
		} 
	} while (user != 3);
}