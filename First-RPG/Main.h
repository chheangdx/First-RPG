#pragma once
class CMain
{
private:
	bool quit;

	SDL_Window *window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
	
	SDL_Texture *grass_image;
	SDL_Rect grass_rect;

	SDL_Texture *bob_image;
	SDL_Rect bob_rect;
public:
	CMain(void);
	~CMain(void);

	void GameLoop(void);
};

