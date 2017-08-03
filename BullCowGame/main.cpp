
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
FText GetValidGuess();
void PrintGameSummary();
bool AskToPlayAgain();

FBullCowGame BCGame; 

int main() {

	do {
		PrintIntro();
		PlayGame();
		
	} while (AskToPlayAgain());

	return 0; // exit application
}



void PrintIntro() {


	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game. " << std::endl;

	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of ?" << std::endl;
	std::cout << std::endl;
	return;

}


void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl;


	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) 
	{
		FText Guess = GetValidGuess(); 

		//Submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	}

	PrintGameSummary();
	return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess() { 
	
	EGuessStatus Status = EGuessStatus::Invalid;
	FText Guess = "";
	do {
	int32 CurrentTry = BCGame.GetCurrentTry();
	// get guess from the player
	
	std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
	std::cout << ". Enter your guess: ";
	std::getline(std::cin, Guess);

	Status = BCGame.CheckGuessValidity(Guess);

	switch (Status) {

		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a isogram word\n\n";
			break;

		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your word all in lowercase\n\n";
			break;

		default:
			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}

void PrintGameSummary() {
	if (BCGame.IsGameWon()) {
		std::cout << "You Won! Congrats!\n";
	}
	else {
		std::cout << "Damn! You lose!\n";
	}
}


bool AskToPlayAgain() {

	std::cout << "Do you want to play again with the same hidden word(y/n) ? ";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
}

