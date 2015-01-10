// First-RPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char* argv[])
{
	bool quit = false;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = NULL;
	window = SDL_CreateWindow("My First RPG!", 100, 100, 600, 400, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		return -1;
	}

	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event* mainEvent = new SDL_Event(); // to get events such as pressing the close window button

	SDL_Texture *grass_image = NULL;
	grass_image = IMG_LoadTexture(renderer, "grass.bmp");

	SDL_Rect grass_rect;
	//location to start drawing
	grass_rect.x = 0;
	grass_rect.y = 0;
	//width and height to draw
	grass_rect.w = 600;
	grass_rect.h = 500;

	//do same thing but for bob image
	SDL_Texture *bob_image = NULL;
	bob_image = IMG_LoadTexture(renderer, "bob.png");

	SDL_Rect bob_rect;
	bob_rect.x = 300;
	bob_rect.y = 250;
	bob_rect.w = 80;
	bob_rect.h = 50;

	while(!quit && mainEvent->type != SDL_QUIT){
		SDL_PollEvent(mainEvent); //check for event
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, grass_image, NULL, &grass_rect); //put grass image with rectangle grass rect onto renderer
		SDL_RenderCopy(renderer, bob_image, NULL, &bob_rect); //put bob image with rectangle bob rect onto renderer


		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;

	return 0;
}

