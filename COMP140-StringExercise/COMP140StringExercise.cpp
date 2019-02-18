// COMP140StringExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class CharacterStats
{
public:
	CharacterStats()
	{
		Name = "Name";
		Age = 10;
		Health = 19;
		Score = 0;
	}
	~CharacterStats()
	{

	}

	//Everything public! Bad, make sure its private
	//and we use functions to access!
	std::string Name;
	int Age;
	int Health;
	int Score;

};


int main()
{
	//Create an instance of CharacterStats
	CharacterStats stats;
	stats.Age = 30;
	stats.Name = "Brian";
	stats.Health = 100;
	stats.Score = 0;

	//Build a string to represent the character - to_string - http://www.cplusplus.com/reference/string/to_string/
	std::string characterString = "Name: " + stats.Name + " Age: " + std::to_string(stats.Age) + " Health: " + std::to_string(stats.Health) + " Score: " + std::to_string(stats.Score);

	//Print out the string
	std::cout << "Character Details" << std::endl;
	std::cout << "=================" << std::endl;
	std::cout << characterString << std::endl;
    return 0;
}

