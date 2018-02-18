#include "stdafx.h"
#include "Character.h"

Character::Character()
{
	Name = "Jim";
	Health = 100;
	Age = 20;
	Score = 100;
}

Character::Character(const std::string & name, int age, int health, int score)
{
	Name = name;
	Age = age;
	Health = health;
	Score = score;
}

Character::~Character()
{
	SDL_DestroyTexture(Texture);
}

void Character::BuildTextureFromFont(TTF_Font* currentFont, SDL_Renderer* renderer)
{
	//Build up a string
	std::ostringstream stringstream;
	stringstream << Name << " " << Age << " " << Score << " " << Health << std::endl;

	//Create a surface from current font, a string and a colour
	SDL_Surface* surface = TTF_RenderText_Solid(currentFont, stringstream.str().c_str(), { 255,255,255 });
	//Convert it into a texture
	Texture = SDL_CreateTextureFromSurface(renderer, surface);
	//Get rid of the surface
	SDL_FreeSurface(surface);
}
