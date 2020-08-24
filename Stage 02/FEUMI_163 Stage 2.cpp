// Stage 02.cpp : Defines the entry point for the console application.
//

//Creating a bank account would simultaneously create a customer account.
//A Customer can have one account of each type (Savings/Current).
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

// Creating BankAccount Structure
struct BankAccount
{
	int AccountNumber;
	double AccountBalance;
	string AccountHolder;
};

int main() //Main Function
{
	string username, password, accountHolder, choice; //Declaring variables
	int user, accountNumber,accountType,accountChoice,back,transferOptions;
	double TransferAmount;
	BankAccount Savings; //Creating Savings Account
	BankAccount Current;//Creating Current Account
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
				do
				{
					cout << "\n Select type of account you want to Create/ Update: " << endl;
					cout << "(1)Savings" << endl << "(2)Current" << endl<<"(3) Back"<<endl;
					cin >> accountType;
					if (accountType == 1)
					{
						cout << "\nSavings Account \n\n----Enter Customer Details----" << endl << endl; //Creating or Updating Savngs Account
						do
						{
							cout << "Account Holder Name: ";
							cin >> Savings.AccountHolder;
							cout << "Account Number: ";
							cin >> Savings.AccountNumber;
							cout << "Account Balance: $";
							cin >> Savings.AccountBalance;
						

							cout << "\n----Created Customer Account----" << endl; //Echoing the input
							cout << "Account Holder Name: " << Savings.AccountHolder << endl;
							cout << "Account Number: " << Savings.AccountNumber << endl;
							cout << "Account Balance: $" << Savings.AccountBalance << endl;
						} while (((Current.AccountNumber < 1000) && (Current.AccountNumber>9999)) && (Current.AccountBalance >0));
					
							
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

							cout << "\n----Created Customer Account----" << endl; //Echoing the input
							cout << "Account Holder Name: " << Current.AccountHolder << endl;
							cout << "Account Number: " << Current.AccountNumber << endl;
							cout << "Account Balance: $" << Current.AccountBalance << endl;
						} while (((Current.AccountNumber < 1000) && (Current.AccountNumber>9999)) && (Current.AccountBalance >0));
						
					}
					else
					{
						cout << "Invalid Input" << endl;
					}
				} while (accountType < 3);
			}
			else
				cout << "\nEither Username or Password is Incorrect..! Please Retry..!\n" << endl; //Error Message
		}
		else if (user == 2) //If user is Customer 
		{
			do
			{
				cout << "\nInter Banking Pty" << endl;
				cout << "Select Option: " << endl << "(1) View Savings Account" << endl << "(2) View Current Account" <<endl<< "(3) Transfer Funds" << endl<<"(4) Exit"<<endl;
				cin >> accountChoice; 
				if (accountChoice == 1) //View Savings Account
				{
					cout << "\n----Log In----" << endl; // Customer Menu
					cout << "Acccount Holder: ";
					cin >> accountHolder;
					cout << "Account Number: ";
					cin >> accountNumber;

					if (accountHolder == Savings.AccountHolder && accountNumber == Savings.AccountNumber) //Authorize Customer
					{
						cout << "\n----Savings Account----" << endl;
						cout << "Account Holder: " << Savings.AccountHolder << endl;
						cout << "Account Balance: $" << Savings.AccountBalance << endl;
						cout << "\nWould you like to go back? " << endl << "(1) Yes" << endl << "(2) No" << endl;
						cin >> back;
						if (back == 2)
							break;
					}
						break;
				}
				else if (accountChoice==2) //View Current Account
				{
					cout << "\n----Log In----" << endl;
					cout << "Account Holder: ";
					cin >> accountHolder;
					cout << "Account Number: ";
					cin >> accountNumber;
					if (accountHolder == Current.AccountHolder && accountNumber == Current.AccountNumber) //Authorize Customer
					{
						cout << "\n---- Current Account----" << endl;
						cout << "Account Holder: " << Current.AccountHolder << endl;
						cout << "Account Balance: $" << Current.AccountBalance << endl;
						cout << "\nWould you like to go back? " << endl << "(1) Yes" << endl << "(2) No" << endl;
						cin >> back;
						if (back == 2)
							break;
					}
						break;
				}
				else if (accountChoice==3) //Transfer Funds
				{
					cout << "\n ----Transfer Funds----" << endl;
					cout << "Choose Transfer Options: " << endl << "(1) Savings to Current" << endl << "(2) Current to Savings" << endl;
					cin >> transferOptions;
					if (transferOptions == 1) //Savings to Current Account Fund Transfer
						{
							cout << "\nTranfer from Savings to Current Account" << endl;
							cout << "Enter Trasfer Amount: $";
							cin >> TransferAmount;
							if (TransferAmount < Savings.AccountBalance)
							{
								Savings.AccountBalance = Savings.AccountBalance - TransferAmount;
								Current.AccountBalance = Current.AccountBalance + TransferAmount;
								if (Current.AccountBalance > 100000)
								{
									cout << "\n...Transaction Declined..." << endl;
									cout << "Reason: Exeeded highest amount Federally Insured...!";
									Savings.AccountBalance = Savings.AccountBalance + TransferAmount;
									Current.AccountBalance = Current.AccountBalance - TransferAmount;
									cout << "Account Number: " << Savings.AccountNumber << "\t Savings Account Balance: $" << Savings.AccountBalance << endl;
									cout << "Account Number: " << Current.AccountNumber << "\t Current Account Balance: $" << Current.AccountBalance << endl;
								}
								else
								{
									cout << "\n...Transaction Successful..." << endl;
									cout << "****Your Receipt****" << endl;
									cout << "Account Number: " << Savings.AccountNumber << "\t Savings Account Balance: $" << Savings.AccountBalance << endl;
									cout << "Account Number: " << Current.AccountNumber << "\t Current Account Balance: $" << Current.AccountBalance << endl;
								}
							}
							else
								cout << "\n...Transaction Declined..." << endl << "No Sufficient Funds";
							break;
						}
					else if (transferOptions == 2) //Current to Savings Account Fund Transfer
						{
							cout << "\nTranfer from Current to Savings Account" << endl;
							cout << "Enter Trasfer Amount: $";
							cin >> TransferAmount;
							if (TransferAmount < Current.AccountBalance)
							{
								Current.AccountBalance = Current.AccountBalance - TransferAmount;
								Savings.AccountBalance = Savings.AccountBalance + TransferAmount;
								if (Current.AccountBalance > 100000)
								{
									cout << "\n...Transaction Declined..." << endl;
									cout << "Reason: Exeeded highest amount Federally Insured...!";
									Savings.AccountBalance = Savings.AccountBalance - TransferAmount;
									Current.AccountBalance = Current.AccountBalance + TransferAmount;
									cout << "Account Number: " << Savings.AccountNumber << "\t Savings Account Balance: $" << Savings.AccountBalance << endl;
									cout << "Account Number: " << Current.AccountNumber << "\t Current Account Balance: $" << Current.AccountBalance << endl;
								}
								else
								{
									cout << "\n...Transaction Successful..." << endl;
									cout << "****Your Receipt****" << endl;
									cout << "Account Number: " << Savings.AccountNumber << "\t Savings Account Balance: $" << Savings.AccountBalance << endl;
									cout << "Account Number: " << Current.AccountNumber << "\t Current Account Balance: $" << Current.AccountBalance << endl;
								}
							}
							else
								cout << "...Transaction Declined..." << endl << "No Sufficient Funds";
							break;
						}
					else
						break;
				}
				else if (accountChoice==4) //Exit 
				{
					cout << "Thank You ... ! See You Again..!";
					break;
				}
				
			} while (accountChoice != 4 || back != 2);
		}
		else if (user == 3) //Exit the Menu
		{
			cout << "Thank You..! See you again...!\n" << endl << endl;
			break;
		}
	} while (user != 3);
	
}

