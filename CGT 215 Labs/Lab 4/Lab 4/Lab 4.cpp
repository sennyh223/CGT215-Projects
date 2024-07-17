#include <iostream>
using namespace std;
// Print out the menu of choices for the user to select from

void printMenu() {
	cout << "Please Select which operation to perform:" << endl;
	cout << "\t1. Factorial" << endl;
	cout << "\t2. Arithmetic Series" << endl;
	cout << "\t3. Geometric Series" << endl;
	cout << "\t4. Exit" << endl;
	cout << "Your Selection: ";
}
void factorial() {
	// I recommend writing your factorial code here
	int n;
	int a = 1;
	long factorial = 1.0;
	cout << "Factorial:";
	cout << "\nPlease enter a number:";
	cin >> n;
	while (n < 0) {
		cout << "Please enter a positive number: ";
		cin >> n;
	}
	cout << n << "!" << " = " << "1";
	for (int i = 1; i < n; ++i) {
			a += 1;
			factorial *= a;
			cout << " * " << a;
		}
	cout << " = " <<factorial;
}
void arithmetic() {
	// I recommend writing your arithmetic series code here
	int a;
	int b;
	int n;
	cout << "Arithmetic:";
	cout << "\nPlease enter a number to start at:";
	cin >> a;
	cout << "Please enter a number to add at each time:";
	cin >> b;
	cout << "Enter the number of elements in the series:";
	cin >> n;
	float sumOfAP(float a, float b, int n); {
	float sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum = sum + a;
			a = a + b;
		}

	}
	
}

void geometric() {
	// I recommend writing your geometric series code here
	int a;
	int b;
	int n;
	cout << "Geometric:";
	cout << "\nPlease enter a number to start at:";
	cin >> a;
	cout << "Please enter a number to multiply at each time:";
	cin >> b;
	cout << "Enter the number of elements in the series:";
	cin >> n;
}
int main() {
	int choice;
	char again;
	do {
		printMenu();
		cin >> choice;
		// Quit if user chooses to exit (or any invalid choice)
		if (choice > 3 || choice < 1) {
			return 0;
		}
		else if (choice == 1) {
			factorial();
		}
		else if (choice == 2) {
			arithmetic();
		}
		else if (choice == 3) {
			geometric();
		}
		cout << "\nGo Again? [Y/N] ";
		cin >> again;
	} while (again == 'y' || again == 'Y');
}
