#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){
	double Initial, Interest_rate, payPer_year;	
	cout << "Enter initial loan: ";
	cin >> Initial;
	cout << "Enter interest rate per year (%): ";
	cin >> Interest_rate;
	cout << "Enter amount you can pay per year: ";
	cin >> payPer_year;
	int year = 1;
	double PrevBalance = Initial;
	double Interest = PrevBalance * (Interest_rate/100);
	double Total = PrevBalance + Interest;
	double Payment = payPer_year;
	double NewBalance = Total - Payment;
	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	while (true){
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << year;
		cout << setw(13) << left << PrevBalance;
		cout << setw(13) << left << Interest;
		cout << setw(13) << left << Total;
		if (Total <= Payment){
			Payment = Total;
			NewBalance = 0;
		}
		cout << setw(13) << left << Payment;
		cout << setw(13) << left << NewBalance;
		cout << "\n";
		if (NewBalance <= 0){break;}
		year++;
		PrevBalance = NewBalance;
		Interest = PrevBalance * (Interest_rate/100);
		Total = PrevBalance + Interest;
		NewBalance = Total - Payment;
	}
	
	return 0;
}
