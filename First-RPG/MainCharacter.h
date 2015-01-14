#pragma once
#include "Sprite.h"
#include "SDL_Setup.h"
#include <math.h>
#include "Environment.h"

class MainCharacter
{
private:
	CSprite* bob;
	CEnvironment* environment;

	unsigned int timeCheck;

	bool follow;
	int Follow_point_x;
	int Follow_point_y;
	
	float angle;
	float distance;
	
	CSDL_Setup* csdl_setup;
	int *MouseX;
	int *MouseY;

	float *CameraX;
	float *CameraY;


	void UpdateControls();
	void UpdateAnimation();
public:
	MainCharacter(CSDL_Setup* csdl_setup, int *MouseX, int *MouseY, float *CameraX, float *CameraY, CEnvironment* environment);
	~MainCharacter(void);
	float GetDistance(float x1, float y1, float x2, float y2);
	void Update();
	void Draw();
};

