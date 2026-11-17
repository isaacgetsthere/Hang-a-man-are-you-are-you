#include "Hangman.h"
#include <iostream>
#include <fstream>
#include <random>

std::vector<std::string> getAllDictionaryWords(std::string filename)
{
	std::vector<std::string> words;

	std::ifstream fin(filename);

	if (fin.is_open() == false)
	{
		std::cout << "could not find the file " << filename << std::endl;
		return {};
	}

	std::string currentWord;

	while (std::getline(fin, currentWord))
	{
		words.push_back(currentWord);
	}

	//std::cout << "The number of words is: " << words.size() << std::endl;
 	return words;
}

std::string generatePlaceHolder(std::string wordToGuess)
{
	std::string placeHolder;

	for (int i = 0; i < wordToGuess.size(); i++)
	{
		placeHolder.push_back('*');
	}
	return placeHolder;
}



void playHangman()
{
	std::string absoluteFilePath = "C://Users//Isaac//downloads//popular.txt";

	std::vector<std::string> dictionaryWords = getAllDictionaryWords(absoluteFilePath);

	std::string wordToGuess = pickRandomWord(dictionaryWords);
	std::string placeHolder = generatePlaceHolder(wordToGuess);
	
	//std::cout << "If you are a cheater here is the word " << wordToGuess << std::endl;
	std::cout << "The word to guess is " << placeHolder << std::endl;

	int numGuesses = 0;
	int maxGuesses = wordToGuess.size() + 1;

	char guessedCharacter = ' ';
	while(placeHolder != wordToGuess && numGuesses != maxGuesses)	
	{
		std::cout << "guess a letter " << std::endl;
		std::cin >> guessedCharacter;
		numGuesses++;
		findAndReplace(wordToGuess, placeHolder, guessedCharacter);
	}
	if (placeHolder != wordToGuess)
	{
		std::cout << "You are loved but you didn't get it" << std::endl;
	}

}

std::string pickRandomWord(std::vector<std::string> words)
{
	std::string randomWord;

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, words.size() - 1);

	int randomIndex = distribution(rng);

	randomWord = words[randomIndex];

	return randomWord;
}

void findAndReplace(std::string wordToGuess, std::string& placeHolder, char characterToSearchFor)
{
	bool wasLetterFound = false; 

	for (int i = 0; i < placeHolder.size(); i++)
	{
		if (wordToGuess[i] == characterToSearchFor)
		{
			wasLetterFound = true;
			placeHolder[i] = characterToSearchFor;
		}
	}

	if (wasLetterFound)
	{
		std::cout << "correct " << std::endl;
	}
	else
	{
		std::cout << "Incorrect " << std::endl;
	}
	std::cout << "The updated placeholder is " << placeHolder << std::endl;
}

