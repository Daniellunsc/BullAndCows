#include "FBullCowGame.h"
#include <map>

#define TMap std::map

FBullCowGame::FBullCowGame() {
	Reset();
}


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon;  }

int32 FBullCowGame::GetMaxTries() const { 

	TMap<int32, int32> WordLengthToMaxTries{
		{3,5}, {4,5}, {5,5}, {6,5}
	};

	return WordLengthToMaxTries[MyHiddenWord.length()]; 
}

void FBullCowGame::Reset() {

	 constexpr int32 MAX_TRIES = 8;
	 const FString HIDDEN_WORD = "planet";

	 MyHiddenWord = HIDDEN_WORD;
	 MyCurrentTry = 1;
	 bGameIsWon = false;
	 return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString m_guess) const {

	if (!IsIsogram(m_guess))
	{
		
		return EGuessStatus::Not_Isogram; 
	}
	else if (!IsLowerCase(m_guess))
	{ 
		return EGuessStatus::Not_Lowercase;
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

bool FBullCowGame::IsIsogram(FString Word) const {

	if (Word.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen;

	for (auto Letter : Word)  // for all letter in word
	{
		Letter = tolower(Letter); // handle mixed cases
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
			
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const {

	for (auto Letter : Word) {
		if(!islower(Letter)){
			return false;
		}
	}

	return true;
}
