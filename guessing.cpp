#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    int guessno;
    int n= 0;
    cout << "Welcome to the Number Guessing  Game!" << endl;
    while(secretNumber!=guessno){
       
        cout << "Guess the number (between 1 and 100): ";
        cin >> guessno;
        n++;
        if (guessno < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guessno > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << n << " attempts." << endl;
        }

    }

    return 0;
}
