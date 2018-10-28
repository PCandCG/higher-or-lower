#include <iostream>
#include <ctime>
#include <thread>
using namespace std;

int playerGuesses() {
	srand(time(NULL));
	int randNumber = rand() % 100;
	int userGuess = 0;
	int counter = 0;
	cout << "I am thinking of a whole number between 1 and 100 inclusive - Can you guess what it is" << endl;
	while (userGuess != randNumber) {
		cout << "Please enter your guess: ";
		cin >> userGuess;
		if (userGuess == randNumber) {
			cout << "Well done, you guessed it!" << endl;
		}
		else if (userGuess < randNumber) {
			cout << "Your guess was too low" << endl;
		}
		else if (userGuess > randNumber) {
			cout << "Your guess was too high" << endl;
		}
		counter++;
	}
	cout << "It took you " << counter << " guesses" << endl;
	return 0;
}

int computerGuesses() {
	int highestNumber = 100;
	int lowestNumber = 0;
	int counter = 0;
	bool guessed = false;
	cout << "Please use the format" << endl << "Y - if the guess is correct" << endl << "H - if the guess is too high" << endl << "L - if the guess is too low" << endl;
	while (guessed == false) {
		char userInput = 'G';
		int guess = (lowestNumber + highestNumber) / 2;
		cout << "Is it " << guess << "?" << endl;
		cin >> userInput;
		if (userInput == 'Y') {
			cout << "It took me " << counter +1 << " guesses" << endl;
			guessed = true;
		}
		else if (userInput == 'H') {
			highestNumber = guess;
			counter++;
		}
		else if (userInput == 'L') {
			lowestNumber = guess;
			counter++;
		}
		else {
			cout << "Your input was invalid - Please try again";
		}
	}
	return 0;
}

int gamemodeSelect() {
	int selection = 0;
	cout << "Please select how you would like to play:" << endl << "1. You guess" << endl << "2. I guess" << endl;
	while (selection < 1 or selection > 2) {
		cin >> selection;
	}
	if (selection == 1) {
		playerGuesses();
	}
	else if (selection == 2) {
		computerGuesses();
	}
	return 0;
}

int main() {
	gamemodeSelect();
	system("PAUSE");
	return 0;
}