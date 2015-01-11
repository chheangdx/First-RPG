#pragma once

#include "SDL_Setup.h"
#include "Sprite.h"
#include "MainCharacter.h"
#include <math.h>

class CMain
{
private:
	bool quit;
	CSDL_Setup* csdl_setup;
	CSprite* grass;

	int MouseX;
	int MouseY;

	MainCharacter* bob;
public:
	CMain(int screen_width,int screen_height);
	~CMain(void);

	void GameLoop(void);


};

