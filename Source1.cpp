#include <iostream>
#include <iomanip>

using namespace std;


	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int years;
	int months;
	double totalAmount;
	double interestAmount;
	double yearlyTotalInterest;


int displayMenu() {

		//Initial menu display
		cout << "**********************" << endl;
		cout << "***** Data Input *****" << endl;
		cout << "Initial Investment Amount:" << endl;
		cout << "Monthly Deposit:" << endl;
		cout << "Annual Interest:" << endl;
		cout << "Number of Years:" << endl;
		system("pause");

		//shows user input
		cout << "**********************" << endl;
		cout << "***** Data Input *****" << endl;
		cout << "Initial Investment Amount: $" << endl;
		cin >> initialInvestment;
		cout << "Monthly Deposit: $" << endl;
		cin >> monthlyDeposit;
		cout << "Annual Interest: %" << endl;
		cin >> annualInterest;
		cout << "Number of Years:" << endl;
		cin >> years; months = years / 12;
		system("pause");
		return 0;
	}

	int displayBalanceNoMonthly() {
		//displays menu
		system("cls");
		cout << "	balance and Interest Without Additional Monthly Deposits	" << endl;
		cout << "===============================================================" << endl;
		cout << "Year		Year End Balance		Year End Earned interest	" << endl;
		cout << "---------------------------------------------------------------" << endl;

		//calculations!
		totalAmount = initialInvestment;

		for (int i = 0; i < years; i++) {
			interestAmount = totalAmount * (annualInterest / 100);
			totalAmount = totalAmount + interestAmount;
			cout << " " << (i + 1) << "			" << totalAmount << "			" << interestAmount << endl;
		}
		return 0;
	}

	int displayBalanceWithMonthly() {
		//displays menu

		cout << "	balance and Interest With Additional Monthly Deposits		" << endl;
		cout << "===============================================================" << endl;
		cout << "Year		Year End Balance		Year End Earned interest	" << endl;
		cout << "---------------------------------------------------------------" << endl;

		//calculations!
		totalAmount = initialInvestment;

		for (int i = 0; i < years; i++) {
			yearlyTotalInterest = 0;
			for (int j = 0; j < 12; j++) {
				interestAmount = ((totalAmount + monthlyDeposit) * (annualInterest / 100)) / 12;
				yearlyTotalInterest = yearlyTotalInterest + interestAmount;
				totalAmount = totalAmount + monthlyDeposit + interestAmount;
			}
			cout << " " << (i + 1) << "			" << totalAmount << "			" << yearlyTotalInterest << endl;
		}
		return 0;
	}

int main() {
	
	// displays everything
	displayMenu();
	displayBalanceNoMonthly();
	displayBalanceWithMonthly();
	return 0;
}
