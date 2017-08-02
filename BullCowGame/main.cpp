
/*
This is the console executable, that makes use of the BullCow class
this acts as the view in a MVC pattern, and is responsible for all user interaction. 

For game logic see the FBullCowGame class;


*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using int32 = int;

using FText = std::string;


void PrintIntro();
void PlayGame();
FText GetGuess();
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

	std::cout << "Welcome to Bulls and Cows, a fun word game. " << std::endl;

	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of ?" << std::endl;
	std::cout << std::endl;
	return;

}


void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;

	// lopp for the number of turns asking guesses
	//TODO change from FOR to WHILE loop once we are validating tries
	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText Guess = GetGuess(); //TODO make loop checking valid

		//Submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Print number of bulls and cows

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
	// TODO summarise game
}


FText GetGuess() {

	int32 CurrentTry = BCGame.GetCurrentTry();

	
	// get guess from the player
	FText Guess = "";
	std::cout << "Try "<< CurrentTry << ". Enter your guess: ";
	std::getline(std::cin, Guess);

	return Guess;

}

bool AskToPlayAgain() {

	std::cout << "Do you want to play again (y/n) ? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

