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
		std::cout << "cout not find the file " << filename << std::endl;
		return {};
	}

	std::string currentWord;

	while (std::getline(fin, currentWord))
	{
		words.push_back(currentWord);
	}

	std::cout << "The number of words is: " << words.size() << std::endl;
 	return words;
}

std::string PickRandomWord(std::vector<std::string> words)
{
	std::string randomWord;

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, words.size() - 1);

	int randomIndex = distribution(words[randomIndex]);

	return randomWord;
}
