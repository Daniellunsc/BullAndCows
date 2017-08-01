
#include <iostream>

#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

int main() {

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0; // exit application
}



void PrintIntro() {

	//introduce game
	constexpr int WORLD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows, a fun word game. " << endl;

	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " letter isogram I'm thinking of ?" << endl;
	cout << endl;
	return;

}


void PlayGame() {
	// lopp for the number of turns asking guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int i = 1; i <= NUMBER_OF_TURNS; i++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}

}


string GetGuess() {

	// get guess from the player
	string Guess = "";
	cout << "Enter your guess: ";

	getline(cin, Guess);

	return Guess;

}

bool AskToPlayAgain() {

	cout << "Do you want to play again (y/n) ? ";
	string Response = "";
	getline(cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

