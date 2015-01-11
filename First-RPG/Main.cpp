#include "StdAfx.h"
#include "Main.h"


CMain::CMain(int screen_width,int screen_height)
{
	CameraX = 0;
	CameraY = 0;

	quit = false;

	csdl_setup = new CSDL_Setup(&quit, screen_width, screen_height);
	grass = new CSprite(csdl_setup->GetRenderer(), "data/grass.bmp", 0, 0, 600, 500, 1, 1, &CameraX, &CameraY);

	MouseX = 0;
	MouseY = 0;

	bob = new MainCharacter(csdl_setup, &MouseX, &MouseY, &CameraX, &CameraY);
}


CMain::~CMain(void)
{
	delete csdl_setup;
	delete grass;
}

void CMain::GameLoop(void)
{
	while(!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT){
		csdl_setup->Begin();
		SDL_GetMouseState(&MouseX, &MouseY);

		grass->Draw();

		bob->Draw();
		bob->Update();

		csdl_setup->End();
	}
}
