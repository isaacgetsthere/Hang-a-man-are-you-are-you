#include <iostream>
#include "Hangman.h"

int main()
{
	std::string absoluteFilePath = "C://Users//downloads//popular.txt";
	std::vector<std::string> dictionaryWords = getAllDictionaryWords(absoluteFilePath);

	std::cout << "The randomw word to guess is: " << pickRandomWord(dictionaryWords) << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "The random word to guess is: " << pickRandomWord(dictionaryWords) << std::endl;
	}
}