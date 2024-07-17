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
	int a;
	int b;
	cout << "Factorial:" << endl;
	cout << "Please enter a number: ";
	cin >> n;
	while (n < 0) {
		cout << "Nice try, please enter a POSITIVE number instead: ";
		cin >> n;
	}
		b = n; 
		a = n;
	cout << n << "! = ";
		for (int i(n); i > 1; i--) {
			cout << i << " * ";
			b -= 1;
			a *= b;
		}
		cout << "1 = " << a << endl;
}
void arithmetic() {
	// I recommend writing your arithmetic series code here
	int a;
	int b;
	int n;
	int x;
	int y;
	cout << "Arithmetic:" << endl;
	cout << "Please enter a number to start at: ";
	cin >> a;
	cout << "Please enter a number to add at each time: ";
	cin >> b;
	cout << "Enter the number of elements in the series: ";
	cin >> n;
	while (n < 0) {
		cout << "Nice try, please enter a POSITIVE number instead: ";
		cin >> n;
	}
	x = a;
	y = a;
	cout << a << " + ";
	for (int i = 2; i <= n; i++)
	{
		x += b;
		y += x;
		if (i < n) {
			cout << x << " + ";
		}
		if (i >= n) {
			cout << x;
		}
	}
	cout << " = " << y << endl;
}
void geometric() {
// I recommend writing your geometric series code here
	int a;
	int b;
	int n;
	int x;
	int y;
	cout << "Geometric:" << endl;
	cout << "Please enter a number to start at: ";
		cin >> a;
	cout << "Please enter a number to multiply at each time: ";
		cin >> b;
	cout << "Enter the number of elements in the series: ";
		cin >> n;
	while (n < 0) {
		cout << "Nice try, please enter a POSITIVE number instead: ";
		cin >> n;
	}
	x = a;
	y = a;
	cout << a << " * ";
	for (int i = 2; i <= n; i++) {
		x *= b;
		y += x;
		if (i < n) {
			cout << x << " + ";
		}
		if (i >= n) {
			cout << x;
		}
		cout << " = " << endl;
}
	int main()  {		
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
			cout << "Go Again? [Y/N] ";
			cin >> again;
		} while (again == 'y' || again == 'Y'); 
	}

	