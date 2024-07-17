#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int number, guess;
    srand(time(0)); // seed random number generator
    number = rand() % 100 + 1; // generate random number between 1 and 100

    cout << "Guess a number between 1 and 100: ";
    cin >> guess;

    while (guess != number) {
        if (guess < number) {
            cout << "Too low. Try again: ";
        }
        else {
            cout << "Too high. Try again: ";
        }
        cin >> guess;
    }

    cout << "You guessed it! The number was " << number << endl;

    return 0;
}
