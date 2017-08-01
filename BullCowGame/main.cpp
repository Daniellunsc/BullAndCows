
#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

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

	std::cout << "Welcome to Bulls and Cows, a fun word game. " << std::endl;

	std::cout << "Can you guess the " << WORLD_LENGTH;
	std::cout << " letter isogram I'm thinking of ?" << std::endl;
	std::cout << std::endl;
	return;

}


void PlayGame() {


	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;
	// lopp for the number of turns asking guesses

	for (int i = 1; i <= MaxTries; i++)
	{
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

}


std::string GetGuess() {

	int CurrentTry = BCGame.GetCurrentTry();

	
	// get guess from the player
	std::string Guess = "";
	std::cout << "Try "<< CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);

	return Guess;

}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again (y/n) ? ";
	std::string Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

