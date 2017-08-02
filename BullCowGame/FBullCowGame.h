#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {

	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EGuessStatus {

	Invalid,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame{

public:

	FBullCowGame(); // constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const; //TODO make game logic to win
	void Reset(); // TODO Make more rich return value
	EGuessStatus CheckGuessValidity(FString) const;  // TODO Make more rich return value
	FBullCowCount SubmitValidGuess(FString);



private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameIsWon;

};
