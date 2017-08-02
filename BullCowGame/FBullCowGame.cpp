#include "FBullCowGame.h"
#include <string>

FBullCowGame::FBullCowGame() {
	Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon;  }


void FBullCowGame::Reset() {

	 constexpr int32 MAX_TRIES = 8;
	 const FString HIDDEN_WORD = "planet";

	 MyHiddenWord = HIDDEN_WORD;
	 MyMaxTries = MAX_TRIES;
	 MyCurrentTry = 1;
	 bGameIsWon = false;
	 return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString m_guess) const {

	//if guess isn't a isogram, 
	if (false)
	{
		return EGuessStatus::Not_Isogram; //TODO write function
	}
	else if (false)
	{ // if the guess isn't all lowercase, 
		return EGuessStatus::Not_Lowercase; // TODO write function
	}
	else if(m_guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

//receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) {

	MyCurrentTry++;

	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length(); // assuming same length as guesss

	//loop through all letter in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) 
	{
		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < WordLength; GChar++) 
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
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}

	return BullCowCount;
}
