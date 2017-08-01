#include "FBullCowGame.h"
#include <string>

void FBullCowGame::Reset() {
	return;
}

int FBullCowGame::GetMaxTries() {
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() {
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() {
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string m_guess) {
	return false;
}