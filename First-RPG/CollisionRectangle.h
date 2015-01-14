#pragma once
#include "StdAfx.h"

class CCollisionRectangle
{
private:
	SDL_Rect CollisionRect;
	//x,y is top left of image, not window

	int OffsetX;
	int OffsetY;
public:
	CCollisionRectangle();
	CCollisionRectangle(int x, int y, int w, int h);
	~CCollisionRectangle(void);

	void SetRectangle(int x, int y, int w, int h);
	SDL_Rect GetRectangle();

	void SetX(int offset);
	void SetY(int offset);

	CCollisionRectangle GetCollisionRect();
};

