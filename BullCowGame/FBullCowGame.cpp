#include "FBullCowGame.h"
#include <string>



FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const {
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const {

	
	return false;
}


void FBullCowGame::Reset() {

	 constexpr int32 MAX_TRIES = 8;
	 const FString HIDDEN_WORD = "planet";

	 MyHiddenWord = HIDDEN_WORD;

	 MyMaxTries = MAX_TRIES;
	 MyCurrentTry = 1;
	 return;
}

bool FBullCowGame::CheckGuessValidity(FString m_guess) {
	return false;
}

//receives a VALID guess, increments turn, and returns count
BullCowCount FBullCowGame::SubmitGuess(FString) {

	// increment the turn number
	MyCurrentTry++;

	//setup a return value
	BullCowCount BullCowCount;

	//loop through all letter in guess
		//compare letters against the hidden word

	return BullCowCount;
}
