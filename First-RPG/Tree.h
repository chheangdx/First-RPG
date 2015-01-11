#pragma once

#include "SDL_Setup.h"
#include "Sprite.h"

class Tree
{
private:
	CSprite* Crown;
	CSprite* Trunk;
public:
	Tree(CSDL_Setup* csdl_setup, float *CameraX, float *CameraY, int x, int y);
	~Tree(void);

	void DrawCrown();
	void DrawTrunk();
};

