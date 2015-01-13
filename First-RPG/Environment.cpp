#include "StdAfx.h"
#include "Environment.h"


CEnvironment::CEnvironment(CSDL_Setup* csdl_setup, int screen_width,int screen_height, float *CameraX, float *CameraY)
{
	this->CameraX = CameraX;
	this->CameraY = CameraY;

	for(int i=0; i<4; i++){
		for(int j=0; j<7; j++){
			grass[i][j] = new CSprite(csdl_setup->GetRenderer(), "data/environment/grass.bmp", screen_width*i, screen_height*j, 600, 500, 1, 1, CameraX, CameraY);
		}
	}

	trees.push_back(new Tree(csdl_setup, CameraX, CameraY, 300, 300));
	trees.push_back(new Tree(csdl_setup, CameraX, CameraY, 350, 300));

	this->csdl_setup = csdl_setup;
	OnePressed = false;
}


CEnvironment::~CEnvironment(void)
{
	for(int i=0; i<4; i++){
		for(int j=0; j<7; j++){
			delete grass[i][j];
		}
	}
	for(std::vector<Tree*>::iterator i=trees.begin(); i != trees.end(); ++i){
		delete (*i);
	}
	trees.clear();
}

void CEnvironment::DrawBack()
{
	for(int i=0; i<4; i++){
		for(int j=0; j<7; j++){
			grass[i][j]->Draw();
		}
	}
	for(std::vector<Tree*>::iterator i=trees.begin(); i != trees.end(); ++i){
		(*i)->DrawTrunk();
	}
}
void CEnvironment::DrawFront()
{
	for(std::vector<Tree*>::iterator i=trees.begin(); i != trees.end(); ++i){
		(*i)->DrawCrown();
	}
}

void CEnvironment::Update()
{	
	if(csdl_setup->GetMainEvent()->type == SDL_KEYDOWN){
		if(!OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_1)
		{
			trees.push_back(new Tree(csdl_setup, CameraX, CameraY,  - (int) *CameraX + 275, - (int) *CameraY + 90));
			OnePressed = true;
		}
	}
	if(csdl_setup->GetMainEvent()->type == SDL_KEYUP){
		if(OnePressed && csdl_setup->GetMainEvent()->key.keysym.sym == SDLK_1)
		{
			OnePressed = false;
		}
	} 
}