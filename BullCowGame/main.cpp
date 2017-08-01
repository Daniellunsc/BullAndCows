
#include <iostream>

#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

int main() {
	
	PrintIntro();

	for (int i = 0; i < 5; i++)
	{
		GetGuessAndPrintBack();
	}
	return 0;
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

string GetGuessAndPrintBack() {
	// get guess from the player
	string Guess = "";
	cout << "Enter your guess: ";

	getline(cin, Guess);
	cout << "Your guess was: " << Guess << endl;

	return Guess;

}