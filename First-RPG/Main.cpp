#include "StdAfx.h"
#include "Main.h"


CMain::CMain(void)
{
	quit = false;
	window = NULL;
	window = SDL_CreateWindow("My First RPG!", 100, 100, 600, 400, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		quit = true;
	}
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mainEvent = new SDL_Event(); // to get events such as pressing the close window button

	grass_image = NULL;
	grass_image = IMG_LoadTexture(renderer, "data/grass.bmp");
		if(grass_image == NULL)
	{
		std::cout << "Grass texture not created!" << std::endl;
	}
	//location to start drawing
	grass_rect.x = 0;
	grass_rect.y = 0;
	//width and height to draw
	grass_rect.w = 600;
	grass_rect.h = 500;

	//do same thing but for bob imagebob_image = NULL;
	bob_image = IMG_LoadTexture(renderer, "data/bob.png");
			if(bob_image == NULL)
	{
		std::cout << "Bob not created" << std::endl;
	}
	bob_rect.x = 300;
	bob_rect.y = 250;
	bob_rect.w = 80;
	bob_rect.h = 50;
}


CMain::~CMain(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
	SDL_DestroyTexture(grass_image);
	SDL_DestroyTexture(bob_image);
}

void CMain::GameLoop(void)
{
	while(!quit && mainEvent->type != SDL_QUIT){
		SDL_PollEvent(mainEvent); //check for event
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, grass_image, NULL, &grass_rect); //put grass image with rectangle grass rect onto renderer
		SDL_RenderCopy(renderer, bob_image, NULL, &bob_rect); //put bob image with rectangle bob rect onto renderer


		SDL_RenderPresent(renderer);
	}
}