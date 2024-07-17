#include <iostream>

using namespace std;

int main()
{
	float A;
	float B;
	float X;
	cout << "Hi, this is Senny and today we will be solving the equation: \nAx + B = 0";

	cout << "\nPlease enter a value for A: ";
	
	cin >> A;
	
	cout << "Please enter a value for B: ";
	
	cin >> B;
	X = (0 - B) / A;
	
	cout << "\nSolving for " << A << "x+" << B << "=0 for x...\n";
	
	cout << "The answer is \nx = " << X << endl;
}
