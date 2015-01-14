#pragma once

#include "SDL_Setup.h"
#include "Sprite.h"
#include "Tree.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class CEnvironment
{
private:
	int Mode;
	CSprite* grass[4][7];
	std::vector <Tree*> trees;

	float *CameraX;
	float *CameraY;	

	CSDL_Setup* csdl_setup;

	bool OnePressed;
public:
	CEnvironment(CSDL_Setup* csdl_setup, int screen_width,int screen_height, float *CameraX, float *CameraY);
	~CEnvironment(void);

	void DrawBack();
	void DrawFront();

	void Update();
	
	void SaveToFile();
	void LoadFromFile();

	std::vector<Tree*> GetTrees();

	enum ModeType
	{
		GamePlay, 
		LevelCreation
	};
};

