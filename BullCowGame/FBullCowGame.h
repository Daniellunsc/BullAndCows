#pragma once
#include <string>

class FBullCowGame{

public:

	FBullCowGame(); // constructor
	
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // Make more rich return value
	bool CheckGuessValidity(std::string);  // Make more rich return value



private:
	int MyCurrentTry;
	int MyMaxTries;
};
