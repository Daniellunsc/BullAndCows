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
	 const FString HIDDEN_WORD = "ant";

	 MyHiddenWord = HIDDEN_WORD;

	 MyMaxTries = MAX_TRIES;
	 MyCurrentTry = 1;
	 return;
}

bool FBullCowGame::CheckGuessValidity(FString m_guess) {
	return false;
}

//receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess) {

	// increment the turn number
	MyCurrentTry++;

	//setup a return value
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();

	//loop through all letter in guess
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) 
	{
		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) 
		{
			//if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) 
			{	
				if  (MHWChar == GChar) 
				{ // if they're in the same place
					BullCowCount.Bulls += 1; // increment bulls	
				}else
				{
					BullCowCount.Cows += 1;		//increment cows
				}		
			}
		}
	}

	return BullCowCount;
}
