#include "StdAfx.h"
#include "SDL_Setup.h"


CSDL_Setup::CSDL_Setup(bool *quit, int screen_width, int screen_height)
{
	SDL_Init(SDL_INIT_VIDEO);

	window = NULL;
	window = SDL_CreateWindow("My First RPG!", 100, 100, screen_width, screen_height, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		*quit = true;
	}
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mainEvent = new SDL_Event(); // to get events such as pressing the close window button

}


CSDL_Setup::~CSDL_Setup(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* CSDL_Setup::GetRenderer(void)
{
	return renderer;
}

SDL_Event* CSDL_Setup::GetMainEvent(void)
{
	return mainEvent;
}

void CSDL_Setup::Begin(void)
{
	SDL_PollEvent(mainEvent); //check for event
	SDL_RenderClear(renderer);
}
void CSDL_Setup::End(void)
{
	SDL_RenderPresent(renderer);
}