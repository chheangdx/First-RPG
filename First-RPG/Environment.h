#pragma once

#include "SDL_Setup.h"
#include "Sprite.h"

class CEnvironment
{
private:
	CSprite* grass[4][7];

	float *CameraX;
	float *CameraY;	
public:
	CEnvironment(CSDL_Setup* csdl_setup, int screen_width,int screen_height, float *CameraX, float *CameraY);
	~CEnvironment(void);

	void DrawBack();
	void DrawFront();
};

