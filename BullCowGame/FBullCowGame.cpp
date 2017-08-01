#include "FBullCowGame.h"
#include <string>

void FBullCowGame::Reset() {
	return;
}

int FBullCowGame::GetMaxTries() const {
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const {
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const {
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string m_guess) {
	return false;
}