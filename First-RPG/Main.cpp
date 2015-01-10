#include "StdAfx.h"
#include "Main.h"


CMain::CMain(int screen_width,int screen_height)
{
	quit = MoveRight = MoveLeft = MoveUp = MoveDown =false;

	csdl_setup = new CSDL_Setup(&quit, screen_width, screen_height);
	grass = new CSprite(csdl_setup->GetRenderer(), "data/grass.bmp", 0, 0, 600, 500);
	bob = new CSprite(csdl_setup->GetRenderer(), "data/bob.png", 300, 250, 50, 100);

	timeCheck = SDL_GetTicks();
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
		
		switch(csdl_setup->GetMainEvent()->type)
		{
		case SDL_KEYDOWN:
			switch(csdl_setup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_a:
				MoveLeft = true;
				std::cout << "Key Down!" << std::endl;
				break;
			case SDLK_s:
				MoveDown = true;
				std::cout << "Key Down!" << std::endl;
				break;
			case SDLK_w:
				MoveUp = true;
				std::cout << "Key Down!" << std::endl;
				break;
			case SDLK_d:
				MoveRight = true;
				std::cout << "Key Down!" << std::endl;
				break;
			default:
				break;
			}

			break;
		case SDL_KEYUP:
			switch(csdl_setup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_a:
				MoveLeft = false;
				break;
			case SDLK_s:
				MoveDown = false;
				break;
			case SDLK_w:
				MoveUp = false;
				break;
			case SDLK_d:
				MoveRight = false;
				break;
			default:
				break;
			}

			break;
		default:
			break;
		}

		if(timeCheck+100 < SDL_GetTicks()) //update every 500 ms
		{
			if(MoveLeft){
				bob->SetX(bob->GetX() - 2);
			}
			if(MoveDown){
				bob->SetY(bob->GetY() + 2);
			}
			if(MoveUp){
				bob->SetY(bob->GetY() - 2);
			}
			if(MoveRight){
				bob->SetX(bob->GetX() + 2);
			}

			timeCheck = SDL_GetTicks();
		}
		csdl_setup->End();
	}
}