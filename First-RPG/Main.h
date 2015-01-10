#pragma once

#include "SDL_Setup.h"
#include "Sprite.h"

#include <math.h>

class CMain
{
private:
	bool quit;
	CSDL_Setup* csdl_setup;
	CSprite* grass;
	CSprite* bob;

	unsigned int timeCheck;

	int MouseX;
	int MouseY;
public:
	CMain(int screen_width,int screen_height);
	~CMain(void);

	void GameLoop(void);
	float GetDistance(float x1, float y1, float x2, float y2);

};

