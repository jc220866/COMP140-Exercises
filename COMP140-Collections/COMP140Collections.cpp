// COMP140Collections.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Character.h"

int main(int, char**)
{
	int windowWidth = 800;
	int windowHeight = 640;
	//Initialise the Video Part of SDL2
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		//Print out an error message to the screen if this fails
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	//Initalise the font library
	if (TTF_Init() != 0)
	{
		std::cout << "Unable to load SDL TTF " << TTF_GetError() << std::endl;
	}

	//Creare a 800x640
	SDL_Window *window = SDL_CreateWindow("Collections", 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		//Print out error if this fails
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	//Create a renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		//Print error and cleanup
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	//Load font
	TTF_Font * currentFont = TTF_OpenFont("assets/fonts/Roboto-Regular.ttf",24);
	if (currentFont == nullptr)
	{
		std::cout << "Unable to load font " << TTF_GetError()<<std::endl;
	}

	//create a vector of characters
	std::vector<Character*> Characters;
	//Add two characters to the vector
	Characters.push_back(new Character("Jim", 12, 40, 0));
	Characters.push_back(new Character("Sarah", 32, 100, 10));

	//Make sure we do this after we have add every character to the vector
	for (auto character : Characters)
	{
		character->BuildTextureFromFont(currentFont, renderer);
	}

	//Drawing position for the characters
	SDL_Rect position;
	//Controls the game loop
	bool quit = false;
	//Holds events coming from SDL
	SDL_Event event;
	//Game Loop, while quit is false
	while (!quit)
	{
		//Check for Messages from SDL
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
				//Quit Message
				case SDL_QUIT:
				{
					quit = true;
					break;
				}
				//Key Down
				case SDL_KEYDOWN:
				{
					//if we have pressed the escape key
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						quit = true;
					}
					break;
				}
			}
		}

		//Clear the renderer
		SDL_RenderClear(renderer);



		//Display the work the renderer has been doing, this make something appear on the screen

		//The starting position of the characters on the screen
		position.x = 0;
		position.y = 0;
		position.w = 200;
		position.h = 30;

		//Iterate through the characters
		for (auto character : Characters)
		{
			//Grab the texture and copy onto the renderer
			SDL_RenderCopy(renderer, character->GetTexture(), NULL, &position);
			//move the position on a little bit
			position.y += position.h;
		}
		
		SDL_RenderPresent(renderer);
	}

	//Delete all the characters, this is the best and probably only way top delete 
	//everything in a vector
	for (auto iter = Characters.begin(); iter != Characters.end();)
	{
		//do we have some memory assigned
		if ((*iter))
		{
			//delete it
			delete ((*iter));
			//erase the position in the vector and return back a new iterator to
			//the next item 
			iter = Characters.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	//cleanup!
	TTF_CloseFont(currentFont);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();
	SDL_Quit();

	return 0;
    return 0;
}

