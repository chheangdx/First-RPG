#pragma once
#include "Sprite.h"
#include "SDL_Setup.h"
#include <math.h>

class MainCharacter
{
private:
	CSprite* bob;

	unsigned int timeCheck;

	bool follow;
	int Follow_point_x;
	int Follow_point_y;
	
	float angle;
	float distance;
	
	CSDL_Setup* csdl_setup;
	int *MouseX;
	int *MouseY;

public:
	MainCharacter(CSDL_Setup* csdl_setup, int *MouseX, int *MouseY);
	~MainCharacter(void);

	float GetDistance(float x1, float y1, float x2, float y2);
	void Update();
	void Draw();
};

