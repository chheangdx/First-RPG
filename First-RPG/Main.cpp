#include "StdAfx.h"
#include "Main.h"


CMain::CMain(int screen_width,int screen_height)
{
	quit = false;

	csdl_setup = new CSDL_Setup(&quit, screen_width, screen_height);
	grass = new CSprite(csdl_setup->GetRenderer(), "data/grass.bmp", 0, 0, 600, 500);
	bob = new CSprite(csdl_setup->GetRenderer(), "data/bob.png", 300, 250, 50, 100);
}


CMain::~CMain(void)
{
	delete csdl_setup;
	delete grass;
	delete bob;
}

void CMain::GameLoop(void)
{
	while(!quit && csdl_setup->GetMainEvent()->type != SDL_QUIT){
		csdl_setup->Begin();

		grass->Draw();
		bob->Draw();
		
		csdl_setup->End();
	}
}