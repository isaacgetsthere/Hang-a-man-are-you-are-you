#pragma once
#include <vector>
#include <string>

std::vector<std::string> getAllDictionaryWords(std::string filename);

std::string pickRandomWord(std::vector<std::string> words);

void findAndReplace(std::string wordToGuess, std::string &placeHolder, char characterToSearchFor);

void playHangman();
