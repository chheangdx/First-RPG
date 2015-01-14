#pragma once

#include "SDL_Setup.h"
#include "Sprite.h"

class Tree
{
private:
	CSprite* Crown;
	CSprite* Trunk;
	int x,y;
public:
	Tree(CSDL_Setup* csdl_setup, float *CameraX, float *CameraY, int x, int y);
	~Tree(void);

	void DrawCrown();
	void DrawTrunk();

	int GetX();
	int GetY();

	CSprite* GetCrown();
	CSprite* GetTrunk();
};

