#include "StdAfx.h"
#include "Main.h"


CMain::CMain(int screen_width,int screen_height)
{
	quit = false;

	csdl_setup = new CSDL_Setup(&quit, screen_width, screen_height);
	grass = new CSprite(csdl_setup->GetRenderer(), "data/grass.bmp", 0, 0, 600, 500);
	bob = new CSprite(csdl_setup->GetRenderer(), "data/bob.png", 300, 250, 50, 100);
	bob->SetOrigin(bob->GetWidth()/2.0f, (float) bob->GetHeight());

	timeCheck = SDL_GetTicks();
	MouseX = 0;
	MouseY = 0;
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
		SDL_GetMouseState(&MouseX, &MouseY);

		grass->Draw();
		bob->Draw();

		if(timeCheck+10 < SDL_GetTicks()) //update every 500 ms
		{
			float distance = GetDistance(bob->GetX(), bob->GetY(), (float) MouseX, (float) MouseY);
			if((int)distance != 0){
			if(bob->GetX() > MouseX){
				bob->SetX(bob->GetX() - ((bob->GetX()-MouseX)/distance) * 1.5f);
			}
			if(bob->GetX() < MouseX){
				bob->SetX(bob->GetX() - ((bob->GetX()-MouseX)/distance) * 1.5f);
			}
			if(bob->GetY() < MouseY){
				bob->SetY(bob->GetY() - ((bob->GetY()-MouseY)/distance) * 1.5f);
			}
			if(bob->GetY() > MouseY){
				bob->SetY(bob->GetY() - ((bob->GetY()-MouseY)/distance) * 1.5f);
			}
			}

			timeCheck = SDL_GetTicks();
		}
		csdl_setup->End();
	}
}

float CMain::GetDistance(float x1, float y1, float x2, float y2)
{
	float DifferenceX = x1 - x2;
	float DifferenceY = y1 - y2;
	float distance = sqrt(DifferenceX * DifferenceX + DifferenceY * DifferenceY);
	return distance;
}