#pragma once

#include "SDL_Setup.h"
#include "Sprite.h"

class CMain
{
private:
	bool quit;
	CSDL_Setup* csdl_setup;
	CSprite* grass;
	CSprite* bob;
public:
	CMain(int screen_width,int screen_height);
	~CMain(void);

	void GameLoop(void);
};

