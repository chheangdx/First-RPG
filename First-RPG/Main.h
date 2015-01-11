#pragma once

#include "Environment.h"
#include "SDL_Setup.h"
#include "Sprite.h"
#include "MainCharacter.h"
#include <math.h>

class CMain
{
private:
	bool quit;
	CSDL_Setup* csdl_setup;

	int MouseX;
	int MouseY;

	MainCharacter* bob;

	float CameraX;
	float CameraY;

	CEnvironment* ForestArea;
public:
	CMain(int screen_width,int screen_height);
	~CMain(void);

	void GameLoop(void);


};

