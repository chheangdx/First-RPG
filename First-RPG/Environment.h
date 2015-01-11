#pragma once

#include "SDL_Setup.h"
#include "Sprite.h"
#include "Tree.h"
#include <vector>

class CEnvironment
{
private:
	CSprite* grass[4][7];
	std::vector <Tree*> trees;

	float *CameraX;
	float *CameraY;	

	SDL_Event* events;
public:
	CEnvironment(CSDL_Setup* csdl_setup, int screen_width,int screen_height, float *CameraX, float *CameraY);
	~CEnvironment(void);

	void DrawBack();
	void DrawFront();

	void Update();
};

