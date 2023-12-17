#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!\n";
    cout << "Try to guess the number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        attempts++;

        if (userGuess == secretNumber) {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "Too high! Try again.\n";
        }

    } while (userGuess != secretNumber);

    return 0;
}

